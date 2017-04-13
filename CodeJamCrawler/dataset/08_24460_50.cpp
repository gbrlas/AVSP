#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<sstream>
#include<set>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define all(a) (a).begin(),(a).end()


int main()
{
	ifstream fin("C:\\B-large.in");//B-small-attempt2.in
	ofstream fout("C:\\output11.txt");
	int t;
	fin>>t;
	int total=t;
	while(t--)
	{
		int a=0;
		int b=0;
		vector<int> starttimea;
		vector<int> starttimeb;
		vector<int> endtimea;
		vector<int> endtimeb;
		set<int> events;
		int turnover;
		int noa,nob;
		fin>>turnover;
		fin>>noa;
		fin>>nob;
		stringstream s;
		FOR(i,0,noa)
		{
			string start;
			string end;
			int mins,hrs;
			fin>>start;
			string hours;
			string minutes;
			hours=start.substr(0,2);
			minutes=start.substr(3,2);
			s.clear();
			s<<hours;
			s>>hrs;
			s.clear();
			s<<minutes;
			s>>mins;
			starttimea.push_back(hrs*60+mins);
			events.insert((hrs*60+mins));
			start="";
			fin>>end;
			hours=end.substr(0,2);
			minutes=end.substr(3,2);
			s.clear();
			s<<hours;
			s>>hrs;
			s.clear();
			s<<minutes;
			s>>mins;
			endtimea.push_back(hrs*60+mins+turnover);
			events.insert((hrs*60+mins+turnover));
		}
		FOR(i,0,nob)
		{
			string start;
			string end;
			int mins,hrs;
			string hours,minutes;
			fin>>start;
			hours=start.substr(0,2);
			minutes=start.substr(3,2);
			s.clear();
			s<<hours;
			s>>hrs;
			s.clear();
			s<<minutes;
			s>>mins;
			starttimeb.push_back(hrs*60+mins);
			events.insert(hrs*60+mins);
			start="";
			fin>>end;
			hours=end.substr(0,2);
			minutes=end.substr(3,2);
			s.clear();
			s<<hours;
			s>>hrs;
			s.clear();
			s<<minutes;
			s>>mins;
			endtimeb.push_back(hrs*60+mins+turnover);
			events.insert(hrs*60+mins+turnover);
		}
		int reqa=0,reqb=0;
		//sort(all(events));
		int curr=0;
		for(set<int>:: iterator it=events.begin();it!=events.end();it++)
		{
			if(count(all(endtimeb),*it)>0)
			{
				a+=count(all(endtimeb),*it);
			}
			if(count(all(endtimea),*it)>0)
			{
				b+=count(all(endtimea),*it);
			}
			if(count(all(starttimea),*it)>0)
			{
			    curr=count(all(starttimea),*it);
				if(a<=curr)
				{
					reqa+=(curr-a);
					a=0;
				}
				else
					a-=curr;
			}
			if(count(all(starttimeb),*it)>0)
			{
				curr=count(all(starttimeb),*it);
				if(b<=curr)
				{
					reqb+=(curr-b);
					b=0;
				}
				else
					b-=curr;
			}
			
		}
		fout<<"Case #"<<total-t<<": "<<reqa<<" "<<reqb<<endl;
	}
}



