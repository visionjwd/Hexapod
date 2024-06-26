#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <SPI.h>
#include <Header.h>

#define MIN_P 120
#define MAX_P 500
#define SERVO_BASE 310
#define SERVO_FREQ 50

float pwmFactor = 2.23;

Adafruit_PWMServoDriver servoDriver_0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver servoDriver_1 = Adafruit_PWMServoDriver(0x41);

legStruct leg[6];


V3 offset = V3(118, 0 , 155);

void servoInit()
{
    servoDriver_0.begin();
    servoDriver_1.begin();
    servoDriver_0.setOscillatorFrequency(27000000);
    servoDriver_1.setOscillatorFrequency(27000000);
    servoDriver_0.setPWMFreq(SERVO_FREQ);
    servoDriver_0.setPWMFreq(SERVO_FREQ);

    #pragma region legConfig
        leg[0].servos[2].ch = 0;
        leg[0].servos[1].ch = 1;
        leg[0].servos[0].ch = 2;

        leg[0].mirr = false;

        leg[1].servos[2].ch = 4;
        leg[1].servos[1].ch = 5;
        leg[1].servos[0].ch = 6;

        leg[1].mirr = false;

        leg[2].servos[2].ch = 8;
        leg[2].servos[1].ch = 9;
        leg[2].servos[0].ch = 10;

        leg[2].mirr = false;

        leg[3].servos[2].ch = 16;
        leg[3].servos[1].ch = 17;
        leg[3].servos[0].ch = 18;

        leg[3].mirr = true;

        leg[4].servos[2].ch = 20;
        leg[4].servos[1].ch = 21;
        leg[4].servos[0].ch = 22;

        leg[4].mirr = true;

        leg[5].servos[2].ch = 24;
        leg[5].servos[1].ch = 25;
        leg[5].servos[0].ch = 26;

        leg[5].mirr = true;

        for(int i = 0; i ++; i < 6){
            leg[i].target = (0,0,0);
        }

    #pragma endregion
}

void moveServo(servoStruct &servo)
{
    int angle = constrain(servo.targetAng, servo.minAng, servo.maxAng);

    if(servo.ch < 16){
        servoDriver_0.setPWM(servo.ch, 0, int(servo.targetAng * pwmFactor) + SERVO_BASE);
    }
    else{
        servoDriver_1.setPWM(servo.ch - 16, 0, int(servo.targetAng * pwmFactor) + SERVO_BASE);
    }
}
//move leg in 2 step lerp function smoothfunction. 
//mid path
void lerpServoMove(legStruct &leg)
{
    anglecalc(leg);
    moveServo(leg.servos[0]);
    moveServo(leg.servos[1]);
    moveServo(leg.servos[2]);

}

void allTo90()
{
    for(int i = 0; i < 6; i ++){
        leg[i].servos[0].targetAng = 0;
        leg[i].servos[1].targetAng = 0;
        leg[i].servos[2].targetAng = 0;
    }
}

void walkPos(){
    for(int i = 0; i < 6; i ++){
        leg[i].target = (0,0,walkHeight);
    }
}
