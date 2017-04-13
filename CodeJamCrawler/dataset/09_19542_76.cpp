#include<stdio.h>
#include<conio.h>
#include<string.h>

Search(char strInput[], char strWelcome[], int srcFor,int startPos, int *inpLen, int *Count)
{
	int j =0 ;
	int temp;


		for(j=startPos;j<(*inpLen);j++)
		{
			if((*Count) == 9999)
				return;

			if(((*inpLen) - j + 1) < (19 -srcFor+1))//
				break;

			if(strWelcome[srcFor] == strInput[j])
			{
				
				if(srcFor == 18)
				{
					(*Count)++;
					//temp = srcFor;
				}
				else
				{
					temp = srcFor + 1;
					Search(strInput,strWelcome,temp,j+1,inpLen,Count);
				}

				if((*Count) == 0)
					break;
			}
		}
	//}

}


void main()
{
	FILE *fpIn, *fpOut;
	char Tempchar, strInput[550];
	char strWelcome[] = "welcome to code jam";//length is 19;
	int inpLen, num, i,k;
	int Count;
	
	fpIn = fopen("C-small-attempt2.in","r");
	if(fpIn==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fpOut = fopen("Welcome2CodeJAM-Output.in","w");

	if(fpOut ==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fscanf(fpIn,"%d%c",&num, &Tempchar);

	for(i=1;i<=num;i++)
	{

		//fscanf(fpIn,"%s%c",strInput, &Tempchar);
		fgets(strInput,600,fpIn);
		inpLen = strlen(strInput) - 1;
		Count = 0;
		//srcFor = 0;

		Search(strInput, strWelcome, 0,0, &inpLen, &Count);
		printf("%0.4d\n",Count);
		fprintf(fpOut,"%s%d%c %0.4d\n","Case #",i,':', Count);
		
	}
	

	fclose(fpIn);
	fclose(fpOut);
	getche();
}