from detecto.core import Dataset
import torch
import torchvision
#import pynbody
#import matplotlib.pyplot.close
from torchvision import transforms
from detecto import core, utils, visualize
from detecto.core import Model
from detecto.visualize import plot_prediction_grid, detect_video, detect_live
import serial
import time
import os
import matplotlib.pyplot as plt
from detecto.utils import read_image
from detecto.visualize import show_labeled_image
import os
import struct
import numpy as  np

servo_motor = serial.Serial('COM7', 9600, timeout=0)

def delay():
    i=0
    while(i!=50000):
        i=i+1


def drawCurtainSingle(inpFrame, inpX, inpSer):

    ##Get the frame width
    fWidth = inpFrame.shape[1]
    print("Frame", fWidth)
    print("Single Car Detected")

    # Calculate the width of each column to be turned
    # ON/OFF based on the detected vehicle positions
    col1 = fWidth * 0.1 - 20
    col2 = fWidth * 0.2
    col3 = fWidth * 0.3
    col4 = fWidth * 0.4
    col5 = fWidth * 0.5
    col6 = fWidth * 0.6
    col7 = fWidth * 0.7
    col8 = fWidth * 0.8
    col9 = fWidth * 0.9

    # A slight delay to prevent LEDs from flickering too much
    time.sleep(0.15)

    ### START - If checks to determine which column to be turned ON/OFF ########
    ### ############################################################### ########
    if(inpX < col1):
        posX1 = "0"
        print("POSX1:", posX1.encode())

    elif(inpX >= col1 and inpX < col2):
        posX1 = "1"
        print("POSX1:", posX1.encode())

    elif(inpX >= col2 and inpX < col3):
        posX1 = "2"
        print("POSX1:", posX1.encode())

    elif(inpX >= col3 and inpX < col4):
        posX1 = "3"
        print("POSX1:", posX1.encode())

    elif(inpX >= col4 and inpX < col5):
        posX1 = "4"
        print("POSX1:", posX1.encode())

    elif(inpX >= col5 and inpX < col6):
        posX1 = "5"
        print("POSX1:", posX1.encode())

    elif(inpX >= col6 and inpX < col7):
        posX1 = "6"
        print("POSX1:", posX1.encode())

    elif(inpX >= col7 and inpX < col8):
        posX1 = "7"
        print("POSX1:", posX1.encode())

    elif(inpX >= col8 and inpX < col9):

        posX1 = "8"
        print("POSX1:", posX1.encode())

    elif(inpX >= col9):
        posX1 = "9"
        print("POSX1:", posX1.encode())
    ### ############################################################# ##########
    ### END - If checks to determine which column to be turned ON/OFF ##########

    # Define the final variable to be sent over the serial connection
    # to the LED control module
    # In this project, the variables that are sent to the LED module
    # must start with an "x"
    # Since there is only one detected vehicle in this function,
    # Second character is "y" and only the third character holds
    # the position of the detected vehicle
    posX4 = "x" + "y" + posX1

    print("POSX4: ", posX4.encode())

    # Write the final data to the serial port
    #for i in range(5):
    inpSer.write(posX4.encode())
        #delay()
#### END - FUNCTION TO HANDLE SINGLE VEHICLE DETECTED ##########################
#### ################################################ ##########################


