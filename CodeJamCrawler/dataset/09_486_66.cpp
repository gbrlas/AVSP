#include<iostream>
#include<vector>
#include<string>
using namespace std;
int tmap[100][100];
char bname[100][100];
int v[100][100];
char basin;
int rdiff[]={-1,0,0,1};
int cdiff[]={0,-1,1,0};
int dfs(int crow,int ccol,int H,int W)
{ if(v[crow][ccol]==1)
  return bname[crow][ccol];
  v[crow][ccol]=1;
  int target=-1, talt=tmap[crow][ccol];
  for(int k=0;k<4;k++)
  if(crow+rdiff[k]>=0&&crow+rdiff[k]<H&&ccol+cdiff[k]>=0&&ccol+cdiff[k]<W&&tmap[crow+rdiff[k]][ccol+cdiff[k]]<talt)
  { talt=tmap[crow+rdiff[k]][ccol+cdiff[k]];
    target=k;
  }
  if(target==-1)
  { bname[crow][ccol]=basin++;
    return bname[crow][ccol];
  }  
  else
  return( bname[crow][ccol]=dfs(crow+rdiff[target],ccol+cdiff[target],H,W));
}
int main()
{ int T,H,W;
  scanf("%d",&T);
  for(int t=0;t<T;t++)
  { basin='a';
    scanf("%d %d",&H,&W);
    for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
    v[i][j]=0;
    for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
    scanf("%d",&tmap[i][j]);
    for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
    dfs(i,j,H,W);
    printf("Case #%d:\n",t+1);
    for(int i=0;i<H;i++)
    {
      for(int j=0;j<W;j++)
      cout<<bname[i][j]<<((j==W-1)?"":" ");
      cout<<"\n";
    }
  }
}  
