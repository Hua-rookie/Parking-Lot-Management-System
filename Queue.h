#ifndef Queue_h
#define Queue_h
#include"Car.h"
#include <iostream>
using namespace std;
/*struct QueueNode
{
    Car* p;
    QueueNode* link;
    QueueNode(Car* x, QueueNode* ptr = NULL) :p(x), link(ptr) {};
};*/
class Queue
{
private:
    ParkingNode* front;
    ParkingNode* rear;
    int length;
public:
    Queue() { front = rear = NULL; length = 1; }
    ParkingNode* getfront();
    void EnQueue(Car*, time_t);//入
    void DeQueue(Car*&);//出
    bool Q_isempty();
    bool Q_search(string, time_t);//检索
    void show();
};
#endif
