
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
using namespace std;
int main()
{
    #if defined( faiyaz_pc )
    READ("C-small-attempt0.in");
    WRITE("C-small-attempt0.txt");
#endif
    vector <long> q;
    long t,i;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
    long a,b,count=0;
    scanf("%ld%ld",&a,&b);
    for(long j=a;j<=b;j++)
    {
        long num=j;
        long n = num;
 long rev = 0;
 while (num > 0)
 {
      long dig = num % 10;
      rev = rev * 10 + dig;
      num = num / 10;
 }
 if(n==rev)q.push_back(n);
    }
    for(long j=0;j<q.size();j++)
    {
        long c=sqrt(q[j]);
        if(c*c==q[j]){long num=c;
        long n = num;
 long rev = 0;
 while (num > 0)
 {
      long dig = num % 10;
      rev = rev * 10 + dig;
      num = num / 10;
 }
 if(n==rev)count++;
 }//printf("%d ",q[i]);}
    }
    printf("Case #%ld: %ld\n",i,count);
    q.clear();
    }
    return 0;
}
