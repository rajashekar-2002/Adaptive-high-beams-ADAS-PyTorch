//Mario's Ideas
//MAX7219 - using Led Control library to display 8x8 bitmap
#include <LedControl.h>
char ch[3] = "";
int DIN = 11;
int CS = 7;
int CLK = 13;
LedControl lc=LedControl(DIN, CLK, CS,0);

int Cat[8] ={B10001000,B11111000,B10101000,B01110001,B00100001,B01111001,B01111101,B10111110 };
byte Apple [8]={B00011000,B00001000,B01110110,B11111111,B11111111,B11111111,B01111010,B00110100};
int position0[8]={B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B1111111};
int position1[8]={B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111};
int position2[8]={B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111};
int position3[8]={B11001111,B11001111,B11001111,B11001111,B11001111,B11001111,B11001111,B11001111};
int position4[8]={B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B11100111};
int position5[8]={B11110011,B11110011,B11110011,B11110011,B11110011,B11110011,B11110011,B11110011};
int position6[8]={B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000};
int position7[8]={B11111100,B11111100,B11111100,B11111100,B11111100,B11111100,B11111100,B11111100};
int position8[8]={B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B11111110};
byte position9[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

////////////////////////////////////////////////////////
/////END - FUNCTIONS TO HANDLE SINGLE CAR DETECTION/////



////START - FUNCTIONS TO HANDLE 2 CARS DETECTED//////////
////////////////////////////////////////////////////////
int position01[8]={B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111};
int position02[8]={B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111};
int position03[8]={B11000111,B11000111,B11000111,B11000111,B11000111,B11000111,B11000111,B11000111};
int position04[8]={B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B11100111};
int position05[8]={B11110011,B11110011,B11110011,B11110011,B11110011,B11110011,B11110011,B11110011};
int position06[8]={B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000};
int position07[8]={B11111100,B11111100,B11111100,B11111100,B11111100,B11111100,B11111100,B11111100};
int position08[8]={B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B11111110,B11111110};
int position09[8]={B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111};
int position12[8]={B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111,B00011111};
int position13[8]={B00000111,B00000111,B00000111,B00000111,B00000111,B00000111,B00000111,B00000111};
int position14[8]={B00100111,B00100111,B00100111,B00100111,B00100111,B00100111,B00100111,B00100111};
int position15[8]={B00110011,B00110011,B00110011,B00110011,B00110011,B00110011,B00110011,B00110011};
int position16[8]={B00111000,B00111000,B00111000,B00111000,B00111000,B00111000,B00111000,B00111000};
int position17[8]={B00111100,B00111100,B00111100,B00111100,B00111100,B00111100,B00111100,B00111100};
int position18[8]={B00111110,B00111110,B00111110,B00111110,B00111110,B00111110,B00111110,B00111110};
int position23[8]={B00001111,B00001111,B00001111,B00001111,B00001111,B00001111,B00001111,B00001111};
int position24[8]={B00000111,B00000111,B00000111,B00000111,B00000111,B00000111,B00000111,B00000111};
int position25[8]={B00010011,B00010011,B00010011,B00010011,B00010011,B00010011,B00010011,B00010011};
int position26[8]={B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000};
int position27[8]={B00011100,B00011100,B00011100,B00011100,B00011100,B00011100,B00011100,B00011100};
int position28[8]={B00011110,B00011110,B00011110,B00011110,B00011110,B00011110,B00011110,B00011110};
int position34[8]={B11000110,B11000110,B11000110,B11000110,B11000110,B11000110,B11000110,B11000110};
int position35[8]={B11000010,B11000010,B11000010,B11000010,B11000010,B11000010,B11000010,B11000010};
int position36[8]={B10001000,B10001000,B10001000,B10001000,B10001000,B10001000,B10001000,B10001000};
int position37[8]={B10001100,B10001100,B10001100,B10001100,B10001100,B10001100,B10001100,B10001100};
int position38[8]={B10001110,B10001110,B10001110,B10001110,B10001110,B10001110,B10001110,B10001110};
int position45[8]={B11100011,B11100011,B11100011,B11100011,B11100011,B11100011,B11100011,B11100011};
int position46[8]={B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000};
//int position01[8]={B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111,B00111111};
int position47[8]={B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000};
int position48[8]={B11100110,B11100110,B11100110,B11100110,B11100110,B11100110,B11100110,B11100110};
int position56[8]={B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000};
int position57[8]={B11110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000};
int position58[8]={B00110010,B00110010,B00110010,B00110010,B00110010,B00110010,B00110010,B00110010};
int position67[8]={B00111000,B00111000,B00111000,B00111000,B00111000,B00111000,B00111000,B00111000};
int position68[8]={B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000,B11111000};
int position78[8]={B00111100,B00111100,B00111100,B00111100,B00111100,B00111100,B00111100,B00111100};

//////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         
  lc.shutdown(0,false);
  lc.setIntensity(0,0);
  lc.clearDisplay(0);
  //Serial.setTimeout(100);
  /**
  for(int i=0;i<8;i++) lc.setRow(0,i,Apple[i]);
  delay(5000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,Cat[i]);
  delay(5000);
  lc.clearDisplay(0);
  **/
}
  /**
void loop(){
  for(int i=0;i<8;i++) lc.setRow(0,i,Apple[i]);
  delay(5000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,Cat[i]);
  delay(5000);
  lc.clearDisplay(0);
}
**/




