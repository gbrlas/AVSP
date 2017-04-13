#include <stdio.h>
#include <math.h>

//20 0000 0000

#define NMAX 32

int T, N;

int Data[ NMAX ];
int Size[ NMAX ];

double Calc;
double e =  2.7182818284590452353602874;
double Result;

char Temp[1000];

int Flag;

void Init()
{
	//5.2360679774997896964091736687313
	Data[ 0 ] = 5;
	Data[ 1 ] = 27;
	Data[ 2 ] = 143;
	Data[ 3 ] = 751;
	Data[ 4 ] = 935;
	Data[ 5 ] = 607;
	Data[ 6 ] = 903;
	Data[ 7 ] = 991;
	Data[ 8 ] = 335;
	Data[ 9 ] = 47;

	Data[ 10 ] = 943;
	Data[ 11 ] = 471;
	Data[ 12 ] = 55;
	Data[ 13 ] = 447;
	Data[ 14 ] = 463;
	Data[ 15 ] = 991;
	Data[ 16 ] = 95;
	Data[ 17 ] = 607;
	Data[ 18 ] = 263;
	Data[ 19 ] = 151;

	Data[ 20 ] = 855;
	Data[ 21 ] = 527;
	Data[ 22 ] = 743;
	Data[ 23 ] = 351;
	Data[ 24 ] = 135;
	Data[ 25 ] = 407;
	Data[ 26 ] = 903;
	Data[ 27 ] = 791;
	Data[ 28 ] = 135;
	Data[ 29 ] = 647;
}

/*void Process()
{
	int i;
	//Calc = log(5.2360679774997896964091736687313);
	//Calc *= (double) N;
	Calc = 5.2360679774997896964091736687313;
	Result = pow(Calc, N);
	sprintf(Temp, "%lf", Result);
	for(i = 0; i < 1000; i++)
	{
		if(Temp[ i ] == '.')
		{
			Flag = i;
			break;
		}
	}
}*/

int main()
{
	int i;

	FILE *in = fopen("C.in", "r");
	FILE *out = fopen("C.txt", "w");
	
	Init();

	fscanf(in, "%d", &T);
	for(i = 0; i < T; i ++)
	{
		fscanf(in,"%d", &N);
		//Process();
		fprintf(out, "Case #%d: ", (i + 1));
		if(Data[ N - 1 ] < 10)
			fprintf(out, "00");
		if(Data[ N - 1 ] < 100)
			fprintf(out, "0");
		fprintf(out, "%d\n", Data[ N - 1 ]);
		/*if((Flag - 3) < 0)
			fprintf(out, "0");
		else
			fprintf(out, "%c", Temp[Flag - 3]);
		if((Flag - 2) < 0)
			fprintf(out, "0");
		else
			fprintf(out, "%c", Temp[Flag - 2]);
		if((Flag - 1) < 0)
			fprintf(out, "0");
		else
			fprintf(out, "%c", Temp[Flag - 1]);
		fprintf(out, "\n");*/
	}
	fclose( in );
	fclose( out );
	return 0;
}
