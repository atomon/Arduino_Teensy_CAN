#include "Arduino.h"
#include "CAN_read.h"
#include <FlexCAN.h>
#include <vector>
#include <algorithm>

CAN_READ::CAN_READ(){}

void CAN_READ::printFrame(CAN_message_t &frame, int mailbox)
{
  
   int32_t data = (int32_t) (
       ((frame.buf[0] << 24))
     | ((frame.buf[1] << 16))
     | ((frame.buf[2] <<  8))
     | ((frame.buf[3] <<  0))
   );
   
   int32_t data2 = (int32_t) (
       ((frame.buf[4] << 24))
     | ((frame.buf[5] << 16))
     | ((frame.buf[6] <<  8))
     | ((frame.buf[7] <<  0))
   );
   
   for (unsigned int i = 0; i < vec.size(); i++)
   {
      if((int)frame.id == vec[i][0]){
         vec[i][1] = data;
         vec[i][2] = data2;
         return;
      }
   }

   //vector<int> vec2;
   //vec.push_back({(int)frame.id, data, data2});
   vec.emplace_back(vector<int>());
   vec[vec.size()-1].emplace_back(frame.id);
   vec[vec.size()-1].emplace_back(data);
   vec[vec.size()-1].emplace_back(data2);

   sort(vec.begin(), vec.end());
   
}

bool CAN_READ::frameHandler(CAN_message_t &frame, int mailbox, uint8_t controller)
{
    printFrame(frame, mailbox);
    return true;
}
