
#include<iostream>
using namespace std;
int hh[32]={0,5,27,143,751,935,607,903,991,335,47,943,471,55,447,463,991,95,607,263,151,855,527,743,351,135,407,903,791,135,647};
int main()
{
	int t,i,s;
	freopen("d:\\C-small-attempt0.in","r",stdin);
	freopen("d:\\3.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&s);
		printf("Case #%d: %03d\n",i,hh[s]);
	}
	return 0;
}