#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
int N,P,joga;
bool gana[2000],pierde[2000];
void pr(vector <int> v){
	f(i,0,v.size())cout<<v[i]<<" ";
	cout<<endl;
}

vector <int> simula(vector <int> v){
	//cout<<"ver"<<endl;
	//pr(v);
	if(v.size()==1)return v;
	
	vector <int>  g,p;
	for(int i=0;i<v.size();i+=2){
		if(v[i] < v[i+1]){
			g.pb(v[i]);
			p.pb(v[i+1]);
		}
		else
		{
			g.pb(v[i+1]);
			p.pb(v[i]);
		}
	}
	g=simula(g);
	p=simula(p);
	f(i,0,p.size())
		g.pb(p[i]);
	return g;
}
int main(){
	int cases;
	cin>>cases;
	f(t,1,cases+1){
		clr(gana,false);
		clr(pierde,false);
		cin>>N>>P;	
		joga=(1<<N);
		//para que gane 'i'
		f(i,0,joga){
			vector <int> v;
			v.pb(i);
			f(j,i+1,joga)
				v.pb(j);
			f(j,0,i)
				v.pb(j);
			//if(i==7)pr(v);
			v=simula(v);
			//if(i==7)pr(v);
			//if(i==7){
			//	cout<<gana[i]<<endl;
			//	cout<<i<<" "<<P<<endl;
			//}
			f(j,0,v.size())if(v[j]==i && j<P) gana[i]=true;
		}
		//cout<<gana[7]<<endl;
		//para que pierda 'i'
		f(i,0,joga){
			vector <int> v;
			v.pb(i);
			f(j,0,i)
				v.pb(j);
			f(j,i+1,joga)
				v.pb(j);

			v=simula(v);
			f(j,0,v.size())if(v[j]==i && j>=P) pierde[i]=true;
		}

		int r1,r2;
		//cout<<gana[7]<<endl;
		f(i,0,joga)if(gana[i])r1=i;
		f(i,0,joga)if(!pierde[i])r2=i;

		cout<<"Case #"<<t<<": ";
		cout<<r2<<" "<<r1<<endl;
	}
	return 0;

}
