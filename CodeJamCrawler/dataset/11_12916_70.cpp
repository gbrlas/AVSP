#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

map<char, int> codes;
char table[] = " QWERASDF";

char pairs[100];
int opp[100];

inline int getCode(char c)
{
	return codes.find(c)->second;
}

inline char toChar(int v)
{
	if( v >= 1 && v <= 8)
		return table[v];
	else
		return v;
}

int main()
{
	codes.insert(make_pair('Q', 1));
	codes.insert(make_pair('W', 2));
	codes.insert(make_pair('E', 3));
	codes.insert(make_pair('R', 4));
	codes.insert(make_pair('A', 5));
	codes.insert(make_pair('S', 6));
	codes.insert(make_pair('D', 7));
	codes.insert(make_pair('F', 8));

//	freopen("test.in", "r", stdin);

	int T; scanf("%d", &T);
	for(int test=1; test<=T; ++test)
	{

		memset(pairs, 0, sizeof(pairs));
		memset(opp, 0, sizeof(opp));

		int C; scanf("%d ", &C);


		for(int i=0; i<C; ++i)
		{
			char a,b,res;
			scanf("%c%c%c ", &a, &b, &res);
			int c1 = getCode(a), c2 = getCode(b);
			pairs[10 * c1 + c2] = pairs[10 * c2 + c1] = res;
		}

		int D; scanf("%d ", &D);
		for(int i=0; i<D; ++i)
		{
			char a,b;
			scanf("%c%c ", &a, &b);
			int c1 = getCode(a), c2 = getCode(b);
			opp[10 * c1 + c2] = opp[10 * c2 + c1] = 1;
		}

		int N; scanf("%d ", &N);

		char cc;;
		int curr;
		char prev = 0;
		int pcode = 0;

		printf("Case #%d: [", test);

		list<char> seq;
		list<int> codes;

		for(int i=0; i<N; ++i)
		{
			scanf("%c", &cc);
			curr = getCode(cc);
				
			if(prev)
			{
				int combo = 10 * pcode + curr;

				if(pairs[combo])
				{
					seq.push_back(pairs[combo]);
					codes.push_back(0);

					prev = 0;
					cc = 0;

					continue;
				}
				
				if(opp[combo])
				{
					prev = 0;
					cc = 0;
					seq.clear();
					codes.clear();

					continue;
				}

			}

			bool die = false;
			for(list<int>::iterator itr = codes.begin(); itr != codes.end(); ++itr)
			{
				int code = *itr;
				if(!code)
					continue;
				code = code * 10 + curr;
				if(opp[code])
				{
					die = true;
					break;
				}
			}

			if(die)
			{
				seq.clear();
				codes.clear();
				prev = 0;
				cc = 0;
				continue;
			}

			if(prev)
			{
				seq.push_back(prev);
				codes.push_back(pcode);
			}

			prev = cc;
			pcode = curr;
		
		}

		if(cc)
			seq.push_back(cc);

		if(seq.size())
		{
			printf("%c", seq.front());
			seq.pop_front();
		}

		while(seq.size())
		{
			printf(", %c", seq.front());
			seq.pop_front();
		}

		printf("]\n");
	}

}