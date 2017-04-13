#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#define clr(a) memset(a,0,sizeof(a));
using namespace std;
const int maxsize =110;
const int inf = 0x7fffffff;
template<class T>
void show(T a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
struct node{
	int i,p;
};
node order[2][maxsize];
int solve(int n){
	int l[2],t;
	l[0]=l[1]=t=0;
	int c[2];
	c[0]=c[1]=1;
	for(int i=1;i<=n;i++){
		int r=1;
		if(order[0][c[0]].i==i) r=0;
		int dt=order[r][c[r]-1].p-order[r][c[r]].p;
		dt=abs(dt);
		//cout<<"r="<<r<<" dt="<<dt<<endl;
		if(t-l[r]<dt){
			t=l[r]+dt;
		} 
		t++;
		l[r]=t;
		c[r]++;
	}
	return t;
}



int main(int argc, char *argv[])
{
	freopen("A-small.in","r",stdin);
	freopen("out.txt","w",stdout);
	int n,p;
	char ch;
	int t;
	cin>>t;
	for(int haha=1;haha<=t;haha++){
		scanf("%d",&n);
		int io=1,ib=1;
		for(int i=1;i<=n;i++){
			do{ ch=getchar();
			}while(ch!='O'&&ch!='B');
			scanf("%d",&p);
			if(ch=='O'){
				order[0][io].p=p;
				order[0][io].i=i;
				io++;
			}else{
				order[1][ib].p=p;
				order[1][ib].i=i;
				ib++;
			}
		}
		order[0][0].p=order[1][0].p=1;
		order[0][io].i=order[1][ib].i=-1;
		//cout<<"io="<<io<<" ib="<<ib<<endl;
		int ans=solve(n);
		printf("Case #%d: %d\n",haha,ans);
	}
	
   
    //system("PAUSE");
    return 0;
}

