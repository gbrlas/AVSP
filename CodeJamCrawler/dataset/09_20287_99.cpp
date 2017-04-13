#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map< string, int > app;

string wh1[5010];
bool wh[20][30];
int l, n, m;

int main(){
	cin>>l>>n>>m;
	for ( int i=0; i<n; i++ ){
		string s;
		cin>>wh1[i];
	}
	for ( int i=0; i<m; i++ ){
		string s;
		cin>>s;
		int t=0;
		memset( wh, false, sizeof( wh ) );
		for ( int j=0; j<l; j++ )
			if ( s[t]!='('){
				wh[j][s[t]-'a']=true; t++;
			}else{
				t++;
				while ( t<s.size() && isalpha(s[t]) ){
					wh[j][s[t]-'a']=true; t++;
				}
				t++;
			}
		int ans=0;
		for ( int j=0; j<n; j++ ){
			bool ok=true;
			for ( int k=0; k<l; k++ )
				if ( ! wh[k][wh1[j][k]-'a'] ){
					ok=false; break;
				}
			if ( ok ) ans++;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
}
