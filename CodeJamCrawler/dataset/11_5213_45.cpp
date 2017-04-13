#include <stdio.h>
#include <string.h>

int pos_o[1000], index_o;
int pos_b[1000], index_b;
struct node {
	char ch;
	int d;
};
struct node pos[1000];
int index;

int main()
{
	int T, i, ca, n,d ;
	int dir_o, dir_b, mov_b, mov_o;
	char ch;
	int sindex_o, sindex_b, start_o, start_b;
	int tot;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++)
	{
		memset(pos_o, 0, sizeof(pos_o));
		memset(pos_b, 0, sizeof(pos_b));
		memset(pos, 0, sizeof(pos));
		index_o = index_b = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf(" %c%d", &ch, &d);
			pos[i].ch = ch;
			pos[i].d = d;
			if (ch == 'O')
				pos_o[index_o++] = d;
			else 
				pos_b[index_b++] = d;
		}
		sindex_o = sindex_b = 0;
		start_o = start_b = 1;
		i = 0;
		tot = 0;
		dir_o = dir_b = 1;
		while (i < n) {
			mov_o = mov_b = 0;
			if (sindex_o < index_o && start_o != pos_o[sindex_o]) {
				start_o += dir_o;
				mov_o = 1;
			}

			if (sindex_b < index_b && start_b != pos_b[sindex_b]) {
				start_b += dir_b;
				mov_b = 1;
			}
			
			//printf("%d %d\n", start_o, start_b);
			if (mov_o == 0 && pos[i].ch == 'O' && start_o == pos[i].d) {
				i++;
				if (sindex_o + 1 < index_o)
					dir_o = pos_o[sindex_o] < pos_o[sindex_o + 1] ? 1 : -1;
				sindex_o++;
			}
			else if (mov_b == 0 && pos[i].ch == 'B' && start_b == pos[i].d) {
				i++;
				if (sindex_b + 1 < index_b)
					dir_b = pos_b[sindex_b] < pos_b[sindex_b + 1] ? 1 : -1;
				sindex_b++;
			}
			tot++;
		}
		printf("Case #%d: %d\n", ca, tot);
	}

	return 0;
}