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
#include <algorithm>
#include <functional>

using namespace std;


//vector <int> x; 
//vector <int>::iterator iter;

int s1[1450][100],s2[1450][100];
int v1[1450],v2[1450];

int main()
{
	
	int d1,d2,d3,d4,a,b;
	int z,out,k,i,last,flag,j,ansA,ansB,key,T,temp,l,min1,min2;
	char ch[5000];
	char list[1010][500];

	freopen("B-small-attempt4.in","r",stdin);
	freopen("output.txt","w",stdout);

	gets(ch);sscanf(ch,"%d",&z);
	for (out=1;out<=z;out++)
	{
		ansA=0; ansB=0;
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));		

		gets(ch);sscanf(ch,"%d",&T);
		gets(ch);sscanf(ch,"%d %d",&a,&b);
		for (i=1;i<=a;i++)
		{
			gets(ch); sscanf(ch,"%d:%d %d:%d",&d1,&d2,&d3,&d4);
			s1[d1*60+d2][0]++;	s1[d1*60+d2][s1[d1*60+d2][0]] = d3 * 60 + d4; 
			v2[d3 * 60 + d4 + T]++;
		}
		for (i=1;i<=b;i++)
		{
			gets(ch); sscanf(ch,"%d:%d %d:%d",&d1,&d2,&d3,&d4);
			s2[d1*60+d2][0]++;	s2[d1*60+d2][s2[d1*60+d2][0]] = d3 * 60 + d4;
			v1[d3 * 60 + d4 + T]++;
		}

/*
		for (i=0;i<=1440;i++)
		{
			if (s1[i][0]>1)
			{
				for (j=1;j<s1[i][0];j++)
				for (k=j+1;k<=s1[i][0];k++)
					if (s1[i][j]<s1[i][k])
					{
						temp=s1[i][j]; s1[i][j]=s1[i][k]; s1[i][k]=temp;
					}
			}
			if (s2[i][0]>1)
			{
				for (j=1;j<s2[i][0];j++)
				for (k=j+1;k<=s2[i][0];k++)
					if (s2[i][j]<s2[i][k])
					{
						temp=s2[i][j]; s2[i][j]=s2[i][k]; s2[i][k]=temp;
					}
			}
		}
*/


		for (i=0;i<=23*60+59;i++)
		{
			if (s1[i][0]>0)
			{
				for (l=0;l<=i;l++)
				{
					if (v1[l]>0) 
					{
						while(s1[i][0]>0 && v1[l]>0)
						{
							s1[i][0]--;
							v1[l]--;
						}
					}
					if (s1[i][0]==0) break;
				}
				if (s1[i][0]>0) ansA+=s1[i][0];
				while(s1[i][0]>0)
				{
					s1[i][0]--;
				}
			}

			if (s2[i][0]>0)
			{
				for (l=0;l<=i;l++)
				{
					if (v2[l]>0) 
					{
						while(s2[i][0]>0 && v2[l]>0)
						{
							s2[i][0]--;
							v2[l]--;
						}
					}
					if (s2[i][0]==0) break;
				}
				if (s2[i][0]>0) ansB+=s2[i][0];
				while(s2[i][0]>0)
				{
					s2[i][0]--;
				}
			}

		}

						





		
		printf("Case #%d: %d %d\n",out,ansA,ansB);
	}







	return 1;
}