#include <cstdio>
#include <vector>

using namespace std;

int ans[1000];
int na,n;
int change[26][26];
int ok[26];
vector<int> opp[26];
char s[100];

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		printf("Case #%d: ", T);
		for ( int i=0; i<26; ++i )
			opp[i].clear();
		for ( int i=0; i<26; ++i )
			for ( int j=0; j<26; ++j )
				change[i][j]=-1;
		scanf("%d",&n);
		for ( int i=0; i<n; ++i ){
			scanf("%s", s);
			change[s[0]-'A'][s[1]-'A']=change[s[1]-'A'][s[0]-'A']=s[2]-'A';
		}
		scanf("%d",&n);
		for ( int i=0; i<n; ++i ){
			scanf("%s",s);
			opp[s[0]-'A'].push_back(s[1]-'A');
			opp[s[1]-'A'].push_back(s[0]-'A');
		}
		scanf("%d",&n);
		scanf("%s",s);
		memset(ans,0,sizeof(ans));
		memset(ok,0,sizeof(ok));
		na=0;
		for ( int i=0; i<n; ++i ){
			ans[na++]=s[i]-'A';
			if ( na>1 && change[ans[na-1]][ans[na-2]]!=-1){
				for ( int i=0; i<opp[ans[na-2]].size(); ++i )
					--ok[opp[ans[na-2]][i]];
				ans[na-2]=change[ans[na-1]][ans[na-2]];
				--na;
			}
			if ( ok[ans[na-1]] ){
				memset(ok,0,sizeof(ok));
				na=0;
			}
			if ( na>0 )
				for ( int i=0; i<opp[ans[na-1]].size(); ++i )
					++ok[opp[ans[na-1]][i]];
		}
		printf("[");
		for ( int i=0; i<na; ++i ){
			if ( i ) printf(", ");
			printf("%c",'A'+ans[i]);
		}
		printf("]\n");
	}
}
