#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <numeric>
#include <sstream>

using namespace std;

long long M;
long long N;
long long A;

long long X0, X1, X2, Y0, Y1, Y2;

bool isOK ()
{
	double a = sqrt( (double)(X0 - X1) * (X0 - X1) + (Y0 - Y1) * (Y0 - Y1));
	double b = sqrt( (double)(X0 - X2) * (X0 - X2) + (Y0 - Y2) * (Y0 - Y2));
	double c = sqrt( (double)(X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
	double p = (a + b + c) / 2;

	double area = sqrt(p * (p-a) * (p-b) * (p-c));
	if ( area * 2 - 0.1 < A && A < area * 2 + 0.1) {
		return true;
	} else {
		return false;
	}
}

bool f()
{
	/*
	for (X0 = 0; X0 <= N; X0++) {
		for (X1 = 0; X1 <= N; X1++) {
			for (X2 = 0; X2 <= N; X2++) {
				for (Y0 = 0; Y0 <= N; Y0++) {
					for (Y1 = 0; Y1 <= N; Y1++) {
						for (Y2 = 0; Y2 <= N; Y2++) {
							if (isOK()) {
								return true;
							}
						}

					}
				}
			}
		}
	}
	*/
	for (X1 = 0; X1 <= N; X1++) {
		for (X2 = X1; X2 <= N; X2++) {
			for (Y1 = 0; Y1 <= M; Y1++) {
				for (Y2 = 0; Y2 <= M; Y2++) {
					X0 = 0;
					Y0 = 0;
					if (isOK()) {
						return true;
					}

					X0 = N;
					Y0 = 0;
					if (isOK()) {
						return true;
					}

					X0 = 0;
					Y0 = M;
					if (isOK()) {
						return true;
					}

					X0 = N;
					Y0 = M;
					if (isOK()) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	long long nTest;
	cin>>nTest;
	for (long long i = 1; i <= nTest; i++) {
		cin>>N>>M>>A;
		bool rtn = f();
		if (rtn == true) {
			cout<<"Case #"<<i<<": "<<X0<<" "<<Y0<<" "<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<endl;
		} else {
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		}
	}
}