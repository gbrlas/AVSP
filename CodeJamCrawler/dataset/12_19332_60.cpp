#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
/* Prewritten code ends */

const int maxL = 202;
char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";
char s[maxL];
int main() {
	int T;
	fgets(s, maxL, stdin); sscanf(s, "%d", &T);
	FOR(cs,1,T) {
		fgets(s, maxL, stdin);
		for(int i = 0; s[i] != '\n'; i++) 
			if(islower(s[i]))
				s[i] = mapping[s[i]-'a'];
		printf("Case #%d: %s", cs, s);
	}
	return 0;
}
