#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>
#include <climits>
#define MAX 100005
#define ll long long
using namespace std;




int main() {
	int a[5][5],b[5][5],d,s,i,j,t,ans,count,m;

             cin>>t;
          for(m=1;m<=t;++m)
      {

           cin>>s;
         for(i=1;i<5;i++)
            {
              for(j=1;j<5;j++)
               {
             cin>>a[i][j];
               }
            }

             cin>>d;
                for(i=1;i<5;i++)
            {
              for(j=1;j<5;j++)
               {
               cin>>b[i][j];
               }
            }

            count=0;
              for(i=1;i<5;i++)
               {
                for(j=1;j<5;++j)
                 {
                 if(a[s][i]==b[d][j])
                  {
                   count++;
                            if(count==1)
                    ans=b[d][j];
                  }
                 }
                }

              if(count==1)
               printf("Case #%d: %d\n",m,ans);
              else if(count>1)
                 printf("Case #%d: Bad magician!\n",m);
              else
                  printf("Case #%d: Volunteer cheated!\n",m);
       }
	return 0;
}
