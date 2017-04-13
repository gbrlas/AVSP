#include <iostream>

using namespace std;

bool valid(int f[][55],int k,int v,int x,int y)
{
    int g[115][115];
    for(int i=1; i<=v; ++i)
        for(int j=1; j<=v; ++j)
            g[i][j]=-1;
    for(int i=1; i<=k; ++i)
        for(int j=1; j<=k; ++j)
            g[i+x][j+y]=f[i][j];
    for(int i=1; i<=v; ++i)
        for(int j=1; j<=i; ++j){
            if(g[i][j]==-1||g[j][i]==-1||g[i][j]==g[j][i])
                continue;
            return false;
        }
    for(int i=1; i<=v; ++i)
        for(int j=v+1-i; j>=1; --j){
            if(g[i][j]==-1||g[v+1-j][v+1-i]==-1||g[i][j]==g[v+1-j][v+1-i])
                continue;
            return false;
        }
    return true;
}

void solvecase()
{
    int k,f[55][55];
    cin>>k;
    for(int i=1; i<=k; ++i){
        int j=0;
        while(j<i){
            int num; cin>>num;
            f[i-j][j+1]=num;
            ++j;
        }
    }
    for(int i=k-1; i; --i){
        int j=i;
        while(j){
            int num; cin>>num;
            f[k-(i-j)][k+1-j]=num;
            --j;
        }
    }
    for(int v=k; v<=10*k; ++v){
        for(int x=0; x+k<=v; ++x)
            for(int y=0; y+k<=v; ++y)
                if(valid(f,k,v,x,y)){
                    cout<<(v+k)*(v-k);
                    return ;
                }
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i){
        cout<<"Case #"<<i<<": ";
        solvecase();
        cout<<endl;
    }
    return 0;
}
