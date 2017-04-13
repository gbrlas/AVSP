#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
 int hour;
 int min;
 int cum;
 struct node * next;
}NODE;

typedef struct list
{
 	NODE * head;
}LIST;

#define DPRINTF(args...)

static inline parse(char *str, NODE * A, NODE *B)
{
char start[10],finish[10];
int th,tm;

sscanf(str,"%d:%d %d:%d",&A->hour,&A->min,&B->hour,&B->min);
A->cum = A->hour * 60 + A->min;
B->cum = B->hour * 60 + B->min;
DPRINTF("Parsed %02d:%02d %02d:%02d \n",A->hour,A->min,B->hour,B->min);
}

/* insertion into sorted list */
/* If time permits convert this to a binary tree */
static inline int ins_list(LIST * l, NODE * node)
{

node->next = NULL;

if(l->head == NULL)
	{
	l->head = node;
	}
else
	{
	NODE *ptr,*prev;

	ptr = l->head;
	prev = NULL;
	while ( ptr && (node->cum > ptr->cum))
		{
		prev = ptr;
		ptr = ptr->next;
		}
	if(prev == NULL)
		{
		/* add node at the head */
		node->next = l->head;
		l->head = node ;
		}
	else
		{
		node->next = prev->next;
		prev->next = node;
		}
	
	}
}
 
LIST a_dep={0},b_arr={0},b_dep={0},a_arr={0};
main(int argc , char * argv[])
{
FILE * fp;
int i,j,k,temp;
unsigned int num_tests = 0,delay=0;
unsigned int a2bcnt=0,b2acnt=0;
char str1[101];
char line[1000];
NODE * freeList,*freehead;
NODE * aPtr,*dPtr;
unsigned int acnt,bcnt;

if(argc !=2)
	{
	DPRINTF("Usage %s <input-file>\n");
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
DPRINTF(" Number of test cases %d\n",num_tests);

for (i=0; i < num_tests; i++)
        {
	acnt = bcnt = 0;
	fgets(line,1000,fp);
        sscanf(line,"%d",&delay);

	DPRINTF(" Turn around time =  %d \n",delay);
	
	fgets(line,1000,fp);
        sscanf(line,"%d %d",&a2bcnt,&b2acnt);

	DPRINTF("a2bcnt= %d  b2acnt=%d\n",a2bcnt,b2acnt);

	/*allocate memory for nodes: one Node per time elem */
	freehead = (NODE*)calloc(((a2bcnt+b2acnt)*2),sizeof(NODE));
	freeList = freehead;

	for(j=0;j<a2bcnt;j++)
		{
		NODE *aNode, *bNode;
		
		fgets(line,1000,fp);
		aNode = freeList++;
		bNode = freeList++;
		parse(line,aNode,bNode);
		ins_list(&a_dep,aNode);
		ins_list(&b_arr,bNode);
		}
	
	for(j=0;j<b2acnt;j++)
		{
		NODE *aNode, *bNode;

		fgets(line,1000,fp);
		aNode = freeList++;
		bNode = freeList++;
		parse(line,aNode,bNode);
		ins_list(&b_dep,aNode);
		ins_list(&a_arr,bNode);
		}
			
	{
	NODE *ptr;
	ptr = a_dep.head;
	DPRINTF("A departure list..\n");
	while(ptr)
		{
		DPRINTF("%d:%d->",ptr->hour,ptr->min);
		ptr = ptr->next;
		}
	DPRINTF("\n");
	}

	/* run through A departure list and compate against arrival list */
	dPtr = a_dep.head;
	aPtr = a_arr.head;
	while(dPtr)
		{
		if( (aPtr) && ( (aPtr->cum + delay) <= dPtr->cum) )
			{
			aPtr = aPtr->next;
			}
		else
			{
			acnt++;
			}
		dPtr = dPtr->next;
		}
	
	/* run through B departure list and compare against arr list */
	dPtr = b_dep.head;
	aPtr = b_arr.head;
	while(dPtr)
		{
		if( (aPtr) && ( (aPtr->cum + delay) <= dPtr->cum) )
			{
			aPtr = aPtr->next;
			}
		else
			{
			bcnt++;
			}
		dPtr = dPtr->next;
		}
	
	printf("Case #%d: %d %d \n",i+1,acnt,bcnt);

	/* clean up and start all over again */
	free(freehead);
	freeList = NULL;
	a_dep.head = a_arr.head = b_dep.head = b_arr.head = 0;
	
	}

}
