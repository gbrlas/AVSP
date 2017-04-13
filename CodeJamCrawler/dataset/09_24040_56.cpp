#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR2(i,a,b) for (int i = (b)-1; i >= (a); --i)

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define $(x) int(x.size())
#define PB push_back

typedef pair<int,int> PII;
typedef long long ll;
typedef long double ld;

set<string> cute;

class Tree
{
public:
	double prob;
	string feature;
	Tree *yes, *no;

	Tree()
	{
		yes = no = NULL;
	}

	void Read()
	{
		char s[100];
		if (scanf("( ") != 0) printf("Error1\n");
		if (scanf("%lf ", &prob) != 1) printf("Error2\n");
		if (scanf("%s ", s) != 1) printf("Error2\n");
		if (s[0] == ')') {
			//printf("EndNode %f\n", prob);
			scanf(" ");
		}
		else {
			feature = string(s);
			yes = new Tree();
			no = new Tree();
			yes->Read();
			no->Read();
			scanf(") ");
		}
	}

	double Cuteness(double pr)
	{
		pr *= prob;

		if (yes == NULL)
			return pr;

		if (cute.find(feature) != cute.end())
			return yes->Cuteness(pr);
		else
			return no->Cuteness(pr);
	}
};


int main()
{
	int T, junk;
	scanf("%d ", &T);

	FOR (t, 0, T) {

		printf("Case #%d:\n", t+1);

		scanf("%d ", &junk);
		Tree tr;
		tr.Read();

		int A;
		scanf("%d ", &A);
		FOR (a, 0, A) {
			char animal[100];
			scanf("%s", animal);
			int C;
			scanf("%d ", &C);
			cute.clear();

			FOR (c, 0, C) {
				char feature[100];
				scanf("%s", feature);
				cute.insert(string(feature));
			}
			
			printf("%.8f\n", tr.Cuteness(1.0));
		}

	}
	
}
