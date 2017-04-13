#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double speed = 2.0, now = 0.0, answer = X / speed;
		for (int farms = 1; farms <= X && now <= answer; farms++) {
			now += C / speed;
			speed += F;
			answer = min(answer, now + X / speed);
		}
		printf("Case #%d: %.7lf\n", i, answer);
	}
	return 0;
}