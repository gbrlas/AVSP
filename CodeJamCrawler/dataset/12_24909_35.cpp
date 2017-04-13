#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FORTO(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,n) for (int i = (n)-1; i >= 0; i--)

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;
#define SIZE(x) int(x.size())

typedef pair<int, int> PII;
typedef long long ll;

//////////////////////////////////////////////////////////////////

int n;
string ch;
string line[32], answer[32];
map <char, char> M;
set <char> I, O;

int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    getline(cin,ch);
    for(int i=0; i<n; i++)
    {
        getline(cin,line[i]);
        //DEBUG(line[i]);
	}
	for(int i=0; i<n; i++)
    {
        getline(cin,answer[i]);
	}
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<line[i].size(); j++)
	    {
	        M[line[i][j]]=answer[i][j];
	    }
	}
	M['y'] = 'a';
	M['e'] = 'o';
	M['q'] = 'z';
	//DEBUG(M.size());
	for(char c='a'; c<='z'; c++)
	{
	    I.insert(c);
	    O.insert(c);
	}
	for(typeof(M.begin()) it = M.begin(); it != M.end(); it++)
	{
	    I.erase(it->first);
	    O.erase(it->second);
	}
	//DEBUG(I.size());
	//DEBUG(O.size());
	M[*I.begin()] = *O.begin();
	freopen("A-small-attempt0.in", "r", stdin);
	cin >> n;
	getline(cin,ch);
	for(int i=0; i<n; i++)
    {
        getline(cin,line[i]);
        answer[i].resize(line[i].size());
	}
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<line[i].size(); j++)
	    {
	        answer[i][j]=M[line[i][j]];
	    }
	}
	for(int i=0; i<n; i++)
    {
        cout << "Case #" << i+1 << ": " << answer[i] << endl;
    }
    return 0;
}
