#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "GeneralHashFunctions.h"

typedef struct 
{
	char name[102];
	struct SvrNode * next;
	unsigned int hash;
	unsigned int count;
}SvrNode;

typedef struct 
{
	SvrNode * head;	
	SvrNode * last;
}HashBkt;

#define DPRINTF(args...)  

main(int argc , char * argv[])
{
FILE * fp;
int num_tests=0,num_servers=0,num_queries=0;
int i,j,k,temp;
char str1[101];
char line[1000];
HashBkt * table;
int runlen_change_count = 0, max_runlength = 0, current_run = 0i,switch_count =0;

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
	fgets(line,1000,fp);
	sscanf(line,"%d",&num_servers);
	DPRINTF(" Number of servers %d for case %d\n",num_servers,i+1);

	table = malloc(sizeof(HashBkt) * num_servers);
	memset(table,0,(sizeof(HashBkt) * num_servers));
	switch_count = 0;

	/* read server strings */
	DPRINTF("servers \n");
	for (j=0; j< num_servers;j++)
		{
		unsigned int hashval,index;
		SvrNode *svrPtr,*tempPtr;
		
		fgets(str1,101,fp);
		str1[strlen(str1) - 1]='\0';
		hashval = JSHash(str1,strlen(str1));
		index = hashval % num_servers;
                
		/*add the node to right bucket */
		DPRINTF("Add server %s to bkt %d head=%d tail=%u\n",str1,index,table[index].head,table[index].last);
		svrPtr = malloc(sizeof(SvrNode));
		if(svrPtr == NULL)
			{
			DPRINTF("Unable to allocate memory.Aborting\n");
			exit(3);
			}
		svrPtr->hash = hashval;
		svrPtr->next = NULL;
		strncpy(svrPtr->name,str1,100);
		svrPtr->count = 0;
		if(!table[index].last)
			{
			 table[index].head = svrPtr;
			 table[index].last = svrPtr;
			}
		else
			{
			table[index].last->next = svrPtr;
			table[index].last = svrPtr;
			}
		
		DPRINTF("%s %d hash=%d\n",str1,j+1,hashval);
		}
	
	fgets(line,1000,fp);
	sscanf(line,"%d",&num_queries);
	DPRINTF(" Number of queries%d for case %d\n",num_queries,i+1);

	/* set max running length of queries to max value */
	max_runlength = num_queries;
	for(j=0;j<num_servers;j++)
		{
		 SvrNode *svrPtr,*tempPtr;

		 svrPtr = table[j].head;

		 while(svrPtr)
		 	{
			svrPtr->count = max_runlength;
			svrPtr = svrPtr->next;
			}
		}

        runlen_change_count = num_servers;
	current_run =0;
	
	/* read query strings */
	DPRINTF("query \n");
	for (j=0; j< num_queries;j++)
		{
		unsigned int hashval,index;
		SvrNode  *svrPtr,*tempPtr;

		fgets(str1,100,fp);
		str1[strlen(str1) - 1]='\0';
		hashval = JSHash(str1,strlen(str1)) ;
		DPRINTF("%s %d hash=%d\n",str1,j+1,hashval);
		current_run++;

		index = hashval % num_servers;
		svrPtr = table[index].head;
		DPRINTF("^^^^^^ index=%d head=%u last=%u\n",index,table[index].head,table[index].last);
		while(svrPtr)
			{
			DPRINTF("@@@@@ %d @@@@",svrPtr->hash);
			if(svrPtr->hash == hashval)
				{
				/*server match */
				DPRINTF("svrCnt=%d name=%s at %u max_run=%d\n",svrPtr->count,svrPtr->name,svrPtr,max_runlength);
				if(svrPtr->count == max_runlength)
					{
					runlen_change_count--;
					DPRINTF("Server Match %s count=%d runlen=%d\n",svrPtr->name,svrPtr->count,runlen_change_count);
					if(0 == runlen_change_count)
						{
						/*we need to swtich servers here and reset logic */
						switch_count++;
						//printf("switching off %s \n",svrPtr->name);

						/*reset state machine */
						max_runlength = num_queries - (j+1);
						runlen_change_count = num_servers - 1;/*exclude chosen server */
						current_run = 0;

						for(k=0;k<num_servers;k++)
							{
							SvrNode *tempPtr;

							tempPtr = table[k].head;
							while(tempPtr)
								{
								tempPtr->count = max_runlength;
								DPRINTF("reset Server %s at %u  Max to %d\n",tempPtr->name,tempPtr,tempPtr->count);
								tempPtr = tempPtr->next;
								}
							}
						/*exclude chosen server from comparison */
						svrPtr->count = 0;
						break;
						}
					}
				if(svrPtr->count > current_run)
					{
					svrPtr->count = current_run;
					}
				break;
				}
			else
				{
				svrPtr = svrPtr->next;
				}
			}
		
		}
	
	printf("Case #%d: %d \n",i+1,switch_count);
	
	/* free allocated memory here*/
	for(k=0;k< num_servers;k++)
		{
		SvrNode *svrPtr,*tempPtr;

		svrPtr = table[k].head;
		while(svrPtr)
			{
			tempPtr = svrPtr;
			svrPtr = svrPtr->next;
			free(tempPtr);
			}
		}
	free(table);
	}/* end of for loop over num_tests */
fclose(fp);
}

