#include <cstdio>
#include <iostream>
using namespace std;
char a[50][51];
char rot[50][50];
int state[50][50][4];///0,right;1,leftdown,2,down,3rightdown;

int T,t,i,j,k,N,K;

int main(){
    FILE *fin = freopen("A-large.in","r",stdin);
    FILE *fout = freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        printf("Case #%d: ",t);
        scanf("%d %d",&N,&K);
        for(i=0;i<N;i++){
            scanf("%s",a[i]);
        }
        for(i=0;i<N;i++)for(j=0;j<N;j++)rot[i][j]='.';
        int cnt;
        for(i=0;i<N;i++){
            cnt = 0;
            for(j=N-1;j>=0;j--){
                if(a[i][j]=='.')cnt++;
                else{
                    rot[j+cnt][i]=a[i][j];
                }
            }
        }
        ///rotation finished
        /*for(i=0;i<N;i++){
            for(j=0;j<N;j++)cout<<rot[i][j]<<" ";
            cout<<endl;
        }*/
        bool red=false,blue=false;
        for(i=0;i<N;i++)for(j=0;j<N;j++)for(k=0;k<4;k++)state[i][j][k]=K;
        for(i=0;i<N;i++)for(j=0;j<N;j++){
            for(k=0;k<4;k++)if(state[i][j][k]==1){
                if(rot[i][j]=='R')red=true;
                else if(rot[i][j]=='B') blue=true;
            }
            if(j+1<N&&rot[i][j]==rot[i][j+1]){
                state[i][j+1][0] = state[i][j][0] - 1;
            }
            if(j>0&&i+1<N&&rot[i][j]==rot[i+1][j-1]){
                state[i+1][j-1][1] = state[i][j][1] - 1;
            }
            if(i+1<N&&rot[i][j]==rot[i+1][j]){
                state[i+1][j][2] = state[i][j][2] - 1;
            }
            if(i+1<N&&j+1<N&&rot[i][j]==rot[i+1][j+1]){
                state[i+1][j+1][3] = state[i][j][3] - 1;
            }
        }
        /*for(i=0;i<N;i++){
            for(j=0;j<N;j++)cout<<state[i][j][0]<<" ";
            cout<<endl;
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++)cout<<state[i][j][1]<<" ";
            cout<<endl;
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++)cout<<state[i][j][2]<<" ";
            cout<<endl;
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++)cout<<state[i][j][3]<<" ";
            cout<<endl;
        }*/

        if(red&&blue)printf("Both\n");
        else if(red)printf("Red\n");
        else if(blue)printf("Blue\n");
        else printf("Neither\n");
        fflush(fout);
    }
}
