#include<cstdio>

bool G[100][100],G1[100][100];
bool empty(){
 int i,j;
 for(i=0;i<100;i++)
  for(j=0;j<100;j++)
   if(G[i][j]>0) return 0;
  return 1;
}
int main(){
 int t,T,x1,y1,x2,y2,i,j,k,R,res,f;
 scanf("%d",&T);
 for(t=1;t<=T;t++){
  scanf("%d",&R);
  for(i=0;i<100;i++)
   for(j=0;j<100;j++)
    G[i][j]=0;
  for(i=0;i<R;i++)
  {
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   for(j=y1-1;j<y2;j++)
    for(k=x1-1;k<x2;k++)
	 G[j][k]=1;
  }
	res=0;
   while( !empty() )
   {
     res++;
	 //printf("%d\n",res);
	 for(i=0;i<100;i++)
	  for(j=0;j<100;j++)
	  {
	   f=0;
	   if( i>0 && G[i-1][j]==1) { f++;}
	   if( j>0 && G[i][j-1]==1) { f++;}
	   G1[i][j]=G[i][j];
	   if( f==2) G1[i][j]=1;
	   if( f==0) G1[i][j]=0;
	   
	  }
	 for(i=0;i<100;i++)
	  for(j=0;j<100;j++)
	   G[i][j]=G1[i][j];
   }
  printf("Case #%d: %d\n",t,res);
 }
 return 0;
}

