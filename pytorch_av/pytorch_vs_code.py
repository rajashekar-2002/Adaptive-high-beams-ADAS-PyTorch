from detecto.core import Dataset
import torch
import torchvision
#import pynbody
from torchvision import transforms
from detecto import core, utils, visualize
from detecto.core import Model
from detecto.visualize import plot_prediction_grid, detect_video, detect_live

import matplotlib.pyplot as plt
from detecto.utils import read_image
from detecto.visualize import show_labeled_image


import numpy as  np


#---------------------------------------------------------------
#calculating angle
from math import atan
def anglefor2(medx1,medx2,y):
  angb=atan((y[1][1]-350)/(400-y[1][0]))
  angt=atan((400-y[1][2])/(y[1][1]-350))
  thetha=90-(angb+angt)
  angb1=atan((y[0][1]-350)/(500-y[0][0]))
  angt1=atan((500-y[0][2])/(350-y[0][1]))
  thetha1=90-(angb1+angt1)
  print("angb={} angt={} angb1={} angt1={}".format(angb,angt,angb1,angt1))

def anglefor1(medx1, y):
      ang1 = atan((y[0][3] - 350) / (400 - y[0][0]))
      ang2 = atan((400 - y[0][2]) / (y[0][1] - 350))
      ang3 = atan((y[0][3] - 350) / (500 - y[0][0]))
      ang4 = atan((500 - y[0][2]) / (y[0][3] - 350))
      thetha = 90 - (ang1 + ang2)  # angle between led 5 and 4
      thetha1 = 90 - (ang3 + ang4)  # angle between led 2 and 1
      print("ang1={} ang2={} thetha={} thetha1={}".format(ang1, ang2, thetha, thetha1))


medX1 = None  # Variable for the position of first detected vehicle
medX2 = None  # Variable for the position of second detected vehicle
first = True  # Variable to turn False when the loop is entered 2nd time
second = False

#load saved model
model = Model.load('model_weights.pth', ['vehicle'])
torch_model = model.get_internal_model()
type(torch_model)

import cv2
from numpy import asarray

cap = cv2.VideoCapture('123.mp4')
# cap.set(cv2.CAP_PROP_POS_FRAMES, 500)
# cap.set(cv2.CAP_PROP_POS_MSEC,sec*1000)
# cap = cap.get(cv2.CAP_PROP_FPS*5) # Gets the frames per second
coord = [[100, 350], [500, 350], [100, 100], [500, 100]]
c = 0
while (True):
    # Capture frame-by-frame

    #if c != 0:
    ret, frame = cap.read()
     #   c = 0
    #else:
     #   while c != 200:
      #      ret, frame = cap.read()
       #     c = c + 1

    #h, w, c = frame.shape
    # roi=frame[100:500,100:350]#roi(x1x2,y1y2)
    # plt.show(roi)
    # roi = cv2.resize(roi, (h, w))
    numpydata1 = asarray(frame)
    # cv2_imshow(numpydata1)
    labels, boxes, scores = model.predict(numpydata1)
    thresh = 0.6
    height, width = numpydata1.shape[:2]
    h = height
    w = width
    print('height{} width{}'.format(height, width))
    filtered_indices = np.where(scores > thresh)
    filtered_scores = scores[filtered_indices]
    filtered_boxes = boxes[filtered_indices]
    num_list = filtered_indices[0].tolist()
    filtered_labels = [labels[i] for i in num_list]

    count = 0
    count = len(filtered_labels)
    print('count value={}'.format(count))
    medx1 = 0
    medx2 = 0
    med=[]
    show_labeled_image(frame, filtered_boxes, filtered_labels)
    cv2.line(frame, (coord[0][0], coord[0][1]), (coord[1][0], coord[1][1]), (0, 200, 80), 2)  # First horizontal line
    cv2.line(frame, (coord[0][0], coord[0][1]), (coord[2][0], coord[2][1]), (0, 2000, 80), 2)  # Vertical left line
    cv2.line(frame, (coord[2][0], coord[2][1]), (coord[3][0], coord[3][1]), (0, 200, 80), 2)  # Second horizontal line
    cv2.line(frame, (coord[1][0], coord[1][1]), (coord[3][0], coord[3][1]), (0, 200, 80), 2)  # Vertical right line

    for i in range (len(filtered_labels)):
        med.append((filtered_boxes[i][0] + filtered_boxes[i][2]) / 2)
    print(med)

    if count == 1:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        print("medx1={}".format(medx1))
        anglefor1(medx1, filtered_boxes)
    if count == 2:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        print("medx1={}".format(medx1))

        medx2 = (filtered_boxes[1][0] + filtered_boxes[1][2]) / 2
        print("medx2={}".format(medx2))
        anglefor2(medx1, medx2, filtered_boxes)
    if count == 0:
        continue

    if count>2:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        print("medx1={}".format(min(med)))

    #pynbody.plot.plt.close()

    # cv2_imshow(frame)
    # cv2_imshow(roi)
    '''
    while (count!=0 and count>0):
       count=count-1
       x=int(filtered_boxes[count][0])
       y=int(filtered_boxes[count][1])
       w=int(filtered_boxes[count][2])
       h=int(filtered_boxes[count][3])
  
      # get face bounding box for overlay
       cv2.rectangle(frame,(x,y),(x+w,y+h),(25,0,10),4)
       cv2_imshow(frame)      
       count=count-1
       '''

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()