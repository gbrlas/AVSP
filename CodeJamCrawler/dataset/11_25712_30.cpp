#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
char D[10005][15];
char L[30];
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n, m;
		scanf("%d %d", &n ,&m);
		for(int i = 0; i < n; i++)
			scanf(" %s", D[i]);
		printf("Case #%d: ", t);
		for(int M = 0; M < m; M++)
		{
			scanf(" %s", L);
			int WYNIK = 0, INDEX = 0;
			for(int i = 0; i < n; i++)
			{
				int length = strlen(D[i]), wynik = 0;
				set<int> S;
				int kubel[30];
				for(int j = 0; j <= 'z'-'a'; j++)
					kubel[j] = 0;

				for(int j = 0; j < n; j++)
					if(strlen(D[j]) == length)
					{
						S.insert(j);
						for(int k = 0; D[j][k] != 0; k++)
							kubel[D[j][k]-'a']++;
					}

				int gdzieL = 0;
				while(S.size() > 1)
				{
//					printf("Case %d. lista=%d, i=%d, zostało=%d, poz=%d ", t, M, i, S.size(), gdzieL);
					while(gdzieL < 30 && kubel[L[gdzieL]-'a'] == 0) gdzieL++;
//					printf("transmutowana w %d.\n\t", gdzieL);
//					for(set<int>::iterator test = S.begin(); test != S.end(); test++)
//						printf("%d[%s] ", *test, D[*test]);
//					printf("\n");
					if(t == 7 && M == 7 && i == 6) {int q = 100000000; while(q--);};
			//		if(gdzieL > 'z'-'a')
			//			break;
					bool uff = 0;
					for(int j = 0; D[i][j] != 0; j++)
						if(D[i][j] == L[gdzieL]) uff = 1;
					if(!uff)
						wynik++;
					for(set<int>::iterator it = S.begin(); it != S.end();)
					{
						bool mozna = 1;
						for(int k = 0; D[*it][k] != 0; k++)
							if(!((D[i][k] == L[gdzieL] && D[i][k] == D[*it][k]) || (D[i][k] != L[gdzieL] && D[*it][k] != L[gdzieL])))
								mozna = 0;
						if(!mozna)
						{
							for(int k = 0; D[*it][k] != 0; k++)
								kubel[D[*it][k]-'a']--;
//							set<int>::iterator next = it;
							S.erase(it);
//							next++;
							it = S.begin();
						}
						else
							it++;
					}
					gdzieL++;
				}
				if(wynik > WYNIK)
				{
					WYNIK = wynik;
					INDEX = i;
				}
			}
			printf("%s ", D[INDEX]);
		}
	printf("\n")	;
	}
	return 0;
}
