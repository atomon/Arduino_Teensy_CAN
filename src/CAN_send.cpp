#include "Arduino.h"
#include "CAN_send.h"
#include <FlexCAN.h>

CAN_SEND::CAN_SEND(){}

void CAN_SEND::send(int id[], int encoder[], int x)
{
    for(int lp=0; lp<x; lp++)
    {  
        msg.id = id[lp];
        msg.ext = 0;
        msg.len = 4;
        msg.buf[0] = (byte)((encoder[lp] >> 24));
        msg.buf[1] = (byte)((encoder[lp] >> 16));
        msg.buf[2] = (byte)((encoder[lp] >>  8));
        msg.buf[3] = (byte)((encoder[lp] >>  0));
        msg.buf[4] = 0;
        msg.buf[5] = 0;
        msg.buf[6] = 0;
        msg.buf[7] = 0;
        Can0.write(msg);
    }
}

void CAN_SEND::dual_send(int id[], int encoder[], int x){
    x = (x+1)/2;
    int count = 0;
    for(int lp = 0; lp < x+1; lp += 2)
    {  
        msg.id = id[count];
        msg.ext = 0;
        msg.len = 8;
        msg.buf[0] = (byte)((encoder[lp] >> 24));
        msg.buf[1] = (byte)((encoder[lp] >> 16));
        msg.buf[2] = (byte)((encoder[lp] >>  8));
        msg.buf[3] = (byte)((encoder[lp] >>  0));
        msg.buf[4] = (byte)((encoder[lp+1] >> 24));
        msg.buf[5] = (byte)((encoder[lp+1] >> 16));
        msg.buf[6] = (byte)((encoder[lp+1] >>  8));
        msg.buf[7] = (byte)((encoder[lp+1] >>  0));
        Can0.write(msg);
        count++;
    }
}
