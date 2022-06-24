#ifndef ParkingLot_h
#define ParkingLot_h
#include <iostream>
#include"Car.h"
#include"Queue.h"
#include "TemporaryPark.h"
using namespace std;
/*struct ParkingNode{
    ParkingNode *next;
    Car *c;
    ParkingNode(Car* x, ParkingNode* ptr = NULL) :c(x), next(ptr) {};
};*/
class ParkingLot
{
public:
    ParkingLot() { top = NULL; length = 0; }
    ~ParkingLot();
    void add(Car* p, time_t time);
    void Q_add(Car* p, time_t time);
    void out(int imout, time_t time, Car* &);
    bool PL_isfull();
    bool PL_isempty();
    bool P_search(string ,time_t);
    ParkingNode* GetTop() { return top; }
    int show();
    int fee(Car*);
protected:
    ParkingNode* top;
    int length;
};
#endif /* ParkingLot_h */
