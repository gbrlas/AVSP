#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
char kc[5],kd[5],kal[20];
int main()
{
	int t,c,d,n;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		scanf("%d",&c);
		if(c==1)scanf("%s",kc);
		scanf("%d",&d);
		if(d==1)scanf("%s",kd);
		scanf("%d",&n);
		scanf("%s",kal);
		vector <char> aa;
		aa.clear();
		for(int i=0;i<n;i++)
		{
			
			aa.push_back(kal[i]);
		/*	printf("awal\n");
			for(int j=0;j<aa.size();j++)printf("%c",aa[j]);
			printf("\n");*/
			int uk = aa.size();
			if(c==1&&uk>1&&((aa[uk-1]==kc[0]&&aa[uk-2]==kc[1])||(aa[uk-1]==kc[1]&&aa[uk-2]==kc[0])))
			{
			
					aa.erase(aa.end()-2,aa.end());
					aa.push_back(kc[2]);
			/*		printf("ganti\n");
					for(int j=0;j<aa.size();j++)printf("%c",aa[j]);
					printf("\n");*/
				
			}
			else if(d==1&&kal[i]==kd[0])
			{
				for(int j=0;j<aa.size()-1;j++)
				{
					if(aa[j]==kd[1])
					{
						aa.clear();
					//	printf("h1\n");
						break;
					}
				}
			}
			else if(d==1&&kal[i]==kd[1])
			{
				for(int j=0;j<aa.size()-1;j++)
				{
					if(aa[j]==kd[0])
					{
						aa.clear();
						//	printf("h2\n");
						break;
					}
				}
			}
			
		/*	printf("akhir\n");
				for(int j=0;j<aa.size();j++)printf("%c",aa[j]);
		printf("\n");*/
		
		}
		printf("Case #%d: [",it+1);
		for(int i=0;i<aa.size();i++)
		{
			if(i==0)printf("%c",aa[i]);
			else printf(", %c",aa[i]);
		}
		printf("]\n");
	}

	return 0;
}
