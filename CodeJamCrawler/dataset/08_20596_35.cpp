#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn=10010, LIM=9000;
const int mv[4][2]={0,1, 1,0, 0,-1, -1,0};

int tme[maxn<<1], l[maxn], r[maxn], ul[maxn], dl[maxn], ur[maxn], dr[maxn];
string s[2000];
int cx, cy, ret, d, sum;
int task, n;

int main(){
       freopen("A-small-attempt0.in", "r", stdin);
       freopen("a.out", "w", stdout);
       scanf("%d", &task);
       for (int tk=1; tk<=task; tk++) {
		   scanf("%d", &n);
           for (int i=0; i<n; i++) cin>>s[i]>>tme[i];

		   int fx, fy;
           cx = cy = 5000; ret = d = sum = 0;
           for (int i=LIM+1; i>0; i--){
			   r[i] = 0;
			   l[i] = LIM;
			}

           for (int i=0; i<n; i++)
           for (int j=0; j<tme[i]; j++)
           for (int k=0; k<s[i].length(); k++) {
				if (s[i][k]=='L'){ 
					(d+=3)%=4; 
					continue;
				}
				if (s[i][k]=='R'){ 
					(d+=1)%=4; 
					continue;
				}
				if ( !mv[d][0] ) {
					if (d==2) fy = cy-1; else fy = cy;
					l[fy] <?= cx; 
					r[fy] >?= cx;
				}
				ret += (cx+mv[d][0])*cy - (cy+mv[d][1])*cx;
				cx = cx+mv[d][0]; cy = cy+mv[d][1];
		   }

           dl[0] = ul[LIM+1] = 10000;
           for (int i=1; i<LIM; i++) {
               dl[i] = min( dl[i-1], l[i] );
               dr[i] = max( dr[i-1], r[i] );
           }
           for (int i=LIM; i; i--) {
               ul[i] = min( ul[i+1], l[i] );
               ur[i] = max( ur[i+1], r[i] );
               l[i] <?= max( dl[i], ul[i] );
               r[i] >?= min( dr[i], ur[i] );
           }
           for (int i=LIM; i; i--)
               sum += max( r[i]-l[i], 0 );
		   printf("Case #%d: %d\n", tk, sum-abs(ret)/2);
       }
}
