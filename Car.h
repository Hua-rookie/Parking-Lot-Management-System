#ifndef Car_h
#define Car_h
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

enum Status
{
    In,
    Out,
    Waiting
};

class Car
{protected:
    string LisenceNumber;
    int No;
    Status Car_Status;
    time_t EntryTime;
    time_t QuitTime;
public:
    Car(string l_num = "###",int no = -1,Status car_status = Out,long entrytime = 0,long quittime = 0) : No(no),LisenceNumber(l_num),Car_Status(car_status),EntryTime(entrytime),QuitTime(quittime) {};
    //~Car();
    bool Entry(int num,time_t m_time);
    bool Wait(int num,time_t m_time);
    bool Quit(time_t m_time);
    time_t GetEntryTime() const {return EntryTime;}
    time_t GetQuitTime() const {return QuitTime;}
    int GetNo() const {return No;}
    string GetLicenceNumber() const {return LisenceNumber;}
    Status GetStatus() const {return Car_Status;}
};

struct ParkingNode
{
    Car *c;
    ParkingNode *next;
    ParkingNode(Car* x, ParkingNode* ptr = NULL) :c(x), next(ptr) {};
};
#endif /* Car_h */
