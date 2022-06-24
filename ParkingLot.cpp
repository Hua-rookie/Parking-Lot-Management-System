#include<iostream>
#include<math.h>
#include "ParkingLot.h"
#include"Car.h"
#include"Queue.h"
#include "TemporaryPark.h"
using namespace std;
ParkingLot::~ParkingLot()
{
    while (top != NULL)
    {
        ParkingNode* p;
        p = top;
        top = top->next;
        delete p;
    }
}
void ParkingLot::add(Car* p, time_t m_time) {
    top = new ParkingNode(p, top);
    length++;
    p->Entry(length, m_time);
    if(m_time!=0)
         cout << endl << "≥µ≈∆∫≈£∫" << p->GetLicenceNumber() << endl << "Õ£≥µ ±º‰£∫" << ctime(&m_time)<< endl << "≥µŒª∫≈£∫" << length << endl << endl;
    /*p=front->p;
    if(top==NULL){
        top=new ParkingNode(p);
        top->next=NULL;
        length=1;
    }
    else{
        ParkingNode *q;
        q=new ParkingNode(p);
        q->next=top;
        top=q;
        length++;
    }
    p->Wait(x,time);
    DeQueue(Car *p);*/
}

void ParkingLot::Q_add(Car* p, time_t m_time)
{
    top = new ParkingNode(p, top);
    length++;
    p->Entry(length, m_time);
}
void ParkingLot::out(int imout, time_t m_time ,Car* &q)
{
    TemporaryPark TP;
    ParkingNode* p;
    Car* C = NULL;
    while (length >= imout)
    {
        if (length == imout)
        {
            q=top->c;
            top->c->Quit(m_time);
        }
        else
            TP.In(top->c);
            p = top;
        top = top->next;
        delete p;
        length--;
    }
    while (!TP.TP_isempty())
    {
        TP.Out(C);
        add(C, 0);
    }
    /*while(length>imout){
        ParkingNode *q;
        q=new ParkingNode;
        q=top->next;
        EnQueue(top->c,0,0);
        delete top;
        top=q;
        length--;
    }*/
}
bool ParkingLot::PL_isfull()
{
    if (length == 25) { return true; }
    else { return false; }
}

bool ParkingLot::PL_isempty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

int ParkingLot::fee(Car *p)
{
    time_t intime=p->GetEntryTime(),outime=p->GetQuitTime();
    if (outime - intime < 1) { return 5; }
    else { return 5 + 2 * ceil((outime - intime - 1) / 1000); }
}

int ParkingLot::show()
{
    int i = 0;
    int j = 0;
    int p = 1;
    for (; j < 11; j++)
    {

        for (i = 0; i < 5; i++)
        {
            if (j % 2 == 0)
                cout << "----- ";
            else if (j % 2 != 0)
            {
                if (p < 10 && p <= length)
                    cout << "|" << p << " " << "”–" << " ";
                else if (p<10 && p>length)
                    cout << "|" << p << " " << "ø’" << " ";
                else if (p >= 10 && p <= length)
                    cout << "|" << p << "”–" << " ";
                else if (p >= 10 && p > length)
                    cout << "|" << p << "ø’" << " ";
                p++;
            }
        }
        cout << endl;
    }
    return 0;
}
bool ParkingLot::P_search(string chepaihao,time_t m_time)
{
    ParkingNode* p = top;
    Car *q;
    while (p != NULL)
    {
        q=p->c;
        if (q->GetLicenceNumber() == chepaihao)
        {
            cout<<"Status:IN"<<endl;
            cout<<"No:"<<q->GetNo()<<endl;
            cout<<"StayTime:"<<(m_time-q->GetEntryTime())/1000<<"–° ±"<<endl;
            cout<<"Expense:"<< 5 + 2 * ((m_time-q->GetEntryTime()- 1) / 1000)<<"‘™"<<endl<<endl;
            return true;
        }
        p = p->next;
    }
    return false;
}

