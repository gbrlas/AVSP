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

int main()
{
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    int test,t,n,k,x;
    cin>>test;
    t=0;
    while(test--)
    {
        cin>>n>>k;
        printf("Case #%d: ",++t);
        if(n==1)
            if(k%2==1)
                cout<<"ON"<<endl;
            else
                cout<<"OFF"<<endl;
        else
        {
            x=pow((double)2,(double)n);
            if((k%x)==(x-1))
                cout<<"ON"<<endl;
            else
                cout<<"OFF"<<endl;
        }
    }
    return 0;
}
