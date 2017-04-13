#include <iostream>
using namespace std;

int Testnum,flag,N,Pg,Pd;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&Testnum);
	for (int Test=1; Test<=Testnum; ++Test)
	{
		printf("Case #%d: ",Test);
		scanf("%d %d %d",&N,&Pd,&Pg);
		flag=0;
		for (int D=1; D<=N; ++D)
		{
			if (D*Pd%100==0)
			{
				flag=1;
				break;
			}
		}
		if ((Pg==100)&&(Pd<100)) flag=0;
		if ((Pg==0)&&(Pd>0)) flag=0;
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