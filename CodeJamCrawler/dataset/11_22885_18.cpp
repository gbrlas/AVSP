#include <cstdio>

int T,N,L,H;
int notes[10000];

int find()
{
	bool tag;
	for (int i = L; i <= H; i++ )
	{
		tag = true;
		for (int j = 0; j < N; j++)
			if (notes[j]%i && i%notes[j])
			{
				tag = false;
				break;
			}
		if (tag)
			return i;
	}
	return -1;

}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	int j,k;
	scanf("%d",&T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d%d%d",&N,&L,&H);	
		for (j = 0; j < N; j++)
			scanf("%d",&notes[j]);

		int res = find();
		printf("Case #%d: ", i);
		if (res > 0)
			printf("%d\n", res);
		else
			printf("NO\n");			
	}

	return 0;
}