////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 115200 
#define REMOTEXY_WIFI_SSID "R15 Project" 
#define REMOTEXY_WIFI_PASSWORD "ilangkaviyan" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,3,0,0,0,93,0,8,163,0,
  1,0,9,26,22,22,246,16,69,110,
  103,105,110,101,32,83,116,97,114,116,
  0,2,0,36,12,26,15,135,25,31,
  31,76,105,103,104,116,0,79,70,70,
  0,129,0,22,2,61,6,24,77,73,
  76,75,32,81,85,69,69,78,32,70,
  65,77,73,76,89,0,129,0,40,50,
  18,6,16,82,49,53,0,1,0,64,
  27,23,23,36,31,72,111,114,110,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t Light; // =1 if switch ON and =0 if OFF 
  uint8_t button_2; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_BUTTON_1 13
#define PIN_LIGHT 12
#define PIN_BUTTON_2 11


void setup()  
{ 
  RemoteXY_Init ();  
   
  pinMode (PIN_BUTTON_1, OUTPUT);
  pinMode (PIN_LIGHT, OUTPUT);
  pinMode (PIN_BUTTON_2, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  digitalWrite(PIN_LIGHT, (RemoteXY.Light==0)?LOW:HIGH);
  digitalWrite(PIN_BUTTON_2, (RemoteXY.button_2==0)?LOW:HIGH);
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
