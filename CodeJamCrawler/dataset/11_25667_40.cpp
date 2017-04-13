#include<iostream>

using namespace std;

int t,n,m,caso;
char M[50][50];
int dx[4]={0,0,1,1};
int dy[4]={0,1,1,0};
char car[4]={'/','\\','/','\\'};


int val(int x,int y){
    //m[x][y]='/';
    for(int i=0;i<4;++i){
        int u=x+dx[i],v=y+dy[i];
        if(!(u>=0&&u<n&&v>=0&&v<m&&M[u][v]=='#')){
            return false;
        }
        M[u][v]=car[i];
    }
}

bool doit(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>M[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<i<<" "<<j<<endl;
            if(M[i][j]=='#'){
                if(!val(i,j)){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    scanf("%d",&t);
    //cout<<t<<endl;
    for(int i=0;i<t;++i){
        printf("Case #%d:\n",++caso);
        if(doit()){
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    cout<<M[i][j];
                }
                puts("");
            }
        }
        else{
            puts("Impossible");
        }
    }
}
