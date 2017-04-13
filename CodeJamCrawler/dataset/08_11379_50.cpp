# include <stdio.h>
# include <string.h>
# include <algorithm>
using namespace std;

struct node
{
	char from[10];
	char to[10];
}A[105],B[105];
int T,NA,NB;

bool cmp(const node &a,const node &b)
{
	return strcmp(a.from,b.from)<0;
}

int ansA,ansB;
int waitA[105],waitB[105];
int str_to_num(int st,int n,char str[])
{
	char tmp[5];
	strncpy(tmp,str+st,n);
	return atoi(tmp);
}
bool cmpT(char str1[],char str2[])
{
	int ah,am,bh,bm;
	ah=str_to_num(0,2,str1);
	am=str_to_num(3,2,str1);
	bh=str_to_num(0,2,str2);
	bm=str_to_num(3,2,str2);
	bm+=T;
	if(bm>=60)
	{
		bm-=60;
		bh++;
	}
	if(ah>bh||(ah==bh&&am>=bm))
		return true;
	return false;
}

void init()
{
	int i,j;
	memset(waitA,0,sizeof(waitA));
	memset(waitB,0,sizeof(waitB));
	for(i=0;i<NA;i++)
		for(j=0;j<NB;j++)
			waitA[i]+=cmpT(A[i].from,B[j].to);
	for(i=0;i<NB;i++)
		for(j=0;j<NA;j++)
			waitB[i]+=cmpT(B[i].from,A[j].to);
}
				
void solve()
{
	int i;
	sort(A,A+NA,cmp);
	sort(B,B+NB,cmp);
	init();
	int already=0;
	for(i=0;i<NA;i++)
		if(waitA[i]-already>0)
			already++;
	ansA=NA-already;
	already=0;
	for(i=0;i<NB;i++)
		if(waitB[i]-already>0)
			already++;
	ansB=NB-already;
}

int main()
{
	int n,t,i,j;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		scanf("%d",&T);
		scanf("%d%d",&NA,&NB);
		for(i=0;i<NA;i++)
			scanf("%s%s",A[i].from,A[i].to);
		for(i=0;i<NB;i++)
			scanf("%s%s",B[i].from,B[i].to);
		solve();
		printf("Case #%d: %d %d\n",t,ansA,ansB);
	}
	return 0;
}
