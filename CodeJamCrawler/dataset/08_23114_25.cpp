// Train Timetable
// Coded by Papp Tibor [papptibi@gmail.com]

#include <fstream>
#include <list>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

//const unsigned int MAX 100;

struct Trip {
    int departure;
    int arrival;
    int ready;
    int returned;
};

//Trip NA[MAX];
//Trip NB[MAX];

/**********************************************************************/

void insertTrip(list<Trip>& trip, int dep, int arr, int turnaround) {

    Trip t;
    t.departure = dep;
    t.arrival = arr;
    t.ready = arr + turnaround;
    t.returned = 0;

    list<Trip>::iterator it;
    it = trip.begin();
    while ( (it != trip.end()) && (it->departure < dep) ) {
        ++it;
    }
    trip.insert(it, t);

} // insertTrip()

bool findReady(list<Trip>& trip, int dep) {

    int first = 24*60;
    
    list<Trip>::iterator it, ret;
    for (it=trip.begin(); it!=trip.end(); it++) {
        if ( !(it->returned) && (it->ready < first) ) {
            ret = it;
            first = it->ready;
        }
    }
    if ( first == 24*60 )
        return false;

    if ( ret->ready <= dep ) {
        ret->returned = 1;
        return true;
    }
    return false;
    
} // findReady()


int main() {

    ifstream IN("data.in");
    ofstream OUT("data.out");

    int N;

    IN >> N;
    for (int i = 1; i <= N; i++) {

        list<Trip> tripA;
        list<Trip> tripB;

        int T;
        IN >> T;
        
        int NA, NB;
        IN >> NA >> NB;

        for (int j = 1; j <= NA; j++) {

            string dep, arr;
            IN >> dep >> arr;

            int depHour, depMin, arrHour, arrMin;
            sscanf(dep.c_str(), "%2d:%2d", &depHour, &depMin);
            sscanf(arr.c_str(), "%2d:%2d", &arrHour, &arrMin);

            insertTrip(tripA, depHour*60+depMin, arrHour*60+arrMin, T);

        }

        for (int j = 1; j <= NB; j++) {

            string dep, arr;
            IN >> dep >> arr;

            int depHour, depMin, arrHour, arrMin;
            sscanf(dep.c_str(), "%2d:%2d", &depHour, &depMin);
            sscanf(arr.c_str(), "%2d:%2d", &arrHour, &arrMin);

            insertTrip(tripB, depHour*60+depMin, arrHour*60+arrMin, T);

        }
        
        int numTrainA=0, numTrainB=0;
        
        list<Trip>::iterator it;
        for (it=tripA.begin(); it!=tripA.end(); it++) {
            if ( !findReady(tripB, it->departure) )
                numTrainA++;
        }

        for (it=tripB.begin(); it!=tripB.end(); it++) {
            if ( !findReady(tripA, it->departure) )
                numTrainB++;
        }

        OUT << "Case #" << i << ": " << numTrainA << " " << numTrainB << endl;
        
        tripA.clear();
        tripB.clear();

    } // for all cases
    
    return 0;

} // main()
