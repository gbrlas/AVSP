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
int R,N,M,K;
int ahora[5];
bool res;
vector <int> posi;
int Ks[10];
int pote(int a,int b){
	if(b==0)return 1;
	int re=1;
	f(i,0,b)re*=a;
		return re;
}
bool es(int num,string cad){
	//cout<<num<<" d"<<endl;
	if(num==1)return true;
	f(i,0,cad.size())ahora[i]=cad[i]-'0';
		f(i,cad.size(),3)ahora[i]=1;
	f(mask,0,(1<<N)){
		int r=1;
		f(i,0,N)if(mask&(1<<i))r*=ahora[i];
		if(r==num)return true;
	}
	return false;
}

void go(int pos,int tengo,string cad){
	//cout<<pos<<" x "<<tengo<<endl;
	if(res) return;
	if(tengo==N){
	//	cout<<cad<<endl;
		bool pode=true;
		f(i,0,K)
			if(!es(Ks[i],cad))pode=false;
		
		//cout<<pode<<" da"<<endl;
		if(pode){
			res=true;
			cout<<cad<<endl;			
			return;
		}
	}
	
	if(pos>=posi.size())return;
	if(tengo > N)return ;
	//cogo
	//ahora[tengo]=posi[pos];
	char c='0'+posi[pos];
	go(pos,tengo+1,cad+c);

	go(pos+1,tengo+1,cad+c);

	go(pos+1,tengo,cad);

}
int main(){

	int cases;
	cin>>cases;
	f(t,1,cases+1){
	cin>>R>>N>>M>>K;
	cout<<"Case #"<<t<<":"<<endl;
	f(j,2,M+1)posi.pb(j);
			f(i,0,R){
				//random_shuffle(all(posi));

			f(j,0,K)cin>>Ks[j];
			res=false;
			go(0,0,"");
			if(!res){
				cout<<"no"<<endl;
				f(ii,0,N)cout<<2;
				cout<<endl;
			}
		}
	}
	return 0;
}
