#pragma warning (disable:4786) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

map<string, int> s;
map<string, int>::iterator iter;  


int main()
{
	int z,out,k,i,last,flag,j,ans=0,key;
	char ch[5000];
	char list[1010][500];

	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	gets(ch);sscanf(ch,"%d",&z);
	for (out=1;out<=z;out++)
	{
		ans=0;
		s.clear();
		gets(ch);sscanf(ch,"%d",&k);
		for (i=1;i<=k;i++)
		{
			gets(ch);
			s[ch]=1;
		}
		//begin;
		gets(ch);sscanf(ch,"%d",&k);
		last=1;
		for (i=1;i<=k;i++)
		{
			gets(list[i]);

			//check from last to now, do we need switch
			key=0;
			for(iter = s.begin(); iter != s.end(); ++iter)
			{
				flag=1; // 1, no switch needed.
				for (j=last;j<=i;j++)
				{
					//cout<<iter->first;//<<iter->first.compare("B9"); //compare == 0 means equal
					if (iter->first.compare(list[j])==0) {flag=0; break;}
				}
				if (flag==1) { key=1; break;}
			}
			if (key==0) 
			{
				ans++;
				last=i;
			}
		}
		printf("Case #%d: %d\n",out,ans);
	}






	return 1;
}