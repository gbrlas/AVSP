#include <cstdio>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

const unsigned MAX = 110;

map<pair<int, int>, bool> used;

bool isCon(char c)
{
	switch(c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return false;
	default:
		return true;
	}
};
bool areCons(char name[], int b, int e)
{
	for(int i = b; i < e; i++)
	{
		if(!isCon(name[i]))
			return false;
	}

	return true;
};

int solve(char name[], int n)
{
	int cnt = 0;
	int len = strlen(name);
	
	for(int k=0; k<=len - n; k++)
	{
		if(areCons(name, k, k+n))
		{
			for(int l = k; l >= 0; l--)
			{
				for(int r = k+n - 1; r < len; r++)
				{
					if(!used[make_pair(l, r)])
					{ 
						cnt++;
						used[make_pair(l, r)] = true;
					}
				}
			}
		}
	}

	return cnt;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n;
	char name[MAX];

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		scanf("%s%d", name, &n);
		
		used.clear();

		int ans = solve(name, n);
		printf("Case #%d: %d\n", t, ans);

	}

	return 0;
}