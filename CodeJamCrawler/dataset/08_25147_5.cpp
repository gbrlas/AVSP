#include<stdio.h>
#include<string.h>
int d[102][102];
bool rock[102][102];
int f(int a,int b)
{
	if(a==1&&b==1)return 1;
	if(rock[a][b])return d[a][b]=0;
	if(d[a][b]!=-1)return d[a][b];
	int sum=0;
	if(a-1>=0&&b-2>=0&&!rock[a-1][b-2])
		sum=(sum+f(a-1,b-2))%10007;
	if(a-2>=0&&b-1>=0&&!rock[a-2][b-1])
		sum=(sum+f(a-2,b-1))%10007;
	return d[a][b]=sum;
}
int main()
{
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D-small.txt","w",stdout);
	int pk,k;
	scanf("%d",&pk);
	for(k=1;k<=pk;k++)
	{

		int w,h;
		int R;
		int r,c;
		scanf("%d %d %d",&h,&w,&R);
		memset(d,-1,sizeof d);
		memset(rock,0,sizeof rock);
		int i;
		for(i=0;i<R;i++)
		{
			scanf("%d %d",&r,&c);
			rock[r][c]=1;
		}
		printf("Case #%d: ",k);
		printf("%d\n",f(h,w));
	}
	return 0;

}