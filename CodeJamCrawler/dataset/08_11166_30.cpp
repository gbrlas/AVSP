// To run, please supply the input on stdin
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <cassert>
#include <limits>
#include <sstream>
#include <deque>

using namespace std;

#define DEBUG(x)  //x
#define DEBUG2(x) //x

struct Time {
  int hour, min;
  
  Time(int hour_, int min_) : hour(hour_), min(min_)  {}
  Time(int minutes) {
    hour = 0;
    min  = minutes;
    while (min > 59)  { min -= 60; hour++; }
    if (hour > 23)  hour -= 24;
  }
  Time(const string& rhs) {
    stringstream ss;
    ss << rhs;
    ss >> hour;
    char dummy;
    ss >> dummy;
    ss >> min;
  }
  Time(const Time& lhs) {
    hour = lhs.hour;
    min  = lhs.min;
  }
  
  bool operator< (const Time& rhs) const {
    return hour < rhs.hour || (hour == rhs.hour && min < rhs.min);
  }
  bool operator>= (const Time& rhs) const {
    return !operator< (rhs);
  }
};
ostream& operator << (ostream& o, const Time& time) {
  o << time.hour << ':' << time.min;
  return o;
}

Time operator+ (const Time& lhs, const Time& rhs) {
  Time tmp(lhs);
  tmp.min += rhs.min;
  if (tmp.min > 59)  { tmp.min -= 60; tmp.hour++; }
  tmp.hour += rhs.hour;
  if (tmp.hour > 23)  tmp.hour -= 24;
  return tmp;
}

struct Departure {
  Time time;     // departure time
  Time arrival;  // arrival time
  char station;  // 'A' or 'B'
  bool extra;    // is this the train that has some mileage already?
  
  Departure(Time time_, Time arrival_, char station_, bool extra_ = false) 
    : time(time_), arrival(arrival_), station(station_), extra(extra_)  {}
  
  // we want to sort it
  bool operator< (const Departure& rhs) const {
    return time < rhs.time;
  }
};

int main() {

  int N;
  if (!(cin >> N)) {
    DEBUG(cout << "N expected\n");
    return -1;
  }
  
  int caseN = 1;
  
  int T;
  while (cin >> T) {
    DEBUG(cout << "T: " << T << "\n");

    int trainsA = 0, trainsB = 0;

    int A, B;
    cin >> A;
    cin >> B;
    
    deque<Departure> table;
    
    DEBUG(cout << "A: " << A << "\n");
    for (int i = 0; i < A; i++) {
      string departure, arrival;
      cin >> departure >> arrival;
      DEBUG(cout << "departure: " << departure << ", arrival: " << arrival << "\n");
      table.push_back(Departure(departure, arrival, 'A', false));
    }

    DEBUG(cout << "B: " << B << "\n");
    for (int i = 0; i < B; i++) {
      string departure, arrival;
      cin >> departure >> arrival;
      DEBUG(cout << "departure: " << departure << ", arrival: " << arrival << "\n");
      table.push_back(Departure(departure, arrival, 'B', false));
    }
    

    // time to solve
    while (table.size() > 0) {
      sort(table.begin(), table.end());

      Departure to_go = table.front();
      table.pop_front();
      
      if (!to_go.extra) {
        if (to_go.station == 'A')  trainsA++; else trainsB++;
      }
      
      // find a departure spot for this train
      DEBUG2(cout << "Before adding " << T << ": " << to_go.arrival \
                  << ", after: " << to_go.arrival + T << "\n");
      Time target_time    = to_go.arrival + T;
      char target_station = to_go.station == 'A' ? 'B' : 'A';
      for (int i = 0; i < table.size(); i++) {
        if (table[i].time >= target_time && table[i].station == target_station && 
            table[i].extra == false) {
          DEBUG(cout << "Found spot\n");
          table[i].extra = true;
          break;
        }
      }
    }
    

    cout << "Case #" << caseN << ": " << trainsA << " " << trainsB << "\n";
    caseN++;
  }
  
}