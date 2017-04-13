#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int T,n,s,p;
int a[200];

bool cmp(int a, int b) {return a<b?0:1;}

int main(){
	scanf("%d",&T);
	for (int Ti=0;Ti<T;Ti++){
		scanf("%d%d%d",&n,&s,&p);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		int ans = 0;
		for (int i=0;i<n;i++){
			if (a[i] % 3 == 0){
				if (a[i] / 3 >=p) ans++;
				else if (s && a[i] / 3 + 1 >=p && a[i] / 3 + 1 <=10 && a[i] / 3 - 1 >=0) s--,ans++;
			}else if (a[i] % 3 == 1){
				if (a[i] / 3 + 1>=p) ans++;
			}else{
				if (a[i] / 3 + 1>=p) ans++;
				else if (s && a[i] / 3 + 2 >=p) s--,ans++;
			}
		}
		cout << "Case #" << Ti+1 << ": " << ans << endl;
	}
}
