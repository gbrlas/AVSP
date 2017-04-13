#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

//ifstream fin("B-small-attempt1.in");
//#define cin fin

class Event
{
public:
   unsigned int time;
   bool departure;
   bool atA;
   Event(unsigned int time, bool departure, bool atA)
   :
      time(time),
      departure(departure),
      atA(atA)
   {
   }

   void print()
   {
      cout << (atA ? "[A]" : "[B]")
         << (departure ? "[DEP] " : "[ARR] ")
         << time/60 << ":" << time % 60 << endl;
   }
};

struct test_compare
: binary_function<Event*, Event*, bool>
{
bool operator()(const Event* e1, const Event* e2) const
{
return (e1->time > e2->time ||
       (e1->time == e2->time && (e1->departure && !e2->departure)));
}
};


int turnaround;
int aToB;
int bToA;

priority_queue<Event*, vector<Event*>, test_compare> Events;

int num(char c)
{
   return (int)(c-'0');
}

void grabTimes(int* departure, int* arrival)
{
   string d,a;
   cin >> d >> a;
   *departure = 60*(num(d[0])*10+num(d[1])) +
                num(d[3])*10+num(d[4]);

   *arrival = turnaround + 60*(num(a[0])*10+num(a[1])) +
                num(a[3])*10+num(a[4]);
}

void rockNroll()
{
   cin >> turnaround >> aToB >> bToA;
   int aTime, bTime;
   for(int i=0;i<aToB;++i)
   {
      grabTimes(&aTime, &bTime);
      Events.push(new Event(aTime, true, true));
      Events.push(new Event(bTime, false, false));
   }
   for(int i=0;i<bToA;++i)
   {
      grabTimes(&bTime, &aTime);
      Events.push(new Event(bTime, true, false));
      Events.push(new Event(aTime, false, true));
   }

   int startAtA = 0;
   int startAtB = 0;

   int curAtA = 0;
   int curAtB = 0;
   while(!Events.empty())
   {
      Event* e = Events.top();
      //e->print();
      if(e->atA)
      {
         if(e->departure)
         {
            if(curAtA == 0)
            {
               ++startAtA;
               //cout << "startAtA: " << startAtA << endl;
            }
            else
            {
               --curAtA;
            }
         }
         else
         {
            ++curAtA;
         }
      }
      else
      {
         if(e->departure)
         {
            if(curAtB == 0)
            {
               ++startAtB;
               //cout << "startAtB: " << startAtB << endl;
            }
            else
            {
               --curAtB;
            }
         }
         else
         {
            ++curAtB;
         }
      }

      Events.pop();
   }
   cout << startAtA << " " << startAtB << endl;
}

int main()
{
   int cases;
   cin >> cases;
   for(int i=1;i<=cases;++i)
   {
      cout << "Case #" << i << ": ";
      rockNroll();
   }
}
