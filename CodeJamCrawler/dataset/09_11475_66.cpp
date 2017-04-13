#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

struct node
{
	bool flag;
	node * next[26];
};

node * T;

void init ()
{
	T = new node;
	memset (T, 0, sizeof (node));
}

void insert (char st[])
{
	node * p = T, * s;
	for (int i = 0; st[i] != '\0'; i++){
		if (!p->next[st[i] - 'a']){
			s = new node;
			memset (s, 0, sizeof (node));
			p->next[st[i] - 'a'] = s;
		}
		p = p->next[st[i] - 'a'];
	}
	p->flag = true;
}

bool query (char st[])
{
	node * p = T;
	for (int i = 0; st[i] != '\0'; i++){
		if (!p->next[st[i] - 'a'])
			return false;
		p = p->next[st[i] - 'a'];
	}
	return p->flag;
}

int L, D, N, ans;
char st[400], res[20];
vector <pair <int, int> > v;

void solve ()
{
	v.clear ();
	bool flag = false;
	int t;
	for (int i = 0; st[i] != '\0'; i++){
		if (st[i] == '(')
			flag = true, t = i + 1;
		else if (st[i] == ')')
			v.push_back (make_pair (t, i - 1)), flag = false;
		else if (!flag)
			v.push_back (make_pair (i, i));
	}
}

void dfs (int c, node * p)
{
	/*if (c == L - 1){
		for (int i = v[c].first; i <=v[c].second; i++)
			if (p->flag)
				ans++;
		return ;
	}*/
	if (c == L){
		if (p->flag)
			ans++;
		return ;
	}
	for (int i = v[c].first; i <=v[c].second; i++){
		if (!p->next[st[i] - 'a'])
			continue;
		dfs (c + 1, p->next[st[i] - 'a']);
	}
}

int main ()
{
	freopen ("A-large.in", "r", stdin);
	freopen ("A-large.out", "w", stdout);
	init();
	scanf("%d%d%d", &L, &D, &N);
	for (int i = 0; i < D; i++)
		scanf("%s", st), insert (st);
	for (int i = 0; i < N; i++){
		scanf("%s", st);
		ans = 0;
		solve ();
		dfs (0, T);
		printf("Case #%d: %d\n", i + 1, ans);
	}
}

