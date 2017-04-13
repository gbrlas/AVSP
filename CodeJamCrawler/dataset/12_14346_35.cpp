#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>

using namespace std;
int ar[2000001];
long do1(long a,long b,long c)
{
    if(a>2000000 || ar[a] ||a<b || a>c)return 0;
    int p[8];
    int d,e,f,g,h,x,y,z;
    d=a;
    e=0;
    while(d>0)
    {
        p[e]=d%10;
        e++;
        d/=10;
    }
    f=0;
    int q[8];
    for(x=e-1;x>=0;x--)
    {
        q[x]=p[e-x-1];
    }
    for(x=0;x<e;x++)
    {
        g=0;
        for(y=x;y<x+e;y++)
        {
            g=(g*10)+q[y%e];
        }
        if(g<=2000000 && !ar[g] && g>=b && g<=c){f++;}
        ar[g]=1;
    }
    return f*(f-1)/2;

}
int main()
{
    FILE *fin=fopen("a.in","r"),*fout=fopen("a.out","w");
    long a,b,c,d,e=0,f,g,h,x,y,z,p,q,r,s,t,u,v;
    fscanf(fin,"%ld",&a);
    for(b=1;b<=a;b++)
    {
        e=0;
        fscanf(fin,"%ld %ld",&c,&d);
        memset(ar,0,sizeof ar);
        for(x=0;x<=9;x++)
        {
            for(y=0;y<=9;y++)
            {
                for(z=0;z<=9;z++)
                {
                    for(p=0;p<=9;p++)
                    {
                        for(q=0;q<=9;q++)
                        {
                            for(r=0;r<=9;r++)
                            {
                                for(s=0;s<=9;s++)
                                {
                                    t=(((((((x*10)+y)*10+z)*10+p)*10+q)*10+r)*10+s);
                                    if(t!=0)e+=do1(t,c,d);
                                }
                            }
                        }
                    }
                }
            }
        }
        fprintf(fout,"Case #%ld: %ld\n",b,e);
    }
    return 0;
}
