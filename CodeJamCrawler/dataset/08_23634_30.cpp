#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct
{
	int ah,am;
	int dh,dm;
} triptime;

bool timeLessThanEqual(int ah,int am, int bh, int bm)
{
	if(ah < bh) return true;
	else if(ah == bh && am <= bm) return true;
	else return false;
}
bool timeLessThan(int ah,int am, int bh, int bm)
{
	if(ah < bh) return true;
	else if(ah == bh && am < bm) return true;
	else return false;
}
void sortDepartures(vector<triptime> &trips)
{
	triptime temp;
	for(int i = 0; i < trips.size(); i++)
	{
		for(int j = 0; j < trips.size() - 1; j++)
		{
			if(timeLessThan(trips[j+1].dh,trips[j+1].dm,trips[j].dh,trips[j].dm))
			{
				temp = trips[j];
				trips[j] = trips[j+1];
				trips[j+1] = temp;
			}
		}
	}

}
void sortArrivals(vector<triptime> &trips)
{
	triptime temp;
	for(int i = 0; i < trips.size(); i++)
	{
		for(int j = 0; j < trips.size() - 1; j++)
		{
			if(timeLessThan(trips[j+1].ah,trips[j+1].am,trips[j].ah,trips[j].am))
			{
				temp = trips[j];
				trips[j] = trips[j+1];
				trips[j+1] = temp;
			}
		}
	}
	
}
int checkTime(int dh,int dm,int turnaround,vector<triptime> &arrivals)
{
	for(int i = 0; i < arrivals.size(); i++)
	{
		if(timeLessThanEqual((arrivals[i].ah + (turnaround/60)),(arrivals[i].am + (turnaround%60)),dh,dm))
		{
			return i;
		}
	}
	return -1;
}
void solve(vector<triptime> &tripsA, vector<triptime> &tripsB, int turnaround, int *solA, int *solB)
{
	vector<triptime> tripsAtemp = tripsA;
	vector<triptime> tripsBtemp = tripsB;
	sortArrivals(tripsAtemp);
	sortArrivals(tripsBtemp);
	sortDepartures(tripsA);
	sortDepartures(tripsB);
	for(int i = 0; i < tripsA.size(); i++)
	{
		int ret;
		if((ret = checkTime(tripsA[i].dh,tripsA[i].dm,turnaround,tripsBtemp)) == -1)
		{
			(*solA)++;
		}
		else
		{
			tripsBtemp.erase(tripsBtemp.begin() + ret);
		}
	}
	for(int i = 0; i < tripsB.size(); i++)
	{
		int ret;
		if((ret = checkTime(tripsB[i].dh,tripsB[i].dm,turnaround,tripsAtemp)) == -1)
		{
			(*solB)++;
		}
		else
		{
			tripsAtemp.erase(tripsAtemp.begin() + ret);
		}

	}

	
}
int main()
{
	int numCases = 0, turnaround = 0, na = 0, nb = 0;
	vector<triptime> tripsA, tripsB;
	cin>>numCases;
	string s;
	for(int i = 1; i <= numCases; i++)
	{
		cin>>turnaround;
		cin>>na>>nb;
		for(int j = 0; j < na; j++)
		{
			triptime trip;
			char temp[10];
			char *tok;
			cin>>s;
			strcpy(temp,s.c_str());
			tok = strtok(temp,":");
			trip.dh = atoi(tok);
			tok = strtok(NULL,":");
			trip.dm = atoi(tok);
			cin>>s;
			strcpy(temp,s.c_str());
			tok = strtok(temp,":");
			trip.ah = atoi(tok);
			tok = strtok(NULL,":");
			trip.am = atoi(tok);

			tripsA.push_back(trip);
		}
		for(int j = 0; j < nb; j++)
		{
			triptime trip;
			char temp[10];
			char *tok;
			cin>>s;
			strcpy(temp,s.c_str());
			tok = strtok(temp,":");
			trip.dh = atoi(tok);
			tok = strtok(NULL,":");
			trip.dm = atoi(tok);
			cin>>s;
			strcpy(temp,s.c_str());
			tok = strtok(temp,":");
			trip.ah = atoi(tok);
			tok = strtok(NULL,":");
			trip.am = atoi(tok);

			tripsB.push_back(trip);
		}

		int solA = 0, solB = 0;

		solve(tripsA,tripsB,turnaround,&solA,&solB);
		cout<<"Case #"<<i<<": "<<solA<<" "<<solB<<endl;
		tripsA.clear();
		tripsB.clear();

	}
	return 0;
}