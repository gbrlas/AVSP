#include <cstdio>
#include <cstring>

char a[111][111];
char ans[111][111];
bool check[111][111];
int main(){
	//freopen("a_large.txt","r",stdin);
	//freopen("a_out_large.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		int r, c;
		scanf("%d %d", &r, &c);
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		memset(check, 0, sizeof(check));
		for(int i=0; i<r; i++)
			scanf("%s", a[i]);

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(a[i][j] == '#' && a[i+1][j] == '#' &&
					a[i][j+1] == '#' && a[i+1][j+1] == '#'){
						a[i][j] = '.';
						a[i+1][j] = '.';
						a[i][j+1] = '.';
						a[i+1][j+1] = '.';

						ans[i][j] = '/';
						ans[i+1][j] = '\\';
						ans[i][j+1] = '\\';
						ans[i+1][j+1] = '/';

						check[i][j] = check[i+1][j] = check[i][j+1] = check[i+1][j+1] = true;
				}
				else if(!check[i][j])
					ans[i][j] =  a[i][j];
			}
		}
		bool ok = true;
		for(int i=0; i<r; i++) for(int j=0; j<c; j++)
			if(a[i][j] == '#')
				ok = false;
		printf("Case #%d:\n", tc);
		if(ok){
			for(int i=0; i<r; i++) printf("%s\n", ans[i]);
		}
		else printf("Impossible\n");
	}
	return 0;
}