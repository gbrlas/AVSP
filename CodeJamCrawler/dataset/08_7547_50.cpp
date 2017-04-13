#include<iostream>
#include<algorithm>
using namespace std;
int w[2][105];
char tem[105];
int n,m;
struct node{
	char str[105];
	bool operator<(const node a)const{
		return strcmp(str,a.str)<0;
	}
};
node tt[105];
int cal(char tem[])
{
	int hig=n-1,low=0,mid,h;
	while(low<hig){
		mid=(low+hig)/2;
		h=strcmp(tem,tt[mid].str);
		if(h==0)return mid;
		else if(h<0)hig=mid-1;
		else low=mid+1;
	}
	if(strcmp(tem,tt[low].str)==0)return low;
	return -1;
}
int main()
{
	freopen("d://a-large.in","r",stdin);
	freopen("d://aa.out","w",stdout);
	int t,i,j,s;
	scanf("%d",&t);	
	int k=1;
	while(t--){
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++){
			gets(tt[i].str);
		}
		sort(tt,tt+n);
		scanf("%d",&m);
		memset(w,0,sizeof(w));
		getchar();
		int h0,h1;
		for(i=1;i<=m;i++){
			h0=(i+1)%2;
			h1=i%2;
			gets(tem);
			int h=cal(tem);
			for(s=0;s<n;s++){
				if(s==h){
					w[h1][s]=10000;
					continue;
				}
				int min1=10000;
				for(j=0;j<n;j++){
					if(j==s){
						if(w[h0][j]<min1)min1=w[h0][j];
					}
					else if(w[h0][j]+1<min1){
						min1=w[h0][j]+1;
					}
				}
				w[h1][s]=min1;
			}
		}
		int min1=10000;
		h1=m%2;
		for(j=0;j<n;j++)if(w[h1][j]<min1)min1=w[h1][j];
		printf("Case #%d: %d\n",k++,min1);
	}
	return 0;
}