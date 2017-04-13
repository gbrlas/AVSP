#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath> 
using namespace std;

const int MaxN=1000000;
bool v[MaxN+3]; 

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    
    for (int i=2; i<=MaxN; ++i) v[i]=1;
    for (int i=2; i<=MaxN; ++i) if (v[i])
    {
   //     cout<<i<<" "; 
        int p; 
        p=i+i;
        while (p<=MaxN)
        {
            v[p]=0;
            p+=i; 
        } 
    } 
    
    int Testnum; 
    scanf("%d",&Testnum); 
 //   cout<<Testnum<<endl; 
    for (int Test=1; Test<=Testnum; ++Test)
    {
        int N,cnt; 
        printf("Case #%d: ",Test);
        cin>>N; 
        if (N<=1) 
        {
            cout<<"0"<<endl;
            continue;
        } 
        cnt=0; 
        for (int i=2; i<=(int)(sqrt(N)); ++i) if (v[i])
        {
            int cur,cc; 
            cur=i;
            cc=0; 
            while (cur<=N)
            {
                 ++cc;
                 cur*=i; 
            } 
            cnt+=cc-1; 
        } 
        cout<<cnt+1<<endl; 
    } 
    return 0; 
}
