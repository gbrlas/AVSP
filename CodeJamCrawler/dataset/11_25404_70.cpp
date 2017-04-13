#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
char C[10],D[10],N[110];
char Change[10][10];
bool Diff[10][10];
int getNum(char c)
{
	switch(c)
	{
	case 'Q':return 1;
	case 'W':return 2;
	case 'E':return 3;
	case 'R':return 4;
	case 'A':return 5;
	case 'S':return 6;
	case 'D':return 7;
	case 'F':return 8;
	default:return 0;
	}
}
char stack[110],top=0;
int main()
{
	
	int t,c,d,n;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		CLR(Diff,0);
		CLR(Change,0);
		top=0;
		scanf("%d",&c);
		for(int i=0;i!=c;i++)
		{
			scanf("%s",C);
			Change[getNum(C[0])][getNum(C[1])]=C[2];
			Change[getNum(C[1])][getNum(C[0])]=C[2];
		}
		scanf("%d",&d);
		for(int i=0;i!=d;i++)
		{
			scanf("%s",D);
			Diff[getNum(D[0])][getNum(D[1])]=true;
			Diff[getNum(D[1])][getNum(D[0])]=true;
		}
		scanf("%d",&n);
		scanf("%s",N);
		for(int i=0;i!=n;i++)
		{
			int num=getNum(N[i]);
			if(top != 0 && Change[num][getNum(stack[top-1])])
			{
				stack[top-1]=Change[num][getNum(stack[top-1])];
			}
			else 
			{
				bool flag = false;
				for(int j=0;j!=top;j++)
					if(Diff[getNum(stack[j])][num])
					{
						top=0;
						flag=true;
						break;
					}
				if(!flag) stack[top++]=N[i];
			}
		}
		bool first=true;
		printf("Case #%d: [",test);
		for(int i=0;i!=top;i++)
		{
			if(!first) printf(", ");
			first=false;
			printf("%c",stack[i]);
		}
		puts("]");
	}
}