#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
    int T,N,K;
    char M1[51][51],M2[51][51];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&N,&K);
        
        for(int i=0;i<N;++i) scanf("%s",M1[i]);
        
        for(int i=0;i<N;++i) for(int j=0;j<N;++j) M2[i][j] = '.';
        
        for(int i=N-1;i>=0;--i){
            for(int j=N-1,k=0;j>=0;--j){
                if(M1[i][j]!='.'){
                    M2[k][N-1-i] = M1[i][j];
                    ++k;
                }
            }
        }
        
        /*for(int i=0;i<N;++i){
            for(int j=0;j<N;++j) cout<<M2[i][j];
            cout<<endl;
        }
        cout<<endl;*/
        
        bool blue = false, red = false;
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(M2[i][j]=='.') continue;
                bool found = false,done = false;
                
                if(i+K<=N){
                    found = true;
                    for(int k=0;k<K;++k) if(M2[i+k][j]!=M2[i][j]) found = false;
                    if(found) done = true;
                }
                
                if(j+K<=N){
                    found = true;
                    for(int k=0;k<K;++k) if(M2[i][j+k]!=M2[i][j]) found = false;
                    if(found) done = true;
                }
                
                if(i+K<=N && j+K<=N){
                    found = true;
                    for(int k=0;k<K;++k) if(M2[i+k][j+k]!=M2[i][j]) found = false;
                    if(found) done = true;
                }
                
                if(i+K<=N && j-K+1>=0){
                    found = true;
                    for(int k=0;k<K;++k) if(M2[i+k][j-k]!=M2[i][j]) found = false;
                    if(found) done = true;
                }
                
                if(done){
                    if(M2[i][j]=='B') blue = true;
                    else red = true;
                }
            }
        }
        
        printf("Case #%d: ",tc);
        if(blue && red) printf("Both");
        else if(blue) printf("Blue");
        else if(red) printf("Red");
        else printf("Neither");
        printf("\n");
    }
    
    return 0;
}
