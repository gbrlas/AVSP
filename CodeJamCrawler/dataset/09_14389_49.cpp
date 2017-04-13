#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>


#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }
#define maxn (1 << 6)

typedef long long int64;
typedef double real;

struct pnt{
	real x, y;

	pnt(){}
	pnt(real _x, real _y) : x(_x), y(_y){}
	pnt operator-(const pnt& r) const{
		return pnt(x - r.x, y - r.y);
	}
	real dst(){
		return sqrt(x * x + y * y);
	}
};

pnt ps[maxn];
real r[maxn];

int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf %lf", &ps[i].x, &ps[i].y, &r[i]);
		real res = 0.;
		if (n == 1) res = r[0];
		else if (n == 2) res = std::max(r[0], r[1]);
		else if (n == 3){
			res = 1e+50;
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++){
					real tmp = std::max(r[3 - i - j], ((ps[i] - ps[j]).dst() + r[i] + r[j]) * 0.5);
					if (tmp < res)
						res = tmp;
				}
		}
		printf("Case #%d: %.6lf\n", _ + 1, res);
	}
	return 0;
}
