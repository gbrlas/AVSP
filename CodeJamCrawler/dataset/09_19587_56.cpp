#include <iostream>
#include <algorithm>
using namespace std;


char s[25];

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T, C;
	cin>>T;
	int i, j, k, len;
	for(C=1; C<=T; ++C)
	{
		printf("Case #%d: ", C);
		k = 0;
		cin>>s;
		len = strlen(s);
		for(i=len-1; i>=0; i--)
		{
			char min = '9' + 1;
			int t;
			for(j=len-1; j>i; j--)
			{
				if(s[j] > s[i])
					if( min > s[j]) { min = s[j]; t = j; }
			}
			if( min != '9' + 1)
			{
				k = 1;
				s[t] = s[i];
				s[i] = min;
				sort(s+i+1, s+len);
				cout<<s<<endl;
				break;
			}
		}
		if( k == 0 )
		{
			int vis[10];
			memset(vis, 0, sizeof(vis));
			for(i=0; i<len; i++)
				vis[ s[i] - '0'] ++;
			for(i=1; i<10; i++)
			{
				if( vis[i] )
				{
					vis[i] --;
					cout<<i<<"0";
					break;
				}
			}
			for(i=0; i<10; i++)
				for(j=0; j<vis[i]; j++)
					cout<<i;
			cout<<endl;
		}
	}
	return 0;
}