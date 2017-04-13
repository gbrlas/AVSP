#include <iostream> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <bitset> 

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};

int arr[102][102];
int A,B;
int cor[10003],sz[10003];

void UFinit(int V)
{
	int v=0;
		for(v=0;v<V;v++)
		{
		cor[v]=v;
		sz[v]=1;
		}
		return;
}

int find(int v)
{
	while(v!=cor[v])
	v=cor[v];
	return v;
}

int UFfind(int v,int w)
{
	return (find(v)==find(w));
}
void UFunion(int v0,int w0)
{
	int v=find(v0),w=find(w0);
	if(v==w)
	return;
	if(sz[v]<sz[w])
	{
		cor[v]=w;
		sz[w]+=sz[v];
	}
	else
	{
		cor[w]=v;
		sz[v]+=sz[w];
	}
return;
}

bool dentro(int x,int y)
{
    if(x<0||y<0||x>=A||y>=B)
    return false;
    return true;
}
void procesa(int x,int y)
{
    int menor=arr[x][y];
    int sigx=-1;
    int sigy=-1;
    for(int i=0;i<4;i++)
    {   
        if(dentro(dirx[i]+x,diry[i]+y))
        {
            if(arr[dirx[i]+x][diry[i]+y]<menor)
                {
                    menor=arr[dirx[i]+x][diry[i]+y];
                    sigx=dirx[i]+x;
                    sigy=diry[i]+y;
                }
        }
    }
    if(sigx==-1&&sigy==-1)
    return;
    int u,v;
    u=x*B+y;
    v=sigx*B+sigy;
    
    if(UFfind(u,v))
    return;
    else
    {
       UFunion(u,v);
       procesa(sigx,sigy);
    }
}
int main()
{
    int cases;
    cin>>cases;
    for(int k=1;k<=cases;k++)
    {
        cin>>A>>B;
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<B;j++)
            {
                cin>>arr[i][j];           
            }
        }
        UFinit(A*B);
        
        for(int i=0;i<A*B;i++)
        {
            procesa(i/B,i%B);    
        }
        
        cout<<"Case #"<<k<<":"<<endl;
        int cont=0;
        int ex=0;
        char c;
        int van=0;
        map<int,bool> esta;
        map<int,char> letra;
        
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<B;j++)
            {
                   //cout<<find(cont)<<" ";
                   ex=find(cont);
                   if(!esta[ex])
                   {    
                        c='a'+van;
                        van++;
                        esta[ex]=true;
                        letra[ex]=c;
                   }
                   if(j==0)
                   {
                   cout<<letra[ex];
                   }
                   else
                   {
                    cout<<" "<<letra[ex];
                   }
                   cont++;
            }
            cout<<endl;
        }
        
    }


return 0;
}
