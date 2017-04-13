#include <stdio.h>
#include <string.h>

char curTable[100][100];
char nxtTable[100][100];
int cntTable[100][100][4];
int n,m;

void rotateTable()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			nxtTable[i][j]=curTable[n-j-1][i];
	}
	
}

void adjustTable()
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
			curTable[i][j]='.';
		k=n-1;
		for(i=n-1;i>=0;i--)
		{
			if(nxtTable[i][j]!='.')
				curTable[k--][j]=nxtTable[i][j];
		}
	}
	
}

int findTable(char ch)
{
	memset(cntTable,0,sizeof(cntTable));

	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(j>=1 &&curTable[i][j]==curTable[i][j-1] && curTable[i][j]==ch)
				cntTable[i][j][0]=cntTable[i][j-1][0]+1;
			else if(curTable[i][j]==ch)
				cntTable[i][j][0]=1;
		
			if(i>=1 && curTable[i][j]==curTable[i-1][j] && curTable[i][j]==ch)
				cntTable[i][j][1]=cntTable[i-1][j][1]+1;
			else if(curTable[i][j]==ch)
				cntTable[i][j][1]=1;
			
			if(i>=1 && j>=1 && curTable[i][j]==curTable[i-1][j-1] && curTable[i][j]==ch)
				cntTable[i][j][2]=cntTable[i-1][j-1][2]+1;
			else if(curTable[i][j]==ch)
				cntTable[i][j][2]=1;

			if(i>=1 && j<=n-2 && curTable[i][j]==curTable[i-1][j+1] && curTable[i][j]==ch)
				cntTable[i][j][3]=cntTable[i-1][j+1][3]+1;
			else if(curTable[i][j]==ch)
				cntTable[i][j][3]=1;
				
		}
	}
	for(k=0;k<4;k++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(cntTable[i][j][k]>=m)
					return 1;
	}
	return 0;

}


int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("small.out","w",stdout);
	int cases;
	int iCases;

	scanf("%d",&cases);
	iCases=1;
	while(iCases<=cases)
	{
		memset(curTable,0,sizeof(curTable));
		memset(nxtTable,0,sizeof(nxtTable));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",curTable[i]);
		
		rotateTable();

		adjustTable();

		int red=findTable('R');
		int blue=findTable('B');

		if(red && blue)
			printf("Case #%d: Both\n",iCases);
		else if(red)
			printf("Case #%d: Red\n",iCases);
		else if(blue)
			printf("Case #%d: Blue\n",iCases);
		else
			printf("Case #%d: Neither\n",iCases);
		iCases++;
	}
	return 0;

}
