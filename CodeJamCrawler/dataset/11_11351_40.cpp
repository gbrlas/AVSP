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
		int x=GI;
		int y=GI;
		string ar[x];
		for(int i=0;i<x;i++)
			cin>>ar[i];
		int visited[x][y];
		int dx[]={0,0,1,1};
		int dy[]={0,1,0,1};
		memset(visited,-1,sizeof(visited));
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(ar[i][j]=='#'){
					int flag=0;
					for(int p=0;p<4;p++){
						int newx=i+dx[p];
						int newy=j+dy[p];
						if(newx >=0 && newy >=0 && newx < x && newy < y && visited[newx][newy]==-1 && ar[newx][newy]=='#'){
							flag=1;
						}
						else {
							flag=0;break;
						}
					}
					if(flag==1){
//						cout<<i<<" ---  "<<j<<endl;
						for(int p=0;p<4;p++){
							int newx=i+dx[p];
							int newy=j+dy[p];
	//						cout<<"\t"<<newx <<" "<<newy<<endl;
							visited[newx][newy]=1;
							if(p==0 || p==3)
								ar[newx][newy]='/';
							else 
								ar[newx][newy]='\\';
						}
					}
				}
			}
		}
		int flag=0;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(ar[i][j]=='#'){
					flag=1;break;
				}
			}
		}
		cout<<"Case #"<<kase<<":"<<endl;
		if(flag==1){
			cout<<"Impossible"<<endl;
		}
		else{
			for(int i=0;i<x;i++){
				cout<<ar[i]<<endl;
			}
		}
		
	}
        GI;
    return 0;
}
