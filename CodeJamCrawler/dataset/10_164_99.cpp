#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
using namespace std;

#define printcase(x) printf("Case #%d: ",x)

void solvecase(int index,int n,int k)
{
    int m=1<<n;
    k%=m;
    printcase(index);
    if(k==m-1)
        printf ("ON\n");
    else
        printf ("OFF\n");
}

int main()
{   
    int T;
    scanf("%d",&T);
    for(int index=1; index<=T; ++index){
        int n,k;
        scanf("%d%d",&n,&k);
        solvecase(index,n,k);
    }
    return 0;
}
