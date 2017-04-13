#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)

using namespace std;

const int maxn=103;

int n,t,ans;
int q[maxn];
bool f[maxn];

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	scanf("%d",&t);
	int i,j,v,a,b,x,y;
	char ch;
	for1(i,1,t){
		scanf("%d ",&n);
		for1(j,1,n){
			scanf("%c%d ",&ch,&v);
			f[j]=(ch=='O');
			q[j]=v;
		}
		ans=0;
		a=b=1;
		x=y=1;
		while (a<=n && !f[a])a++;
		while (b<=n && f[b])b++;
		while (a<=n || b<=n){
			ch=0;
			if (a<=n){
				if (x==q[a]){
					if (a<b){
						a++;
						while (a<=n && !f[a])a++;
						ch=1;
						//cout<<"Opush ";
					}
				}else if (x<q[a]){
					x++;
					//cout<<"Oright ";
				}
				else {
					x--;
					//cout<<"Oleft ";
				}
			}
			if (b<=n){
				if (y==q[b]){
					if (ch==0 && b<a){
						b++;
						while (b<=n && f[b])b++;
						//cout<<"Bpush ";
					}
				}else if (y<q[b]){
					y++;
					//cout<<"Bright ";
				}
				else {
					y--;
					//cout<<"Bleft ";
				}
			}
			ans++;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
