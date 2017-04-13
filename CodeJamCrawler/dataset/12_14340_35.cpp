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

int main()
{
    FILE *fin=fopen("a.in","r"),*fout=fopen("a.out","w");
    int a,b,c,d,e,f,g,h,x,y,z;
    fscanf(fin,"%d",&a);
    for(z=1;z<=a;z++)
    {
        fscanf(fin,"%d %d %d",&b,&c,&d);
        e=0;
        for(y=0;y<b;y++)
        {
            fscanf(fin,"%ld",&f);
            if(d==1)
            {
                if(f>=1)e++;
            }
            else if((f-d)/2>=d-1 )e++;
            else if(c>0 && (f-d)/2>=d-2){c--;e++;}
        }
        fprintf(fout,"Case #%d: %d\n",z,e);
    }
    return 0;
}
