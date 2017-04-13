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

const int maxn=1003;

int n,t;
int pt[maxn];
bool f[maxn];
double ay[maxn];

double work(int q[],int n,double v){
	int i,k,t;
	memset(f,0,sizeof(f));
	for1(i,1,n)swap(q[i],q[rand()%i+1]);
	for1(i,1,n){
		if (!f[i]){
			t=0;
			k=i;
			while (!f[k]){
				f[k]=true;
				k=q[k];
				t++;
			}
			if (t!=n)v+=ay[t];else return work(q,n,v+1);
		}
	}
	return v;
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	scanf("%d",&t);
	int i,j,k,v,ans;
	for1(i,1,t){
		scanf("%d",&n);
		for1(j,1,n)scanf("%d",&pt[j]);
		memset(f,0,sizeof(f));
		ans=0;
		for1(j,1,n){
			if (!f[j]){
				v=0;
				k=j;
				while (!f[k]){
					v++;
					f[k]=true;
					k=pt[k];
				}
				if (v!=1)ans+=v;
			}
		}
		printf("Case #%d: %d.000000\n",i,ans);
	}
	/*srand(time(NULL));
	ay[1]=0;
	ay[2]=2;
	int i,j,k,t=1000;
	n=30;
	for1(i,2,n){
		ay[i]=0;
		for1(j,1,t){
			for1(k,1,i)pt[k]=k;
			ay[i]+=work(pt,i,1);
		}
		ay[i]/=t;
	}
	for1(i,1,n)cout<<i<<':'<<ay[i]<<endl;*/
	return 0;
}
