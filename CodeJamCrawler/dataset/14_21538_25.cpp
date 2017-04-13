#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <ctime>
#define demid int mid = l + r >> 1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const int N = 1000010;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef long long ll;
using namespace std;
int fun(int n)
{
  if(n <= 2)
    return n;
  return fun(n-1) + fun(n-2);
}
int main()
{
    freopen("in.txt","r",stdin);
    // ios::sync_with_stdio(0);
   int num[8] = {1,8,6,2,5,4,7,3};
   
    return 0;
}