################################################################################
#### START - FUNCTION TO HANDLE TWO VEHICLES DETECTED ##########################
def drawCurtainDouble(inpFrame, inpX1, inpX2, inpSer):

    ##Get the frame width
    fWidth = inpFrame.shape[1]
    print("Frame", fWidth)
    print("2 Cars Detected")

    # Calculate the width of each column to be turned
    # ON/OFF based on the detected vehicle positions
    col1 = fWidth * 0.1 - 20
    col2 = fWidth * 0.2
    col3 = fWidth * 0.3
    col4 = fWidth * 0.4
    col5 = fWidth * 0.5
    col6 = fWidth * 0.6
    col7 = fWidth * 0.7
    col8 = fWidth * 0.8
    col9 = fWidth * 0.9

    # A slight delay to prevent LEDs from flickering too much
    time.sleep(0.15)

    ### START - If checks to determine which column to be turned ON/OFF ########
    ### For the first detected vehicle
    ### ############################################################### ########
    if(inpX1 < col1):
        posX1 = "0"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col1 and inpX1 < col2):
        posX1 = "1"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col2 and inpX1 < col3):
        posX1 = "2"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col3 and inpX1 < col4):
        posX1 = "3"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col4 and inpX1 < col5):
        posX1 = "4"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col5 and inpX1 < col6):
        posX1 = "5"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col6 and inpX1 < col7):
        posX1 = "6"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col7 and inpX1 < col8):
        posX1 = "7"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col8 and inpX1 < col9):
        posX1 = "8"
        print("POSX1:", posX1.encode())

    if(inpX1 >= col9):
        posX1 = "0"
        print("POSX1:", posX1.encode())
    ##END - If checks to determine which column to be turned ON/OFF
    ##For the first detected vehicle

    ##START - If checks to determine which column to be turned ON/OFF
    ##For the second detected vehicle
    if(inpX2 < col1):
        posX2 = "0"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col1 and inpX2 < col2):
        posX2 = "1"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col2 and inpX2 < col3):
        posX2 = "2"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col3 and inpX2 < col4):
        posX2 = "3"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col4 and inpX2 < col5):
        posX2 = "4"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col5 and inpX2 < col6):
        posX2 = "5"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col6 and inpX2 < col7):
        posX2 = "6"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col7 and inpX2 < col8):
        posX2 = "7"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col8 and inpX2 < col9):
        posX2 = "8"
        print("POSX2:", posX2.encode())

    if(inpX2 >= col9):
        posX2 = "0"
        print("POSX2:", posX2.encode())
    ### ############################################################### ########
    ### END - If checks to determine which column to be turned ON/OFF ##########
    ### For the second detected vehicle

    # Define the final variable to be sent over the serial connection
    # to the LED control module
    # In this project, the variables that are sent to the LED module
    # must start with an "x"
    # Since there is two detected vehicles in this function,
    # The second & third characters hold the position of the detected vehicles
    posX3 = "x" + posX1 + posX2

    print("POSX3: ", posX3.encode())

    # Write the final data to the serial port
    #for i in range(5):
    inpSer.write(posX3.encode())
        #delay()
#### END - FUNCTION TO HANDLE TWO VEHICLES DETECTED ############################
#### ############################################## ############################


#### ################################################################## ########
#### START - FUNCTION TO HANDLE ZERO OR MORE THAN TWO VEHICLES DETECTED ########
def ledOnOff(state, inpSer):
    # If state is 1, switch all the LEDs ON
    # Since there is no cars detected
    if state == 1:
        posX = "0"
        posX1 = "x" + "y" + posX
        print("POSX1: ", posX1)

    # If state is 0, switch all the LEDs OFF
    # Since there is more than 2 cars detected
    if state == 0:
        posX = "9"
        posX1 = "x" + "y" + posX
        print("POSX1: ", posX1)

    # Write the final data to the serial port
    #for i in range(5):
    inpSer.write(posX1.encode())
        #delay()


#---------------------------------------------------------------
#calculating angle
from math import atan
import math
def anglefor2(medx1,medx2,y):
  count=2
  x1 = y[0][0]
  y1 = (y[0][3] + y[0][1]) / 2
  x2 = y[0][2]
  y2 = y1

  x11 = y[1][0]
  y11 = (y[1][1] + y[1][3]) / 2
  x12 = y[1][2]
  y12 = y11

  print(y[0][0],y[0][1],y[0][2],y[0][3])
  print(y[1][0],y[1][1],y[1][2],y[1][3])
  print(x1,x2,y1,y2,y11,y12,x12,x11)


  ang1 = atan(abs(350 - y1) / abs(300 - x1))
  ang2 = atan(abs(300 - x2) / abs(350 - y1))
  thetha = 90 - (abs(ang1 + ang2) *57.2958)  # angle between led 5 and 4
  angb=atan(abs(350-y11)/abs(400-x11))
  angt=atan(abs(x12-400) / abs(350-y12))
  thetha1=90-(abs(angb+angt)*57.2958)
  print("angb={} angt={} thetha={} thetha1={}".format(ang1, ang2, abs(thetha), abs(thetha1)))
  '''
  angb=atan((y[1][1]-350)/(400-y[1][0]))
  angt=atan((400-y[1][2])/(y[1][1]-350))
  thetha=90-(angb+angt)
  angb1=atan((y[0][1]-350)/(500-y[0][0]))
  angt1=atan((500-y[0][2])/(350-y[0][1]))
  thetha1=90-(angb1+angt1)
  print("angb={} angt={} angb1={} angt1={}".format(angb,angt,angb1,angt1))
  servo_motor.write(struct.pack('>BB', round(thetha), round(thetha1)))
  '''
  '''
  if (medx1 <300) and (medx2 <300):
      servo_motor.write(struct.pack('>BB', round(thetha), 0))
  if medx1 >300 and medx2 >300:
      servo_motor.write(struct.pack('>BB', 0, round(thetha1)))
  else:
      servo_motor.write(struct.pack('>BB', round(thetha), round(thetha1)))
      '''


