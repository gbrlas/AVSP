/*
#include <iostream>
using namespace std;
int ans[512];
bool flag[11];
bool check(int n,int count)
{
	int sum,base,t=n,cnt=0;
	for(base =2;base <= 10;base++)
	{
		n = t;
		if(flag[base]==0) continue;
		for(int time=1;time<=10;time++){
		sum = 0;
		while(n)
		{
			sum += (n%base)*(n%base);
			n/=base;	
		}
		if(sum==1) {
			cnt++;
			break;
		}
		n = sum;
		}
	}
	if(cnt==count) return true;
	return false;
}
int solve(int n)
{
	int i,cnt=0;
	memset(flag,false,sizeof(flag));
	for(i=0;i<9;i++)
		if((n&(1<<i))){
			flag[i+2]=true;
			cnt++;
		}
	for(i=2;i;i++)if(check(i,cnt))break;
	return i;
}
int main()
{
	int i;
	freopen("output.txt","w",stdout);
	for(i=0;i<512;i++)
	{
		ans[i]=solve(i);
		printf("%d\n",ans[i]);
	}
	return 0;
}
*/
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
char str[1000];
int ans[550];
int main()
{
	int T,now,ca,tmp;
	freopen("output.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<512;i++) scanf("%d",&ans[i]);
	scanf("%d",&T);
	getchar();
	for(ca=1;ca<=T;ca++)
	{
		gets(str);	
		stringstream ssin(str);
		now = 0;
		while(ssin>>tmp) now |= (1<<(tmp-2));
		printf("Case #%d: %d\n",ca,ans[now]);
	}
	return 0;
}