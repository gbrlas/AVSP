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

#define MAXS 110

int T, R, C;

char chr[MAXS][MAXS];
int arr[MAXS][MAXS];

char curChar;

int dirs[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};

bool read()
{
	cin >> R >> C;
	int y, x;
	fr (y, R)
		fr (x, C) 
			cin >> arr[y][x];
 
 return true;
}

int getValue(int r, int c, int dir) {
	r += dirs[dir][0];
	c += dirs[dir][1];
	if (r < 0 || c < 0 || r >= R || c >= C) 
		return -1;
	else
		return arr[r][c];
}

void rec(int r, int c) {
	if (chr[r][c] != '*') 
		return;

	int dir=-1;
	int i;
	int val;
	int curValue = arr[r][c];

	fr (i, 4) {
		val = getValue(r, c, i);
		if (val == -1) 
			continue;

		if (val < curValue) {
			curValue = val;
			dir = i;
		}
	}
	if (dir == -1) {
		chr[r][c] = curChar++;
	} else {
		int tr, tc;
		tr = r + dirs[dir][0];
		tc = c + dirs[dir][1];

		rec(tr, tc);
		chr[r][c] = chr[tr][tc];
	}
}

void proc(int tc)
{
	int y, x;
	fr (y, R)
		fr (x, C)
			rec(y, x);

        cout << "Case #" << tc+1 << ":" << endl;
	fr (y, R) {
                fr (x, C) {
                        if (x != 0)
                                cout << " ";
			cout << chr[y][x];
                }
		cout << endl;
	}
}

void init() {
	int y, x;
	fr (y, MAXS)
		fr (x, MAXS)
		chr[y][x] = '*';

	curChar = 'a';
}

int main()
{
	int i;
        cin >> T;
	fr (i, T) {
		read();
		init();
                proc(i);
	}
 
	 return 0;
}
