#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	100

struct time_table
{
	short s_hour;
	short s_min;
	short e_hour;
	short e_min;
	char station;
	short go;
	short num;	
} AtoB[MAX], BtoA[MAX];

void processing(int NA, int NB, int T);
void check_all(int num, char station, int size);
void output(int A, int B);
void sort_e(struct time_table* x, int n);
void sort_s(struct time_table* x, int n);
struct time_table* mearge_table(struct time_table*, int NA, int NB);
void re(struct time_table* arr, int hour, int min, int size, char station);
void re2(struct time_table* arr, int hour, int min, int size, char station);

FILE* out;
struct time_table* end;
struct time_table* start;
int T;

int main(void)
{
	FILE* in;

	int n;	
	int NA, NB;
	int i, j;
	char ch;

	in = fopen("B-large.in","r");
	out = fopen("out", "wt");


	fscanf(in, "%d", &n);
	for(i=0; i < n; i++)
	{
		fscanf(in, "%d %d %d", &T, &NA, &NB);
		for(j=0; j < NA; j++)
		{
			fscanf(in, "%d%c%d", &AtoB[j].s_hour, &ch, &AtoB[j].s_min);
			fscanf(in, "%d%c%d", &AtoB[j].e_hour, &ch, &AtoB[j].e_min);
			AtoB[j].go = 0;
			AtoB[j].station = 'A';
			AtoB[j].num = j;
		}
		for(j=0; j < NB; j++)
		{
			fscanf(in, "%d%c%d", &BtoA[j].s_hour, &ch, &BtoA[j].s_min);
			fscanf(in, "%d%c%d", &BtoA[j].e_hour, &ch, &BtoA[j].e_min);
			BtoA[j].go = 0;
			BtoA[j].station = 'B';
			BtoA[j].num = j;
		}
		processing(NA, NB, T);
	}

	return 0;
}

void processing(int NA, int NB, int T)
{
	int i;
	int hour, min;
	int n_A = 0;
	int n_B = 0;

	end = mearge_table(end, NA, NB);
	start = mearge_table(start, NA, NB);
	sort_e(end, NA+NB);
	sort_s(start, NA+NB);

	for(i=0; i < NA+NB; i++)
	{
		if(end[i].go==1) continue;

		hour = end[i].e_hour;
		min = end[i].e_min + T;
		if(min >= 60)
		{
			hour++;
			min -= 60;
		}
		check_all(end[i].num, end[i].station, NA+NB);

		re(start, hour, min, NA+NB, end[i].station);

		if(end[i].station=='A') n_A++;
		else n_B++;
	}

	output(n_A, n_B);
}

void re(struct time_table* arr, int hour, int min, int size, char station)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		if( (arr[i].s_hour > hour || ( (arr[i].s_hour==hour) && (arr[i].s_min >=min) )) && arr[i].go==0
			&& arr[i].station!=station)
		{
			check_all(arr[i].num, arr[i].station, size);
			hour = arr[i].e_hour;
			min = arr[i].e_min + T;
			if(min >=60)
			{
				hour++;
				min -= 60;
			}
			if(station=='A') re(start, hour, min, size, 'B');
			else re(start, hour, min, size, 'A');
			break;
		}
	}
}

void re2(struct time_table* arr, int hour, int min, int size, char station)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		if((arr[i].e_hour > hour || ( (arr[i].e_hour==hour) && (arr[i].e_min >=min) )) && arr[i].go==0
			&& arr[i].station!=station)
		{
			check_all(arr[i].num, arr[i].station, size);
			if(station=='A') re(start, arr[i].s_hour, arr[i].s_min, size, 'B');
			else re(start, arr[i].s_hour, arr[i].s_min, size, 'A');
			break;
		}
	}
}

void check_all(int num, char station, int size)
{
	int i;
	for(i=0; i < size; i++)
	{
		if(end[i].num==num && end[i].station==station)
		{
			end[i].go = 1;
			break;
		}
	}
	for(i=0; i < size; i++)
	{
		if(start[i].num==num && start[i].station==station)
		{
			start[i].go = 1;
			break;
		}
	}
}

struct time_table* mearge_table(struct time_table* All, int NA, int NB)
{	
	All = (struct time_table *) calloc(sizeof(struct time_table), NA+NB);

	memcpy(All, &AtoB, sizeof(struct time_table) * NA);
	memcpy(All+NA, &BtoA, sizeof(struct time_table) * NB);

	return All;
}

void sort_e(struct time_table* x, int n)
{
	int i, j;
	struct time_table temp;

	for(i=0; i < n; i++)
	{
		for(j=i; j < n; j++)
		{
			if(x[i].e_hour > x[j].e_hour || (x[i].e_hour==x[j].e_hour) && (x[i].e_min > x[j].e_min))
			{
				memcpy(&temp, &x[i], sizeof(struct time_table));
				memcpy(&x[i], &x[j], sizeof(struct time_table));
				memcpy(&x[j], &temp, sizeof(struct time_table));
			}
		}
	}
}

void sort_s(struct time_table* x, int n)
{
	int i, j;
	struct time_table temp;

	for(i=0; i < n; i++)
	{
		for(j=i; j < n; j++)
		{
			if(x[i].s_hour > x[j].s_hour || (x[i].s_hour==x[j].s_hour) && (x[i].s_min > x[j].s_min))
			{
				memcpy(&temp, &x[i], sizeof(struct time_table));
				memcpy(&x[i], &x[j], sizeof(struct time_table));
				memcpy(&x[j], &temp, sizeof(struct time_table));
			}
		}
	}
}

void output(int A, int B)
{
	static int n = 1;

	fprintf(out, "Case #%d: %d %d\n", n, A, B);
	n++;
}
