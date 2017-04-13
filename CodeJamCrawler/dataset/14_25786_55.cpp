#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define ll long long

int main()
{
	freopen("inp1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; ++t) {
		double C;
		double F;
		double X;
		scanf("%lf%lf%lf", &C, &F, &X);
		
		double ans = 1e18;
		double tim = 0.00;
		double rate = 2.00;
		while(true) {
			double temp = tim + (X / rate);
			if(ans > temp) {
				ans = temp;
			} else {
				break;
			}
			tim += (C / rate); 
			rate += F;
		}
		
		printf("Case #%d: %.6lf\n", t, ans);
	}
	
	return 0;
}
