#include <iostream>
#include <set>

using namespace std;

struct ScheduleTime{
	unsigned hour;
	unsigned minute;
	unsigned timeinminutes;
};

unsigned GetTrainsNeeded(multiset<unsigned> departures, multiset<unsigned> arrivals)
{
	unsigned result = 0;
	if(departures.size()!=0)
	{
		unsigned lastDep = *(--departures.end());
		arrivals.erase(arrivals.upper_bound(lastDep),arrivals.end());
		for(multiset<unsigned>::iterator it_a = arrivals.begin(); it_a != arrivals.end(); it_a++)
		{
			if(departures.lower_bound(*it_a)!=departures.end())
				departures.erase(departures.lower_bound(*it_a));
		}
		result = departures.size();
	}
	return result;
}

int main()
{
	unsigned N;
	cin >> N;
	for(unsigned cases = 0; cases < N; cases++)
	{
		unsigned T;
		unsigned NA;
		unsigned NB;
		char separator;
		multiset<unsigned> aDepartures;
		multiset<unsigned> aArrivals;
		multiset<unsigned> bDepartures;
		multiset<unsigned> bArrivals;
		
		cin >> T;
		cin >> NA >> NB;

		for(unsigned aTrips = 0; aTrips < NA; aTrips++)
		{
			ScheduleTime departure;
			ScheduleTime arrival;			
			cin >> departure.hour >> separator >> departure.minute >> arrival.hour >> separator >> arrival.minute;
			departure.timeinminutes = departure.hour*60 + departure.minute;
			arrival.timeinminutes = arrival.hour*60 + arrival.minute + T;
			aDepartures.insert(departure.timeinminutes);
			bArrivals.insert(arrival.timeinminutes);
		}
		for(unsigned bTrips = 0; bTrips < NB; bTrips++)
		{
			ScheduleTime departure;
			ScheduleTime arrival;
			cin >> departure.hour >> separator >> departure.minute >> arrival.hour >> separator >> arrival.minute;
			departure.timeinminutes = departure.hour*60 + departure.minute;
			arrival.timeinminutes = arrival.hour*60 + arrival.minute + T;
			bDepartures.insert(departure.timeinminutes);
			aArrivals.insert(arrival.timeinminutes);
		}

		cout << "Case #" << cases+1 << ": " << GetTrainsNeeded(aDepartures,aArrivals) << " " << GetTrainsNeeded(bDepartures,bArrivals) << endl;
	}
	return 0;
}
