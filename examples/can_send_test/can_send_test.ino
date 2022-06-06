/*
 *      @content  This example is Teensy's CAN send
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
int id[4] = {1, 2, 3, 4};      // set ID
int data[4]={11, 2200, 330000, 44000000};  // initial setting

void setup(void)
{
    // setup only can_send
    can.set_send();
}

void loop(void)
{   
    //Send data with CAN
    can.send(id, data, 4);  //(ID[array], value[array], number of data)

    //Put a delay(minimum 1ms)
    delay(10);
}
