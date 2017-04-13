#include<iostream>
#include<algorithm>


int main(){
	freopen("bs.out","w",stdout);
  int T;
  scanf("%d",&T);
  int cs;
  double c,f,x;
  for(cs=1;cs<=T;cs++){
	scanf("%lf %lf %lf",&c,&f,&x);
    double now =2;
    double ans = 1000000;
    double pre=0;    
    for(int i=0;i<100000;i++){
		if(x/now +pre < ans){
	      ans = x/now+pre;
		 
        }else break;
        pre+=c/now;
		now+=f;
    }
    printf("Case #%d: %.06lf\n",cs,ans);
  }

	return 0;
} 
