// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * input, * output;

	char orginal [8];
	char sandbox [8];

	input = fopen("inLarge.txt","r");
	output = fopen("out.txt","w");

	char tab [250005];

	if (input!=NULL)
	{
		int nr = 1;
		int ile;
		fscanf(input, "%d", &ile);
		while (ile--) {

			for (int i=0; i<sizeof(tab); i++)
				tab[i]=0;

			int A,B;
			fscanf(input, "%d %d", &A, &B);

			int times=0;

			for (int number=A; number<=B; number++) {
				
				if (tab[ number / 8 ] & (1 << number % 8))
					continue;
				
				//czyszczenie pojemniczkow
				for (int i=0; i<8; i++)
				{
					sandbox[i]=0;
					orginal[i]=0;
				}

				//zdobywamy liczbe
				itoa(number, orginal, 10);
				int digits = strlen(orginal);
				int counter = 0;

				for (int dig=0; dig<digits; dig++)
				{
					memcpy(sandbox, orginal + digits - dig, dig);	//koncoweczka na poczatek
					memcpy(sandbox + dig, orginal, digits - dig);	//poczatek na koniec

					int copy = atoi(sandbox);

					if (copy>=A && copy<=B &&!(tab[ copy / 8 ] & (1 << copy % 8)) && sandbox[0]!='0') //nie bylo jeszcze zaznaczone i rozne od zera
					{
						tab[ copy / 8 ]|= (1 << copy % 8);

						counter++;
					}
				}

				int adder=0;
				for (int i=1; i<=counter-1; i++)
					adder+=i;

				times += adder;

			}

			fprintf(output, "Case #%d: %d%s", nr, times, ile!=0?"\n":"" );
			nr++;
		}
		fclose (output);
		fclose (input);
	}

	return 0;
}