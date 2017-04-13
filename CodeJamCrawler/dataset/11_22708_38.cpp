#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char tab[500][500];

typedef long long ll;

ll xpos[500][500];
ll ypos[500][500];
ll wsum[500][500];

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int test = 1; test <= lz; test++){
		int r, c, d;
		scanf("%d%d%d", &r, &c, &d);
		for ( int i =0; i < r; i++){
			scanf("%s", tab[i]);
		}
		
		for ( int i =0; i < r; i++){
			for ( int j = 0; j < c; j++){
				xpos[i][j] = (2*i+1)*(d+tab[i][j]-'0');
				if ( i > 0 ) xpos[i][j] += xpos[i-1][j];
				if ( j > 0 ) xpos[i][j] += xpos[i][j-1];
				if ( i > 0 && j > 0 ) xpos[i][j] -= xpos[i-1][j-1];

				ypos[i][j] = (2*j+1)*(d+tab[i][j]-'0');
				if ( i > 0 ) ypos[i][j] += ypos[i-1][j];
				if ( j > 0 ) ypos[i][j] += ypos[i][j-1];
				if ( i > 0 && j > 0 ) ypos[i][j] -= ypos[i-1][j-1];		
				
				wsum[i][j] = (d+tab[i][j]-'0');
				if ( i > 0 ) wsum[i][j] += wsum[i-1][j];
				if ( j > 0 ) wsum[i][j] += wsum[i][j-1];
				if ( i > 0 && j > 0 ) wsum[i][j] -= wsum[i-1][j-1];	
			}
		}
		
		int best = 0;
		
		for ( int i =0; i < r; i++){
			for ( int j = 0; j < c; j++){
				for ( int s = max(best+1,3); s <= min(r,c); s++){
					int xBeg = i - s+1;
					int yBeg = j - s+1;
					
					if ( xBeg < 0 || yBeg < 0 ) break;
					ll xSum = xpos[i][j];
					if ( xBeg > 0 ) xSum -= xpos[xBeg-1][j];
					if ( yBeg > 0 ) xSum -= xpos[i][yBeg-1];
					if ( xBeg > 0 && yBeg > 0 ) xSum += xpos[xBeg-1][yBeg-1];
					
					ll ySum = ypos[i][j];
					if ( xBeg > 0 ) ySum -= ypos[xBeg-1][j];
					if ( yBeg > 0 ) ySum -= ypos[i][yBeg-1];
					if ( xBeg > 0 && yBeg > 0 ) ySum += ypos[xBeg-1][yBeg-1];		
					
					ll wSum = wsum[i][j];
					if ( xBeg > 0 ) wSum -= wsum[xBeg-1][j];
					if ( yBeg > 0 ) wSum -= wsum[i][yBeg-1];
					if ( xBeg > 0 && yBeg > 0 ) wSum += wsum[xBeg-1][yBeg-1];				
					
					xSum -= (2*i+1)*(d+tab[i][j]-'0');
					xSum -= (2*i+1)*(d+tab[i][yBeg]-'0');
					xSum -= (2*xBeg+1)*(d+tab[xBeg][j]-'0');
					xSum -= (2*xBeg+1)*(d+tab[xBeg][yBeg]-'0');		
					
					ySum -= (2*j+1)*(d+tab[i][j]-'0');
					ySum -= (2*j+1)*(d+tab[xBeg][j]-'0');
					ySum -= (2*yBeg+1)*(d+tab[i][yBeg]-'0');
					ySum -= (2*yBeg+1)*(d+tab[xBeg][yBeg]-'0');
					
					wSum -= (d+tab[i][j]-'0');
					wSum -= (d+tab[xBeg][j]-'0');
					wSum -= (d+tab[i][yBeg]-'0');
					wSum -= (d+tab[xBeg][yBeg]-'0');
					
					ll xCenter = (ll)(i+xBeg+1)*wSum;
					ll yCenter = (ll)(j+yBeg+1)*wSum;
					
					double xGen = (i+0.5+xBeg+0.5)/2;
					double yGen = (j+0.5+yBeg+0.5)/2;
					
					if ( xSum == xCenter && ySum == yCenter ) best = max(best, s);
					//if ( i == 5 && j == 5 )printf("xSum: %lld, xCenter: %lld, xGen: %lf\n", xSum, xCenter, xGen);
					//if ( i == 5 && j == 5 )printf("ySum: %lld, yCenter: %lld, yGen: %lf\n", ySum, yCenter, yGen);					
				}				
			}
		}
		if ( best < 3 ) printf("Case #%d: IMPOSSIBLE\n", test);
		else printf("Case #%d: %d\n", test, best);
	}
	return 0;
}
