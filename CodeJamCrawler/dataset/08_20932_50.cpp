#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct M{
public:
	M(int t,bool s,int tim)
	{
		train=t;start=s;time=tim;
	}
	int train;
	bool start;
	int time;
	bool operator<(const M w) const
	{
		return (time<w.time) || (time==w.time && !start);
	}
};


int t,T;
char str[100];
vector <M> mas;

int main()
{
	freopen("b-large.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	int i,j;
	for (t=1;t<=T;t++)
	{
		mas.clear();
		int tt,a,b;
		int h1,m1,h2,m2; char c;
		scanf("%d%d%d",&tt,&a,&b);gets(str);
		for (i=1;i<=a;i++)
		{
			gets(str);
			istringstream io(str);
			io>>h1>>c>>m1>>h2>>c>>m2;
			mas.push_back(M(1,true,h1*60+m1));
			mas.push_back(M(1,false,h2*60+m2+tt));
		}
		for (i=1;i<=b;i++)
		{
			gets(str);
			istringstream io(str);
			io>>h1>>c>>m1>>h2>>c>>m2;
			mas.push_back(M(2,true,h1*60+m1));
			mas.push_back(M(2,false,h2*60+m2+tt));
		}
		sort(mas.begin(),mas.end());
		int fa=0,fb=0,ma=0,mb=0;
		for (i=0;i<mas.size();i++)
		{
			if (mas[i].start)
			{
				if (mas[i].train==1)
				{
					if (fb>0) fb--;
					else ma++;
				}
				else
				{
					if (fa>0) fa--;
					else mb++;
				}
			}
			else
			{
				if (mas[i].train==1)
					fa++;
				else
					fb++;				
			}
		}
		printf("Case #%d: %d %d\n",t,ma,mb);
	}
	
	return 0;
}