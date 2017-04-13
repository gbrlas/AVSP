#include <iostream>
using namespace std;

const char t[25] = "welcome to code jam";
char s[25];
int arr[2][20];

int main()
{
	int test,count=1,tlen = strlen(t);
	int i,j,temp=1;
	scanf("%d",&test);
	getchar();
	while (test--)
	{
		temp=1;
		memset(arr,0,sizeof(arr));
		gets(s);
		int slen = strlen(s);
		for (i=1;i<=slen;++i,temp^=1)
		{
			for (j=0;j<20;++j)
			{
				arr[temp][j]=arr[1-temp][j];
			}			
			if (s[i-1]==t[0])
				arr[temp][1]++;
			for (j=2;j<=tlen;++j)
			{
				if (s[i-1]==t[j-1])
				{
					arr[temp][j]+=arr[temp][j-1];
					arr[temp][j]%=10000;
				}
			}			
		}
		printf("Case #%d: %4.4d\n",count,arr[temp^1][tlen]);count++;
	}
	return 0;
}