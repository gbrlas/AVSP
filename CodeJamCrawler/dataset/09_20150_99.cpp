#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	string str="xwelcome to code jam";
	char inp[10000];
	int flag=19;
	int no;
	char c;
	scanf("%d%c",&no,&c);
	for(int tok=1;tok<=no;tok++)
	{
		gets(inp);
		if( strlen(inp) < flag )
		{
			cout<<"Case #"<<tok<<": 0000\n";
			continue;
		}

		int arr[100];
		for(int i=1;i<=flag;i++)
			arr[i]=0;

		arr[0]=1;
		for(int i=0;i<strlen(inp);i++)
		{
			char temp=inp[i];
			for(int j=1;j<=flag;j++)
			{
				if( temp==str[j] )
				{
					arr[j]=(arr[j]+arr[j-1])%1000000;
				}
			}
		}
		int ans=arr[flag]%10000;
		cout<<"Case #"<<tok<<": ";
		if(ans/10 == 0)
			cout<<"000"<<ans<<endl;
		else if( ans/100 == 0)
			cout<<"00"<<ans<<endl;
		else if( ans/1000 == 0)
			cout<<"0"<<ans<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

