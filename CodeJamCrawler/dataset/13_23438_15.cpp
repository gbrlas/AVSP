#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1200*2;
const int BASE = 1000002013;

int n, m, top, nm, ret1, ret;
pair<int, int> d[maxn];
pair<int, int> stack[maxn];

int count1( int a, int b, int c ){
	int num = b-a;
	int ret = num*n%BASE-(((long long)num)*((long long)num-1)/2)%BASE;
	ret %= BASE;
	ret = (long long)ret*c%BASE;
	return ret;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int task, CS = 1;
	for (scanf("%d", &task); task--; CS++){
		scanf("%d%d", &n, &m);
		nm = 0;
		ret1 = 0;
		for (int i=0; i<m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ret1 += count1(a, b, c);
			ret1 %= BASE;
			d[nm].first = a; d[nm++].second = -c;
			d[nm].first = b; d[nm++].second = c;
		}
		sort( d, d+nm );
		//cout<<ret1<<endl;

		ret = 0;
		top = -1;
		for (int i=0; i<nm; i++)
		if ( d[i].second<0 ){
			top++;
			stack[top].first = d[i].first;
			stack[top].second = -d[i].second;
		}else{
			int num = d[i].second;
			while (num>0){
				if ( stack[top].second>num ){
					ret += count1(stack[top].first, d[i].first, num);
					ret %= BASE;
					stack[top].second -= num;
					num = 0;
				}else{
					ret += count1(stack[top].first, d[i].first, stack[top].second);
					ret %= BASE;
					num -= stack[top].second;
					top--;
				}
			}
		}

		ret = ret1-ret;
		ret %= BASE;
		if ( ret<0 ) ret += BASE;
		printf("Case #%d: %d\n", CS, ret);
	}
	return 0;
}
