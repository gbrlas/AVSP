#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node
{
 char word[16];
 int index;
}NODE;

NODE * dict= 0,*nodeptr;

#define DPRINTF(args...) 


main(int argc , char * argv[])
{
FILE * fp;
int i,j,k,temp,pos;
unsigned int num_tests = 0,wordlen=0, num_words=0,matches=0;
char str1[101];
char line[5000],*ptr1,*ptr2;
unsigned int *masks=0;
int flag;


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
sscanf(line,"%d %d %d",&wordlen,&num_words,&num_tests);
DPRINTF(" wlen=%d nwords=%d tests=%d\n",wordlen,num_words,num_tests);


DPRINTF("Allocating Dictionary for %d words \n",num_words);
dict = calloc(num_words , sizeof(NODE));
nodeptr = dict;
DPRINTF("ADDR :%x\n",dict);
for (i=0; i< num_words; i++)
	{
	fgets(line,1000,fp);
	nodeptr[i].index = i;
	strncpy(nodeptr[i].word,line,wordlen);
	DPRINTF("Word %d is: %s\n",i+1,nodeptr[i].word);
	}
masks = calloc(wordlen,sizeof(unsigned int));

for(k=0; k< num_tests; k++)
	{
	fgets(line,1000,fp);
	bzero(masks,(wordlen * sizeof(unsigned int)) );
	DPRINTF("Pattern %s\n",line);
        ptr1 = line;
        for(j=0;j<wordlen;j++)
		{
                  if(*ptr1 == '(')
		   {
		   ptr1++;
		   do
		   	{
			pos = (*ptr1) - 'a';
			masks[j] |= ( 1 << pos);
			ptr1++;
			}while(*ptr1 != ')');
		   }
		   else
		   {
		   /* its a single character pattern */
			pos = (*ptr1) - 'a';
			masks[j] = (1 << pos);
		   }
		   ptr1++;
		   DPRINTF("Mask[%d]=0x%x\n",j,masks[j]);
		}
	DPRINTF("Masks set up. Lets scan the dictionary now \n");

	matches =0 ;
	nodeptr=dict;
	for(i=0; i<num_words; i++)
		{
		ptr1 = nodeptr[i].word;
		flag =1;
		for(j=0;j<wordlen;j++)
			{
			 pos = (*ptr1) - 'a' ;
			 if ( !( masks[j] &  (1 << pos)) ) 
				{
				flag=0;
				break;
				}
			 ptr1++;
			}
		if (flag) 
			{
			matches++;
			DPRINTF("%s matches pattern \n",nodeptr[i].word);
			}
			
			
		}
	DPRINTF("Number of matches for Test pattern %d is %d \n",k,matches);
	printf("Case #%d: %d\n", k+1, matches);
	
        
	
	}

}
