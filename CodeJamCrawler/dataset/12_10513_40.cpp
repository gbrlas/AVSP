#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back
#define mp make_pair
#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define disvec(v) { for(int vec_index=0;vec_index<v.size();vec_index++) cout<<v[vec_index]<<" "; cout<<endl;}
using namespace std;
typedef  long long LL;
typedef  long long ll;
int p10[10];
vector<int>graph[2000000+10];
vector<int>get(int i1){
	stringstream ss;
	ss<<i1;
	string temp;
	ss>>temp;
	set<int>ret;
	int len=temp.length();
	for(int i=1;i<len;i++){
		rotate(temp.begin(),temp.begin()+1,temp.end());
		if(temp[0]!='0'){
			int x=0;
			for(int j=0;j<len;j++){
				x*=10;
				x+=temp[j]-'0';
			}
			if(x!=i1)
				ret.insert(x);
		}
	}
	vector<int>re;
	set<int>::iterator it;
	for(it=ret.begin();it!=ret.end();it++)re.pb(*it);
	return re;
}
void precompute(){
	p10[0]=1;
	for(int i=1;i<10;i++)p10[i]=10*p10[i-1];
	for(int i=11;i<=2000000;i++){
		vector<int>temp=get(i);
		for(int j=0;j<temp.size();j++)
			graph[i].pb(temp[j]);
	}
}
int ok(int i,int j){
	stringstream s,s1;s<<i;
	string a,b;
	s>>a;
	s1<<j;s1>>b;
	if(a.length()!=b.length()){
		cout<<a<<" "<<b<<endl;
		return 0;
	}
	a+=a;
	if(a.find(b)!=-1)return 1;
	return 0;
}
int main(){
	INPUT;
	OUTPUT;
	precompute();
	int t=GI;
	for(int ca=1;ca<=t;ca++){
		int a=GI,b=GI;
		LL ret=0;
		for(int i=a;i<=b;i++){
			for(int j=0;j<graph[i].size();j++){
				if(graph[i][j]<=b && graph[i][j]>i){
					ret++;
				}
			}
		}
		cout<<"Case #"<<ca<<": "<<ret<<endl;	
	}	
	//GI;
	return 0;
}
