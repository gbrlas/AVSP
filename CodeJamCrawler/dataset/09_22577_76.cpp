#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int h,w;
int matrix[101][101];
bool used[101][101];
char ans[101][101];
int dirx[]={-1,0,0,1};
int diry[]={0,-1,1,0};
int num,ttx,tty;
typedef struct
{
	int x,y;
}pp;
pp in[101][101],queue[100001],was[101][101][10];
int nn[101][101];
void bfs(int id1,int id2,int ind)
{
	int i,j,s,ix,iy,temp1,temp2,temp;
	temp1=temp2=0;
	temp=1;
	used[id1][id2]=true;
	queue[0].x=id1;
	queue[0].y=id2;
	ans[id1][id2]=ind+'a';
	while(temp1<=temp2)
	{
	   for(i=temp1;i<=temp2;i++)
	   {
	   	     ttx=in[queue[i].x][queue[i].y].x;
			 tty=in[queue[i].x][queue[i].y].y;
			 if(used[ttx][tty]==false)
			 {
			 	 queue[temp].x=ttx;
			 	 queue[temp++].y=tty;
			 	 ans[ttx][tty]=ind+'a';
			 	 used[ttx][tty]=true;
			 }
			 for(j=0;j<nn[queue[i].x][queue[i].y];j++)
			 {
			 	 ttx=was[queue[i].x][queue[i].y][j].x;
			 	 tty=was[queue[i].x][queue[i].y][j].y;
			 	 if(used[ttx][tty]==false)
			 	 {
			 	 	 queue[temp].x=ttx;
			 	 	 queue[temp++].y=tty;
			 	 	 ans[ttx][tty]=ind+'a';
			 	 	 used[ttx][tty]=true;
			 	 }
			 }
	   }
	   temp1=temp2+1;
	   temp2=temp-1;
	}
}
int main()
{
	int t,i,j,s,p;
	freopen("A.in","r",stdin);
	freopen("fuck.out","w",stdout);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    scanf("%d%d",&h,&w);
		for(j=0;j<h;j++)
		  for(s=0;s<w;s++)
		     scanf("%d",&matrix[j][s]);
        memset(ans,'a'-1,sizeof(ans));
		memset(used,false,sizeof(used));
		memset(nn,0,sizeof(nn));
		num=0;
		for(j=0;j<h;j++)
		   for(s=0;s<w;s++)
		   {
		   	    in[j][s].x=j;
		   	    in[j][s].y=s;
		   	    for(p=0;p<4;p++)
		   	    {
		   	    	ttx=j+dirx[p];
		   	    	tty=s+diry[p];
		   	        if(ttx<h&&ttx>=0&&tty<w&&tty>=0)
		            {
		            	 if(matrix[ttx][tty]<matrix[in[j][s].x][in[j][s].y])
		            	 {
						     in[j][s].x=ttx;
		            	     in[j][s].y=tty;
						 }
					}
		   	    }
		   	    was[in[j][s].x][in[j][s].y][nn[in[j][s].x][in[j][s].y]].x=j;
		   	    was[in[j][s].x][in[j][s].y][nn[in[j][s].x][in[j][s].y]++].y=s;
		   }
		for(j=0;j<h;j++)
		  for(s=0;s<w;s++)
		  {
                if(used[j][s]==false)	 	 
                {
 		    	   bfs(j,s,num);
 		    	   num++;
                }
		  }
		printf("Case #%d:\n",i+1); 
        for(j=0;j<h;j++)
        {
          for(s=0;s<w;s++)
          {
          	  if(s)
          	    putchar(' ');
              putchar(ans[j][s]);
          }
		  putchar('\n');
        }
	}
	return 0;
}
