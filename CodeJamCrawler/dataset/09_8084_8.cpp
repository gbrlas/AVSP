# include <iostream>

using namespace std;

char str[100];
int val[100];
bool vis[100];

bool allvisited()
{
	int i;

	for(i = 0; str[i]; i++)
		if(!vis[i])
			return false;

	return true;
}

int main()
{
	 unsigned __int64 n;
	 int i, j, t, tcase,x ;

	 scanf("%d", &t);

	 for(tcase = 1; tcase <= t; tcase++)
	 {
		 scanf("%s", str);

		 for(i = 0; i < 100; i++)
			 vis[i] = false;

		 val[0] = 1;
		 vis[0] = true;

		 for(i = 0; str[i]; i++)
			 if(str[i] == str[0])
			 {
				 val[i] = 1;
				 vis[i] = true;
			 }

			for(i = 0; vis[i]; i++);

			val[i] = 0;
			vis[i] = true;

			for(j = 0; str[j]; j++)
				if(str[j] == str[i])
				{
					val[j] = 0;
					vis[j] = true;
				}

			for(x = 2; !allvisited(); x++)
			{
				for(i = 0; vis[i]; i++);

				val[i] = x;
				vis[i] = true;

				for(j = i; str[j]; j++)
					if(str[j] == str[i])
					{
						val[j] = x;
						vis[j] = true;
					}
			}

			int base = x;
			n = 0;

			for(i = 0; str[i]; i++)
				n = base*n+val[i];

			printf("Case #%d: %I64u\n", tcase, n);
	 }

	 return 0;
}