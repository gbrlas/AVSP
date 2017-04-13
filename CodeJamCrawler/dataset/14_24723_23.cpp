#include<stdio.h>
#include<algorithm>
int tc,tcn;
int n;
int x;
int a[10100];
int ans;
int main(){
	int i,j,k;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d",&n,&x);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		std::sort(a,a+n);
		ans=0;
		i=0;
		j=n-1;
		while(1){
			if(i==j){
				ans++;
				break;
			}
			if(i>j)break;
			if(a[i]+a[j]>x){
				j--;
			}
			else{
				i++;
				j--;
			}
			ans++;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}