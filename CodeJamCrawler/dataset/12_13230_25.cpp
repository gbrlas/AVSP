#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int test(){
	int n, s, p;
	scanf("%d %d %d", &n, &s, &p);
	vector<int> wy;
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d", &x);
		wy.push_back(x);
	}
	sort(wy.begin(), wy.end(), greater<int>());
	int z = 0;
	for(vector<int>::iterator it = wy.begin(); it != wy.end(); it++){
		if(*it >= max(3*p-2, p)){
			z++;
		}else if(*it >= max(p, 3*p-4) && s > 0){
			z++;
			s--;
		}
	}
	return z;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: %d\n", i, test());
	}
}
