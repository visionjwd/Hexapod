#include <Arduino.h>
#include "Header.h"
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <Wire.h>


#define MIN_P 120
#define MAX_P 500
#define SERVO_FREQ 50

void test(){
  /*Serial.begin(115200);
  Serial.println("Test Test Test");
  servoDriver_0.begin();
  servoDriver_0.setPWMFreq(SERVO_FREQ);
  servoDriver_1.begin();
  servoDriver_1.setPWMFreq(SERVO_FREQ);
  
  for(int i = 0; i < 16; i ++)
  {
    servoDriver_0.setPWM(i, 1 , 310);
    //servoDriver_1.setPWM(i, 1 , MAX_P);
  }*/
}
void init(){
  controllerInit();
  //HexaStatus = STAND;
  allTo90();
  walkPos();
  



}
void setup() {

  /*-------------------------Startup--------------------------*/
  init();

  
  delay(1000);
  controllerInit();
};

void loop() {
  // put your main code here, to run repeatedly:
  walkCycle();
  
}

