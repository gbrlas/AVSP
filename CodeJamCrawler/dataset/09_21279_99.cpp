// acmx.cpp : 定义控制台应用程序的入口点。
//



#include<iostream>
#include<cstring>
using namespace std;
typedef struct node
{
	int flag;
	node *next[27];
	void init(){memset(next,0,sizeof(next));flag=0;}
}node;
char tmp[5010];
char hash[15000];
char mapx[501][27];
int L,D,K;

int del(node *T)
{
	int i;
	if(T==NULL)
		return 0;
	for(i=0;i<27;i++)
	{
		if(T->next[i]!=NULL)
		{
			del(T->next[i]);
		}
	}
	free(T);
	return 0;
}

int predeal(int len)
{
	int i,xk=0;
	for(i=0;i<len;i++)
	{
		if(hash[i]=='(')
		{
			int xxk=0;
			for(i=i+1;i<len;i++)
			{
				if(hash[i]==')')
				{
					mapx[xk][xxk]='\0';
					xk++;
					break;
				}
				mapx[xk][xxk++]=hash[i];
			}
		}
		else
		{
			mapx[xk][0]=hash[i];
			mapx[xk][1]='\0';
			xk++;
		}
	}
	return xk;
}

int total=0;
int deal(int now,node *T)
{
	int i;
	if(now==L)
	{
		total++;
		return 1;
	}
	for(i=0;mapx[now][i]!='\0';i++)
	{
		if(T->next[mapx[now][i]-'a'+1]==NULL)
			continue;
		deal(now+1,T->next[mapx[now][i]-'a'+1]);
	}
	return 0;
}

int main()
{
	int i,j;
	node *T,*p,*q;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("xxx.out","w",stdout);
	while(scanf("%d %d %d",&L,&D,&K)!=EOF)
	{
		getchar();
		T=(node*)malloc(sizeof(node));
		T->init();
		for(i=0;i<D;i++)
		{
			gets(tmp);
			p=T;
			for(j=0;j<L;j++)
			{
				if(p->next[tmp[j]-'a'+1]==NULL)
				{
					q=(node*)malloc(sizeof(node));
					q->init();
					p->next[tmp[j]-'a'+1]=q;
					p=q;
				}
				else
					p=p->next[tmp[j]-'a'+1];
			}
		}
		int len,pre;
		for(i=1;i<=K;i++)
		{
			gets(hash);
			len=strlen(hash);
			pre=predeal(len);
			if(pre!=L)
			{
				printf("Case #%d: 0\n",i);
				continue;
			}
			total=0;
			deal(0,T);
			printf("Case #%d: %d\n",i,total);
		}
		del(T);
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}


