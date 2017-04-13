#include<stdio.h>
#include<string.h>

void Print(char *s){
	int  len = strlen(s);
	int  i;
	i=len-1;
	while(s[i]=='0')i--;
	s[i+1] = 0;
	puts(s);
}

int main(){
	int i,j,n;
	int T,t = 0;
	char a[101][101];
	double WP[101];
	int WinTime[101];
	int ContestTime[101];
	double OWP[101];
	double OOWP[101];
	double RPI[101];
	char temp[100];
	freopen("A-large.in","r",stdin);
	freopen("woniu.out","w",stdout); 
	scanf("%d",&T);
	while(t++<T){
		printf("Case #%d:\n",t);
		
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%s",a[i]);
		 
		for(i=0;i<n;i++){
			WinTime[i] = 0;
			ContestTime[i] = 0;
			for(j=0;j<n;j++)
				if(a[i][j]!='.'){
					if(a[i][j]=='1')WinTime[i]++;
					ContestTime[i]++;
				}
			WP[i] = WinTime[i]*1.0/ContestTime[i];
		}
		for(i=0;i<n;i++){
			double sum = 0;
			
			for(j=0;j<n;j++)if(a[i][j]!='.'){
				sum +=  (WinTime[j]-(a[i][j]=='0'))*1.0/(ContestTime[j]-1);
			}
			OWP[i] = sum/ContestTime[i];
		}

		for(i=0;i<n;i++){
			double sum = 0;
			for(j=0;j<n;j++)if(a[i][j]!='.'){
				sum += OWP[j];
			}
			OOWP[i] = sum/ContestTime[i];
		}
		for(i=0;i<n;i++){
			RPI[i] = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
			sprintf(temp,"%.12lf",RPI[i]);
			Print(temp);
		}
		
	} 
	return 0;
}
