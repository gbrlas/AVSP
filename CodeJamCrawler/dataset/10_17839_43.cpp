#include <vector>
#include <list>
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
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

int main()
{
    FILE *fi=fopen("snapper chain.in","r"), *fo=fopen("snapper chain.out","w");
    int t;
    fscanf(fi,"%d",&t);
    for (int i=0;i<t;i++)
    {
        int n, k;
        fscanf(fi,"%d %d",&n,&k);
        fprintf(fo,"Case #%d: ",i+1);
        int pow=1;
        for (int j=0;j<n;j++) pow*=2;
        if ((k+1)%pow==0) fprintf(fo,"ON\n");
        else fprintf(fo,"OFF\n");
    }
}
