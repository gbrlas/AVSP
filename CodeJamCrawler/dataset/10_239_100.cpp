#include <iostream>
#include <vector>

using namespace std;

void solvecase (int index) 
{
    int m,n;
    int f[512][512],g[512][512];
    cin>>m>>n;
    for(int i=0; i<m; ++i){
        string s;
        cin>>s;
        for(int j=0; j<(int)s.length(); ++j)
        {
            for(int k=0; k<4; ++k)
                f[i][j*4+k]=((s[j]>='A'?10+s[j]-'A':s[j]-'0')>>(3-k))&1;   
        }
    }
    vector<int> a,b;
    while(true){
        int s=0,x,y;
        for(int j=0; j<n; ++j)
            g[0][j]=f[0][j]>=0?1:0;
        for(int i=1; i<m; ++i){
            g[i][0]=f[i][0]>=0?1:0;
            for(int j=1; j<n; ++j){
                if(f[i][j]==-1)
                    g[i][j]=0;
                else g[i][j]=1;
                if(g[i][j]&&f[i][j]==f[i-1][j-1]&&f[i-1][j]==f[i][j-1]&&f[i-1][j]!=f[i][j])
                    g[i][j]+=min(g[i-1][j-1],min(g[i-1][j],g[i][j-1]));
                if(g[i][j]>s){
                    s=g[i][j]; x=i; y=j;
                }
            }
        }
        if(s>1){
            if(a.size()==0||a.back()!=s)
            {
                a.push_back(s); b.push_back(1);
            }
            else ++b.back();
            for(int i=0; i<s; ++i)
                for(int j=0; j<s; ++j)
                    f[x-i][y-j]=-1;
        }
        else break;
    }
    int cnt1=0;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(f[i][j]!=-1) ++cnt1;
    cout<<"Case #"<<index<<": "<<a.size()+(cnt1>0)<<endl;
    for(int i=0; i<(int)a.size(); ++i)
        cout<<a[i]<<" "<<b[i]<<endl;
    if(cnt1) cout<<1<<" "<<cnt1<<endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
        solvecase(i);
    return 0;
}
