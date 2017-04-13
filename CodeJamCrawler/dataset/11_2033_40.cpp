#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

int main(){
  int cases;
	cin>>cases;
	for(int t = 0;t<cases;t++){
		ll l,time,n,c;
		cin>>l>>time>>n>>c;
		vector<ll> cycle(c);
		for(int i=0;i<c;i++){
			cin>>cycle[i];
		}
		ll ans;
		if(l==0){
			ans = 0;
			for(int i=0;i<n;i++){
				ans += cycle[i%c]*2;
			}
		}
		else if(l == 1){
			ans = 1e18;
			for(int lpos = 0;lpos < n;lpos++){
				ll a = 0;
				for(int i=0;i<n;i++){
					if(i==lpos){
						if(time <= a){
							a += cycle[i%c];
						}
						else{
							if(time > a+cycle[i%c]*2){
								a += cycle[i%c]*2;
							}
							else{
								a += cycle[i%c]+(time-a)/2;
							}
						}
					}
					else{
						a += cycle[i%c]*2;
					}
				}
				ans = min(ans,a);
			}
		}
		else{
			ans = 1e18;
			for(int lpos1 = 0;lpos1 < n;lpos1++){
				for(int lpos2 = 0;lpos2 < lpos1;lpos2++){
					ll a = 0;
					for(int i=0;i<n;i++){
						if(i==lpos1 || i == lpos2){
							if(time <= a){
								a += cycle[i%c];
							}
							else{
								if(time > a+cycle[i%c]*2){
									a += cycle[i%c]*2;
								}
								else{
									a += cycle[i%c]+(time-a)/2;
								}
							}
						}
						else{
							a += cycle[i%c]*2;
						}
					}
					ans = min(ans,a);
				}
			}
		}
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}
