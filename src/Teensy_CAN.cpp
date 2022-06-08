#include "Arduino.h"
#include "Teensy_CAN.h"
#include "CAN_read.h"
#include "CAN_send.h"
#include <FlexCAN.h>
#include <vector>
#include <algorithm>
#include <tuple>

TEENSY_CAN::TEENSY_CAN(uint8_t _bus, int _bauds)
{
    bus = _bus;
    bauds = _bauds;

#ifndef __MK66FX1M0__
    if(bus == 1) #error "Teensy 3.6 with dual CAN bus is required to run can1"
#endif

}

void TEENSY_CAN::set()
{
    Serial.println(F("Hello Teensy Single CAN Receiving Example With Objects."));
    can[bus]->begin(bauds);
    delay(100);
    can[bus]->attachObj(&can_read);
    can_read.attachGeneralHandler();
}

void TEENSY_CAN::set_send()
{
    Serial.println(F("Hello Teensy Single CAN Receiving Example With Objects."));
    can[bus]->begin(bauds);
    delay(100);
}

void TEENSY_CAN::set_read()
{
    Serial.println(F("Hello Teensy Single CAN Receiving Example With Objects."));
    can[bus]->begin(bauds);
    delay(100);
    can[bus]->attachObj(&can_read);
    can_read.attachGeneralHandler();
}

int TEENSY_CAN::binary_search(int key)
{
  
    int maximum = (int)can_read.vec.size() - 1;
    int minimum = 0;

    while(maximum >= minimum)
    {
        int middle = (maximum + minimum) / 2;

        if(can_read.vec[middle][0] == key) return middle;
        else if(can_read.vec[middle][0] > key) maximum = middle-1;
        else if(can_read.vec[middle][0] < key) minimum = middle+1;
    }
    return -1;
    
}

pair<int, int> TEENSY_CAN::read(int ID){
    int iterator = binary_search(ID);
    if(iterator == -1) return{0,0};
    else return{can_read.vec[iterator][1], can_read.vec[iterator][2]}; 
}

void TEENSY_CAN::send(int id[], int encoder[], int x)
{
    can_send.send(id, encoder, x);
}
        
void TEENSY_CAN::dual_send(int id[], int encoder[], int x)
{
    can_send.dual_send(id, encoder, x);
}
