#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
const int maxsize =1100;
const int inf = 0x7fffffff;
template<class T>
void show(T a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
inline int getbit(const int &x,const int &i){
	return ((x>>i)&1);
}
int add(int x,int y){
	int ans=0;
	for(int i=0;i<32;i++){
		int bit=getbit(x,i)+getbit(y,i);
		if(bit>1) bit=0;
		ans+=(bit<<i);
	}
	return ans;
}
int a[maxsize];
int solve(int n){
	int s=0,mi=inf,sum=0;
	for(int i=0;i<n;i++){
		mi=min(mi,a[i]);
		s=add(s,a[i]);
		sum+=a[i];
	}
	if(s==0) return sum-mi;
	else return -1;
}




int main(int argc, char *argv[])
{
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int haha=1;haha<=t;haha++){
		printf("Case #%d: ",haha);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
		}
		int ans=solve(n);
		if(ans>0){
			printf("%d\n",ans);
		}else{
			puts("NO");
		}
	}
	
   
    //system("PAUSE");
    return 0;
}

