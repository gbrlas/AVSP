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
#define RepV(i,v) for (i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a)) 
#define All(c) (c).begin(),(c).end()
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
typedef pair <int,int> PI;
typedef pair <PI,int> PII;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector < PI > VP;

int n,m,nn,a;
int i,j;
int tt,t;
int x,y,k;
string s;
VI q;
int mx;





int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	cin>>t;

	For(tt,1,t){

		cin>>k;
		cin>>s;

		q.clear();
		For(i,0,k-1) q.push_back(i);

		mx=s.length();


		do{
			string w=s;
			int x=0;

			For(i,0,s.length()-1){
				w[i]=s[k*(i/k)+q[i%k]];
			}

		//	cout<<w<<endl;

			For(i,1,s.length()-1){
				if(w[i]!=w[i-1])x++;
			}

			x++;

			if(x<mx)mx=x;

		}while (next_permutation(All(q)));

		cout<<"Case #"<<tt<<": "<<mx<<endl; 



	}




	
	return 0;
}