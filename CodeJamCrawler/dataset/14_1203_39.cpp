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
	           double c,f,x,tsec,total,k;
               int t,m,i;
                 cin>>t;
                  for(m=1;m<=t;++m)
                 {     k=2;
                     cin>>c>>f>>x;
                     total=0.0;
                     tsec=0;

                   while((x/k)>((c/k)+(x/(k+f))))
                     {

                         tsec+=c/k;

                         k+=f;
                     }
                     tsec+=x/k;

                   printf("Case #%d: %.7f\n",m,tsec);
                 }
	return 0;
}
