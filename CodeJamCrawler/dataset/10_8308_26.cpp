// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

using namespace std;

void split1(const string& str, vector<string>& out)
{
	string::size_type st = 0;
	string::size_type next = 0;
	int word_num = 0;
	string tmp = str;
	do
	{
		next=tmp.find("/",st);
		string word = tmp.substr(st,next-st);
		if(word.length()>=1)
		{
			out.push_back(word);
		}
		st = next+1;
	} while(next!=string::npos);
}



int diff(const vector <string>&a, const vector <string>&b )
{
	int ret = 0;
	const int MAX_COM_LEN = min(SZ(a),SZ(b));
	int com = 0;
	for(int i=0;i<MAX_COM_LEN;i++)
	{
		if(a[i]==b[i])
		{
			com++;
		}
		else
		{
			break;
		}
	}

	ret = (SZ(b)-com);
	return ret;
}

int main()
{
    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		ll ret = 0L;
		int N,M;
		scanf("%d %d",&N,&M);

		vector < vector <string> > path;

		vector <string> root;
		path.push_back(root);
		for(int i=0;i<N+M;i++)
		{
			char str[100005];
			scanf("%s ",str);
			vector <string> out;
			split1(str, out);

			path.push_back(out);
		}

		// root!
		for(int m=0;m<M;m++)
		{
			int mi = 987654321;
			int miid = -1;
			for(int n=0;n<N+1+m;n++)
			{
				int dif = diff(path[n],path[N+1+m]);
				if(dif<mi)
				{
					mi = dif;
					miid = n;
				}
//				cout << " m=" << m << " miid=" << miid << " mi=" << mi << endl;
				
			}
			ret += mi;
		}

		printf("Case #%d: %lld\n",t+1,ret);
	 }

	return 0;
}