#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){
	int T,N,i,j,k,n,m;
	char c[100][101];
	double wp[100]={0}, owp[100]={0}, oowp[100]={0},temp[100];
	FILE * pf;
	pf = fopen("out.txt","w");
	scanf("%i ", &T);
	for(int _=1; _<=T; _++){
		fprintf(pf, "Case #%i:\n", _);
		printf("Case #%i:\n", _);
		scanf("%i ", &N);
		for(i=0;i<N;i++){
			wp[i]=0;
			cin >> c[i];
			for(j=0,n=0;j<N;j++){
				if(c[i][j]=='1'){
					wp[i]++;
					n++;
				}
				else if(c[i][j] == '0'){
					n++;
				}
			}
			wp[i]/=n;
		}
		for(i=0;i<N;i++){
			owp[i]=0;
			for(j=0,n=0;j<N;j++){
				temp[j]=0;
				if(c[i][j]=='1' || c[i][j]=='0'){
					for(k=0,m=0;k<N;k++){
						if(i==k)
							continue;
						if(c[j][k]=='1'){
							temp[j]++;
							m++;
						}
						else if(c[j][k] == '0'){
							m++;
						}
					}
					owp[i]+=(temp[j]/m);
					n++;
				}
			}
			owp[i]/=n;
		}
		for(i=0;i<N;i++){
			oowp[i]=0;
			for(j=0,n=0;j<N;j++){
				if(c[i][j]=='1' || c[i][j] == '0'){
					oowp[i]+=owp[j];
					n++;
				}
			}
			oowp[i]/=n;
		}
		for(i=0;i<N;i++){
			fprintf(pf, "%lf\n", 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
			printf("%lf\n", 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
		}
	}
	fclose(pf);
	return 0;
}