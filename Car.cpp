#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

bool Car::Entry(int num,time_t m_time)
{
    Car_Status=In;
    No=num;
    if (m_time!=0)
       EntryTime=m_time;
    return true;
}

bool Car::Wait(int num,time_t m_time)
{
    Car_Status=Waiting;
    No=num;
    if (m_time!=0)
       EntryTime=m_time;
    return true;
}

bool Car::Quit(time_t m_time)
{
    Car_Status=Out;
    No=-1;
    QuitTime=m_time;
    return true;
}
/*int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}*/

/*int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}*/
