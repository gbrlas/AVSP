#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;

int parent[10000],rank[10000];

int Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++; 
    }
}

void Solve(){
    int H,W;
    cin>>H>>W;
    
    int M[100][100];
    
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            cin>>M[i][j];
    
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            Make_Set(i*W+j);
            
    int dr[]={-1,0,0,1},dc[]={0,-1,1,0};
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int R,C,h=-1;
            
            for(int k=0;k<4;k++){
                int r=i+dr[k],c=j+dc[k];
                
                if(r>=0 && r<H &&  c>=0 && c<W && M[r][c]<M[i][j]){
                    if(h==-1){
                        h=M[r][c];
                        R=r;
                        C=c;
                    }else if(M[r][c]<h){
                        h=M[r][c];
                        R=r;
                        C=c;
                    }
                }
            }
            
            if(h!=-1) Union(i*W+j,R*W+C);
        }
    }
    
    char ans[100][100];
    bool done[100][100];
    int cont=0;
    memset(done,false,sizeof(done));
    
    for(char c='a';cont<H*W;c++){
        int root=-1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(done[i][j]) continue;
                
                if(root==-1) root=Find(i*W+j);
                
                if(Find(i*W+j)==root){
                    ans[i][j]=c;
                    done[i][j]=true;
                    cont++;
                }
            }
        }
    }
    
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            if(j==W-1) cout<<ans[i][j]<<endl;
            else cout<<ans[i][j]<<" ";
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
    cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<":"<<endl;
        Solve();
    }
    
    return 0;
}
