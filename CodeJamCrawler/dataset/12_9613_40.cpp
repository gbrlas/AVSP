#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#define ll long long 

using namespace std;

int n;
string s;
int c[256];


int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
   
	c[101] = 111;
	c[106] = 117;
	c[112] = 114;
	c[32] = 32;
	c[109] = 108;
	c[121] = 97;
	c[115] = 110;
	c[108] = 103;
	c[99] = 101;
	c[107] = 105;
	c[100] = 115;
	c[120] = 109;
	c[118] = 112;
	c[110] = 98;
	c[114] = 116;
	c[105] = 100;

	c[114] = 116;
	c[98] = 104;
	c[99] = 101;
	c[112] = 114;
	c[32] = 32;
	c[121] = 97;
	c[116] = 119;
	c[115] = 110;
	c[97] = 121;
	c[100] = 115;
	c[107] = 105;
	c[104] = 120;
	c[119] = 102;
	c[102] = 99;
	c[101] = 111;
	c[109] = 108;
	c[118] = 112;
	c[110] = 98;

	c[100] = 115;
	c[101] = 111;
	c[32] = 32;
	c[107] = 105;
	c[114] = 116;
	c[111] = 107;
	c[121] = 97;
	c[97] = 121;
	c[119] = 102;
	c[106] = 117;
	c[116] = 119;
	c[115] = 110;
	c[117] = 106;
	c[108] = 103;
	c[103] = 118;
	c[99] = 101;
	c[118] = 112;
	c['q'] = 'z';
	c['z'] = 'q';
	c[' '] = ' ';
	
    scanf("%d\n", &n);
    
    for (int i = 0; i < n; i++)
    {
		getline(cin, s);
		
		cout << "Case #" << i + 1 << ": ";
		
		for (int j = 0; j < s.size(); j++)
			cout << char(c[s[j]]);
		cout << endl;
	}
}
