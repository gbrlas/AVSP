// TrainTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct __NODE
{
	int time;
	struct __NODE *left;
	struct __NODE *right;
	int availind;
}NODE;

void insert(NODE **root, int time, int ind);
void calculateTrains(NODE* table, int* count, int* trainsAvailable);
void remove(NODE* table);

int main(int argc, char* argv[])
{
	/* Problem variables */
	int turn_time = 0;
	int na = 0;
	int nb = 0;
	int ta = 0;
	int tb = 0;
	NODE* a_table = NULL;
	NODE* b_table = NULL;
	int shr = 0;
	int smin = 0;
	int dhr = 0;
	int dmin = 0;
	int trainsAvailable=0;
	
	/* Other variables */
	int i = 0;
	int j = 0;

	/* File Handling */
	FILE *fp_in=NULL, *fp_out=NULL;
	//char line[20];
	int num_case = 0;

	fp_in = fopen("D:\\Jam\\Prob2\\B-small-attempt3.in","r");
	fp_out = fopen("D:\\Jam\\Prob2\\B-small.out","w");

	fscanf(fp_in, "%d\n", &num_case);

	for(i=0;i<num_case;i++)
	{
		ta = 0;
		tb = 0;
		// Reading Turnaround time
		fscanf(fp_in, "%d\n", &turn_time);

		// Reading NA and NB
		fscanf(fp_in, "%d %d\n", &na, &nb);
	
		// Tree creation and merging of available train times and schedules times
		for(j=0; j<na; j++)
		{
			fscanf(fp_in, "%d:%d %d:%d",&shr,&smin,&dhr,&dmin);
			insert(&a_table, shr*60+smin, 0);
			insert(&b_table, dhr*60+dmin+turn_time, 1);
		}
	
		for(j=0; j<nb; j++)
		{
			fscanf(fp_in, "%d:%d %d:%d",&shr,&smin,&dhr,&dmin);
			insert(&b_table, shr*60+smin, 0);
			insert(&a_table, dhr*60+dmin+turn_time, 1);
		}

		trainsAvailable=0;
		calculateTrains(a_table, &ta, &trainsAvailable);
		trainsAvailable=0;
		calculateTrains(b_table, &tb, &trainsAvailable);

		// Printing Logic
		fprintf(fp_out,"Case #%d: %d %d\n",i+1, ta, tb);

		remove(a_table);
		remove(b_table);

		a_table=0;
		b_table=0;
	}

	return 0;
}

void calculateTrains(NODE* table, int* count, int *trainsAvailable)
{
	if(table->left)
		calculateTrains(table->left, count, trainsAvailable);

	if(table->availind)
	{
		(*trainsAvailable)++;
	}
	else
	{
		if(!(*trainsAvailable))
		{
			(*count)++;
		}
		else
		{
			(*trainsAvailable)--;
		}
	}

	if(table->right)
		calculateTrains(table->right, count, trainsAvailable);
}

void insert(NODE **root, int time, int ind)
{
	NODE *t = *root;
	NODE *prev = NULL;
	NODE *newNode = NULL;

	while(t)
	{
		prev = t;
		if(t->time < time)
		{
			t = t->right;
		}
		else if(t->time == time)
		{
			if(ind)
				t=t->left;
			else
				t=t->right;
		}
		else
		{
			t = t->left;
		}
	}

	newNode = (NODE*)malloc(sizeof(NODE));
	newNode->time = time;
	newNode->availind = ind;
	newNode->left = NULL;
	newNode->right = NULL;

	if(prev)
	{
		if(prev->time < time)
			prev->right = newNode;
		else if(prev->time == time)
		{
			if(ind)
				prev->left = newNode;
			else
				prev->right = newNode;

		}
		else
			prev->left = newNode;
	}
	else
	{
		*root = newNode;
	}
}

void remove(NODE* table)
{
	if(table)
	{
		remove(table->left);
		table->left=NULL;
		remove(table->right);
		table->right=NULL;
		free(table);
	}
}