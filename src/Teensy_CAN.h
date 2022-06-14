#ifndef Teensy_CAN_H
#define Teensy_CAN_H

#include "Arduino.h"
#include "CAN_read.h"
#include "CAN_send.h"
#include <FlexCAN.h>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class TEENSY_CAN
{

    private:

        CAN_READ can_read;
        CAN_SEND can_send;

        int bus, bauds;

#ifndef __MK66FX1M0__
        FlexCAN *can[1] = {&Can0};
#else 
        FlexCAN *can[2] = {&Can0, &Can1};
#endif


        int binary_search(int key);

    public:

        TEENSY_CAN(uint8_t _bus = 0, int _bauds = 1000000);

        void set();

        void set_send();

        void set_read();

        pair<int, int> read(int ID);

        void send(int id[], int encoder[], int x);

        void dual_send(int id[], int encoder[], int x);

};

#endif
