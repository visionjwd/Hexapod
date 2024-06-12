#include <Arduino.h>
#include "Header.h"
#include <PS4Controller.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_err.h"

inputStruct input;


//remove paired devices
void removePairedDevices() {
  uint8_t pairedDeviceBtAddr[20][6];
  int count = esp_bt_gap_get_bond_device_num();
  esp_bt_gap_get_bond_device_list(&count, pairedDeviceBtAddr);
  for (int i = 0; i < count; i++) {
    esp_bt_gap_remove_bond_device(pairedDeviceBtAddr[i]);
  }
  
}
//initializing controller
void controllerInit(){
    PS4.begin("A8:8F:D9:30:74:06");
    PS4.setLed(255,0,0);
    removePairedDevices();
}
//get XY movement inputs from left joystick
void getMoveInput()
{
    input.xyinput.x = PS4.LStickX();
    input.xyinput.y = PS4.RStickY();
}
//get XY inputs for rotation from right joystick
void getRollInput()
{
    input.rollInput.x = PS4.RStickX();
    input.rollInput.y = PS4.LStickY();
}
void getRotateInput()
{
    input.rotateLeft = PS4.L2Value();
    input.rotateRight = PS4.R2Value();
}
//clearing movement input
void clearInput()
{
    input.xyinput.x = 0;
    input.xyinput.y = 0;
    input.rollInput.x = 0;
    input.rollInput.y = 0;
    input.rotateLeft = 0;
    input.rotateRight = 0;
}
void switchStatus()
{
    if(PS4.Square())
    {
        HexaStatus = STAND;
    }
    else if (PS4.Triangle())
    {
        HexaStatus = SIT;
    }
}