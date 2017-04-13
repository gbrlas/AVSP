#include <iostream>

#include <boost/functional/hash.hpp>
#include <algorithm>

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef char s8;
typedef unsigned char u8;

using namespace std;

class Trip
{
public:
    u32 time;
    bool arrival;
    bool operator< (const Trip& rhs)const
    {
        if (time < rhs.time) 
            return true;
        else 
            return (time == rhs.time) && arrival; // Arrivals always come first 
    }
};

Trip stationA[150];
Trip stationB[150];
u32 numTrips;

int main()
{
    u32 numProblems = 0;
    cin >> numProblems;

    for (u32 probNum = 0; probNum < numProblems; ++ probNum)
    {
        cout << "Case #" << probNum + 1<<": ";

        u32 turnaround = 0;
        u32 numA = 0, numB = 0;
        numTrips = 0;
        cin >> turnaround;
        cin >> numA >> numB;
        
        for (int a = 0; a < numA; a++)
        {
            u32 hour, minute;
            u32 hourA, minuteA;
            char junk;
            cin >> hour >> junk >> minute >> hourA >> junk >> minuteA;
//            cout << hour<<"," << minute << "->"<< hourA<<"," << minuteA << endl;
            stationA[numTrips].time = hour*60 + minute;
            stationA[numTrips].arrival = false;

            stationB[numTrips].time = hourA*60 + minuteA + turnaround;
            stationB[numTrips].arrival = true;
            numTrips ++;
        }

        for (int b = 0; b < numB; b++)
        {
            u32 hour, minute;
            u32 hourA, minuteA;
            char junk;
            cin >> hour >> junk >> minute >> hourA >> junk>> minuteA;
//            cout <<"B:" << hour<<"," << minute << "->"<< hourA<<"," << minuteA << endl;

            stationB[numTrips].time = hour*60 + minute;
            stationB[numTrips].arrival = false;

            stationA[numTrips].time = hourA*60 + minuteA + turnaround;
            stationA[numTrips].arrival = true;
            numTrips ++;
        }

        sort(stationA, &stationA[numTrips]);
        sort(stationB, &stationB[numTrips]);

        s32 currRequirementA = 0;
        s32 peakRequirementA = 0;
        
//cout << " === stationA  === " << endl;
        for (int ansA = 0; ansA < numTrips; ansA++)
        {
            if (stationA[ansA].arrival)
            {
                currRequirementA --; //One train arrives, so we have an extra for later
//cout << "A: " << stationA[ansA].time / 60 << ":" << stationA[ansA].time % 60 << " " << currRequirementA << endl;
            }
            else
            {
                currRequirementA ++; //If now +ve, we had more departures than arrivals!
//cout << "A: " << stationA[ansA].time / 60 << ":" << stationA[ansA].time % 60 << " " << currRequirementA;
                if (peakRequirementA < currRequirementA)
                {
                    peakRequirementA = currRequirementA;
//cout << "!";
                }
//                cout << endl;
            }
        }

        s32 currRequirementB = 0;
        s32 peakRequirementB = 0;

//cout << " === stationB  === " << endl;
        for (int ansB = 0; ansB < numTrips; ansB++)
        {
            if (stationB[ansB].arrival)
            {
                currRequirementB --; //One train arrives, so we have an extra for later
//cout << "A: " << stationB[ansB].time / 60 << ":" << stationB[ansB].time % 60 << " " << currRequirementB << endl;
            }
            else
            {
                currRequirementB ++; //If now +ve, we had more departures than arrivals!
//cout << "A: " << stationB[ansB].time / 60 << ":" << stationB[ansB].time % 60 << " " << currRequirementB;
                if (peakRequirementB < currRequirementB)
                {
                    peakRequirementB = currRequirementB;
//cout << "!";
                }
//                cout << endl;
            }
        }

        cout << peakRequirementA << " " << peakRequirementB << endl;
    }
}
