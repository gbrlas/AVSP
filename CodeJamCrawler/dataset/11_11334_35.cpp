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

#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef  long long LL;
typedef  long long ll;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=GI;
	int kase=0;
	while(t--){
		kase++;
		int n=GI;
		string ar[n];
		for(int i=0;i<n;i++)
			cin>>ar[i];
		int wins[n];
		int loses[n];
		int opploses[n];
		int totalgames[n];
		int winag[n][n];
		vector<int>graph[200];
		for(int i=0;i<n;i++){
			wins[i]=0;
			loses[i]=0;
			opploses[i]=0;
			totalgames[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				winag[i][j]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ar[i][j]=='.'){
					
				}
				if(ar[i][j]=='1'){
					wins[i]++;
					totalgames[i]++;
					graph[i].pb(j);
				}
				if(ar[i][j]=='0'){
					totalgames[i]++;
					loses[i]++;
					opploses[i]++;
					graph[i].pb(j);
				}
			}
		}
		double wp[n];
		double owp[n];		
		double oowp[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				oowp[i][j]=0.00;
			}
		}
		for(int i=0;i<n;i++){
			wp[i]=0.00000000;
			owp[i]=0.00000000;
		}
		int val;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ar[i][j]=='.')continue;
				if(ar[j][i]=='1'){
					val=1;
				}
				else val=0;
				winag[i][j]=wins[j]-val;
				oowp[i][j]=(winag[i][j]/((double)(totalgames[j]-1)));
			}
		}/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<oowp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<oowp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=0;i<n;i++){
			wp[i]=wins[i]/((double)totalgames[i]);
		}
		for(int i=0;i<n;i++){
			double temp=0.0;
			for(int j=0;j<graph[i].size();j++){
				int index=graph[i][j];
				temp+=oowp[i][index];

			}
			temp=temp/((double)totalgames[i]);
			owp[i]=temp;
		}
		double ooowp[n];
		double ans[n];
		for(int i=0;i<n;i++){
			ooowp[i]=0.0;
			ans[i]=0.0;
		}
		for(int i=0;i<n;i++){
			double temp=0.0;
			for(int j=0;j<n;j++){
				if(ar[i][j]!='.')
					temp+=owp[j];
			}
			ooowp[i]=temp/(double)totalgames[i];
		}
		cout.precision(9);
		for(int i=0;i<n;i++){
			ans[i]=.25*wp[i] + .50 *owp[i] + .25*ooowp[i];
		}
		cout<<"Case #"<<kase<<":"<<endl;
		for(int i=0;i<n;i++)
			cout<<ans[i]<<endl;
	}
        GI;
    return 0;
}
