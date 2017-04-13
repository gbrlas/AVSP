#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int Max = 60;

struct LongNum
{
	int A[Max];
	int S;
};

LongNum Init()
{
	LongNum N;
	for(int i=0;i<Max;i++)
		N.A[i] = 0;
	N.S = 1;
	return N;
}

int Compare(LongNum N1, LongNum N2)
{
	for(int i=Max-1;i>=0;i--)
		if(N1.A[i]>N2.A[i])
			return 1;
		else
			if(N1.A[i]<N2.A[i])
				return 2;
	return 0;
}

LongNum Dif(LongNum N1, LongNum N2)
{
	LongNum N = Init();
	N.S = max(N1.S, N2.S);
	for(int i=0;i<N.S;i++)
		N.A[i] = N1.A[i] - N2.A[i];
	
	for(int i=0;i<N.S;i++)
		if(N.A[i]<0)
		{
			N.A[i] +=10;
			N.A[i+1]--;
		}
	N.S = 1;
	for(int i = Max-1;i>0;i--)
		if(N.A[i]!=0)
		{
			N.S = i+1;
			break;
		}
	return N;
}

LongNum Div(LongNum N1, LongNum N2, LongNum &ost)
{
	LongNum temp = Init(), N = Init(), zero = Init();
	bool flag = false;
	N.S = 0;
	temp.A[0] = N1.A[N1.S - 1];
	for(int i = N1.S - 2;i>=-1;i--)
	{
		int k=0;
		if(Compare(temp,N2)!=2)
		{
			flag = true;
			while(Compare(temp,N2)!=2)
			{
				temp = Dif(temp,N2);
				k++;
			}
		}
		if(flag)
		{
			for(int j=N.S;j>0;j--)
				N.A[j] = N.A[j-1];
			N.A[0] = k;
			N.S++;
		}
		if(i!=-1)
		{
			for(int j=temp.S;j>0;j--)
				temp.A[j] = temp.A[j-1];
			temp.A[0] = N1.A[i];
			temp.S = 1;
			for(int j=Max-1;j>0;j--)
				if(temp.A[j]!=0)
				{
					temp.S = j+1;
					break;
				}
		}
	}
	if(N.S==0)
		N.S = 1;
	ost = temp;
	return N;
}

LongNum ZERO;

LongNum GCD(LongNum N1, LongNum N2)
{
	if(Compare(N2,ZERO)==0)
		return N1;
	else
	{
		LongNum ost;
		Div(N1,N2,ost);
		return GCD(N2,ost);
	}
}

char s[60];
LongNum Ar[1500];
vector<int> dif;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	ZERO = Init();
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;z++)
	{
		//int bestYear = 0;
		//int BestDiv = 1;
		//int N;
		//scanf("%d",&N);
		//for(int i=0;i<N;i++)
		//	scanf("%d",&Ar[i]);
		//sort(Ar,Ar+N);
		//int Max = Ar[1]+2;
		//for(int i=0;i<Max;i++)
		//{
		//	int Div = Ar[0];
		//	for(int j=1;j<N;j++)
		//		Div = GCD(Ar[j],Div);
		//	if(Div>BestDiv)
		//	{
		//		BestDiv = Div;
		//		bestYear = i;
		//	}
		//	for(int j=0;j<N;j++)
		//		Ar[j]++;
		//}
		//printf("Case #%d: %d\n",z,bestYear);
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%s",s);
			LongNum temp = Init();
			for(int j = strlen(s)-1,p=0;j>=0;j--,p++)
				temp.A[p] = s[j]-'0';
			temp.S = strlen(s);
			Ar[i] = temp;
		}

		for(int i=0;i<N-1;i++)
			for(int j=0;j<N-1-i;j++)
				if(Compare(Ar[j],Ar[j+1])==1)
					swap(Ar[j],Ar[j+1]);
		for(int i=1;i<N;i++)
			Ar[i-1] = Dif(Ar[i],Ar[i-1]);
		LongNum temp = Ar[0];
		for(int i=1;i<N-1;i++)
			temp = GCD(temp,Ar[i]);
		if(!((temp.A[0]==1)&&(temp.S==1)))
		{
			LongNum ost;
			Div(Ar[N-1],temp,ost);
			LongNum temp1 = Dif(temp,ost);
			Div(temp1,temp,temp);			
		}
		else
			temp.A[0] = 0;
		printf("Case #%d: ",z);
		for(int i=temp.S-1;i>=0;i--)
			printf("%d",temp.A[i]);
		printf("\n");
	}
	return 0;
}