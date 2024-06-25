#include <Arduino.h>
#include "Header.h"

int triGroup1[3] = {0,2,4};
int triGroup2[3] = {1,3,5};

int legLift = 15;
boolean flipper = false;

void legForward(legStruct &leg, V2 &moveInput)
{

    //3 target points; 3 target angles
    //seperate gait into 3 parts. 
    //when 3 legs are moving back, lift and move the other 3 forward.
    V2 inter = (moveInput.x / 2, moveInput.y / 2); 
    if(leg.lift){
        leg.target = (inter.x, inter.y, legLift);
    }
    else{
        leg.target = (inter.x, inter.y, 0);
    }

    //first third
    delay(10);
    lerpServoMove(leg);
    delay(10);

    //second third
    leg.target = (moveInput.x, moveInput.y);
    delay(10);
    lerpServoMove(leg);
    delay(10);

}

void legBack(legStruct &leg, V2 &moveInput)
{
    leg.target = (-moveInput.x/2, -moveInput.y/2);
    delay(10);
    lerpServoMove(leg);
    delay(10);

    leg.target = (-moveInput.x, -moveInput.y);
    delay(10);
    lerpServoMove(leg);
    delay(10);

}

void walkCycle(){
    getMoveInput();
    V2 CurrInput = input.xyinput;

    if(flipper){
        legForward(leg[0], CurrInput);
        legForward(leg[2], CurrInput);
        legForward(leg[4], CurrInput);

        legBack(leg[1], CurrInput);
        legBack(leg[3], CurrInput);
        legBack(leg[5], CurrInput);
    }
    else{
        legForward(leg[1], CurrInput);
        legForward(leg[3], CurrInput);
        legForward(leg[5], CurrInput);

        legBack(leg[0], CurrInput);
        legBack(leg[2], CurrInput);
        legBack(leg[4], CurrInput);
    }

    flipper != flipper;

}



