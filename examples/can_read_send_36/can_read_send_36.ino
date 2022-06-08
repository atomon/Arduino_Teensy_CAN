#include <Arduino.h>
#include <Teensy_CAN.h>

//declare object and set baud
TEENSY_CAN CAN0(0, 1000000);
TEENSY_CAN CAN1(1, 1000000);

//declare array
int id[2] = {1, 2};
int s_val[4] = {0, 1, 2, 3};
int r_val[4] = {0};

void setup() {

  Serial.begin(9600);
    // setup can_read and can_send
    CAN0.set();
    CAN1.set();
}

void loop() {

  for(int index=0; index<(int)sizeof(s_val)/4; index++){
    s_val[index]++;
  }

  CAN0.dual_send(id, s_val, 4);

    // Read together two data with CAN
    tie(r_val[0], r_val[1]) = CAN1.read(1);  // tie(Value, Value2) = object name.read(ID);
    tie(r_val[2], r_val[3]) = CAN1.read(2);

    // Show on serial monitor
    for(int lp : r_val){
        Serial.print(lp);
        Serial.print(" ");
    }
    Serial.println();
    
    delay(10);
}
