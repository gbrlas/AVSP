#include<stdio.h>
#include<math.h>

bool ZS(double a){
	if(a == (int)a)return true;
	return false;
}

int main(){
	double i,n;
	int t= 0,T,Can;
	double Pd,Pg;
	char *temp[2] = {"Broken","Possible"};
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);

	while(t++<T){
		scanf("%lf%lf%lf",&n,&Pd,&Pg);
		Can = 0;
		if(Pd!=100&&Pg==100);
		else if(Pd!=0&&Pg==0);
		else{
			Pd/=100.0,Pg/=100.0;
			for(i=1;i<=n;i++)
				if(ZS(i*Pd)){
					Can = 1;
					break;
				}
		}
		printf("Case #%d: %s\n",t,temp[Can]);
	}
	
} 
