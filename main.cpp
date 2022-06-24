#include <iostream>
#include <string>
#include "Car.h"
#include "ParkingLot.h"
#include "Queue.h"
#include"TemporaryPark.h"
#include"time.h"
using namespace std;
int main()
{
    ParkingLot PARK;
    ParkingLot* p = &PARK;
    Queue waiting_softpath,out_softpath;
    Queue *q=&waiting_softpath,*w=&out_softpath;
    time_t m_time;
    //int i = 0;
    int j = 0;
    string s;
    //long x = 0;
    //ParkingNode *p_ParkingNode = NULL;
    
    //the prowork
    while (true)
    {
        cout << "«Î—°‘Ò“‘œ¬π¶ƒ‹" << endl;
        cout << "A:PARK" << endl;
        cout << "B:OUT" << endl;
        cout << "C:CHECK THE STUIATION" << endl;
        cout << "D:CHECK THE Car" << endl;
        cout << "E:OUT THE SYSTEM" << endl;
        cout << "«ÎŒ∞¥∂Ø“‘…œ∞¥º¸Õ‚µƒ∆‰À¸∞¥º¸" <<endl<< endl;
        char a;
        cin >>a;//menu
        
        switch (a)
        {
        case 'A':
            {
                cout << "«Î ‰»Î≥µ≈∆∫≈£∫" << endl<<endl;
                string s;
                cin >> s;
                Car* o2 = new Car(s);
                //ParkingNode r(o2,p_ParkingNode);
                //p_ParkingNode = & r;
                m_time = time(NULL);
                if (p->PL_isfull())
                {
                    q->EnQueue(o2, m_time);
                    //i++;
                }//go to path
                else
                {
                    p->add(o2, m_time);
                    //i++;
                }//come in park
             }
                break;

        case 'B':
        {
            
            cout << "«Î ‰»Î“™ÕÀ≥ˆµƒ≥µŒª∫≈£∫" << endl<<endl;
            cin >>j;
            Car *d=NULL;
            p->out(j, time(NULL),d);
            cout<<"Fee:"<<p->fee(d)<<"‘™"<<endl<<endl;
            w->EnQueue(d, 0);
            if (!q->Q_isempty())
            {
                q->DeQueue(d);
                p->Q_add(d, time(NULL));
            }
        /*if (!q->Q_isempty())
        {   p->out(j,clock());
            Car* d = NULL;
            q->DeQueue(d);
            p->add(d,clock());
        }
        else
            p->out(j, clock());*/
             
        }//one out one in
        break;

        case'C':
            p->show();
            if(!q->Q_isempty())
            q->show();
            //excel
            break;

        case'D':
            cout << "«Îº¸»Î" << endl<<endl;
            
            cin >> s;
                m_time=time(NULL);
                if(p->P_search(s,m_time))
                    ;
                else if(!q->Q_isempty()&& q->Q_search(s, m_time))
                    ;
                else if(!w->Q_isempty()&& w->Q_search(s, -1))
                    ;
                else
                    cout<<"Sorry, we have never received the car."<<endl;
            //as the mane tells,car
            break;

        case 'E':

        {  cout << "ª∂”≠œ¬¥Œπ‚¡Ÿ£°" << endl;
          exit(0);
        }

        break;

        default:
        {cout << "«Î÷ÿ–¬ ‰»Î" << endl<<endl;
        continue;
        }
        break;
        }
    }
return 0;
}
