#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
//#include<conio.h>
using namespace std;
int nt,r,c;
int grid[101][101] ;
char used = 'a';
char finished[101][101];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
char build(int x,int y)
{
	if(finished[x][y] != ' ')
	   return finished[x][y] ;
//	printf("In %d %d\n",x,y);
//	getch();
	int m = 10001 , nx = -1 , ny = -1;
	for( int i = 0 ; i < 4 ; ++ i )
	{
		int cx = x + dx[i] , cy = y + dy[i] ;
		if(cx < 0 || cx >= r || cy < 0 || cy >= c )
		   continue;
		if( grid[cx][cy] < grid[x][y] && grid[cx][cy] < m )
		{
			nx = cx ;
			ny = cy ;
			m = grid[cx][cy];
		}
	}
//	printf("New %d %d\n",nx,ny);
//	getch();
	if(nx == -1 && ny == -1)
	  return finished[x][y] = (char)used ++  ;
	else
	{
		return finished[x][y] = build(nx,ny);
	}
}
int main()
{
	FILE  * fin = fopen("C:/inp1.txt","r");
	FILE  *fout = fopen("C:/out1.txt","w");
	fscanf(fin,"%d",&nt);
	int ncase = 0 ;
	while(nt--)
	{
		fscanf(fin,"%d %d",&r,&c);
		used = 'a' ;
		for(int i=0;i < r; ++i)
		   for(int j=0;j < c ; ++ j)
		   {
			   fscanf(fin,"%d",&grid[i][j]);
			   finished[i][j] = ' ' ;
			}
		for(int i=0;i<r;++i)
		   for(int j=0;j<c;++j)
			  build(i,j);
		fprintf(fout,"Case #%d:\n",++ncase);
		for(int i=0;i<r;++i)
		{
		   for(int j=0;j<c;++j)
		   {
			 fprintf(fout,"%c",finished[i][j]);
			 if(j!=c-1) fprintf(fout," ");
			}
			fprintf(fout,"\n");
		}
	}
}
