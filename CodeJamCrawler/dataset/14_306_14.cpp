#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
	double F, I, T, c=2, t, s, x, y;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		t = 0; s = 0; x = 0; y= 0; c = 2;
		scanf("%lf%lf%lf", &F, &I, &T);
		while(1) {
			x = (F/c);
			y = (T/(c+I));
			s = (T/c);
			if( ((x+y) - s) > 0.00000001) {
				t += s;
				break;
			}
			else {
				t += x;
				c += I;
			}
		}
		printf("Case #%d: %0.7lf\n", i+1, t);
	}
	return 0;
}
