#include <Ticker.h>
#include "ESP8266WiFi.h"

String ssids[3] = {"0900 Breakfast", "1200 Lunch", "1500 Afternoon tea"};
Ticker ssidChanger;
int ptr = 0;

void changeSsid() {  
  WiFi.softAP(ssids[ptr].c_str());
  ptr++;
  if (ptr == 3) {
    ptr = 0;
  }
}

void setup() {  
  ssidChanger.attach(0.5, changeSsid);
}

void loop() {}
