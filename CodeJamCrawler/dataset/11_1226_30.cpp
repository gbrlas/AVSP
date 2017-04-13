#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);

llong n;
int pd,pg;

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	//freopen("in.txt","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int i,j,k,t,nc = 0;
	cin>>t;
	while(t--){
		cin>>n>>pd>>pg;
		int work = true;
		if(pd!=100 && pg==100 || pd!=0 && pg==0)work = false;
		else{
			int tmp = gcd(pd,100);
			int t0 = 100/tmp;
			if(n<t0)work = false;
		}
		if(work)printf("Case #%d: Possible\n",++nc);
		else printf("Case #%d: Broken\n",++nc);
	}
	return 0;
}