using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

int main()
{
     long long int caseval=0,cases,n,ans,onum,bnum,i,otym,btym,x,opos,bpos,diff;
     char ch;
     char seq[500];
     long long int o[250],b[250];
     scanf("%lld",&cases);
     while(cases--)
     {
          caseval++;
          scanf("%lld",&n);
          onum=1;bnum=1;
          o[0]=1;b[0]=1;
          for(i=0;i<n;i++)
          {
               cin>>ch;
               cin>>x;
               seq[i]=ch;
               if(ch=='O')
               {
                    o[onum]=x;
                    onum++;
               }
               if(ch=='B')
               {
                    b[bnum]=x;
                    bnum++;
               }
          }
          bpos=0;btym=0;
          opos=0;otym=0;
              
          for(i=0;i<n;i++)
          {
               if(seq[i]=='O')
               {
                    diff=o[opos+1]-o[opos];
                    if(diff<0)
                         diff*=-1;
                    otym=otym+diff;
                    if(otym<btym)
                         otym=btym;
                    otym++;
                    opos++;
                    ans=otym;
               }
               if(seq[i]=='B')
               {
                    diff=b[bpos+1]-b[bpos];
                    if(diff<0)
                         diff*=-1;
                    btym=btym+diff;
                    if(btym<otym)
                         btym=otym;
                    btym++;
                    bpos++;
                    ans=btym;
                    
               }
          }        
          printf("Case #%lld: %lld\n",caseval,ans);
     }
     return 0;
}                         
