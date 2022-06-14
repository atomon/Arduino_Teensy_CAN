# Arduino_Teensy_CAN

## Dependencies

* [FlexCan.h](https://github.com/pawelsky/FlexCAN_Library)

## Basics

### Declaration

~~~C
#include <Teensy_CAN.h>

TEENSY_CAN can(0, 1000000); // busNumber, baudrate
~~~

### Set

~~~C
TEENSY_CAN can(0, 1000000);

void setup(void)
{
    can.set();
}
~~~

### Send

~~~C
TEENSY_CAN can(0, 1000000);

int id[4] = {};
int data[4]={};

void loop(void)
{
    can.send(id, data, 4); // idArray, dataArray, arraySize
}
~~~

### Send(Dual)

Send two data per one ID.

(Because data sent at one time in CAN communication is equivalent to 2 integer data)

~~~C
TEENSY_CAN can(0, 1000000);

int id[2] = {};
int data[4]={};

void loop(void)
{
    can.sendDual(id, data, 4); // idArray, dataArray, arraySize
}
~~~

### Read

~~~C
TEENSY_CAN can(0, 1000000);

int id;
int receivedData;

void loop(void){
    tie(receivedData, ignore) = can.read(id);
}
~~~

### Read(Dual)

~~~C
TEENSY_CAN can(0, 1000000);

int id;
int receivedData[2];

void loop(void){
    tie(receivedData[0], receivedData[1]) = can.read(id);
}
~~~

## [Examples](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples)

* [can_dual_read_test](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_dual_read_test) and [can_dual_send_test](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_dual_send_test)
* [can_read_test](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_read_test) and [can_send_test](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_send_test)
* [can_read_send_36](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_read_send_36)
* [can_two-way_communications](https://github.com/atomon/Arduino_Teensy_CAN/tree/main/examples/can_two-way_communications)