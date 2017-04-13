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
int main () {	

		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	int t, kase = 1;
	cin>>t;
	while(t--) {
		LL l, t, n, c, tot = 0;
		LL  first[1010];
		LL  second[1010], mini;
		cin>>l>>t>>n>>c;
		for(int i=0;i<c;i++){
			 cin>>first[i]; 
			 first[i] *= 2; 
		}
		for(int i=0;i<n;i++){
				 second[i] = tot;
				  tot += first[i%c];
		}
		mini = tot;
		if(l==0) {
			// hahahha
		}
		else if(l==1){
			for(int i=0;i<n;i++) {
				int a1=0;
				if(second[i]>=t)
					 a1=first[i%c]/2;
				else if(second[i]+first[i%c]>=t)
					 a1 = (first[i%c]-(t-second[i]))/2;
				mini = min(mini,tot-a1);
			}
		}
		else if(l==2) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)
						 if(i!=j) {
							int a1=0, a2=0;
							if(second[i]>=t) 
								a1=first[i%c]/2;
							else if(second[i]+first[i%c]>=t){
									 a1 = (first[i%c]-(t-second[i]))/2;
								}
							if(second[j]>=t)
								 a2=first[j%c]/2;
							else if(second[j]+first[j%c]>=t)
								 a2 = (first[j%c]-(t-second[j]))/2;
							mini = min(mini,tot-a1-a2);
					}
			}
		}
		cout<<"Case #"<<kase++<<": "<<mini<<endl;
	}
//	while(1);
	return 0;
}
