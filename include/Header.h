#include <Arduino.h>
#include <Wire.h>
#include <vector>

#define SERVO
#define CONTROLLER

//MATH//

class V3
{
    public:
    float x,y,z;
    V3(float xx = 0.0f, float yy = 0.0f, float zz = 0.0f);
    V3 operator+(const V3 &input) const;
    V3 operator-(const V3 &input) const;
    V3 operator*(const float &value) const;
    V3 operator/(const float &value) const;
    V3 &operator=(const V3 &input);
    V3 operator==(const V3 &input) const;
    V3 operator!=(const V3 &input) const;
    float magnitude() const;
    float xscorr() const;
    float ys() const;
    float zs() const;
    V3 lerp(const V3 &start, const V3 &end, const float &t);
};
class V2
{
    public:
    float x,y;
    V2(float xx = 0.0f, float yy = 0.0f);
    V2 operator+(const V2 &input) const;
    V2 operator-(const V2 &input) const;
    V2 operator*(const float &value) const;
    V2 operator/(const float &value) const;
    V2 &operator=(const V2 &input);
    V2 operator==(const V2 &input) const;
    V2 operator!=(const V2 &input) const;
};

#ifdef SERVO

struct servoStruct
{
    int ch = 0;
    int minAng = 50, maxAng = 130;
    int targetAng = 90;
};
struct legStruct
{
    servoStruct servos[3];
    bool mirr;
    V3 target;
    V3 current; 
    int mountangle;
    bool lift = false;
};
legStruct leg[6];

void lerpServoMove(legStruct &leg);

#endif

#ifdef CONTROLLER

enum gaitmode
{
    tripod,
    biwave
};

struct inputStruct
{
    V2 xyinput;
    V2 rollInput;
    float rotateRight;
    float rotateLeft;
};

inputStruct input;
V2 inputTarget;
V2 rotateTarget;

void controllerInit();
void getMoveInput();
void getRollInput();
void clearInput();

#endif

enum status
{
    STAND,
    SIT,
    WALK
};

extern status HexaStatus;

//ik//

void anglecalc(legStruct &leg);