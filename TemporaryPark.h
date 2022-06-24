#ifndef TemporaryPark_h
#define TemporaryPark_h
#include <iostream>
#include"Car.h"
#include"Queue.h"
using namespace std;
class TemporaryPark
{protected:
    ParkingNode *top;
public:
    TemporaryPark() {top=NULL;}
    ~TemporaryPark();
    void In(Car *p);
    void Out(Car* &p);
    bool TP_isempty();
};
/*class Park
{protected:
    ParkingNode *top;
public:
    Park();
    bool isempty();
    bool isfull();
    void add();
};*/
#endif /* TemporaryPark_h */
