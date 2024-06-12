#include <Arduino.h>
#include "Header.h"

int triGroup1[3] = {0,2,4};
int triGroup2[3] = {1,3,5};

int legLift = 15;

void legForward(legStruct &leg, V2 &moveInput){
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
    lerpServoMove(leg);
}
void walkCycle(){
    getMoveInput();

}