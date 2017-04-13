#include<stdio.h>
#include<math.h>

__int64 gcd(__int64 a,__int64 b){  for(__int64 t;b;){t=a%b,a=b,b=t;}return a;	}

int main(){
	__int64 i,n;
	int t= 0,T,Can;
	__int64 Pd,Pg;
	__int64 k,m;
	char *temp[2] = {"Broken","Possible"};
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);

	while(t++<T){
		scanf("%I64d%I64d%I64d",&n,&Pd,&Pg);
		Can = 0;
		if(Pd!=100&&Pg==100);
		else if(Pd!=0&&Pg==0);
		else{
			k = 100;
			m = gcd(k,Pd);
			k/=m;
			if(n>=k)Can = 1;
		}
		printf("Case #%d: %s\n",t,temp[Can]);
	}
	
} 
//1000000000000000
