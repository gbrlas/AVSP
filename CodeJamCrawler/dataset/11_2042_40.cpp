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
	for(int t;t<cases;t++){
		int ans = -1;
		int n,l,h;
		cin>>n>>l>>h;
		vector<int> freq(n);
		for(int i=0;i<n;i++){
			cin>>freq[i];
		}
		for(int i=l;i<h+1;i++){
			bool div = true;
			for(int j = 0;j<n;j++){
				if(freq[j]%i!=0&&i%freq[j]!=0){
					div = false;
					break;
				}
			}
			if(div){
				ans = i;
				break;
			}
		}
		printf("Case #%d: ",t+1);
		if(ans == -1)
			printf("NO\n");
		else
			printf("%d\n",ans);
	}
  return 0;
}
