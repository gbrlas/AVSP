#include <stdio.h>

void main()
{
	int testcases;
	int i,j,k,p,q,inst;
	int grid[2][4][4];
	int ch[2];
	int output[100]={0};
	int num=0,mask=0;
	char space,newline;

	scanf("%d", &testcases);
	if(testcases < 1 || testcases > 100)
	{
		printf("InputError: Total testcases range: [1 to 100]\n");
		return;
	}
	scanf("%c",&newline);
	if(newline!='\n')
	{
		printf("InputError: newline expected\n");
		return;
	}	

	for (i=0;i<testcases;i++)
	{
		for(inst=0;inst<2;inst++)
		{
			scanf("%d",&(ch[inst]));
			if(ch[inst] < 1 || ch[inst] > 4)
			{
				printf("InputError: Row choice range: [1 to 4] \n");
				return;
			}
			scanf("%c",&newline);
			if(newline!='\n')
			{
				printf("InputError: newline expected\n");
				return;
			}	
			num=0;
			for (j=0; j<4; j++)
			{
				for (k=0; k<4; k++)
				{
					scanf("%d",&(grid[inst][j][k]));
					if(grid[inst][j][k] < 1 || grid[inst][j][k] > 16)
					{
						printf("InputError: Input range should be from [1 to 16]\n");
						return;
					}
					mask=0;
					mask=1<<grid[inst][j][k];
					if((mask & num))
					{
						printf("\nInputError: number already entered\n");
						return;
					}
					else	
						num=num|mask;
					if(k<3)
					{
						scanf("%c",&space);
						if(space!=' ')
						{
							printf("InputError: space expected between columns\n");
							return;
						}	
					}
					else
					{	
						scanf("%c",&newline);
						if(newline!='\n')
						{
							printf("InputError: newline expected between rows\n");
							return;
						}
					}
				}
			}
		}
		/*Comparing the input */
		for(p=0;p<4;p++)
		{
			for(q=0;q<4;q++)
			{
				if(grid[0][ch[0]-1][p] == grid[1][ch[1]-1][q])
				{
					if(0 == output[i])
					{	
						output[i]=grid[1][ch[1]-1][q];
					}
					else
						output[i]=17;
				}		
			}
		}
	}
		/*print the output*/
		for(i=0;i<testcases;i++)
		{
			switch(output[i])
			{
				case 0:
						printf("Case #%d: Volunteer cheated!\n",i+1);
						break;
				case 17:
						printf("Case #%d: Bad magician!\n",i+1);
						break;
				default:
						printf("Case #%d: %d\n",i+1,output[i]);
			}			
		}
}
