#include <algorithm> 
#include <numeric>
#include <cmath> 

#include <string> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 

using namespace std;
#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for( i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for( i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <PI> VP;

int n;
int t;
int na,nb;
pair< PI, bool> a[220];
//PI b[110];
int hh,mm;
int tt,i,j;
bool va[220];
//bool vb[110];
int ra,rb;

/*int go(int q,bool fa){
	int i;
	int res=0;

	if(fa){
		if(!va[q]){
			va[q]=1;
			int qq=0;
			For(i,1,nb){
				if(a[q].second+t<=b[i].first&&(!vb[i])){
					qq=go(i,0)+1;
					break;
				}
			}
			//if(qq==-1)va[q]=0;
			res=qq;
		}
	}else{
		if(!vb[q]){
			vb[q]=1;
			int qq=0;
			For(i,1,na){
				if(b[q].second+t<=a[i].first&&(!va[i])){
					qq=go(i,1)+1;
					break;
				}
			}
			//if(qq==-1)vb[q]=0;
			res=qq;
		}
	}


	return res;
}*/


int main(){
	freopen("in.txt","rt",stdin);
	//freopen("out.txt","wt",stdout);

	scanf("%d",&n);

	For(tt,1,n){
		scanf("%d%d%d",&t,&na,&nb);
		For(i,1,na){
			scanf("%d:%d",&hh,&mm);
			a[i].first.first=hh*100+mm;
			scanf("%d:%d",&hh,&mm);
			a[i].first.second=hh*100+mm;
			a[i].second=1;
		}
		For(i,na+1,na+nb){
			scanf("%d:%d",&hh,&mm);
			a[i].first.first=hh*100+mm;
			scanf("%d:%d",&hh,&mm);
			a[i].first.second=hh*100+mm;
			a[i].second=0;
		}

		Fill(va,0);

		sort(a,a+na+nb+1);
		ra=na;
		rb=nb;

		For(i,1,na+nb){
			if(!va[i]){
				va[i]=1;
				bool fa=a[i].second;
				int qt=a[i].first.second;

				j=i+1;

				while(j<=na+nb){
					if((a[j].first.first>=qt+t)&&(a[j].second!=fa)&&(!va[j])){
						va[j]=1;
						qt=a[j].first.second;
						fa=a[j].second;
						if(fa)ra--;
						else rb--;
					}
					j++;
				}
			}
		}

		/*For(i,1,na){
			int qq=go(i,1);
			rb-=(qq+1)/2;
			ra-=qq/2;

		}

		For(i,1,nb){
			int qq=go(i,0);
			ra-=(qq+1)/2;
			rb-=qq/2;

		}*/

		printf("Case #%d: %d %d\n",tt,ra,rb);

	}

	
	return 0;
}