#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;
#define MAXM 1010 
vector<float> naomi ;
vector<float> ken ;
int n ;

int read_inp(){
	
	scanf("%d",&n) ;
	float temp ;
	for(int i=0;i<n;i++){
		scanf("%f",&temp) ;
		naomi.push_back(temp) ;
		
	}
	for(int i=0;i<n;i++){
		scanf("%f",&temp) ;
		ken.push_back(temp) ;
		
	}
	sort(naomi.begin(),naomi.end()) ;
	sort(ken.begin(),ken.end()) ;
}

int logic1(){
	int sn = 0 ;
	int sk =0 ;
	int en = n-1;
	int ek = n-1 ;
	int cov =0 ;
	int ans=0 ;
	while(cov<n){
		if(naomi[sn]<ken[sk]){
			sn++ ;
			ek-- ;
		}
		else if(naomi[sn]==ken[sk]){
			if(naomi[sn]<ken[ek]){
				sn++ ;
				ek-- ;
			}
			else if(naomi[sn]==ken[ek]){
				sn++ ;
				sk++ ;
			}
		}
		else if(naomi[sn]>ken[sk]){
			sn++ ;
			sk++ ;
			ans++ ;
		}
		cov++ ;
		
	}
	return ans ;
}


int logic2(){
	int sn = 0 ;
	int sk =0 ;
	int en = n-1;
	int ek = n-1 ;
	int cov =0 ;
	int ans=0 ;
	int i=0;int j=0;
	for(;i<n;i++){
		while(ken[j]<naomi[i] && j<n){
			j++ ;
			
		}
		if(j<n && ken[j]>=naomi[i]){
			ans++ ;
			j++ ;
		}
		else if(j==n-1 && ken[j]==naomi[i]){
			ans++ ;j++;}
	}
	return n-ans ;
}
int main(){
	int test ;
	FILE *fp = freopen("D-large.in","r",stdin) ;
	FILE *fp1 = freopen("d1.out","w",stdout) ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
		ken.clear() ;naomi.clear() ;
		read_inp() ;
		//cout<<"Case #"<<i<<logic1()<<" "<<logic2()<<endl ;
		printf("Case #%d: %d %d\n",i,logic1(),logic2()) ;
		//cout<<logic2()<<endl ;
		
		
	}
	/*double x = 5.52547 ;
	 double y = 2 ;
	double ans =x/y ;
	printf("%.8llf",ans );*/
}
