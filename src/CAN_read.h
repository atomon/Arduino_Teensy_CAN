#ifndef CAN_READ1_H
#define CAN_READ1_H

#include "Arduino.h"
#include <FlexCAN.h>
#include <vector>
#include <algorithm>

using namespace std;

class CAN_READ : public CANListener
{

    private:

        void printFrame(CAN_message_t &frame, int mailbox);

        bool frameHandler(CAN_message_t &frame, int mailbox, uint8_t controller); //overrides the parent version so we can actually do something

    public:

        vector<vector<int>> vec;

        CAN_READ();
        
};

#endif
