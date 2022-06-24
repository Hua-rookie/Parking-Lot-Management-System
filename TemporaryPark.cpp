#include "TemporaryPark.h"
#include "ParkingLot.h"
#include"Car.h"
#include"Queue.h"
using namespace std;
TemporaryPark::~TemporaryPark()
{
    while(top!=NULL)
    {
        ParkingNode *p;
        p=top;
        top=top->next;
        delete p;
    }
}

void TemporaryPark::In(Car *p)
{
    top=new ParkingNode(p,top);
}

void TemporaryPark::Out(Car* &p)
{
    p=top->c;
    ParkingNode *q = top;
    top=top->next;
    delete q;
}

bool TemporaryPark::TP_isempty()
{
    if (top==NULL)
        return true;
    else
        return false;
}
