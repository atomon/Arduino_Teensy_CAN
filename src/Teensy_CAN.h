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

        int bauds;

        int binary_search(int key);

    public:

        TEENSY_CAN(int _bauds);

        void set();

        void set_send();

        void set_read();

        pair<int, int> read(int ID);

        void send(int id[], int encoder[], int x);

        void dual_send(int id[], int encoder[], int x);

};

#endif
