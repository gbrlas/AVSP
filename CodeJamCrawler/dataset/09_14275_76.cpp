#include <stdio.h>
#include <string.h>

int H, W;
int map[102][102];
char result[102][102];

typedef struct _Ptr Ptr;
struct _Ptr{
    int x, y;
} sets[102][102];

Ptr  ToPtr(int x, int y){ Ptr p = { x, y }; return p; }

Ptr  GetSets(int x, int y);

int main(){
    int T;
    int cc;
    scanf(" %d", &T);

    for(cc = 1; cc <= T; ++cc){
	int i, j;
	scanf(" %d%d", &H, &W);
	for(i = 1; i <= H; ++i)
	    for(j = 1; j <= W; ++j)
		scanf(" %d", &map[i][j]);

	for(i = 0; i <= H; ++i)
	    map[i][0] = map[i][W + 1] = 31767;
	for(i = 0; i <= W; ++i)
	    map[0][i] = map[H + 1][i] = 31767;

	for(i = 1; i <= H; ++i)
	    for(j = 1; j <= W; ++j){
		int min = map[i][j];
		sets[i][j] = ToPtr(i, j);
		if(map[i - 1][j] < min){
		    min = map[i - 1][j];
		    sets[i][j] = ToPtr(i - 1, j);
		}
		if(map[i][j - 1] < min){
		    min = map[i][j - 1];
		    sets[i][j] = ToPtr(i, j - 1);
		}
		if(map[i][j + 1] < min){
		    min = map[i][j + 1];
		    sets[i][j] = ToPtr(i, j + 1);
		}
		if(map[i + 1][j] < min){
		    min = map[i + 1][j];
		    sets[i][j] = ToPtr(i + 1, j);
		}
	    }

	char nextChar = 'a';
	memset(result, 0, sizeof(result));
	for(i = 1; i <= H; ++i)
	    for(j = 1; j <= W; ++j){
		if(result[i][j]) continue;

		Ptr p = GetSets(i, j);
		if(!result[p.x][p.y])
		    result[p.x][p.y] = nextChar++;
		result[i][j] = result[p.x][p.y];
	    }

	printf("Case #%d:\n", cc);
	for(i = 1; i <= H; ++i){
	    printf("%c", result[i][1]);
	    for(j = 2; j <= W; ++j)
		printf(" %c", result[i][j]);
	    printf("\n");
	}
    }

    return 0;
}

Ptr  GetSets(int x, int y){
    if(sets[x][y].x == x && sets[x][y].y == y)
	return sets[x][y];

    Ptr p = GetSets(sets[x][y].x, sets[x][y].y);
    return (sets[x][y] = p);
}
