#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string s[555];
int g[555][555],dc[555][555],dr[555][555];

int main() {
	ifstream cin("input.txt");
	freopen("output.txt","w",stdout);
	//ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int cid=1;cid<=cc;++cid) {
	    int r,c,d;
	    memset(g,0,sizeof(g));
	    cin>>r>>c>>d;
	    for(int i=0;i<r;++i) cin>>s[i];
	    for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j)
            {
                g[i][j]=d+(s[i-1][j-1]-'0');
                dc[i][j]=dc[i-1][j]+g[i][j];
                dr[i][j]=dr[i][j-1]+g[i][j];
            }
	    int ans = 0;
	    for(int k=3;k<=min(r,c);++k)
	    {
	        for(int i=1;i+k-1<=r;++i)
                for(int j=1;j+k-1<=c;++j)
                {
                    int t=(k-1)*((dc[i+k-2][j]-dc[i][j])-(dc[i+k-2][j+k-1]-dc[i][j+k-1]));
                    for(int p=j+1,q=j+k-2;p<q;++p,--q)
                    {
                        int dis=q-p;
                        t+=(dc[i+k-1][p]-dc[i-1][p])*dis;
                        t-=(dc[i+k-1][q]-dc[i-1][q])*dis;
                    }
                    if(t!=0) continue;
                    t=(k-1)*((dr[i][j+k-2]-dr[i][j])-(dr[i+k-1][j+k-2]-dr[i+k-1][j]));
                    for(int p=i+1,q=i+k-2;p<q;++p,--q)
                    {
                        int dis=q-p;
                        t+=(dr[p][j+k-1]-dr[p][j-1])*dis;
                        t-=(dr[q][j+k-1]-dr[q][j-1])*dis;
                    }
                    if(t!=0) continue;
                    ans=max(ans,k);
                }
	    }
	    if(ans>=3) printf("Case #%d: %d\n",cid,ans);
	    else printf("Case #%d: IMPOSSIBLE\n",cid);
	}
	return 0;
}
