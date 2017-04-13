#include <cstdio>
char all[1005][1005]; 
bool win(char now) {
	bool tmp;
	for(int i=0; i<4; ++i) {
		tmp=true;
		for(int j=0; j<4; ++j)
			if( all[i][j]!='T' && all[i][j]!=now ) tmp=false;
		if( tmp ) return true;
	}
	for(int j=0; j<4; ++j) {
		tmp=true;
		for(int i=0; i<4; ++i)
			if( all[i][j]!='T' && all[i][j]!=now ) tmp=false;
		if( tmp ) return true;
	}
	tmp=true;
	for(int i=0; i<4; ++i) if( all[i][i]!='T' && all[i][i]!=now ) tmp=false;
	if( tmp ) return true; 
	tmp=true;
	for(int i=0; i<4; ++i) if( all[i][3-i]!='T' && all[i][3-i]!=now ) tmp=false;
	return tmp;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int t=1; t<=n; ++t) {
		fgets(all[0], 6, stdin);
		for(int i=0; i<4; ++i) fgets(all[i], 6, stdin);
		if( win('X') ) printf("Case #%d: X won\n", t);
		else if( win('O') ) printf("Case #%d: O won\n", t);
		else {
			bool fin=true;
			for(int i=0; i<4&&fin; ++i)
				for(int j=0; j<4&&fin; ++j) 
					if( all[i][j]=='.' ) fin=false;
			if( fin ) printf("Case #%d: Draw\n", t);
			else printf("Case #%d: Game has not completed\n", t);
		}
	}
}
