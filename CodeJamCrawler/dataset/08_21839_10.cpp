#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <functional>
using namespace std;
typedef long long LL;
#define debug(x) cout<<#x<<": "<<x<<endl
#define inf 1000000000
template<class T>void show(T a,int n){for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int r,int c){for(int i=0;i<r;i++)show(a[i],c);}

map < int,set<int> > mm;
map < int,set<int> > :: iterator it, iit;
set <int> :: iterator sl;

int main()
{
	int testnum, n, m, a, temp;

	scanf("%ld",&testnum);
	for(int i = 0;i <= 500;i++){
		for(int j = i;j <= 500;j++){
			temp = i * j;
			it = mm.find(temp);
			if(it != mm.end()){
				((*it).second).insert(i);
			}else{
				set<int> tmp;
				tmp.insert(i);
				mm[temp] = tmp;
			}
		}
	}
	for(int test = 1;test <= testnum;test++){
		bool suc = false;
		scanf("%ld%ld%ld",&n,&m,&a);
		int ma = n * m, x, y, xl, yl, tmp;
		a <<= 1;
		it = mm.begin();
		while((it != mm.end()) && ((*it).first + a <= ma)){
			x = (*it).first;
			if(x > 0)
				xl = ((x - 1) / m) + 1;
			else
				xl = 0;
			y = x + a;
			if(y > 0)
				yl = ((y - 1) / m) + 1;
			else
				yl = 0;
			iit = mm.find(y);
			if(iit == mm.end()){
				it++;
				continue;
			}
			sl = ((*it).second).lower_bound(xl);
			//sr = ((*it).second).upper_bound(n);
			if(sl != ((*it).second).end()){
				tmp = (*sl);
				if(tmp <= n){
					sl = ((*iit).second).lower_bound(yl);
					if((sl != ((*iit).second).end()) && ((*sl) <= n)){
						printf("Case #%ld: 0 0 %ld %ld %ld %ld\n",test,
								tmp,((*it).first) / tmp,
								(*sl),((*iit).first) / (*sl));
						suc = true;
						break;
					}
				}
			}
			it++;
		}
		if(!suc){
			printf("Case #%ld: IMPOSSIBLE\n",test);
		}
	}
	return 0;
}

