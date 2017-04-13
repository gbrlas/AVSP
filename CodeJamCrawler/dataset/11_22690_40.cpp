#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

char tab[100][100];

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int test = 1; test <= lz; test++){
		memset(tab, '.', sizeof(tab));
		int r, c;
		scanf("%d %d", &r, &c);
		for ( int i =0; i < r; i++) scanf("%s", tab[i]);
		
		int fails = 0;
		for ( int i = 0; i < r; i++){
			for ( int j = 0; j < c; j++){
				if 
				( 
					tab[i][j] == '#' &&
					tab[i+1][j] == '#' &&
					tab[i][j+1] == '#' &&
					tab[i+1][j+1] == '#'
				)
				{
					tab[i][j] = '/';
					tab[i+1][j] = '\\';
					tab[i][j+1] = '\\';
					tab[i+1][j+1] = '/';		
				}
				
				if ( tab[i][j] == '#' ) fails++;
			}
		}
		printf("Case #%d:\n", test);
		if ( fails > 0 ) printf("Impossible\n");
		else{
			for ( int i = 0; i < r; i++) printf("%s\n", tab[i]);
		}
	}
	return 0;
}
