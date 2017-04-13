#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double c, f, x;
		cin >> c >> f >> x;
		double cookies = 0;
		double elapsed = 0;
		double speed = 2;
		while (cookies < x) {
			if (c/speed < (x-cookies)/speed) {
				elapsed += c/speed;
				if ((x-cookies)/(speed+f)+elapsed < (x-cookies-c)/speed+elapsed) {
					speed += f;
				} else {
					cookies += c;
				}
			} else {
				elapsed += (x-cookies)/speed;
				break;
			}
		}
		printf("Case #%d: %.7Lf\n", i, elapsed);
	}
	return 0;
}