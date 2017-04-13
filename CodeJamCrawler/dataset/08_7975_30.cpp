#include<iostream>
#include<ctime>
using namespace std;

struct time{
	char start[6];
	char end[6];
	int id;
};
struct time A[110],B[110];
int N,T,NA,NB,resA,resB;
bool Af[100],Bf[100];
char temp[6];

cmp(const void *p,const void *q)
{
	struct time *pp=(struct time *)p;
	struct time *qq=(struct time *)q;
	return strcmp(pp->start,qq->start);
}

cmpp(const void *p,const void *q)
{
	struct time *pp=(struct time *)p;
	struct time *qq=(struct time *)q;
	return strcmp(pp->end,qq->end);
}
int solve(char *tp,char *t)
{
	int time=((t[0]-'0')*10+(t[1]-'0'))*60+(t[3]-'0')*10+(t[4]-'0')+T;
	int t1=time/60;
	int t2=time%60;
	tp[0]=t1/10+'0';
	tp[1]=t1%10+'0';
	tp[3]=t2/10+'0';
	tp[4]=t2%10+'0';
	tp[2]=':';
	tp[5]='\0';

	return 0;
} 

int main()
{ 
    freopen("B-in.txt","r",stdin);
    freopen("B-out.txt","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		resA=resB=0;
		scanf("%d",&T);
		scanf("%d %d",&NA,&NB);
		for(int j=0;j<NA;j++)
		{
			scanf("%s %s",A[j].start,A[j].end);
			A[j].id=j;
		}
		for(int k=0;k<NB;k++)
		{
			scanf("%s %s",B[k].start,B[k].end);
			B[k].id=k;
			}
		memset(Af,1,sizeof(Af));
		memset(Bf,0,sizeof(Bf));
		qsort(A,NA,sizeof(A[0]),cmp);
		qsort(B,NB,sizeof(B[0]),cmpp);
		for(int m=0;m<NA;m++)
		{
			for(int n=0;n<NB;n++)
			{
				if(!Bf[n])
				{
					solve(temp,B[n].end);
					if(strcmp(temp,A[m].start)<0 || strcmp(temp,A[m].start)==0)
					{
						Af[m]=0;
						Bf[n]=1;
						break;
					}
				}
			}
		}
		for(int mm=0;mm<NA;mm++)
			if(Af[mm])
				resA++;
		memset(Af,0,sizeof(Af));
		memset(Bf,1,sizeof(Bf));
		qsort(B,NB,sizeof(B[0]),cmp);
		qsort(A,NA,sizeof(A[0]),cmpp);
		for(int p=0;p<NB;p++)
		{
			for(int q=0;q<NA;q++)
			{
				if(!Af[q])
				{
					solve(temp,A[q].end);
					if(strcmp(temp,B[p].start)<0 || strcmp(temp,B[p].start)==0) 
					{
						Af[q]=1;
						Bf[p]=0;
						break;
					}
				}
			}
		}
		for(int pp=0;pp<NB;pp++)
			if(Bf[pp])
				resB++;

		printf("Case #%d: %d %d\n",i,resA,resB);
	}

	return 0;
}




