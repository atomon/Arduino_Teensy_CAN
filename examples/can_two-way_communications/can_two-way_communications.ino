/*
 *      @content  This example is Teensy's CAN two-way communications
 *      @author   Ryouhei Ohnishi
 *      @date     2019/8/25
 *      
 * Both buses are set to 1M(1000k) to show things with a faster bus.
 * The reception of frames in this library is done via callbacks
 * to an object rather than polling. Frames are delivered as they come in.
 */

#include <Teensy_CAN.h>

//declare object and set baud
TEENSY_CAN can(1000000);

//declare array
int id[4] = {1, 2, 3, 4};
int data[4]={11, 220, 3300, 44000};
int id2[4] = {5, 6, 7, 8};
int data2[4] = {550000, 6600000, 77000000, 880000000};
int val[8];

void setup(void)
{
    //can setup
    can.set();
}

void loop(void)
{
    //Send data with CAN
    can.send(id, data, 4);
    can.dual_send(id2, data2, 4);
    
    //Read data with CAN
    tie(val[0], ignore) = can.read(1);
    tie(val[1], ignore) = can.read(2);
    tie(val[2], ignore) = can.read(3);
    tie(val[3], ignore) = can.read(4);
    tie(val[4], val[5]) = can.read(5);
    tie(val[6], val[7]) = can.read(6);
    
    //Show on serial monitor
    for(int lp : val){
        Serial.print(lp);
        Serial.print(" ");
    }
    Serial.println();

    delay(100);
}
