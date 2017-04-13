#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;

int T,t,A,B,a,b;
int sol;
set <int> R;

string flip_str(string x) {
	string y = "";
	for(int i = x.size()-1;i>=0;i--) {
		y += x[i];
	}
	return y;
}
string int_to_string(int x) {
	string s = "";
	while(x>0) {
		s += ('0'+x%10);
		x/=10;
	}
	return flip_str(s);
}
int string_to_int(string s) {
	int x = 0;
	for(int i=0;i<(int)s.length();i++) {
		x*=10;
		x+=s[i]-'0';
	}
	return x;
}
string shift(string x, int o) {
	string y = "";
	int s = x.size();
	for(int i=0;i<s;i++) {
		y+=x[(i+o)%s];
	}
	return y;
}

int ispair(int xa, int xb) {
	string sa = int_to_string(xa);
	string sb = int_to_string(xb);
	fflush(stdout);
	for(int o=0;o<(int)sa.size();o++) {
		if(shift(sa,o)==sb) {
			//printf("%s %s\n", sa.c_str(), sb.c_str());
			return 1;
		}
	}
	return 0;
}
int count(int xa) {
	R.clear();
	string sa = int_to_string(xa);
	int res = 0;
	for(int o=1;o<(int)sa.size();o++) {
		int xb = string_to_int(shift(sa,o));
		if(xa<xb && xb<=B) {
			//printf("%d %d\n",xa,xb);
			R.insert(xb);
		}
	}
	return res = R.size();
}
void testc() {
	sol = 0;
	scanf("%d %d",&A, &B);
	for(a=A;a<=B;a++) {
		sol+=count(a);
	}
	printf("Case #%d: %d\n",t,sol);
}

int main() {
	scanf("%d",&T);
	for(t=1;t<=T;t++) {
		testc();
	}
	return 0;
}