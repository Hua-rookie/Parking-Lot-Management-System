#include"Queue.h"
#include"Car.h"
#include <iostream>
using namespace std;
void Queue::EnQueue(Car* p, time_t m_time)
{
    if (front == NULL)
    {       front = rear = new ParkingNode(p); length = 1;
}
    else {
        rear->next = new ParkingNode(p); rear = rear->next;
    }
    p->Wait(length, m_time);
    length++;
}


void Queue::DeQueue(Car*& p) {
    ParkingNode* q = front;
    if (front == rear)
    {
        p = front->c;
        p->Wait(1,0);
        delete q;
        front = rear = NULL;
    }
    else
    {
        p = front->c;
        front = front->next;
        delete q;
        q = front;
        int i = 1;
        while (q->next != NULL) {
            q->c->Wait(i, 0);
            i++;
            q=q->next;
        }
        q->c->Wait(i, 0);
    }
}

bool Queue::Q_isempty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

ParkingNode* Queue::getfront()
{
    return front;
}

bool Queue::Q_search(string Lisense, time_t Currenttime)
 {
    ParkingNode* p = front;
    Car *q=NULL;
    int place=1;
     while (p != NULL) {
         q = p->c;
         if (q->GetLicenceNumber() == Lisense)
         {
             if (Currenttime==-1)
             {
                 time_t m_time=q->GetQuitTime();
                 cout<<"Status:OUT"<<endl;
                 cout<<"No:"<<q->GetNo()<<endl;
                 cout<<"QuiTime:"<<ctime(&m_time)<<endl;
                 cout<<"StayTime:"<<(q->GetQuitTime()-q->GetEntryTime())/1000<<"–° ±"<<endl<<endl;
                 return true;
             }
             else
                 cout<<"Status:WAITING"<<endl;
                 cout<<"No:"<<q->GetNo()<<endl;
                 cout<<"StayTime:"<<(Currenttime-q->GetEntryTime())/1000<<"–° ±"<<endl<<endl;
             return true;
         }
         p = p->next;
         place++;
     }
    /*while (q->next != NULL) {
        a = q->c->GetLicenceNumber();
        if (a == Lisense) {
            Waitingtime = q->c->GetEntryTime();
            Waitingtime = Currenttime - Waitingtime;
            cout << place << endl << Lisense << endl << Waitingtime << endl << q->c->GetEntryTime() << endl;
            return true;
        }
        q = q->next;
        place++;
    }
    a = q->c->GetLicenceNumber();
    if (a == Lisense) {
        Waitingtime = q->c->GetEntryTime();
        Waitingtime = Currenttime - Waitingtime;
        cout << place << endl << Lisense << endl << Waitingtime << endl << q->c->GetEntryTime() << endl;
        return true;
    }*/
    
    return false;
};

;
void Queue::show() {
    ParkingNode* q = front;
    while (q->next != NULL) {
        cout << q->c->GetLicenceNumber()<<endl;
        q = q->next;
    }
    cout << q->c->GetLicenceNumber()<<endl<<endl;
};