void loop()
{
    ////START - Check serial connection status
    if(Serial.available() > 0)
    { 
        ////START - Handle detected vehicles
        //Data sent over the serial port will contain 3 characters
        //So the loop will be executed 3 times
        for(int i = 0; i < 3; i++)
        {
            ch[i] = Serial.read();                //Start reading characters from the received data
            if(ch[1]=='y'){
            ////START - else if checks for single vehicle detected
            if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '0')
                {
                for(int i=0;i<8;i++) lc.setRow(0,i,position0[i]);
                delay(5000);
                lc.clearDisplay(0);
                }
    
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '1')
                {
                for(int i=0;i<8;i++) lc.setRow(0,i,position1[i]);
                delay(5000);
                lc.clearDisplay(0);
                }
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '2')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position2[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
    
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '3')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position3[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
    
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '4')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position4[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '5')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position5[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '6')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position6[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '7')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position7[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '8')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position8[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '9')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position9[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            }
            ////END - else if checks for single vehicle detected
  
  
            ////START - else if checks for double vehicle detected
              
            //START - ZEROTH COLUMN
            else if (ch[0] == 'x' && ch[1] == '0' && ch[2] == '1' || ch[0] == 'x' && ch[1] == '1' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position01[i]);
                delay(20000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == '0' && ch[2] == '2' || ch[0] == 'x' && ch[1] == '2' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position02[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if (ch[0] == 'x' && ch[1] == '0' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position03[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            else if (ch[0] == 'x' && ch[1] == '0' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position04[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position05[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position06[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position07[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '0' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '0')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position08[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            //END - ZEROTH COLUMN  
  
            //START - FIRST COLUMN
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '2' || ch[0] == 'x' && ch[1] == '2' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position12[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position13[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position14[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position15[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
    
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position16[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position17[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '1' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '1')
            {
                for(int i=0;i<8;i++) lc.setRow(0,i,position18[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            //END - FIRST COLUMN  
  
            //START - SECOND COLUMN
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '3' || ch[0] == 'x' && ch[1] == '3' && ch[2] == '2')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position23[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '2')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position24[i]);
                delay(5000);

            }  
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '2')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position25[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '2'){
                                for(int i=0;i<8;i++) lc.setRow(0,i,position26[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '2')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position27[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '2' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '2')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position28[i]);
                delay(5000);
                lc.clearDisplay(0);
            //END - SECOND COLUMN  
            }
  
            //START - THIRD COLUMN
            else if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '4' || ch[0] == 'x' && ch[1] == '4' && ch[2] == '3')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position34[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '3')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position35[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '3')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position36[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '3')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position37[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '3' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '3')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position34[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            //END - THIRD COLUMN  
  
            //START - FOURTH COLUMN
            else if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '5' || ch[0] == 'x' && ch[1] == '5' && ch[2] == '4')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position45[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '4')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position46[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '4')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position47[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '4' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '4')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position48[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            //END - FOURTH COLUMN  
  
            //START - Felse ifTH COLUMN
            else if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '6' || ch[0] == 'x' && ch[1] == '6' && ch[2] == '5')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position56[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '5')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position57[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '5' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '5')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position58[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
            //END - Felse ifTH COLUMN            
  
            //START - SIXTH COLUMN
            else if(ch[0] == 'x' && ch[1] == '6' && ch[2] == '7' || ch[0] == 'x' && ch[1] == '7' && ch[2] == '6')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position67[i]);
                delay(5000);
                lc.clearDisplay(0);
            }
  
            else if(ch[0] == 'x' && ch[1] == '6' && ch[2] == '8' || ch[0] == 'x' && ch[1] == '8' && ch[2] == '6')
            {
                                for(int i=0;i<8;i++) lc.setRow(0,i,position68[i]);
                delay(5000);
                lc.clearDisplay(0);
            //END - SIXTH COLUMN  
            }
  
            //START - SEVENT COLUMN
            else if ((ch[0] == 'x' && ch[1] == '7' && ch[2] == '8') || (ch[0] == 'x' && ch[1] == '8' && ch[2] == '7'))
            {
                for(int i=0;i<8;i++) 
                 lc.setRow(0,i,position78[i]);
                delay(5000);
                lc.clearDisplay(0); 
            }
            
            //END - SEVENTH COLUMN
            
            ////END - else if checks for double vehicle detected

            //To make sure what is being received from the serial port
            //Wirte on the serial to double check the characters on the Pyhton side
            Serial.print(ch[i]);

            //Flush to clear the received data
            Serial.flush();  
        }
        ////END - Handle detected vehicles        
    }
    ////END - Check serial connection status    
}