// source code of submission 738516, Zhongshan University Online Judge System
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <list>
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
const int maxsize =210;
template<class T>
void show(T a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

char ma[maxsize][maxsize];
int w[maxsize];
int all[maxsize];
double wp[maxsize];
double owp[maxsize];
double oowp[maxsize];
double rpi[maxsize];
void solve(int n){
	for(int i=0;i<n;i++){
		all[i]=w[i]=0;
		for(int j=0;j<n;j++){
			if(ma[i][j]!='.'){
				all[i]++;
				if(ma[i][j]=='1')
					w[i]++;
			}	
		}
		wp[i]=1.0*w[i]/all[i];
	}	
	for(int i=0;i<n;i++){
		int c=0;
		owp[i]=0;
		for(int j=0;j<n;j++){
			if(i!=j&&ma[i][j]!='.'){
				c++;
				if(ma[j][i]=='1'){
					owp[i]+=1.0*(w[j]-1)/(all[j]-1);
				}else{
					owp[i]+=1.0*(w[j])/(all[j]-1);
				}
			}
		}	
		owp[i]/=c;
	}
	for(int i=0;i<n;i++){
		int c=0;
		oowp[i]=0;
		for(int j=0;j<n;j++){
			if(ma[i][j]!='.'){
				c++;
				oowp[i]+=owp[j];
			}
		}
		oowp[i]/=c;
	}
	for(int i=0;i<n;i++){
		rpi[i]=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
	}
}




int main(){
	int t,haha=1;
	for(cin>>t;t;--t,haha++){
		printf("Case #%d:\n",haha);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%s",ma[i]);
		solve(n);
		//show(wp,n); show(owp,n); show(oowp,n);
		for(int i=0;i<n;i++){
			printf("%.8lf\n",rpi[i]);
		}
	}	
	
		
	return 0;
}






















