#include<iostream>
#include<cstdio>
using namespace std;

int visited[100][100],alt[100][100],H,W,;
char out[100][100];

void recur(int x,int y,char *pc)
{    int diff,c=0;
     diff=0;
     if(x>0){{if(diff<(alt[x][y]-alt[x-1][y])) {diff=alt[x][y]-alt[x-1][y]; c=1;}}}
     if(y>0) {{if(diff<(alt[x][y]-alt[x][y-1])) {diff=alt[x][y]-alt[x][y-1]; c=2;}}}
     if(y<(W-1)) {{if(diff<(alt[x][y]-alt[x][y+1])) {diff=alt[x][y]-alt[x][y+1]; c=3;}}}
     if(x<(H-1)){{if(diff<(alt[x][y]-alt[x+1][y])) {diff=alt[x][y]-alt[x+1][y]; c=4;}}}
     if(c==0) {  if(visited[x][y]==0) { visited[x][y]=-1; *pc=*pc+1; out[x][y]=*pc; }return; }
     visited[x][y]=1;
     if(c==1)   if(visited[x-1][y]==-1|| visited[x-1][y]==1) *pc=out[x-1][y]; else recur(x-1,y,pc);
     if(c==2)           if(visited[x][y-1]==-1 || visited[x][y-1]==1) *pc=out[x][y-1]; else recur(x,y-1,pc);
     if(c==3)           if(visited[x][y+1]==-1|| visited[x][y+1]==1) *pc=out[x][y+1]; else recur(x,y+1,pc);
     if(c==4)           if(visited[x+1][y]==-1 || visited[x+1][y]==1) *pc=out[x+1][y]; else recur(x+1,y,pc);
    out[x][y]=*pc;
}
    

main()
{
      int t,v=1;
      char pc;
      cin>>t;
      while(t--)
      {
                cin>>H>>W;
                for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>alt[i][j];
                for(int i=0;i<100;i++) for(int j=0;j<100;j++) visited[i][j]=0;
                 
                pc='a'-1;   
                 for(int i=0;i<H;i++) for(int j=0;j<W;j++) recur(i,j,&pc);
                 printf("Case #%d:\n",v++);
                for(int i=0;i<H;i++){ for(int j=0;j<W;j++){ cout<<out[i][j]<<" ";} cout<<endl; }
                
      }
      return 0;
}
