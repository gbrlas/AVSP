#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 2000005

int n,hi,lo,res,used[MAXN],cont;
vector<int> num;

void go(int x) {
	int aux = x,y;
	num.clear();
	while (aux) {
		num.push_back(aux%10);	aux /= 10;
	}
	
	n = num.size();
	reverse(num.begin(),num.end());
	
	for (int i=0; i<n; i++)
		num.push_back(num[i]);
	
	for (int i=1; i<n; i++) {
		if (num[i] == 0) continue;
		y = 0;
		for (int j=0; j<n; j++) {
			y *= 10;	y += num[i+j];
		}
		
		if (y>x && y<=hi && used[y] != cont) {
			used[y] = cont;
			res++;
		}
	}
	
	return;
}

int main() {
	int nt,nteste=1;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d%d",&lo,&hi);
		
		for (int i=lo; i<=hi; i++)
			used[i] = 0;	cont = 1;
		
		res = 0;
		for (int i=lo; i<=hi; i++) {
			go(i);
			cont++;
		}
		
		printf("Case #%d: %d\n",nteste++,res);
	}
	
	return 0;
}