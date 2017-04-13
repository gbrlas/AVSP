#include <iostream>
using namespace std;

struct Node
{
	double t;
	char s[20];
	int lson, rson;
}a[1000];

int tag;
bool isLetter(const char &c)
{
	return c >= 'a' && c <= 'z';
}

void read(int now)
{
	a[now].s[0] = 0;
	//cout<<now<<endl;
	char c;
	while( scanf("%c", &c)!=EOF )
		if( c == '(' )break;
	scanf("%lf", &a[now].t);
	while( scanf("%c", &c)!=EOF )
	{
		if( isLetter(c) )
		{
			int i = 1;
			a[now].s[0] = c;
			for( ; ;i++)
			{
				scanf("%c", &a[now].s[i]);
				if( !isLetter(a[now].s[i]) )
				{
		//			cout<<"agadfgafdg"<<endl;
					a[now].s[i] = 0;
					tag++;
					a[now].lson = tag;
					read(tag);
					tag++;
					a[now].rson = tag;
					read(tag);
					break;
				}
			}
			//break;
		}

		if( c == ')' )
		{
			if(a[now].s[0] == 0) a[now].rson = a[now].lson = -1;
			break;
		}
	}
}

char str[120][20];
int n;
double out;

void dfs(int now)
{
	if(now == -1) return;
	out *= a[now].t;
	if( a[now].s[0] == 0 ) return ;
	for(int i=0; i<n; i++)
		if(strcmp(str[i], a[now].s) == 0)
		{
			dfs(a[now].lson);
			return ;
		}
	dfs(a[now].rson);
}
void get(char *s)
{
	char c;
	while( scanf("%c", &c) != EOF)
	{
		if( isLetter(c)) break;
	}
	s[0] = c;
	for(int i=1; ; i++)
	{
		if( !isLetter( cin.peek() ) )
		{
			s[i] = 0;
			return ;
		}
		scanf("%c", s + i);
	}
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T, C;
	int line;
	scanf("%d", &T);
	int i, CA;
	char s[20];
	for(C=1; C<=T; C++)
	{
		scanf("%d", &line);
		tag = 0;
		read(0);
		//dfs(0);
		scanf("%d", &CA);
		printf("Case #%d:\n", C);
		while(CA--)
		{
			get(s);
			scanf("%d", &n);
			for(i=0; i<n; i++)
				get(str[i]);
		//	for(i=0; i<n; i++)
		//		cout<<str[i]<<endl;
			out = 1;
			dfs(0);
			cout.precision(7);
			cout<<fixed<<out<<endl;
			//printf("%.7lf\n", out);
		}
	}
	return 0;
}