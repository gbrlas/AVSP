#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
	int l,d,n;
	char dic[5005][16];
	bool w[16][26];
	memset(dic, 0 , sizeof(dic));
	scanf ("%d%d%d", &l, &d, &n);
	for (int i = 0; i < d; i++) scanf("%s", dic[i]);

	char ch = getchar();
	for (int i = 0; i < n; i++)
	{
		memset(w, false, sizeof(w));
		
		ch = getchar();
		int idx = 0;
		bool move = true;
		while (ch != '\n')
		{
			if (ch == '(') 
			{
				move = false;
				ch = getchar();
				continue;
			}
			else if (ch == ')')
			{
				idx++;
				move = true;
				ch = getchar();
				continue;
			}
			else if (!move)
			{
				w[idx][ch - 'a'] = true;
				ch = getchar();
				continue;
			}
			else
			{
				w[idx++][ch - 'a'] = true;
				ch = getchar();
				continue;
			}
		}
		int ans = 0;
		bool ok = true;
		for (int j = 0; j < d; j++)
		{
			ok = true;
			for (int k = 0; k < l; k++)
			{
				if (w[k][dic[j][k] - 'a'] == false)
				{
					ok = false;
					break;
				}
			}
			if (ok) ans++;
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	return 0;
}