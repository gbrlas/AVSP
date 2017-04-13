#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int x, y, min1, min2, max1, max2, top1, down1, top2, down2;
int task,n, m, num, dat[100000][2];
char st[100];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n", &task);
	for (int tk=1; tk<=task; tk++){
			printf("Case #%d:\n", tk);
		scanf("%d\n",&n);
		down1 = down2 = max1 = max2 = -100000000; 
		top1 =  top2 = min1 = min2 = 100000000;
		

		num=0;
		for (int i=1; i<=n; i++){
			scanf("%d %d", &x, &y);
			gets( st );
			int o=0;
			while ( st[o]==' ' ) o++;
			if ( st[o]=='B' ){
				max1 >?= x;
				min1 <?= x;
				max2 >?= y;
				min2 <?= y;
			}else{
				dat[num][0] = x;
				dat[num][1] = y;
				num++;
			}
		}
/*
		for (int i=0; i<num; i++){
			x = dat[i][0]; y= dat[i][1];
				if ( x<min1 ) down1 >?= x;
				if ( max1<x ) top1 <?= x;
				if ( y<min2 ) down2 >?= y;
				if ( max2<y ) top2  <?= y;
		}
*/
//		cout<<min1<<' '<<max1<<endl;
//		cout<<min2<<' '<<max2<<endl;
//		cout<<down1<<' '<<top1<<endl;
//		cout<<down2<<' '<<top2<<endl;
		
		scanf("%d\n", &m);
		for (int i=1; i<=m; i++){
			scanf("%d%d\n", &x, &y);
			if ( min1>max1 || min2>max2 ){
				bool ok = false;
				for (int i=0; i<num; i++)
				if ( dat[i][0]==x && dat[i][1]==y ){
					ok = true;
					break;
				}
				if ( ok ) printf("NOT BIRD\n");else 
				printf("UNKNOWN\n");
				continue;
			}
			if ( min1<=x && x<=max1 && min2<=y && y<=max2 ){
				printf("BIRD\n");
				continue;
			}
			bool ok = false;
			for (int i=0; i<num; i++)
			if ( (dat[i][0]<min1 && x<=dat[i][0] || max1<dat[i][0] && dat[i][0]<=x || min1<=dat[i][0] && dat[i][0]<=max1) &&
				 (dat[i][1]<min2 && y<=dat[i][1] || max2<dat[i][1] && dat[i][1]<=y || min2<=dat[i][1] && dat[i][1]<=max2)
				){
				ok = true;
				break;
			}
			if ( ok ) printf("NOT BIRD\n");else 
			printf("UNKNOWN\n");
		}

	}
	return 0;
}
