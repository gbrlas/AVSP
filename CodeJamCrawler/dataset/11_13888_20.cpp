// source code of submission 738516, Zhongshan University Online Judge System
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
const int maxsize =50010;
template<class T>
void show(T a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool ok(int a1,int a2,int c){
	int g=gcd(a1,a2);
	return c%g==0;
}

bool solve(int n,int pg,int pd){
	if(pg==0) return pd==0;
	else if(pg==100) return pd==100;
	else {
		int g=gcd(pd,100);
		return n>=100/g;
	}




	int pp=100;
	int g=gcd(pp,pd);
	int check=100/g;
	for(int p=1;p<=n;p++){
		if(p%check==0){
			int c=p*pd-p*pg;
			int a1=100,a2=pg;
			if(ok(a1,a2,c)){
				return true;
			}
		}
	}
	return false;
}



int main(){
	int t,haha=1;
	for(cin>>t;t;--t,haha++){
		int n,p,g;
		scanf("%d%d%d",&n,&p,&g);
		bool ok=solve(n,g,p);
		if(ok){
			printf("Case #%d: Possible\n",haha);
		}else{
			printf("Case #%d: Broken\n",haha);
		}
	}	
	
		
	return 0;
}






















