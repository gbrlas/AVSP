#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream input;
ofstream output;

int N, S;
string str[10];

string a[100];

int top;
int t[10];
int gp[10][10];
int fac[] = {1, 1, 2, 6, 24, 120, 720};

int ans, cnt;

void Add(int & top, string & str)
{
	string tmp = "";
	for (int i=0; i<str.length(); i++)
	{
		tmp += str[i];
		a[top++] = tmp;
	}
}

int cmp(const void * a, const void * b)
{
	if (*((string*)a) < (*(string*)b)) return -1;
	if (*((string*)a) > (*(string*)b)) return 1;
	return 0;
}

void Update()
{
	int cand = 0;
	for (int s=0; s<S; s++)
	{
		int top = 0;
		for (int i=0; i<t[s]; i++)
			Add(top, str[gp[s][i]]);
		qsort(a, top, sizeof(string), cmp);

		int c = 0;
		for (int i=0; i<top-1; i++)
			if (a[i]!=a[i+1]) c++;
		c++;

		cand += (c+1);
	}
	if (cand>ans)
	{
		ans = cand; cnt = 1;
	}
	else
		if (cand == ans)
			cnt++;
}

void gen(int index)
{
	if (index==N)
	{
		if (top==S) Update();
		return;
	}
	for (int i=0; i<top; i++)
	{
		gp[i][t[i]++] = index;
		gen(index+1);
		t[i]--;
	}
	gp[top][0] = index;
	t[top++] = 1;
	gen(index+1);
	top--;
}

void singleCase(int case_num)
{
	input >> N >> S;
	for (int i=0; i<N; i++) input >> str[i];

	ans = -1; cnt = 0;

	top = 0;
	gen(0);

	output << "Case #" << case_num << ": " << ans << ' ' << cnt * fac[S] << endl;
}

int main()
{
	input.open("D.in");
	output.open("D.out");
	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i+1);
	return 0;
}