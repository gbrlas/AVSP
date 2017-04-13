#include <iostream>
using namespace std;

int Testnum,flag,Pg,Pd,cur;
long long N;

int main()
{
	freopen("a_large.in","r",stdin);
	freopen("a_large.out","w",stdout);
	cin>>Testnum;
	for (int Test=1; Test<=Testnum; ++Test)
	{
		printf("Case #%d: ",Test);
		cin>>N>>Pd>>Pg;
		flag=0;
		if ((Pg==100)&&(Pd<100)) flag=0;
		else if ((Pg==0)&&(Pd>0)) flag=0;
			 else 
			{
				cur=100;
				if (Pd%2==0) cur/=2;
				if (Pd%4==0) cur/=2;
				if (Pd%5==0) cur/=5;
				if (Pd%25==0) cur/=5;
				if (cur<=N) flag=1; 
			}
		if (flag) printf("Possible\n");
		else printf("Broken\n");
	}
	return 0;
}

/*
3
1 100 50
10 10 100
9 80 56
*/