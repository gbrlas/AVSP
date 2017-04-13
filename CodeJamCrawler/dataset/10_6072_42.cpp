/**********************************************************************************/
/*  Problem: d518 "垃圾題回來了" from 絕對不是字串題                 */
/*  Language: C++                                                                 */
/*  Result: AC (448ms, 11664KB) on ZeroJudge                                      */
/*  Author: locke2833 at 2010-03-23 10:44:12                                      */
/**********************************************************************************/


#include <iostream>
#include <cstring>
#include <cmath>
#define MAXN 100010
#define MAXS 2200
using namespace std;

typedef struct NODE
{
	int next[36];
	//int id;        // 單字的編號
	bool isword;   // 是不是單字的結尾
}NODE;
NODE tri[MAXN];
bool isend[MAXN];
int nb,top;    // Initial top 為 1 , 紀錄 用到 tri的哪個位置
			  //  nb 為有幾個單字
char word[MAXS];
int insert()
{
	int i,size,ptr = 0;
	size = strlen(word);

	for(i=0;i<size;i++)
	{
		if(word[i] == '/') continue;
		if(word[i] >='0' && word[i]<='9')
		{
			if(tri[ptr].next[26+word[i]-'0']==0)
				tri[ptr].next[26+word[i]-'0'] = top++;
			ptr = tri[ptr].next[26+word[i]-'0'];
			
		}
		else
		{
			if(tri[ptr].next[word[i]-'a']==0)
				tri[ptr].next[word[i]-'a'] = top++;
			ptr = tri[ptr].next[word[i]-'a'];
			
		}
		if(isend[i])
			if(!tri[ptr].isword)
			{
				++nb;
				tri[ptr].isword = true;
			}
		
	}
}

int main()
{
	freopen("A-small-attempt1 (1).in","r",stdin);
	freopen("A.out","w",stdout);
	int n,ca,m;
	memset(tri,0,sizeof(tri));
	top=1;
	scanf("%d",&ca);
	int cs=1;
	while(ca--)
	{
		scanf("%d%d",&n,&m);
		memset(tri,0,sizeof(NODE)*(top+2));
		nb=0,top=1;
		int now=0,tmp;
		int size;
		for(int i=0;i<n;i++)
		{
			scanf("%s",word);
			size = strlen(word);
			for(int j=0;j<size;j++)
			{
				if(j==size-1 || word[j+1]=='/')
					isend[j]=true;
				else
					isend[j]=false;	
			}
			insert();
		}
		int beg = nb;
		for(int i=0;i<m;i++)
		{
			scanf("%s",word);
			size = strlen(word);
			for(int j=0;j<size;j++)
			{
				if(j==size-1 || word[j+1]=='/')
					isend[j]=true;
				else
					isend[j]=false;	
			}
			insert();	
		}
		printf("Case #%d: ",cs++);
		printf("%d\n",nb-beg);
	}
	return 0;
}

