#include <string>
#include <iostream>

using namespace std;

const string a="welcome to code jam.";
const int mo=10000;

int ans;
int f[1000][20];

int main(){
	int test=0;
	scanf("%d\n", &test);
	for ( int T=1; T<=test; T++ ){
		string s;
		getline( cin, s );
		int n=s.size();
		memset( f, 0, sizeof( f ) );
		f[0][0]=1;
		ans=0;
		for ( int i=0; i<n; i++ ){
			for ( int j=0; j<19; j++ ){
				f[i+1][j]=(f[i+1][j]+f[i][j])%mo;
				if ( s[i]==a[j] )
					f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%mo;
			}
			ans=(ans+f[i][19])%mo;
		}
		ans=(ans+f[n][19])%mo;
		printf("Case #%d: %04d\n", T, ans);
	}
}
