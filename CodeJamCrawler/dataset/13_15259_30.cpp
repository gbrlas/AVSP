#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	long TestCase,countX,countO,i,j,k,l=1,m,n;
	scanf("%ld",&TestCase);	
	while(TestCase--)
	{
		getchar();
		char s[5][5];
		bool x=false,o=false,d=false;
		countX=0;
		countO=0;
		for(i=0;i<4;i++)		
			gets(s[i]);		
		

		// horizontal
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(s[i][j]=='X' ||s[i][j]=='T')
					countX++;
				if(s[i][j]=='O' ||s[i][j]=='T')
					countO++;
				if(s[i][j]=='.')
					d=true;
			}			
			if(countX==4)
				x=true;
			else if(countO==4)
				o=true;
			countX=0;countO=0;
		}
		countX=0;countO=0;
		if(x)
		{
			printf("Case #%ld: X won\n",l++);
			continue;
		}
		else if(o)
		{
			printf("Case #%ld: O won\n",l++);
			continue;
		}
		
		//vertical checking
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(s[j][i]=='X' ||s[j][i]=='T')
					countX++;
				if(s[j][i]=='O' ||s[j][i]=='T')
					countO++;
				if(s[i][j]=='.')
					d=true;
			}
			
			if(countX==4)
				x=true;
			else if(countO==4)
				o=true;			
			countX=0;countO=0;
		}
		countX=0;countO=0;
		if(x)
		{
			printf("Case #%ld: X won\n",l++);
			continue;
		}
		else if(o)
		{
			printf("Case #%ld: O won\n",l++);
			continue;
		}

		//diagonal checking 1
		for(i=0;i<4;i++)
		{						
			if(s[i][i]=='X' ||s[i][i]=='T')
				countX++;
			if(s[i][i]=='O' ||s[i][i]=='T')
				countO++;			
		}
		if(countX==4)
			x=true;
		else if(countO==4)
			o=true;			
		
		if(x)
		{
			printf("Case #%ld: X won\n",l++);
			continue;
		}
		else if(o)
		{
			printf("Case #%ld: O won\n",l++);
			continue;
		}
		countX=0;countO=0;
		//diagonal checking 2
		for(i=0,j=3;i<4;i++,j--)
		{						
			if(s[i][j]=='X' ||s[i][j]=='T')
				countX++;
			if(s[i][j]=='O' ||s[i][j]=='T')
				countO++;
		}
		if(countX==4)
			x=true;
		else if(countO==4)
			o=true;			
		

		if(x)
		{
			printf("Case #%ld: X won\n",l++);
		//	continue;
		}
		else if(o)
		{
			printf("Case #%ld: O won\n",l++);
		//	continue;
		}
		else if(d)
			printf("Case #%ld: Game has not completed\n",l++);
		else
			printf("Case #%ld: Draw\n",l++);
	}
	return 0;
}