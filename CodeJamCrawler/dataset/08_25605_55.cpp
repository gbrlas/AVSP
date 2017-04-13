#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Time
{
	int hour;
	int minute;
	
	Time(){hour =0; minute=0;}
	
	Time(string & s)
	{
		char buf[3];
		buf[2] = '\0';
		
		buf[0]=s[0];buf[1]=s[1];
		hour = atoi(buf);
		buf[0]=s[3];buf[1]=s[4];
		minute = atoi(buf);
	}
	
	void add(int m, Time & t)
	{
		int ms = t.minute + m;
		
		minute = ms % 60;
		hour = t.hour + ms/60;
	}
	
};

bool compare_time (const Time & t1, const Time & t2)
{
    if(t1.hour < t2.hour || (t1.hour == t2.hour) && t1.minute < t2.minute)
		return true;
	else
		return false;
}


typedef vector<Time> TimeTable;

//return needed train
int schedule(TimeTable & train, TimeTable & tm, int turn)
{
	int count = 0;
	bool * usable = new bool[train.size()];
	for(int i=0; i<train.size(); i++)
		usable[i] = true;
	
	for(int ti=0; ti<tm.size(); ti++)
	{
		for(int tr = train.size()-1; tr>=0; tr--)
		{
			if(!usable[tr]) continue;
			//search first usable train
			Time tmp; tmp.add(turn, train[tr]);
			if( ! compare_time(tm[ti], tmp))
				break;	//found
		}
		
		if(tr>=0)
			usable[tr] = false;
		else
			count++;
	}
	
	return count;
}

int main(int argc, char * argv[])
{
	int testN, testi;
	ifstream input(argv[1]);
	input >> testN;
	
	for(testi=0; testi<testN; testi++)
	{
		//for each case
		int turn;
		input >> turn;
		
		TimeTable trainA, trainB;
		TimeTable tmA, tmB;
		
		int nA, nB;
		input	>> nA >> nB;
		
		int i;
		for(i=0; i<nA; i++)
		{
			string leave, arrive;
			input >> leave >> arrive;
			
			Time tl(leave); tmA.push_back(tl);
			Time ta(arrive); trainB.push_back(ta);
		}
		for(i=0; i<nB; i++)
		{
			string leave, arrive;
			input >> leave >> arrive;
			
			Time tl(leave);tmB.push_back(tl);
			Time ta(arrive);trainA.push_back(ta);
		}
		
		//sort them
		sort(trainA.begin(), trainA.end(), compare_time);
		sort(trainB.begin(), trainB.end(), compare_time);
		
		sort(tmA.begin(), tmA.end(), compare_time);
		sort(tmB.begin(), tmB.end(), compare_time);
		
		int CountA = schedule(trainA, tmA, turn);
		int CountB = schedule(trainB, tmB, turn);
		
		cout << "Case #" << testi+1 <<": " << CountA << " " << CountB <<endl;
	
	}/*test N*/
}
