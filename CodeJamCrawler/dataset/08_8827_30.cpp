#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

enum TravelTypes
{
  ArrivalA,
  ArrivalB,
  DepartureA,
  DepartureB
};

struct Time
{
  int hour;
  int minute;
  int whole;

  TravelTypes travelType;

  bool operator<(const Time& date)
  {
    if (this->whole != date.whole)
    {
      return this->whole < date.whole;
    }
    else
    {
      return this->travelType < date.travelType;
    }
  }
};

void GetTimeInFile(std::ifstream& file, Time& time, int turnAroundTime, TravelTypes type)
{
  file >> time.hour;
  file.ignore();
  file >> time.minute;
  file.ignore();

  if (type == ArrivalA || type == ArrivalB) time.minute += turnAroundTime;

  time.travelType = type;
  time.whole      = (time.hour * 100) + time.minute;
}

typedef std::vector<Time> TimeVector;

void main()
{
  std::ifstream file("codejam.in",    std::ios_base::in);
  std::ofstream result("codejam.out", std::ios_base::out);

  int casesCount;
  file >> casesCount;
  file.ignore();

  for (int caseIndex = 0; caseIndex < casesCount; caseIndex++)
  {
    int turnAroundTime;
    file >> turnAroundTime;
    file.ignore();

    int na, nb = 0;

    file >> na;
    file.ignore();
    file >> nb;
    file.ignore();

    TimeVector times;
    int currentTrainsInA = 0;
    int currentTrainsInB = 0;
    int trainsNeededInB  = 0;
    int trainsNeededInA  = 0;

    for (int i = 0; i < na; i++)
    {
      Time currentTime;

      GetTimeInFile(file, currentTime, turnAroundTime, DepartureA);
      times.push_back(currentTime);

      GetTimeInFile(file, currentTime, turnAroundTime, ArrivalB);
      times.push_back(currentTime);
    }

    for (int i = 0; i < nb; i++)
    {
      Time currentTime;

      GetTimeInFile(file, currentTime, turnAroundTime, DepartureB);
      times.push_back(currentTime);

      GetTimeInFile(file, currentTime, turnAroundTime, ArrivalA);
      times.push_back(currentTime);
    }
    std::sort(times.begin(), times.end());

    for (unsigned int i = 0; i < times.size(); i++)
    {
      TravelTypes& travelType = times[i].travelType;

      if (travelType == ArrivalA)   currentTrainsInA++;
      if (travelType == ArrivalB)   currentTrainsInB++;
      if (travelType == DepartureA) currentTrainsInA--;
      if (travelType == DepartureB) currentTrainsInB--;

      if (currentTrainsInB < trainsNeededInB) trainsNeededInB = currentTrainsInB;
      if (currentTrainsInA < trainsNeededInA) trainsNeededInA = currentTrainsInA;
    }

    result << "Case #" << caseIndex + 1 << ": " << abs(trainsNeededInA) << ' ' << abs(trainsNeededInB) << '\n';
  }
}