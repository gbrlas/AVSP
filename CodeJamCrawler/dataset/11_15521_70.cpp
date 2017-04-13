#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> O,B;
vector< pair<char,int> > S;

int prevo,prevb,prevotime,prevbtime,t,NT,i,p,num,dist,p1;
char c;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		prevo = 1; prevb = 1; prevotime = 0; prevbtime = 0;

		cin>>p;
		for(i=1;i<=p;i++)
		{
			cin>>c>>num;
//			if(c=='O') O.push_back(num);
//			else B.push_bakc(num);
//			S.push_back( make_pair<c,num> );
			if(c=='O')
			{
				dist = abs(num - prevo);
				p1 = prevotime + dist + 1;
				if(p1<=prevbtime)
				{
					p1 = prevbtime+1;
				}
				prevotime = p1;
				prevo = num;
			}
			else
			{
				dist = abs(num - prevb);
				p1 = prevbtime + dist + 1;
				if(p1<=prevotime)
				{
					p1 = prevotime+1;
				}
				prevbtime = p1;
				prevb = num;
			}
		}
		cout<<"Case #"<<t<<": ";
		if(prevotime>prevbtime) cout<<prevotime; else cout<<prevbtime;
		cout<<endl;

//		cout<<prevotime<<' '<<prevbtime<<endl;
	}
	return 0;
}
