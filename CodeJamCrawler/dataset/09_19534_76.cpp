#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct Data
{
	char letter;
	struct Data *Next;
	struct Data *Prev;

};

struct Node
{
	struct Data *First;
	struct Data *Last;
	struct Data *Current;
};


void MatchPattern(char Dictionary[25][12],struct Node *Tokens[],int *Count, int L,int D)
{


	int i,j;
	short int exist;
	
	for(i=0;i<D;i++)
	{
		
		for(j=0;j<L;j++)
		{
			exist = 0;
			while(Tokens[j]->Current != NULL)
			{
				if(Tokens[j]->Current->letter == Dictionary[i][j])
				{
					exist = 1;
					break;
				}
				else
				{
					
					Tokens[j]->Current = Tokens[j]->Current->Next;
				}
			}
			Tokens[j]->Current = Tokens[j]->First ;

			if(exist ==0 )
				break;
			
		}
		if(exist ==1 )
			(*Count)++;
	}

}

void main()
{
	FILE *fpIn, *fpOut;


	char Dictionary[25][12],Word[12];
	struct Node *Tokens[11];
	char Tempchar, c;
	struct Data *TempData;
	int L,D, N, i,k;
	int Count,bracket;
	
	fpIn = fopen("A-small-attempt1.in","r");
	
	if(fpIn==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fpOut = fopen("Small-Alien-Number-Output.in","w");

	if(fpOut ==0)
	{
		puts("Cannot Open file.");
		getche();
		exit();
	}

	fscanf(fpIn,"%d%c%d%c%d%c",&L, &Tempchar,&D, &Tempchar,&N, &Tempchar);
	//fscanf(fpIn,"%d%c",&L,&Tempchar);

	for(i=0;i<D;i++)
	{
		fgets(Dictionary[i],12,fpIn);
	}

	for(i=0;i<L;i++)
	{
		Tokens[i] = (struct Node *)malloc(sizeof(struct Node));
		//Tokens[i]->First = NULL;
		Tokens[i]->Last = NULL;
	}
	Word[L] ='\n';
	Word[L+1] ='\0';

	for(i=1;i<=N;i++)
	{
		c = fgetc(fpIn);
	
		k =0;
		bracket =0;
		while(c != '\n')
		{
			if(c=='(' || c==')')
			{	bracket++; }
			else
			{
				TempData = (struct Data *)malloc(sizeof(struct Data));
				TempData->letter = c;
				TempData->Next = NULL;
				if(Tokens[k]->Last == NULL)
				{
					TempData->Prev = NULL;
					Tokens[k]->Last = TempData;
					Tokens[k]->First = TempData;
					Tokens[k]->Current = TempData;
				}
				else
				{
					Tokens[k]->Last->Next = TempData;
					TempData->Prev = Tokens[k]->Last;
					Tokens[k]->Last = TempData;
				}
			}

			if(bracket%2 == 0)
			{	k++;}
				
			c = fgetc(fpIn);
		}
		Count = 0;

		MatchPattern(Dictionary,Tokens,&Count,L,D);
		
		printf("%d\n",Count);
		fprintf(fpOut,"%s%d%c %d\n","Case #",i,':', Count);

		for(k=0;k<L;k++)
		{
			while(Tokens[k]->First != NULL)
			{
				TempData = Tokens[k]->First;
				Tokens[k]->First = Tokens[k]->First->Next;
				free(TempData);
			}
			Tokens[k]->Last = NULL;
		}
		
	}
	

	fclose(fpIn);
	fclose(fpOut);
	printf("Done.");
	getche();
}