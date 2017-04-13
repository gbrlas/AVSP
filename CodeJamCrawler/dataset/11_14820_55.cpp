#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <ctime>
#include <complex>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define sqr(a) ((a)*(a))

using namespace std;

typedef long long LL;
typedef pair<int,int> PAIR;

const int maxn=103;
const int inf=2000000001;

int t,n;
int net[maxn][maxn];
double a[maxn],b[maxn],c[maxn];
	
void work(){
	int i,j,k,v1,v2,v3;
	for1(i,1,n){
		v1=v2=0;
		for1(j,1,n){
			if (net[i][j]>0)v1++;
			else if (net[i][j]<0)v2++;
		}
		a[i]=double(v1)/double(v1+v2);
			
		v3=v1+v2;
		b[i]=0;
		for1(j,1,n){
			if (net[i][j]!=0){
				v1=v2=0;
				for1(k,1,n){
					if (k==i)continue;
					if (net[j][k]>0)v1++;
					else if (net[j][k]<0)v2++;
				}
				b[i]+=double(v1)/double(v1+v2);
			}
		}
		b[i]/=v3;
	}
	for1(i,1,n){
		c[i]=0;
		v1=0;
		for1(j,1,n){
			if (net[i][j]!=0){
				v1++;
				c[i]+=b[j];
			}
		}
		c[i]/=v1;
	}
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i,j,k;
	char ch;
	for1(i,1,t){
		cin>>n;
		getchar();
		for1(j,1,n){
			for1(k,1,n){
				ch=getchar();
				if (ch=='.')net[j][k]=0;
				else if (ch=='1')net[j][k]=1;
				else net[j][k]=-1;
			}
			getchar();
		}
		printf("Case #%d:\n",i);
		work();
		for1(j,1,n){
			printf("%.10lf\n",0.25*a[j]+0.5*b[j]+0.25*c[j]);
		}
	}
    return 0;
}
