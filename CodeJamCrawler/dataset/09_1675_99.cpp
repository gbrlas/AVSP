#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_n=(b);i<=_n;i++)
#define MAX 150

int matrix[MAX][MAX];
char res[MAX][MAX];
bool vis[30];
int a[30][2],m,n;
int ty[]={-1,1,0,0};
int tx[]={0,0,1,-1};

int main(){
	int t;
	scanf("%d",&t);
	REP(i,t){
		scanf("%d %d",&m,&n);
		REP(j,m)REP(k,n)scanf("%d",&matrix[j][k]);
		
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		int lo=0;
		REP(j,m){
			REP(k,n){
				int sx=k,sy=j,mnv=1000000,xx;
				while(1){
					xx=0;
					REP(l,4){
						if( (sy+ty[l]>=0 && sy+ty[l]<m) && (sx+tx[l]>=0 && sx+tx[l]<n) ){
							if(matrix[sy+ty[l]][sx+tx[l]]< matrix[sy][sx]){
								xx=1;
								mnv=min(mnv,matrix[sy+ty[l]][sx+tx[l]]);
							}
						}
					}
					
					if((sy-1>=0 && sy-1<m) && matrix[sy-1][sx]==mnv && xx==1)sy-=1;
					else if((sx-1>=0 && sx-1<n) && matrix[sy][sx-1]==mnv && xx==1)sx-=1;
					else if((sx+1>=0 && sx+1<n) && matrix[sy][sx+1]==mnv && xx==1)sx+=1;
					else if((sy+1>=0 && sy+1<m) && matrix[sy+1][sx]==mnv && xx==1)sy+=1;
					else break;
				}
				int val=0;
				REP(l,lo){
					if(a[l][0]==sy && a[l][1]==sx){
						res[j][k]='a'+l;
						val=1;
					}
				}
				if(val==0){
					vis[lo]=1;
					a[lo][0]=sy;
					a[lo][1]=sx;
					res[j][k]='a'+lo;
					lo++;
				}
			}
		}
		
		printf("Case #%d:\n",i+1);
		REP(j,m){
			REP(k,n){
				printf("%c",res[j][k]);
				if(k!=n-1)printf(" ");
			}
			printf("\n");
		}
	}

return 0;
}
