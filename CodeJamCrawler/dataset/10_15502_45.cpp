#include<iostream>
#include<algorithm>
using namespace std;
struct point 
{
	int x;
	int y;
};
point b[40020];
point a[40020];
int cmp1(point s,point k)
{
	if(s.x==k.x)
	return s.y<k.y;
	return s.x<k.x;
}
int cmp2(point s,point k)
{
	if(s.y==k.y)
	return s.x<k.x;
	return s.y<k.y;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.txt","w",stdout);
	int T,ca=1,n,x,sum,i,j;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			b[i].x=a[i].x;
			b[i].y=a[i].y;
		}
		sort(a,a+n,cmp1);
		sort(b,b+n,cmp2);
		for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		{
			if((a[i].x>b[j].x&&a[i].y<b[j].y)||(a[i].x<b[j].x&&a[i].y>b[j].y))
			{
				//printf("%d  %d  %d  %d\n",a[i].x,a[i].y,b[j].x,b[j].y);
				sum++;
			}
			if(a[i].y<=b[i].y)break;
		}
		printf("Case #%d: %d\n",ca++,sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
		
