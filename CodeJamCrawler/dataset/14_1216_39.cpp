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


int main()
{
    int t,m,n,i,acount,j,k,total,bcount;
    double a[1001],b[1001],c[1001],d[1001],max,min;
    cin>>t;
    for(m=1;m<=t;++m)
    {
        cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(i=0;i<n;++i)
        {
            cin>>b[i];
            d[i]=b[i];
        }

        sort(a,a+n);
        sort(b,b+n);

      acount=0;

for(i=0;i<n;++i)
c[i]=0;
          for(i=n-1;i>=0;i--)
          {   k=0;
          max=0.00000;
              for(j=0;j<n;++j)
              {
                 if(a[i]>=b[j])
                 {
                    c[k]=b[j];

                    k++;
                 }
              }
              for(j=0;j<k;j++)
                {
                    if(max < c[j])
                    {
                    max=c[j];

                    }
                }

                 for(j=0;j<n;++j)
                 {
                     if(b[j]==max && b[j]!=0.00000)
                     {
                         acount++;
                         b[j]=0.00000;
                         break;
                     }
                 }

          }

   bcount=0;
            for(i=n-1;i>=0;i--)
            {
                total=0;
                min=1.10000;

                for(j=0;j<n;++j)
                {
                    if(a[i]<=d[j])
                    {
                        d[j]=0.00000;
                        break;
                    }
                    else
                    {
                        total++;
                    }
                }

                    if(total==n)
                    {
                     for(j=0;j<n;++j)
                        {
                            if(d[j]!=0.00000 && d[j]<min)
                            {
                                min=d[j];

                            }
                        }



                    for(j=0;j<n;++j)
                    {
                        if(d[j]==min)
                        {
                            d[j]=0.00000;
                            bcount++;
                            break;
                        }

                    }

                    }


                }




          printf("Case #%d: %d %d\n",m,acount,bcount);

    }

    return 0;
}
