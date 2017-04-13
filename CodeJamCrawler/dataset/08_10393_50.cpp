// SaveUniverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct __NODE
{
	char* search_engine;
	struct __NODE *link;
}NODE;

int insert(NODE** head, char* line);
void remove(NODE** head);

int main(int argc, char* argv[])
{
	int num_se = 0;

	NODE* hash[91];
	int switches=0;
	int num_qr = 0;
	int uniq_qr = 0;

	/* Loop variables */
	int i;
	int j;
	int k;
	int l;

	/* File handling */
	FILE *fp_in=NULL, *fp_out=NULL;
	char line[100];
	int num_case = 0;

	for(k=0;k<91;k++)
		hash[k] = NULL;

	fp_in = fopen("D:\\Jam\\A-large.in","r");
	fp_out = fopen("D:\\Jam\\A-large.out","w");

	fscanf(fp_in, "%d\n", &num_case);

	for(i=0;i<num_case;i++)
	{
		switches=0;
		uniq_qr=0;

		fscanf(fp_in, "%d\n", &num_se);
		for(j=0;j<num_se;j++)
		{
			// Reading search engines but not using them
			fgets(line, sizeof(line)-1, fp_in);
		}

		// Reading the queries
		fscanf(fp_in, "%d\n", &num_qr);
		for(l=0;l<num_qr;l++)
		{
			fgets(line, sizeof(line)-1, fp_in);
			// If a new insert has been done, then increment unique count
			if(!insert(&hash[line[0]-32], line))
				uniq_qr++;

			// Switch required now...
			if(uniq_qr == num_se)
			{
				switches++;
				uniq_qr=0;
				// Free the hash for the next set
				for(k=0; k<91; k++)
				{
					remove(&hash[k]);
					hash[k] = NULL;
				}
				if(!insert(&hash[line[0]-32], line))
					uniq_qr++;
			}
		}
			


		// Printing Logic
		fprintf(fp_out,"Case #%d: ",i+1);
		fprintf(fp_out,"%d\n", switches);

		// Free the hash for next case
		for(k=0; k<91; k++)
		{
			remove(&hash[k]);
			hash[k] = NULL;
		}
	}

	return 0;
}

int insert(NODE** head, char* line)
{
	NODE* t = *head;
	NODE* newNode;
	while(t && strcmp(t->search_engine, line))
	{
		t=t->link;
	}
	if(t)
	{
		return(1);
	}

	newNode = (NODE*)malloc(sizeof(NODE));
	newNode->search_engine = (char*)malloc((strlen(line)+1)*sizeof(char));
	strcpy(newNode->search_engine, line);
	newNode->link = *head;
	*head = newNode;
	return(0);
}

void remove(NODE** head)
{
	NODE* t; 
	while(*head)
	{
		free((*head)->search_engine);
		t = *head;
		*head = (*head)->link;
		free(t);
	}
}

