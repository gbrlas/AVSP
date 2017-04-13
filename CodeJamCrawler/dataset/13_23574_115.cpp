#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

string dtos(double n)
{
	ostringstream ss;
   	ss << std::fixed << std::setprecision(0) << n;
   	return ss.str();
}

bool isP(string s) {
	int sz = s.size();
	int hfsz = sz/2;
	for(int i = 0; i < hfsz; i++)
		if(s[i] != s[sz-1-i])
			return false;
	return true;
}

double sqP1014[1000];

void prepare() {
	double sqr1014 = ceil(sqrt(100000000000000));
	int pos = 0;
	for(double i = 1; i <= sqr1014; i++) {
		if(isP(dtos(i)) && isP(dtos(i*i))) {
			sqP1014[pos++] = i*i;
		}
	}
	sqP1014[pos] = 1000000000000000;
}

int main() {
	int T;
	double a,b;
	int i,j;
	prepare();
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> a >> b;
		for(i = 0; sqP1014[i] < a; i++);
		for(j = i; sqP1014[j] <= b; j++);
		cout << "Case #" << t << ": " << j-i << endl;
	}
	return 0;
}
