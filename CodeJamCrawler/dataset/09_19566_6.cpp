//A.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define MAXN 12
#define HASH_RANGE 10000000

typedef unsigned long long ull;

struct StateType
{
	bool Matrix[MAXN][MAXN];
	ull State;
	ull RowValue[MAXN];
	int Res;
};

int n;
vector<StateType> vs;
ull mark[HASH_RANGE];
void input();
void work();
bool Find(ull state);
void Insert(ull state);
void Swap(StateType &, int row1,int row2);
ull ReturnStateValue(bool [][MAXN]);

int main()
{
	int iCase,i;
	scanf("%d",&iCase);
	for(i=1;i<=iCase;++i)
	{
		vs.clear();	
		memset(mark,0,sizeof(mark));
		input();
		printf("Case #%d: ",i);
		work();
	}
	
}

void work()
{
	int head=0,i,j,k1,k2,k;
	StateType cur,tmp;
	bool flag=true;
	tmp=vs[0];
	for(i=1;i<=n;++i)
	{
		if(!flag) break;
		for(j=i+1;j<=n;++j)
		{
			if(tmp.Matrix[i][j])
			{
				flag=false;
				break;
			}
		}
	}
	if(flag)
	{
		printf("0\n");
		return;
	}
	while(true)
	{
		cur=vs[head];
		for(i=1;i<n;++i)
		{
			j=i+1;
			tmp=cur;
			Swap(tmp,i,j);
			tmp.Res=cur.Res+1;
			bool flag=true;
			for(k1=1;k1<=n;++k1)	//check tmp is ans
			{
				if(!flag) break;
				for(k2=k1+1;k2<=n;++k2)
				{
					if(tmp.Matrix[k1][k2])
					{
						flag=false;
						break;
					}
				}
			}
			if(!flag)
			{
				bool fflag=true;
				//change row i, row j
				/*
				tmp.State-=(tmp.RowValue[i])*(1<<(n*(i-1)));
				tmp.State-=(tmp.RowValue[j])*(1<<(n*(j-1)));
				tmp.State+=(tmp.RowValue[i])*(1<<(n*(j-1)));
				tmp.State+=(tmp.RowValue[j])*(1<<(n*(i-1)));
				ull t;
				t=tmp.RowValue[i];
				tmp.RowValue[i]=tmp.RowValue[j];
				tmp.RowValue[j]=t;
				*/
				tmp.State=ReturnStateValue(tmp.Matrix);
				
				if(!Find(tmp.State))
				{
					vs.push_back(tmp);
					Insert(tmp.State);
				}
			}
			else
			{
				printf("%d\n",tmp.Res);
				return;
			}		
		}
		++head;
	}
}

void input()
{
	int i,j;
	char ch;
	StateType tmp;
	scanf("%d",&n);

	for(i=1;i<=n;++i)
	{
		tmp.RowValue[i]=0;
		for(j=1;j<=n;++j)
		{
			tmp.RowValue[i]*=2;
			cin >> ch;
			tmp.Matrix[i][j]=ch-'0';
			if(tmp.Matrix[i][j])
				tmp.RowValue[i]+=1;
		}	
	}
	tmp.State = ReturnStateValue(tmp.Matrix);
	tmp.Res=0;
	vs.push_back(tmp);
	Insert(tmp.State);
}

ull ReturnStateValue(bool matrix[][MAXN])
{
	int i,j;
	ull ans=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
	{
		ans*=2;
		if(matrix[i][j]) ans+=1;
	}
	return ans;
}

void Swap(StateType &s, int row1,int row2)
{
	int i,j,t;
	for(i=1;i<=n;++i)
	{
		t=s.Matrix[row1][i];
		s.Matrix[row1][i]=s.Matrix[row2][i];
		s.Matrix[row2][i]=t;
	}
}

bool Find(ull s)
{
	int pos;
	pos=s% HASH_RANGE;
	while(true)
	{
		if(mark[pos]==s)
			return true;
		pos=(pos+1)% HASH_RANGE;
		if(!mark[pos]) break;
	}
	return false;
}

void Insert(ull s)
{	
	int pos;
	pos=s% HASH_RANGE;
	while(mark[pos])	pos=(pos+1) % HASH_RANGE;
	mark[pos]=s;
}
