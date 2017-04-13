/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)


int main(){

	int t;
	scanf("%d",&t);
	map<pair<char,char>,char> comb;
	map<char, char> rem;
	list<char> mylist;
	list<char>::iterator it;
	REP(test,t)
	{
		int c,n,d;
		comb.clear();
		rem.clear();
		mylist.clear();
		
		char u[10000],v[10000],w[10000];

		scanf("%d",&c);
		while(c--)
		{
			scanf("%s",u);
			char c1=u[0],c2=u[1],c3=u[2];
			pair<char,char> p1,p2;
			p1.first=p2.second=c1;
			p2.first=p1.second=c2;

			comb.insert(pair<pair<char,char>,char>(p1,c3));
			comb.insert(pair<pair<char,char>,char>(p2,c3));

		}
		scanf("%d",&d);
		while(d--)
		{
			scanf("%s",v);
			char c1=v[0],c2=v[1];
			rem.insert(pair<char,char>(c1,c2));
			rem.insert(pair<char,char>(c2,c1));

		}

		scanf("%d",&n);
		scanf("%s",w);

		REP(i,n)
		{
			if(mylist.size())
			{
				it=mylist.begin();
				pair<char,char> p1,p2;
				p1.first=p2.second=(*it);
				p2.first=p1.second=w[i];

				if(comb.find(p1)!=comb.end())
				{
					mylist.pop_front();
					mylist.push_front(comb[p1]);
				}
				else if(comb.find(p2)!=comb.end())
				{
					mylist.pop_front();
					mylist.push_front(comb[p2]);
				}

				else if(rem.find(w[i])!=rem.end())
				{
				mylist.push_front(w[i]);
					it=mylist.begin();
					while(it!=mylist.end())
					{
						if((*it)==rem[w[i]])
						{
							mylist.clear();
							break;
						}
						it++;
					}
				}
				else
				mylist.push_front(w[i]);

			}
			else
				mylist.push_front(w[i]);
		}
		it=mylist.end();
		it--;

		if(!(mylist.size()))
			printf("Case #%d: []\n",test+1);
		else
		{
			printf("Case #%d: [",test+1);
			while(it!=mylist.begin())
			{
				printf("%c, ",(*it));
				it--;
			}
			printf("%c]\n",(*it));
		}
	}

	return 0;
}
