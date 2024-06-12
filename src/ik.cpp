#include <Arduino.h>
#include "Header.h"

//#define PI 3.141592 
#define LEN1 45
#define LEN2 73
#define LEN3 155


const V3 offset(118, 0 , 155);

void anglecalc(legStruct &leg)
{
    float sinval = sin(leg.mountangle * DEG_TO_RAD);
    float cosval = cos(leg.mountangle * DEG_TO_RAD);

    V3 ikcoordinates;
    
    ikcoordinates.x = cosval * leg.target.x + sinval * leg.target.y + offset.x;

    ikcoordinates.y = sinval * leg.target.x - cosval * leg.target.y + offset.y;

    ikcoordinates.z = leg.target.z + offset.z;

    float ang0 = atan2(ikcoordinates.y, ikcoordinates.x) * RAD_TO_DEG;

    int LEN2S = LEN2 * LEN2;
    int LEN3S = LEN3 * LEN3;

    int ang1 = atan2(ikcoordinates.z , (ikcoordinates.x - LEN1)) + acosf((LEN3S - LEN2S - ikcoordinates.xscorr() - ikcoordinates.zs())/(-2 * LEN2 * sqrt(ikcoordinates.xscorr() + ikcoordinates.zs()))) * RAD_TO_DEG;
    int ang2 = acosf((LEN3S + LEN2S - ikcoordinates.xscorr() - ikcoordinates.zs())/(2*LEN2*LEN3)) * RAD_TO_DEG;

    if(leg.mirr)
    {
        leg.servos[0].targetAng = 90 - ang0;
        leg.servos[1].targetAng = 90 - ang1;
        leg.servos[2].targetAng = 90 - ang2;
    }
    else{
        leg.servos[0].targetAng = 90 + ang0;
        leg.servos[1].targetAng = 90 + ang1;
        leg.servos[2].targetAng = 90 + ang2;
    }

}





