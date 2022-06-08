/*
 *      @content  This example is Teensy's CAN read
 *      @author   Ryouhei Ohnishi
 *      @date     2019/8/25
 *      
 * Both buses are set to 1M(1000k) to show things with a faster bus.
 * The reception of frames in this library is done via callbacks
 * to an object rather than polling. Frames are delivered as they come in.
 */

#include <Teensy_CAN.h>

//declare object and set baud
TEENSY_CAN CAN0(0, 1000000);

//declare array
int val[4];

void setup(void)
{
    // setup can_read and can_send
    CAN0.set();
}

void loop(void)
{
    //Read data with CAN
    tie(val[0], ignore) = CAN0.read(1);  // tie(Value, ignore) = object name.read(ID);
    tie(val[1], ignore) = CAN0.read(2);  // 'ignore' means that it doesn't receive
    tie(val[2], ignore) = CAN0.read(3);
    tie(val[3], ignore) = CAN0.read(4);

    //Show on serial monitor
    for(int lp : val){
        Serial.print(lp);
        Serial.print(" ");
    }
    Serial.println();
    
    delay(10);
}
