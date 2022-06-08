#ifndef CAN_SEND_H
#define CAN_SEND_H

#include "Arduino.h"
#include <FlexCAN.h>

class CAN_SEND {

    private:

        CAN_message_t msg;
    
    public:
        
        CAN_SEND();

        void send(int id[], int encoder[], int x);
        
        void dual_send(int id[], int encoder[], int x);
        
};

#endif
