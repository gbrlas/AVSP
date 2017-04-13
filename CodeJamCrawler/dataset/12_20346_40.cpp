// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * input, * output;

	char bufor [102];
	char wynik [102];
	char pusta [102];
	char * wrogie = " abcdefghijklmnopqrstuvwxyz";
	char * trans  = " yhesocvxduiglbkrztnwjpfmaq";

	input = fopen("in.txt","r");
	output = fopen("out.txt","a");

	for (int i=0; i<sizeof(pusta); i++)
		pusta[i]='\0';

	if (input!=NULL)
	{
		int nr = 1;
		int ile;
		fgets(bufor, 102, input);
		ile = atoi(bufor);
		while (ile--) {
			fgets(bufor, 102, input);

			char c;

			int j=0;
			while(true)
			{
				c = bufor[j];
				if (c=='\n' || c=='\r' || c=='\0')
				{
					wynik[j]='\0';
					break;
				}
				else
					for (int i=0; i<27; i++)
						if (c==wrogie[i])
						{
							wynik[j]=trans[i];
							break;
						}
				j++;
			}

			fprintf(output, "Case #%d: %s%s", nr, wynik, ile!=0?"\n":"" );
			memcpy(wynik, pusta, 102);
			nr++;
		}
		fclose (output);
		fclose (input);
	}

/*
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
y,h,e,s,o,c,v,x,d,u,i,g,l,b,k,r,z,t,n,w,j,p,f,m,a,q
*/

	return 0;
}

