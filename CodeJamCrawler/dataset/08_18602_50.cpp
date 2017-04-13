#include<iostream>
using namespace std;
unsigned  int  ELFHash( char   * str)
{
	unsigned  int  hash  =   0 ;
	unsigned  int  x     =   0 ;
	while(*str)
	{
		hash  =  (hash  <<   4 )  +  ( * str ++ );
		if  ((x  =  hash  &   0xF000 )  !=   0 )
		{
			hash  ^=  (x  >>   8 );
			hash  &=   ~ x;
		} 
	} 
	return  (hash  &   0x7FFF );
}


struct my
{
	my *point;
	char val[101];
	int ct;
};
int main()
{
	freopen("c:/in.txt","r",stdin);
	freopen("c:/out.txt","w",stdout);
	int n,s,q,jishu=1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&s);
		char sch[100][101],que[101];
		int i,ctm=0;
		my more[100]={0},*hashtab[(1<<15)-1]={0};
		char temp;
		scanf("%c",&temp);
		for(i=0;i<s;i++)
		{
			gets(sch[i]);
			int Temp=ELFHash(sch[i]);
			my *p=hashtab[Temp];
			if(p==0)
				hashtab[Temp]=more+ctm;
			else
			{
				while(p->point!=0)
					p=p->point;
				p->point=more+ctm;
			}
			strcpy(more[ctm].val,sch[i]);
			ctm++;
		}
		scanf("%d",&q);
		scanf("%c",&temp);
		int rmn=s,ct=0;
		for(i=0;i<q;i++)
		{
			gets(que);
			my *p=hashtab[ELFHash(que)];
			if(p->point==0)
			{
				if(ct==p->ct)
				{
					rmn--;
					p->ct++;
				}
				if(!rmn)
				{
					rmn=s-1;
					ct++;
					p->ct++;
				}
			}
			else
			{
				while(strcmp(p->val,que)!=0)
					p=p->point;
				if(ct==p->ct)
				{
					p->ct++;
					rmn--;
					if(!rmn)
					{
						rmn=s-1;
						ct++;
						p->ct++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",jishu,ct);
		jishu++;
	}
	return 0;
}