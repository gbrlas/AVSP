#include<iostream>
#include<algorithm>
using namespace std;

int q1[4][4];
int q2[4][4];
int main(){
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	int cs=1;
	while(T--){
		int row,cal;
		scanf("%d",&row);

		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&q1[i][j]);
			}
		}
		scanf("%d",&cal);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&q2[i][j]);
			}
		}
		int ans;
		int sta=-1;

		row--;
		cal--;		

		for(int c=0;c<4;c++){
			for(int r=0;r<4;r++){
				if(q1[row][c]== q2[cal][r]){
				  sta++;
				  ans = q1[row][c];	
					
				}
			}
		}
		printf("Case #%d: ",cs++);
		if(sta>0) printf("Bad magician!\n");
        else if(sta<0) printf("Volunteer cheated!\n");
		else printf("%d\n",ans);
				
	}
	
	return 0;
} 
