#include <LCD5110_Basic.h>
LCD5110 myGLCD(9,10,11,12,13);
extern uint8_t arduino_logo[];
extern uint8_t oshw_logo[];
extern uint8_t SmallFont[];

int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int analog_button = 8;
int x_axis = A0;
int y_axis = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, analog_button};
int sensorValue1;int outputValue1;
int sensorValue2;int outputValue2;
void setup() 
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  for (int i; i < 7; i++)
  {
   pinMode(buttons[i], INPUT);
   digitalWrite(buttons[i], HIGH);
  }
  myGLCD.clrScr();
  Serial.begin(9600);
  myGLCD.drawBitmap(0, 0, oshw_logo, 84, 48);delay(5000);
  myGLCD.clrScr();
}

void loop() 
{
 
  int up = digitalRead(up_button); int down = digitalRead(down_button);
  int left = digitalRead(left_button); int right = digitalRead(right_button);
  int started = digitalRead(start_button); int select = digitalRead(select_button);
  int clickbutton = digitalRead(analog_button); 
  
  myGLCD.print("Up   =",LEFT, 0);myGLCD.printNumI(up, CENTER, 0);
  myGLCD.print("Down =",LEFT, 15);myGLCD.printNumI(down, CENTER, 15);
  myGLCD.print("Left =",LEFT, 18);myGLCD.printNumI(left, CENTER, 18);
  myGLCD.print("Right=",LEFT, 24);myGLCD.printNumI(right, CENTER, 24);
  //myGLCD.print("Start = ",CENTER, 4);myGLCD.printNumI(up, RIGHT, 0);
  //myGLCD.print("Select = ",CENTER, 5);myGLCD.printNumI(up, RIGHT, 0);
  //myGLCD.print("Click = ",CENTER, 6);myGLCD.printNumI(up, RIGHT, 0);
  
  
  sensorValue1 = analogRead(x_axis); outputValue1 = map(sensorValue1, 0, 1023, 0, 255); 
  sensorValue2 = analogRead(y_axis); outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  myGLCD.print("X =",LEFT, 32);myGLCD.printNumI(outputValue1, CENTER, 32);
  myGLCD.print("Y =",LEFT, 40);myGLCD.printNumI(outputValue2, CENTER, 40);
  delay(100);
  
 }


