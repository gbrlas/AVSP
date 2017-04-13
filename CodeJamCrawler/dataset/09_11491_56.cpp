#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct node
{
	double p;
	string feature;
	node * left , * right;
	node ()
	{
		p = 0;
		feature = "";
		left = NULL;
		right = NULL;
	}
} * T;

char st[80000];
int len, pos;
map <string, bool> m;
double ans;

void solve (node * s)
{
	while (true){
		if (st[pos] == '(')	break;
		pos++;
	}
	pos++;
	sscanf(st + pos, "%lf", &s->p);
	while (true){
		if (st[pos] == ')' || (st[pos] >= 'a' && st[pos] <= 'z'))	break;
		pos++;
	}
	if (st[pos] == ')'){
		pos++;
		return ;
	}
	while (true){
		if (st[pos] == ' ')	break;
		s->feature += string (1, st[pos++]);
	}
	s->left = new node;
	s->right = new node;
	solve (s->left);
	solve (s->right);
}

void output (node * s)
{
	printf("%lf %s\n", s->p, s->feature.c_str());
	if (s->left) output (s->left);
	if (s->right) output (s->right);
}

void go (node * s)
{
	ans *= s->p;
	if (s->left == NULL)
		return ;
	if (m[s->feature])
		go (s->left);
	else
		go (s->right);
}

int main ()
{
	freopen ("A-small.in", "r", stdin);
	freopen ("A-small.out", "w", stdout);
	int t, L, A;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++){
		T = new node;
		scanf("%d", &L);
		getchar();
		pos = len = 0;
		while (true){
			if (L == 0)
				break;
			scanf("%c", &st[len++]);
			if (st[len - 1] == '\n')
				st[len - 1] = ' ', L--;
		}
		solve (T);
		//output (T);
		printf("Case #%d:\n", k);
		scanf("%d", &A);
		while (A--){
			string name, fx;
			m.clear();
			int n;
			ans = 1;
			cin>>name>>n;
			for (int i = 0; i < n; i++)
				cin>>fx, m[fx] = true;
			go (T);
			printf("%.7f\n", ans);
		}
	}
}