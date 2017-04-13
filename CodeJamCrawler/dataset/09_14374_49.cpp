#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }

typedef long long int64;
typedef double real;

int n;
int a[1 << 10];
int tmp[1 << 10];


bool exist(int k){
	for (int i = 0; i < k; i++){
		int cnt = 0;
		for (int j = 0; j < k; j++)
			if (a[j] <= i)
				++cnt;
		if (cnt <= i)
			return false;
	}
	return true;
}

int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		scanf("%d", &n);
		char buff[1 << 10];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++){
			scanf(" %s", buff);
			for (int j = 0; j < n; j++)
				if (buff[j] == '1')
					a[i] = j;
			Eo(a[i]);
		}
		int ans = 0;
		for (int curr = n - 1; curr > 0; --curr){
			int last = -1;
			for (int i = 0; i <= curr; i++) if (a[i] <= curr){
				memcpy(tmp, a, sizeof(a));
				for (int j = i; j < curr; j++)
					a[j] = a[j + 1];
				if (exist(curr))
					last = i;
				memcpy(a, tmp, sizeof(tmp));
			}
			assert(last > -1);
			for (int j = last; j < curr; j++)
				a[j] = a[j + 1];
			ans += curr - last;
		}
		printf("Case #%d: %d\n", _ + 1, ans);
	}
	return 0;
}
