#include <iostream> 
using namespace std; 
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
struct Point{
	int x,y;
};
#define OK(i,j) (i<R&&j<C)
int main(){
	int T;
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,n;
	char *Temp = "Impossible";
	int R,C;
	char map[55][55];
	scanf("%d",&T);
	char Red[2][3] = {"/\\","\\/"};
	Point a[4] = {{0,0},{0,1},{1,0},{1,1}};
	For(t,1,T){
		printf("Case #%d:\n",t);
		cin>>R>>C;
		For(i,0,R-1)cin>>map[i];
		char Can = 1;
		For(i,0,R-1){
			For(j,0,C-1){
				if(map[i][j]=='#'){
					For(k,0,3){
						int x = a[k].x+i;
						int y = a[k].y+j;
						if(OK(x,y)&&map[x][y]=='#'){
							map[x][y] = Red[a[k].x][a[k].y];
						}else {Can = 0;break;}
					}
				}
				if(!Can)break;
			}
			if(!Can)break;
		}
		if(Can){
			For(i,0,R-1)puts(map[i]);
		}
		else{
			puts(Temp);
		}
	}	
	return 0;
}
