#include <Ticker.h>
#include "ESP8266WiFi.h"

String ssids[3] = {"0900 Breakfast", "1200 Lunch", "1500 Afternoon tea"};
Ticker ssidChanger;
int ptr = 0;

void changeSsid() {
  int state = digitalRead(1);  // get the current state of GPIO1 pin
  digitalWrite(1, !state);     // set pin to the opposite state
  
  WiFi.softAP(ssids[ptr].c_str());
  ptr++;
  if (ptr == 3) {
    ptr = 0;
  }
}

void setup() {
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  
  // put your setup code here, to run once:
  //0.1 works ok
  ssidChanger.attach(0.1, changeSsid);
}

void loop() {
  // put your main code here, to run repeatedly:

}
