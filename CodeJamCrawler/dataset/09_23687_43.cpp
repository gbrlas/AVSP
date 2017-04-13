#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node
{
 char alpha;
 int index;
}NODE;

NODE * dict= 0,*nodeptr;

#define DPRINTF(args...)  

char input[] = "welcome to code jam";
int indices[19];

main(int argc , char * argv[])
{
FILE * fp;
int i,j,k,temp,pos,length;
unsigned int num_tests = 0,wordlen=0, num_words=0;
char str1[101];
char line[5000],*ptr1,*ptr2;
unsigned int *masks=0;
int flag;
unsigned long long matches = 0;
int stackptr;


if(argc !=2)
        {
        DPRINTF("Usage %s <input-file>\n",argv[0]);
        exit(2);
        }
fp = fopen(argv[1],"r");
if ( NULL == fp )
        {
        DPRINTF("Input file not found . aborting \n");
        exit(1);
        }
fgets(line,1000,fp);
sscanf(line,"%d",&num_tests);
DPRINTF(" tests=%d\n",num_tests);

for (i=0; i< num_tests; i++)
	{
	fgets(line,1000,fp);
	for(j=0;j<19;j++,indices[j]=-1);
	DPRINTF("Test case %d is: %s\n",i+1,line);
	ptr1 = line;
	flag =1;
	pos = 0;
	matches = 0;
	length = strlen(line);
	for(j=0;j<19;j++)
		{
                if(j) pos = indices[j-1] + 1;

		while ( (pos < length) && (input[j] != ptr1[pos]))
			{
			pos++;
			}
		if(pos < length)
			{
			indices[j]= pos;
			}
		else
			{
			flag = 0 ;
			break;
			}
		   
		}
	if(flag)
		{
		DPRINTF("Found atleast one match. Base indices are..\n");
		for(k=0;k<19;k++)
			DPRINTF("[%d]%c:%d ",k,input[k],indices[k]);
		DPRINTF("\n");

		matches++;

		stackptr = 18;

		pos = indices[stackptr] + 1;

wind:
                DPRINTF("Pos=%d len=%d stackptr=%d index=%d\n",pos,length,stackptr,indices[stackptr]);
		while ( (pos < length) && (input[stackptr] != ptr1[pos]))
			{
			pos++;
			}
		if( pos < length)
			{
			DPRINTF("Match:<%c>at%d id=%d\t",ptr1[pos],pos,stackptr);
			if (stackptr == 18)
				{
				indices[stackptr] =pos;
				matches++;
				matches =matches % 10000;
				pos++;
				goto wind;
				}
			indices[stackptr]=pos;
			stackptr++;
			//pos = indices[stackptr-1] + 1;
			indices[stackptr]=-1;
			pos++;
			goto wind;
			}
		else
			{
			stackptr--;
			if(stackptr >= 0)
				{
				pos = indices[stackptr] + 1;
                        	goto wind;
				}
			}
		
		}
	else
		{
		DPRINTF("No match found for %s\n",line);
		}

		DPRINTF("Number of matches for Test case %d = %u\n",i+1,matches);
		printf("Case #%d: %04d\n",i+1,matches);
	}
	

}
