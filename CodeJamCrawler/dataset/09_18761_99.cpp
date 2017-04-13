#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int hasil[110][110];
int data[110][110];
int arah[4][2] = { {-1,0}, {0,-1}, {0,1}, {1,0} };

int ganti[10010];

int t,h,w;

void rek(int baris,int kolom,int j,int k)
{
	int ar = 0;
	int mn = 99999;
	
	for(int i=0;i<4;i++)
	{
		if(j+arah[i][0]>=0 && k+arah[i][1]>=0 && j+arah[i][0]<h && k+arah[i][1]<w)
		{
			if(mn>data[j+arah[i][0]][k+arah[i][1]]) 
			{
				ar = i;
				mn = data[j+arah[i][0]][k+arah[i][1]];	
			}
		} 
	}
	
	//system("pause");
	if(mn>=data[j][k])
	{
		hasil[baris][kolom]=j*w+k;
	}
	else
	{
		//printf("%d %d %d\n",j,k,data[baris][kolom]);
		rek(baris,kolom,j+arah[ar][0],k+arah[ar][1]);
	}
}

int main()
{
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		memset(hasil,0,sizeof(hasil));	
		memset(ganti,-1,sizeof(ganti));	

		scanf("%d %d",&h,&w);
		
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
			{
				scanf("%d",&data[j][k]);	
			}	
		}
		
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
			{
				rek(j,k,j,k);
				//cout<<hasil[j][k]<<" ";	
			}	
			//cout<<endl;
		}
		
		printf("Case #%d:\n",i+1);	
		
		char tanda = 'a';
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
			{
				if(ganti[hasil[j][k]]==-1)
				{
					ganti[hasil[j][k]]=tanda;	
					tanda++;
				}
				if(k==0) printf("%c",ganti[hasil[j][k]]);
				else printf(" %c",ganti[hasil[j][k]]);
			}	
			cout<<endl;
		}
		
	}
	
	return 0;	
}
