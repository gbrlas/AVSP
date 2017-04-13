#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

#define mod %10000

int main()
{

	long tc,cs,i,l,res;
	char s[600];

//	freopen("C-large.in","r",stdin);
//	freopen("c2.out","w",stdout);

	cin>>tc;
	gets(s);

	for(cs=1;cs<=tc;cs++)
	{
		long line[30]={0};
		line[0] = 1;
		gets(s);
		l = strlen(s);
		
		char c[]="welcome to code jam";
		
		for(i=0;i<l;i++)
		{
			if(s[i]=='w') line[1] = (line[1] + line[0])mod;
			else if(s[i]=='e') 	{	line[2] = (line[2] + line[1])mod;	line[7] = (line[7] + line[6])mod;	line[15] = (line[15] + line[14])mod;	}
			else if(s[i]=='l') line[3] = (line[3] + line[2])mod;
			else if(s[i]=='c') 	{	line[4] = (line[4] + line[3])mod;	line[12] = (line[12] + line[11])mod;	}
			else if(s[i]=='o')	{	line[5] = (line[5] + line[4])mod;	line[10] = (line[10] + line[9])mod;	line[13] = (line[13] + line[12])mod;	}
			else if(s[i]=='m') 	{	line[6] = (line[6] + line[5])mod;	line[19] = (line[19] + line[18])mod;	}
			else if(s[i]==' ') 	{	line[8] = (line[8] + line[7])mod;	line[11] = (line[11] + line[10])mod;line[16] = (line[16] + line[15])mod;	}
			else if(s[i]=='t') line[9] = (line[9] + line[8])mod;
			else if(s[i]=='d') line[14] = (line[14] + line[13])mod;
			else if(s[i]=='j') line[17] = (line[17] + line[16])mod;
			else if(s[i]=='a') line[18] = (line[18] + line[17])mod;

		}
		res = line[19];

	
		printf("Case #%ld: %04ld\n",cs,res);
	}


	return 0;
}