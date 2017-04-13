#include <stdio.h>
#include <conio.h>
#include <math.h>

FILE *fi, *fo;			/* file pointer */

struct Sta_A
{
	int* Dep_A;
	int* Arr_A;
};

struct Sta_B
{
	int* Dep_B;
	int* Arr_B;
};

void bsort (int a[], int n)
{
   int i, j;

   for (i = 0; i < n; i++)
      for (j = n-1; j > i; j--)
         if (a[j-1] > a[j]) {
            int temp = a[j-1];

            a[j-1] = a[j];
            a[j] = temp;
         }
}

int main()
{
	int T_time;
	int NA;
	int NB;
	int Trains_frm_A =0, Trains_frm_B = 0, num_cases = 0, Size_Alloc = 0;
	int time = 0, hrs = 0, mins = 0;
	int i,j,cases;
	char line[300];
	char* ptr;

	struct Sta_A Times_A;
	struct Sta_B Times_B;


	fi = fopen("e:\\B-small-attempt3.in.txt", "rt");
	fo = fopen("e:\\B-small-attempt3.out.txt", "wt");

	fgets(line,300, fi);
	num_cases = atoi(line);
	printf("%d\n",num_cases);

	memset(line, NULL, 300);

	for(cases=0; cases<num_cases; cases++)
	{
		memset(line, NULL, 300);
		fgets(line, 300, fi);
		T_time = atoi(line);
		printf("%d\n",T_time);

		memset(line, NULL, 300);
		fgets(line, 300, fi);
		NA = atoi(line);
		printf("%d\n",NA);

		ptr = line;

		while(*ptr != ' ')
			ptr++;
			
		NB = atoi(ptr);
		printf("%d\n",NB);

		Size_Alloc = NA>NB?NA:NB;

		Times_A.Dep_A = (int*)malloc( sizeof(int)* Size_Alloc);
		Times_B.Dep_B = (int*)malloc( sizeof(int)* Size_Alloc);

		Times_A.Arr_A = (int*)malloc( sizeof(int)* Size_Alloc);
		Times_B.Arr_B = (int*)malloc( sizeof(int)* Size_Alloc);

		for(i=0;i<Size_Alloc;i++)
		{
			Times_A.Arr_A[i] = 2500;
			Times_A.Dep_A[i] = 2500;
			Times_B.Arr_B[i] = 2500;
			Times_B.Dep_B[i] = 2500;
		}

		for(i=0;i<NA;i++)
		{
			memset(line, NULL, 300);
			fgets(line, 300, fi);
			printf("%s\n",line);

			ptr = line;

			hrs = atoi(ptr);
			hrs = hrs*100;
			while(*ptr != ':')
				ptr++;
			ptr++;
			mins = atoi(ptr);
			Times_A.Dep_A[i] = hrs+mins;

			while(*ptr != ' ')
				ptr++;

			hrs = atoi(ptr);
			hrs = hrs*100;
			while(*ptr != ':')
				ptr++;
			ptr++;
			mins = atoi(ptr);
			Times_B.Arr_B[i] = hrs+mins;
		}
		
		for(i=0;i<NB;i++)
		{
			memset(line, NULL, 300);
			fgets(line, 300, fi);
			printf("%s\n",line);

			ptr = line;

			hrs = atoi(ptr);
			hrs = hrs*100;
			while(*ptr != ':')
				ptr++;
			ptr++;
			mins = atoi(ptr);
			Times_B.Dep_B[i] = hrs+mins;

			while(*ptr != ' ')
				ptr++;

			hrs = atoi(ptr);
			hrs = hrs*100;
			while(*ptr != ':')
				ptr++;
			ptr++;
			mins = atoi(ptr);
			Times_A.Arr_A[i] = hrs+mins;
		}

		for(i=0;i<NA;i++)
		{
			printf("%d   %d\n",Times_A.Dep_A[i], Times_B.Arr_B[i]);
		}
		for(i=0;i<NB;i++)
		{
			printf("%d   %d\n",Times_B.Dep_B[i], Times_A.Arr_A[i]);
		}

// SORTING THE TIMES
		bsort(Times_A.Dep_A, NA);
		bsort(Times_B.Arr_B, NA);
		bsort(Times_B.Dep_B, NB);
		bsort(Times_A.Arr_A, NB);

		j = 0;
		for(i=0; i<NA; i++)
		{
			if(Times_A.Dep_A[i] < Times_A.Arr_A[j] + T_time)
			{
				Trains_frm_A++;
			}
			else
				j++;
		}

		j = 0;
		for(i=0; i<NB; i++)
		{
			if(Times_B.Dep_B[i] < Times_B.Arr_B[j] + T_time)
			{
				Trains_frm_B++;
			}
			else
				j++;
		}

		printf("%d   %d\n\n",Trains_frm_A, Trains_frm_B);
		fprintf(fo,"Case #%d: %d %d\n", cases+1,Trains_frm_A,Trains_frm_B);
		Trains_frm_A = 0;
		Trains_frm_B = 0;
	}

	fcloseall();
	getchar();
	return 0;

}

