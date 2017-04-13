#include <iostream>
#include <iomanip>

using namespace std;

int T;
double C , F , X;

int main()
{
    //ifstream cin("test.in");
    //ofstream cout("test.out");
    cin >> T;

    for (int test = 0; test < T ; test++) {
		double cookieRate = 2.0000;
		cin >> C >> F >> X;
		double answer = 0.0000;
		bool stopped = false;
		while (!stopped) {
			double time1 = X / cookieRate;
			double time2 = C / cookieRate;
			double time3 = X / (cookieRate + F);
			if (time1 > time2 + time3) {
				answer += time2;
				cookieRate += F;
			} else {
				stopped = true;
				answer += time1;
			}
		}
		cout << "Case #" << test + 1 << ": ";
		cout << setprecision(10) << answer << endl;
    }
    return 0;
}
