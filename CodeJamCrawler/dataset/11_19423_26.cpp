#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

double absMe(double x){
	if(x<0) return -x;
	else return x;	
}

int main(){
	int nt,r,c;
	double d;
	double data[20][20];
	char input[20][20];
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d %d %lf",&r,&c,&d);
		for(int i=0;i<r;i++){
			scanf("%s",input[i]);
			for(int j=0;j<c;j++){
				data[i][j]=(double)(input[i][j]-'0');
				//scanf("%lf",&data[i][j]);	
			}
		}	
		/*for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%lf ", data[i][j]);	
			}	
			printf("\n");
		}*/
		
		int res = 0;
		int mn = min(r,c);
		for(int k=3;k<=mn;k++){
			for(int i=0;i<=r-k;i++){
				for(int j=0;j<=c-k;j++){
						//printf("%d %d %d\n",k,i,j);
						double baris = 0;
						double kolom = 0;
						
						double tengahX = (double)(i+i+k)/2;
						double tengahY = (double)(j+j+k)/2;
						double sumX = 0;
						double sumY = 0;
						
						for(int x=i;x<i+k;x++){
							for(int y=j;y<j+k;y++){
								if( (x==i && y==j) || (x==i && y==j+k-1) || (x==i+k-1 && y==j) || (x==i+k-1 && y==j+k-1) ) continue;
								sumX+=((double)x+0.5-tengahX) * (d+data[x][y]);
								sumY+=((double)y+0.5-tengahY) * (d+data[x][y]);
							}	
						}	
						
						//printf("%d %d %d %lf %lf\n",k,i,j,sumX,sumY);
						if( fabs(sumX) < 1e-9 && fabs(sumY) < 1e-9 ){
							//printf("%d %d %d\n",k,i,j);
							if(res<k) res = k;
						}
				}
			}
		}
		
		if(res==0){
			printf("Case #%d: IMPOSSIBLE\n",t+1);
		}
		else{
			printf("Case #%d: %d\n",t+1,res);
		}
	}
	return 0;	
}