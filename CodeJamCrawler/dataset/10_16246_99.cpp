#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
const int maxn = 1005,INF = 0x7fffffff;

int n,m;
LL p[maxn];
int next[maxn];
LL Sum[maxn];
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int i,j,k,t,T,x,y,index,r;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&r,&k,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            p[i]=(LL)x;
        }
        for(i=0;i<n;i++)  next[i]=-1;
        LL sum;LL Tr=0,Tm=0;
        i=0;
        while(1)
        {
            j=i;sum=0;
            while(1)
            {
                if(sum+p[j]>k) break;
                sum+=p[j];
                j=(j+1)%n;
                if(j==i) break;
            }
            next[i]=j;Sum[i]=sum;
            i=j;
            if(next[i]!=-1) break;
        }
//        out(next,n);
//        out(Sum,n);
        int first=i,head=i;
        while(1)
        {
             Tr++;Tm+=Sum[head];
             head=next[head];
             if(head==first) break;
        }
//        OUT(first);
//        OUT(Tr);OUT(Tm);
        LL money=0;head=0;
        for(i=1;i<=r;i++)
        {
             if(head==first) break;
             money+=Sum[head];
             head=next[head];
        }
//        OUT(i);
        money+=((LL)r-i+1)/Tr*Tm;
        r=(r-i+1)%Tr;
        head=first;
        for(i=1;i<=r;i++)
        {
            money+=Sum[head];
            head=next[head];
        }
        printf("Case #%d: ",t);
        cout<<money<<endl;
    }
    return 0;
}
