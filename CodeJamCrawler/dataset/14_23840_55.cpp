#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool visited[N];
double naomi[N], ken[N];
vector < int > edges[N];
int next[N], prev[2 * N], used[N];

bool dfs (int v)
{
	if (visited[v])
		return false;

	visited[v] = true;
	for (int i = 0; i < edges[v].size (); i++)
	{
		int temp = edges[v][i];
		if (prev[temp] == -1)
		{
			prev[temp] = v;
			next[v] = temp;
			return true;
		}
	}

	for (int i = 0; i < edges[v].size (); i++)
	{
		int temp = edges[v][i];
		if (dfs (prev[temp]))
		{
			prev[temp] = v;
			next[v] = temp;
			return true;
		}
	}
	return false;
}

int Find (int n)
{
	memset (used, false, sizeof (used));
	sort (naomi, naomi + n);
	sort (ken, ken + n);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ken[j] > naomi[i] && !used[j])
			{
				used[j] = true;
				break;
			}

	for (int i = 0; i < n; i++)
		if (!used[i])
			res++;

	return res;
}

int BipartiteMatch (int t)
{
	memset (prev, -1, sizeof (prev));
	memset (next, -1, sizeof (next));
	bool done = true;
	while (done)
	{
		done = false;
		memset (visited, false, sizeof (visited));
		for (int i = 0; i < t; i++)
			if (next[i] == -1 && dfs (i))
				done = true;
	}
	int ret = 0;
	for (int i = 0; i < t; i++)
		if (next[i] != -1)
			ret++;
	return ret;
}

int main ()
{
	int T, n;
	scanf ("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			edges[i].clear ();
		for (int i = 0; i < n; i++)
			scanf ("%lf", &naomi[i]);
		for (int i = 0; i < n; i++)
			scanf ("%lf", &ken[i]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (naomi[i] > ken[j])
					edges[i].push_back (n + j);

		int deceit = BipartiteMatch (n);
		int war = Find (n);
		printf ("Case #%d: %d %d\n", testcase, deceit, war);
	}
	return 0;
}
