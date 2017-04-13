#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

queue<int>Q;
queue<int>P;

int main()
{
    int i,r,k,n,test,x,sum,cnt,t=0;

    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>test;
    while(test--)
    {
        cin>>r>>k>>n;
        printf("Case #%d: ",++t);
        for(i=0;i<n;i++)
        {
            cin>>x;
            Q.push(x);
        }
        sum=0;
        for(i=1;i<=r;i++)
        {
            cnt=0;
            while((Q.front()+cnt)<=k && !Q.empty())
            {
                cnt=Q.front()+cnt;
                sum+=Q.front();
                P.push(Q.front());
                //cout<<"a"<<endl;
                Q.pop();
            }
            while(!P.empty())
            {
                Q.push(P.front());
                //cout<<"b"<<endl;
                P.pop();
            }
        }
        cout<<sum<<endl;
        while(!Q.empty())
            Q.pop();
        while(!P.empty())
            P.pop();
    }

    return 0;
}
