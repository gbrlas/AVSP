#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool palindrome(long long a){
	long long b = 0;
	long long tmp=a;
	while(tmp>0){
		b*=10;
		b+=tmp%10;
		tmp/=10;
	}
	return a==b;
}

long long f[10000];
int nf;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	f[0] = -1;
	nf = 1;
	long long sq;
	for(long long i=1; i<=100000000L; i++){
		sq = i*i;
		if(palindrome(i) && palindrome(sq)){
//			cout<<sq<<endl;
			f[nf] = sq;
			nf++;
		}
	}
	f[nf] = 100000000000000000L;
	nf++;
	int ntests;
	cin >> ntests;
	for (int testnum = 0; testnum < ntests; testnum++) {
		long long A, B;
		cin >> A >> B;
		int s = 0;
		while(s<nf && f[s]<A) s++;
		int e = s;
		while(e<nf && f[e]<=B) e++;
		cout << "Case #" << testnum + 1 << ": " << e-s << endl;
	}
	return 0;
}
