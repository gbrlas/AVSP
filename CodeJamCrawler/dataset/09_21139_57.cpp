#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=10;
const int mv[4][2]={ -1,0, 1,0, 0,-1, 0,1 };

char mp[maxn][maxn];
string f[2][maxn][maxn][200];
int task, cs, Qn, lim, tar, n;
string ans;

int main(){
	freopen("C-small-attempt1.in","r",stdin);
//	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int bo=100;
	for (scanf("%d", &task); task--;){
		printf("Case #%d:\n", ++cs);
		scanf("%d%d", &n, &Qn);
		for (int i=0; i<n; i++){
			scanf("%s", mp[i]);
		}
		while (Qn--){
			scanf("%d", &tar);
			for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
			for (int k=0; k<200; k++)
				f[1][i][j][k]="";
            for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
            if (mp[i][j]!='+'&&mp[i][j]!='-')
				f[1][i][j][mp[i][j]-'0'+bo] = mp[i][j];
            int o=1;
            do{
                ans="";
                for (int k=0; k<200; k++)
				for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					f[o^1][i][j][k] = "";

                for (int k=0; k<200; k++)
                for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                if ( f[o][i][j][k]!="" ){
                     if (k-bo==tar && ( ans==""||f[o][i][j][k]<ans ) )
                        ans=f[o][i][j][k];                        
	                 for (int dir=0; dir<4 ; dir++){
                          int fx = i+mv[dir][0], fy = j+mv[dir][1];
                          if ( !( 0<=fx&&fx<n && 0<=fy&&fy<n ) )  continue;
                          for (int dir2=0; dir2<4; dir2++){
                               int x2 = fx+mv[dir2][0], y2=fy+mv[dir2][1];
		                       if ( !( 0<=x2&&x2<n && 0<=y2&&y2<n ) )  continue;
                               int nw;
                               if ( mp[fx][fy]=='+' )
                                   nw=k+(mp[x2][y2]-'0');else
                                   nw=k-(mp[x2][y2]-'0');
                               if ( !( 0<=nw && nw<200 ) ) continue;
                               string tmp=f[o][i][j][k]+mp[fx][fy]+mp[x2][y2];
                               if (f[o^1][x2][y2][nw]=="" || tmp<f[o^1][x2][y2][nw])
			                   f[o^1][x2][y2][nw]=tmp;
						  }   
					 }
				}
                if (ans!=""){
					printf("%s\n", ans.c_str());
                    break;   
                }
                o ^= 1;
            }while (true);
		}
	}
	return 0;
}
