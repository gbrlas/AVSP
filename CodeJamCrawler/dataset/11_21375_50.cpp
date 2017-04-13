#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

string s[11000];
bool have[11000][26];
map<string,int> app;
int kd[11000];
bool add[11000];
int tot[11000];
string now[11000];
int n,m;

int main(){
	int test=0;
	cin>>test;
	for ( int T=1; T<=test; ++T ){
		cin>>n>>m;
		for ( int i=0; i<n; ++i ){
			cin>>s[i];
			for ( int j=0; j<26; ++j )
				have[i][j]=0;
			for ( int j=0; j<s[i].size(); ++j )
				have[i][s[i][j]-'a']=1;
		}
		cout<<"Case #"<<T<<":";
		int tkd=0;
		for ( int i=0; i<m; ++i ){
			string t;
			cin>>t;
			app.clear();
			for ( int j=0; j<n; ++j ){
				now[j]=s[j];
				for ( int k=0; k<s[j].size(); ++k )
					now[j][k]='*';
				if ( app[now[j]]==0 )
					app[now[j]]=++tkd;
				kd[j]=app[now[j]]-1;
			}
			memset(tot,0,sizeof(tot));
			for ( int j=0;j<26;++j ){
				memset(add,0,sizeof(add));
				app.clear(); tkd=0;
				for ( int k=0; k<n; ++k )
					if ( have[k][t[j]-'a'] )
						add[kd[k]]=1;
				for ( int k=0; k<n; ++k )
					if ( add[kd[k]] && ! have[k][t[j]-'a'] )
						tot[k]++;
				for ( int k=0; k<n; ++k ){
					for ( int p=0; p<s[k].size(); ++p )
						if ( s[k][p]==t[j] )
							now[k][p]=t[j];
					if ( app[now[k]]==0 )
						app[now[k]]=++tkd;
					kd[k]=app[now[k]]-1;					
				}
			}
			string ans;
			int MM=-1;
			for ( int j=0; j<n; ++j )
				if ( tot[j]>MM ){
					MM=tot[j]; ans=s[j];
				}
			cout<<' '<<ans;
		}
		cout<<endl;
	}
}
