#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define fr2(i, s, n) for(i = (s); i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

const int infi = 2000000000;

#define MAXS 200000

int _T;
int B[11];
int bLen;

int bMin[11];
bool foundMin[11];

bool V[11][200000];
char H[11][200000];

int ans;

bool read()
{
	string st;
	int temp;
 getline(cin, st);
 ISS iss(st);
 bLen = 0;
 while (iss >> temp) {
	B[bLen++] = temp;
 }
 return true;
}

char isHappy(int val, int base) {
	bool res = true;
	int next;
	int temp;
	
	if (val == 1)
		return 1;
	
	if (val < MAXS)
		if (V[base][val]) {
			if (H[base][val] == 0)
				return 2;
			else
				return H[base][val];
		}
				
	if (val < MAXS)
		V[base][val] = true;	

	int t = val;
	next = 0;
	while (t > 0) {
		temp = (t % base);
		next += temp * temp;
		t /= base;
	}


	t = isHappy(next, base);
	if (val < MAXS)
		H[base][val] = t;

	return t;
}

/*
void find(int base) {
	int i;
	if (foundMin[base]) return;


	i = 2;
	while (true) {
		if (isHappy(i, base)) {
			bMin[base] = i;
			break;
		}
		i++;
	}

	foundMin[base] = true;
}
*/

void proc()
{
	int j, i;
	char res;
	ans = infi;

	i=2;
	while (true) {
		/*if (i == 200000-1) {
			ans = infi;
			break;
		}*/
		res = 1;
		fr (j, bLen) {
			res = isHappy(i, B[j]);
			if (res == 2 || res == 0) break;
		}

		if (res == 1) {
			ans = i;
			break;
		}
		i++;
	}


}

int main()
{
int i;
string st;
getline(cin, st);
ISS iss(st);
iss >> _T;
 fr (i, _T) 
 {
	 read();
	 proc();
	 cout << "Case #" << i+1 << ": " << ans << endl;

 }
 
 return 0;
}
