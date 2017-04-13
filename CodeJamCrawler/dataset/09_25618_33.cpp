#include <cstdio>
#include <cstring>

using namespace std;
int n, p[256][30], c[256], cnt[30];
char welcome[]="welcome to code jam", text[505];

int main()
{
	memset(p, -1, sizeof(p));
	for(int i=0; i<strlen(welcome); i++)
		p[welcome[i]][c[welcome[i]]++]=i;

	scanf("%d ", &n);
	for(int i=1; i<=n; i++)
	{
		fgets(text, 505, stdin);
		memset(cnt, 0, sizeof(cnt));
		for(int j=0, k=0; j<strlen(text)-1; j++, k=0)
			while(p[text[j]][k]>=0)
			{
				if(!p[text[j]][k])
					cnt[p[text[j]][k++]]++;
				else
				{
					cnt[p[text[j]][k]]+=cnt[p[text[j]][k]-1];
					cnt[p[text[j]][k++]]%=10000;
				}
			}
		printf("Case #%d: %.4d\n", i, cnt[18]);
	}
	return 0;
}
