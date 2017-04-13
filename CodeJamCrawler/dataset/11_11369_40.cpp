#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string>
#include <string.h>
#define pb push_back

#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef  long long LL;
typedef  long long ll;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);

	int t=GI;	
	int kase=0;		
	while(t--){
		kase++;
		int n=GI;
		int l=GI;
		int h=GI;
		int ar[n];
		for(int i=0;i<n;i++)cin>>ar[i];
		int flag2=0;
		cout<<"Case #"<<kase<<": ";
		for(int i=l;i<=h;i++){
			int flag=1;
			for(int j=0;j<n;j++){
				if( ( ar[j] % i ==0  )||( i % ar[j] ==0 )){
				 	continue;
				}
				else {
					flag=0;
					break;
				}
			}
			if(flag){
				cout<<i<<endl;
				flag2=1;
				break;
			}
		}
		if(flag2==0){
			cout<<"NO"<<endl;
		}
	}
        GI;
    return 0;
}
