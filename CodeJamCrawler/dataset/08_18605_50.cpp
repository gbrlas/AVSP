#include<iostream>
#include<algorithm>
using namespace std;
struct myab
{
	int d,a,par;
};
struct mytt
{
	int d,a,par,flag;
};
myab ta[100],tb[100];
mytt tab[200]={0};
bool cmp1(myab a,myab b)
{
	return a.d<b.d;
}
bool cmp2(mytt a,mytt b)
{
	return a.a<b.a;
}
bool cmp3(mytt a,mytt b)
{
	return a.d<b.d;
}
int fdp(int x,int flag)
{
	if(flag)
	{
		if(tb[x-100].par!=x)
			tb[x-100].par=fdp(tb[x-100].par,0);
	}
	else
	{
		if(ta[x].par!=x)
			ta[x].par=fdp(ta[x].par,1);
	}
	return ta[x].par;
}
int main()
{
	freopen("c:/in.txt","r",stdin);
	freopen("c:/out.txt","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int j,k=0,t,l,na,nb,tp1,tp2,nab;
		scanf("%d%d%d",&t,&na,&nb);
		for(j=0;j<na;j++,k++)
		{
			tab[k].flag=0;
			scanf("%d:%d",&tp1,&tp2);
			tab[k].d=ta[j].d=tp1*60+tp2;
			scanf("%d:%d",&tp1,&tp2);
			tab[k].a=ta[j].a=tp1*60+tp2;
		}
		for(j=0;j<nb;j++,k++)
		{
			tab[k].flag=1;
			scanf("%d:%d",&tp1,&tp2);
			tab[k].d=tb[j].d=tp1*60+tp2;
			scanf("%d:%d",&tp1,&tp2);
			tab[k].a=tb[j].a=tp1*60+tp2;
		}
		nab=k;
		sort(ta,ta+na,cmp1);
		for(j=0;j<na;j++)
			ta[j].par=j;
		sort(tb,tb+nb,cmp1);
		for(j=0;j<nb;j++)
			tb[j].par=j+100;
		sort(tab,tab+nab,cmp3);
		for(j=0,k=0,l=0;l<nab;l++)
		{
			if(tab[l].flag)
				tab[l].par=j++;
			else
				tab[l].par=k++;
		}
		sort(tab,tab+nab,cmp2);
		int edt,flga=0,flgb=0;
		for(j=0;j<nab;j++)
		{
			int x;
			edt=tab[j].a;
			if(tab[j].flag)
			{
				for(k=flga;k<na;k++)
				{
					if(ta[k].d>=edt+t&&ta[k].par==k)
					{
						x=tab[j].par;
						x=fdp(x+100,1);
						ta[k].par=x;
						break;
					}
				}	
				flga=k;
			}
			else
			{
				for(k=flgb;k<nb;k++)
				{
					if(tb[k].d>=edt+t&&tb[k].par==k+100)
					{
						x=tab[j].par;
						x=fdp(x,0);
						tb[k].par=x;
						break;
					}
				}
				flgb=k;
			}
		}
		int cta=0,ctb=0;
		for(j=0;j<na;j++)
			if(ta[j].par==j)
				cta++;
		for(j=0;j<nb;j++)
			if(tb[j].par==j+100)
				ctb++;
		printf("Case #%d: %d %d\n",i,cta,ctb);
	}
	return 0;
}