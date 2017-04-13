#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;
#define SMALL

char islinewin(string str)
{
	for(int i=0;i<4;i++)
	{
		if(str[i]=='.')
			return 0;
	}

	if((str[0]==str[1] && str[1]==str[2] && str[2]==str[3]))
		return str[3];

	if((str[0]==str[1] && str[1]==str[2] && str[3]=='T')
		|| (str[0]==str[1] && str[1]==str[3] && str[2]=='T')
		|| (str[0]==str[3] && str[3]==str[2] && str[1]=='T')
		|| (str[3]==str[1] && str[1]==str[2] && str[0]=='T'))
	{
		if(str[3]!='T')
			return str[3];
		else
			return str[0];
	}

	return 0;
}

void A()
{
#ifdef SMALL
	freopen("A-small-practice.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int nc;
	cin >> nc;
	cin.ignore();

	for(int inc=0;inc<nc;inc++)
	{
		string str[4];
		getline(cin,str[0]);
		getline(cin,str[1]);
		getline(cin,str[2]);
		getline(cin,str[3]);

		//getline(cin,str[3]);
		//continue;
		cout<<"Case #"<<inc+1<<": ";
		char winner=0;

		for(int i=0;i<4;i++)
		{
			if(char w=islinewin(str[i]))
			{
				winner=w;
				cout<<winner<<" won\n";
				goto AEND;
			}

			char temp[5];
			for(int kk=0;kk<4;kk++)
				temp[kk]=str[kk][i];
			temp[4]='\0';

			if(char w=islinewin(temp))
			{
				winner=w;
				cout<<winner<<" won\n";
				goto AEND;
			}
		}
			char temp[5];
			for(int kk=0;kk<4;kk++)
				temp[kk]=str[kk][kk];
			temp[4]='\0';

			if(char w=islinewin(temp))
			{
				winner=w;
				cout<<winner<<" won\n";
				goto AEND;
			}
			for(int kk=0;kk<4;kk++)
				temp[kk]=str[3-kk][kk];
			if(char w=islinewin(temp))
			{
				winner=w;
				cout<<winner<<" won\n";
				goto AEND;
			}

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(str[i][j]=='.')
				{
					goto INCOM;
				}
			}
		}
		if(winner==0)
		goto END;
INCOM:
		cout<<"Game has not completed"<<"\n";
		goto AEND;
END:
			cout<<"Draw\n";
AEND:
		string t;
		getline(cin,t);

	}
}

int main()
{
	A();
	return 0;
}