def anglefor1(medx1, y):
      count=1
      x1 = y[0][0]
      y1 = (y[0][3] + y[0][1]) / 2
      x2 = y[0][2]
      y2 = y1

      ang1 = atan(abs(350 - y1) / abs(300 - x1))
      ang2 = atan(abs(300 - x2) /abs (350 - y1))
      ang3 = atan(abs(350 - y1) / abs(400 - x1))
      ang4 = atan(abs(400 - x2) / abs(350 - y1))
      thetha = 90 - (abs(ang1 + ang2)*57.2958)  # angle between led 5 and 4
      thetha1 = 90 - (abs(ang3 + ang4)*57.2958)  # angle between led 2 and 1
      print("ang1={} ang2={} thetha={} thetha1={}".format(ang1, ang2, abs(thetha), abs(thetha1)))
      servo_motor.write(struct.pack('>BB', round(thetha), round(thetha1)))
'''
      if medx1<300:
            servo_motor.write(struct.pack('>BB',round(thetha),0))
          
      if medx1==300:
            servo_motor.write(struct.pack('>BB',round(thetha),round(thetha1)))
            
      else:
          servo_motor.write(struct.pack('>BB',0,round(thetha1)))

'''
      #servo_motor.write(struct.pack('>BBBB',count,position,abs(ang1),abs(ang3)))

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
ser=serial.Serial('COM4', 9600, timeout = 0)
while (True):
    # Capture frame-by-frame

    if c != 0:
     ret, frame = cap.read()
     c = 0
    else:
     while c != 23:
       ret, frame = cap.read()
       c = c + 1

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
    #cv2.line(frame, (coord[0][0], coord[0][1]), (coord[1][0], coord[1][1]), (0, 200, 80), 2)  # First horizontal line
    #cv2.line(frame, (coord[0][0], coord[0][1]), (coord[2][0], coord[2][1]), (0, 2000, 80), 2)  # Vertical left line
    #cv2.line(frame, (coord[2][0], coord[2][1]), (coord[3][0], coord[3][1]), (0, 200, 80), 2)  # Second horizontal line
    #cv2.line(frame, (coord[1][0], coord[1][1]), (coord[3][0], coord[3][1]), (0, 200, 80), 2)  # Vertical right line

    for i in range (len(filtered_labels)):
        med.append((filtered_boxes[i][0] + filtered_boxes[i][2]) / 2)
    print(med)

    if count == 1:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        print("medx1={}".format(medx1))
        anglefor1(medx1, filtered_boxes)
        drawCurtainSingle(frame, medx1, ser)
    if count == 2:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        medx2 = (filtered_boxes[1][0] + filtered_boxes[1][2]) / 2
        print("medx1={}".format(medx1))
        drawCurtainDouble(frame, medx1, medx2, ser)
        print("medx2={}".format(medx2))
        anglefor2(medx1, medx2, filtered_boxes)
    if count == 0:
        ledOnOff(1, ser)
        print("No cars detected. High beams ON.")

    if count>2:
        medx1 = (filtered_boxes[0][0] + filtered_boxes[0][2]) / 2
        print("medx1={}".format(min(med)))
        ledOnOff(0, ser)
        print("More than two cars detected. High beams OFF.")

    msg = ser.readline()
    print("Arduino received: ", msg)

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