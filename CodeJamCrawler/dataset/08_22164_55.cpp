#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define IN(x) (((x)<0)||(fmod(((x)), r+g)>g))


typedef long long ll;
const double pi = 2*acos(0.0);

void solve(int tcase, int points) {
	ll curr = points;
	ll sum = curr;
	ll sum_bad  = 0;
	ll curr_bad = 0;

	double f, R, t, r, g;
	scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
	t += f;
	g -= 2*f;
	r += r;
	r += 2*f;
	R -= t;

	double prob = 0 ;
	double P;
	double G = R / (double) points;

	if( R <= 0) {
		goto end;
	}


	for(int i=0; i<points; i++) {
		if(IN(G*i-0.5*r)) 
			curr_bad ++;
	}
	sum_bad = curr_bad;



	for(int i=1; i<points; i++) {
		while(curr * curr + i*(ll(i)) > points * (ll) points) {
			if(IN(G*curr-0.5*r))
				curr_bad --;
			curr--;
		}
		sum += curr;
		if(!(IN(G*i-0.5*r)))
			sum_bad += curr_bad;
		else sum_bad += curr;
	}
	P = R*R / ((R+t) * (R+t));
	prob = sum_bad / (double) sum;
	prob = prob * P + 1 - P;

end: ;
	printf("Case #%d: %.8lf\n", tcase, prob);
}

int main() {
	int t, c=0;
	scanf("%d", &t);
	while(t--) {
		solve(++c, 80000000) ;
	}
}
