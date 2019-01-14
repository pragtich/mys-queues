
// RFM69 radio settings
#define MY_RADIO_RFM69
#define MY_RFM69_FREQUENCY RFM69_868MHZ
#define MY_IS_RFM69HW
#define MY_RFM69_NEW_DRIVER
#define MY_RFM69_ATC_TARGET_RSSI_DBM (-70)  // target RSSI -70dBm
#define MY_RFM69_MAX_POWER_LEVEL_DBM (20)   // max. TX power 10dBm = 10mW

#define MY_RFM69_CSMA_LIMIT_DBM (-80)       // TX will wait until rx RSSI below this number; default -95

// Only relevant when OTA enabled on the node
// Requires patched mysensors
#define MY_OTA_RETRY (50)
#define MY_OTA_RETRY_DELAY (1000u) // default 500u


// Other
#define MY_SPLASH_SCREEN_DISABLED


// Enable debug prints
// #define MY_DEBUG

#include <MySensors.h>

#define CHILD_ID 3
#define SLEEP_MS (2000u)
MyMessage msg(CHILD_ID,V_TRIPPED);

void setup()  
{
}

void presentation() {
  sendSketchInfo("Test sensor queue sender", "1.0");
  // Register binary input sensor to gw (they will be created as child devices)
  // You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage. 
  // If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
  present(CHILD_ID, S_DOOR);  
}

int value = 0;

void loop() 
{
   // Send in the new value
   send(msg.set(value));
   value = 1 - value;
   smartSleep(SLEEP_MS);
}
