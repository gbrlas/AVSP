#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 4

int main()
{
	FILE *in_ptr,*out_ptr;
	int match_found=0;
	int Testcase=1,T,num, input_row1, input_row2,i,j;
	int grid1[SIZE][SIZE],grid2[SIZE][SIZE];


    in_ptr=fopen("in.txt","r+");
    if(in_ptr == NULL)
    {
		printf("\n\n CANNOT OPEN INPUT FILE! \n EXITING...");
		exit (1);
    }
    
	out_ptr=fopen("out.txt","w+");
	if(out_ptr == NULL)
    {
		printf("\n\n CANNOT OPEN OUTPUT FILE! \n EXITING...");
		fclose(in_ptr);
		exit (1);
    }
	

	fscanf(in_ptr,"%d",&T);

	while(1)
    {
		match_found=0;

        if(T==0)
            break;
		
  		fscanf(in_ptr,"%d",&input_row1);

		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				fscanf(in_ptr,"%d",&grid1[i][j]);
 			}
		}
		

		fscanf(in_ptr,"%d",&input_row2);

		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				fscanf(in_ptr,"%d",&grid2[i][j]);
    		}
		}

		for(i=0;i<SIZE;i++)
		{
            for(j=0;j<SIZE;j++)
			{
				if(grid1[input_row1-1][i]==grid2[input_row2-1][j])
				{
				  num=grid1[input_row1-1][i];
				  match_found++;
				}
			}
	    }
	    
	    if(match_found==0)
	    {
		  fprintf(out_ptr,"Case #%d: Volunteer cheated!\n",Testcase);
	    }
	    else if( match_found==1)
	    {
           fprintf(out_ptr,"Case #%d: %d\n",Testcase,num);
	    }
	    else
	    {
		   fprintf(out_ptr,"Case #%d: Bad magician!\n",Testcase);
	    }
	    
	    
		Testcase++;
		T--;
		
	}
	
	
  	fclose(in_ptr);
   	fclose(out_ptr);
  
}
