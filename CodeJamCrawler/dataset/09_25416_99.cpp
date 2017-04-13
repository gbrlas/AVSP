#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int L,D,N;
	cin >>L>>D>>N;

	vector<string> dict;
	REP(d,D)
	{
		string w;
		cin >> w;
		dict.PB(w);
	}

	REP(n,N)
	{
		string p;
		cin >> p;

		VVI msg;
		VI letters;
		bool paren=false;
		REP(i, p.size())
		{
			if (p[i] == '(')
			{
				paren = true;
			}
			else if (p[i] == ')')
			{
				msg.push_back(letters);
				letters.clear();
				paren = false;
			}
			else
			{
				if (paren)
				{
					letters.push_back(p[i]);
				}
				else
				{
					VI tmp;
					tmp.push_back(p[i]);
					msg.push_back(tmp);
				}
			}
		}

		int result=0;

		REP(i, dict.size())
		{
			bool match = true;
			REP(j, dict[i].size())
			{
				if (find(ALL(msg[j]), dict[i][j]) == msg[j].end())
				{
					match = false;
					break;
				}
			}
			if (match)
				result++;
		}

		cout << "Case #" << (n+1) << ": " << result << "\n";
	}

}