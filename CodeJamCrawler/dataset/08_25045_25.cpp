#include <stdlib.h>
#include <stdio.h>


typedef struct _Server
{
	char name[102];
	int check;
} Server;

// main start

int main(int argc , char *argv[])
{
	FILE *ip,*op;

	int i,j,k,l,ncase,nserver,nswitch=0,nq,count;
	char buff[102];
	if(argc != 2)
	{
		printf("Error:\n");
		printf("Usage: universe <input file>\n");
		printf("Example: universe A-small-attempt0.in\n");
		exit(1);
	}
	ip = fopen(argv[1] , "r");
	if( ip == NULL )
	{
		printf("error in opening file");
	}

	// Read from the file 
	
	fscanf(ip,"%d",&ncase);
	Server *sname = NULL;
	for(i = 0; i < ncase ; i++)
	{
		fscanf(ip,"%d",&nserver);
		fgetc(ip);
		sname = (Server *) calloc(nserver,sizeof(Server));
		//. create memory for server names
		nswitch=0;
		count=nserver;
		for( j = 0 ; j < nserver ;j++)
		{
			
			fgets(sname[j].name,101,ip);
			sname[j].check = 0;
		}

		fscanf(ip,"%d",&nq);
		fgetc(ip);
		for( j = 0 ; j < nq ; j++)
		{
			fgets(buff,101,ip);
						
			for(k = 0 ; k < nserver ; k++)
			{
				if(strcmp(buff,sname[k].name) == 0)
				{
					if(sname[k].check==0)
					{
						sname[k].check++;
						count--;
						if(count==0)
						{
							nswitch++;
							count = nserver-1;
							for(l=0;l<nserver;l++)
							{
								if(l!=k)
								{
									sname[l].check = 0;
								}
							}
							
						}
					}
					
					break;
				}
			}
		}
		printf("Case #%d: %d\n",i+1,nswitch); 
		free(sname);
	}
	return 0;
}
