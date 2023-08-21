#include<Servo.h>
Servo servo0;
Servo servo1;
int incoming[1];
int pos=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo0.attach(3);
  servo1.attach(5);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(8,HIGH);
}



void loop()
 {
      // put your main code here, to run repeatedly:
             while(Serial.available()>=1){
                      for(int i=0;i<=1;i++){
                     incoming[i]=Serial.read();
                        }
               }
            incoming[0]=incoming[0]/2;


                              for (pos = 0; pos <= incoming[0]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                              {                                                                             

                                servo0.write(pos);                                 // tell servo to go to position in variable 'pos'

                                delay(15);                                                   // waits 15ms for the servo to reach the position

                              }
      
                            for (pos = incoming[0]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                              {            

                              servo0.write(pos);                                  // tell servo to go to position in variable 'pos'

                               delay(15);                                         // waits 15ms for the servo to reach the position

                              }

                               for (pos = 0; pos <= incoming[0]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                              {                                                                             

                                servo1.write(pos);                                 // tell servo to go to position in variable 'pos'

                                delay(15);                                                   // waits 15ms for the servo to reach the position

                              }
      
                            for (pos = incoming[0]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                              {            

                              servo1.write(pos);                                  // tell servo to go to position in variable 'pos'

                               delay(15);                                         // waits 15ms for the servo to reach the position

                              }
                              digitalWrite(8,HIGH);
                              digitalWrite(9,HIGH);
                              digitalWrite(10,HIGH);

                              if(incoming[0]>6){
                                
                                digitalWrite(9,LOW);
                              }
                              if(incoming[0]<6){
                               
                                digitalWrite(9,HIGH);
                              }



          
                   

 }

/**
            if(incoming[0]!=0 && incoming[1]==0){
                              for (pos = 0; pos <= incoming[0]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                              {                                                                             

                                servo0.write(pos);                                 // tell servo to go to position in variable 'pos'

                                delay(15);                                                   // waits 15ms for the servo to reach the position

                              }
      //delay();
                            for (pos = incoming[0]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                              {            

                              servo0.write(pos);                                  // tell servo to go to position in variable 'pos'

                               delay(15);                                         // waits 15ms for the servo to reach the position

                              }

                   }
  
              else if(incoming[0]==0 && incoming[1]!=0){
                      for (pos = 0; pos <= incoming[1]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                      {                                                                             

                        servo1.write(pos);                                 // tell servo to go to position in variable 'pos'

                        delay(15);                                                   // waits 15ms for the servo to reach the position

                      }
      //delay();
                      for (pos = incoming[1]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                      {            

                       servo1.write(pos);                                  // tell servo to go to position in variable 'pos'

                       delay(15);                                         // waits 15ms for the servo to reach the position

                      }

                    }
  
               else if(incoming[0]!=0 && incoming[1]!=0){
                     for (pos = 0; pos <= incoming[0]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                       {                                                                             

                          servo0.write(pos);                                 // tell servo to go to position in variable 'pos'

                        delay(15);                                                   // waits 15ms for the servo to reach the position

                       }
                  for (pos = 0; pos <= incoming[1]; pos += 1)         // goes from 0 degrees to 180 degrees

                                                                                // in steps of 1 degree

                     {                                                                             

                       servo0.write(pos);                                 // tell servo to go to position in variable 'pos'

                       delay(15);                                                   // waits 15ms for the servo to reach the position

                     }
      //delay();
                   for (pos = incoming[0]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                     {            

                      servo1.write(pos);                                  // tell servo to go to position in variable 'pos'

                      delay(15);                                         // waits 15ms for the servo to reach the position

                       }

             
  
                 for (pos = incoming[1]; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

                        {            

                             servo1.write(pos);                                  // tell servo to go to position in variable 'pos'

                              delay(15);                                         // waits 15ms for the servo to reach the position

                        }

                }
  

        
    }
      
 
  
    **/





