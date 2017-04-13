#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <ctime>
#include <complex>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define sqr(a) ((a)*(a))

using namespace std;

typedef long long LL;
typedef pair<int,int> PAIR;

const int maxn=200003;
const int inf=2000000001;

int n,t,a,b;

inline bool work(){
	if (a<0 || b<0 || a>100 || b>100 || (a<100 && b==100))return false;
	int i,j,A=-1,B;
	for1(i,1,n){
		if (i*a%100==0){
			B=i;
			A=i*a/100;
			break;
		}
	}
	if (A==-1)return false;
	for1(i,0,1000)
		for1(j,i,1000)
			if (b*(B+j)==100*(A+i))return true;
	return false;
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i;
	for1(i,1,t){
		cin>>n>>a>>b;
		if (work())printf("Case #%d: Possible\n",i);
		else printf("Case #%d: Broken\n",i);
	}
    return 0;
}
