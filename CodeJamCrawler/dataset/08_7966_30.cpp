#include<iostream>
#include<string>
using namespace std;

char word[110];
int N,S,Q,number[110],cnt,res,cntt;
bool flag[15];
struct node{
	int id;
	node *p[100];
	node()
	{
		id=-1;
		for(int i=0;i<100;i++)
			p[i]=NULL;
	}
}root;

int solve(char *s)
{
	node *r=&root;
	for(int i=0;s[i];i++)
	{
		if(r->p[s[i]-' ']==NULL)
			r->p[s[i]-' ']=new node();
		r=r->p[s[i]-' '];
	}
	if(r->id==-1)
		r->id=++cnt;
	return 0;
}

int find(char *s)
{
	node *r=&root;
	for(int i=0;s[i];i++)
		r=r->p[s[i]-' '];
	return r->id;
}

int main()
{
	freopen("A-small-attempt0.in.txt","r",stdin);
    freopen("A-small.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		memset(flag,0,sizeof(flag));
		cnt=0;
		res=0;
		scanf("%d",&S);
		getchar();
		for(int k=0;k<S;k++)
			solve(gets(word));
		scanf("%d",&Q);
		getchar();
		for(int m=0;m<Q;m++)
			number[m]=find(gets(word));
		cntt=0;
		for(int j=0;j<Q;j++)
		{
			if(flag[number[j]]==0)
			{
				++cntt;
				flag[number[j]]=1;
			}
			if(cntt==cnt)
			{
				++res;
				cntt=0;
				j--;
				memset(flag,0,sizeof(flag));
			}
		}

		printf("Case #%d: %d\n",i+1,res);
		node *r=&root;
		for(int i=0;i<100;i++)
		{
		//	while(r->p[i]!=NULL)
		//	{
		//		r=r->p[i];
		//		delete r->p[i];
		//	}
			r->p[i]=NULL;
		}
	}
	return 0;
}






