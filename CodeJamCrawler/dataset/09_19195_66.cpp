#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
string al="abcdefghijklmnopqrstuvwxyz";
vector <int> cl;
vector <vector <int> > gra;
vector <vector <int> > zyun;
bool sumi[11000];
void dfs(int a,int b){
//	cout<<a<<' '<<b<<'\n';
	if(sumi[a]) return;sumi[a]=true;zyun[b].pb(a);
//	cout<<a<<' '<<b<<'\n';
	for(int i=0;i<gra[a].size();i++) dfs(gra[a][i],b);
	return;
}
int main()
{
	int i,j,k,l,n;cin>>n;
	for(i=0;i<n;i++){
		int ma[110][110];int h,w;
		char m[110][110];
		gra.clear();zyun.clear();
		cin>>h>>w;
		for(j=0;j<h*w;j++) gra.pb(cl);for(j=0;j<28;j++) zyun.pb(cl);
		for(j=0;j<h;j++) for(k=0;k<w;k++) cin>>ma[j][k];
//		cout<<"a\n";
		for(j=0;j<h;j++) for(k=0;k<w;k++){
			int a=0,b=100000;
			for(l=0;l<4;l++){
				int x=j+dx[l],y=k+dy[l];
				if(x<0 || y<0 || x>=h || y>=w) continue;
				if(b>ma[x][y]){a=l;b=ma[x][y];}
			}
			if(b<ma[j][k]){gra[j*w+k].pb((j+dx[a])*w+k+dy[a]);gra[(j+dx[a])*w+k+dy[a]].pb(j*w+k);}
		}
/*		cout<<"b\n";
		for(j=0;j<h*w;j++){
			for(k=0;k<gra[j].size();k++) cout<<gra[j][k]<<' ';
			cout<<'\n';
		}
		cout<<"d\n";
*/		int f=0;
		memset(sumi,false,sizeof(sumi));
		for(j=0;j<h*w;j++){
			if(sumi[j]) continue;dfs(j,f);f++;
		}
		for(j=f;j<28;j++) zyun[j].pb(99999);
//		cout<<"c\n";
		for(j=0;j<zyun.size();j++) sort(zyun[j].begin(),zyun[j].end());
		sort(zyun.begin(),zyun.end());
		for(j=0;j<zyun.size();j++) for(k=0;k<zyun[j].size();k++){
//			cout<<j<<' '<<k<<'\n';
			if(zyun[j][k]>80000) break;
			m[zyun[j][k]/w][zyun[j][k]%w]=al[j];
		}
		cout<<"Case #"<<i+1<<":\n";
		for(j=0;j<h;j++) for(k=0;k<w;k++){
			cout<<m[j][k];
			if(k==w-1) cout<<'\n';else cout<<' ';
		}
	}
	return 0;
}
