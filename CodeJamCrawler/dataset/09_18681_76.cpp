#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

int N, i, j, c, ctr;

char line[500], needle[20] = "welcome to code jam", ch;
vector<int> links[500][19];

int nlen = 19, llen;

void create_links_to_next(int line_ptr, int needle_ptr)
{
	cout << "Ln: " << line_ptr << " / Nd: " << needle_ptr << " ";
	if ( line[line_ptr] == needle[needle_ptr] )
	{
		for (int k=line_ptr+1; k<llen; k++)
			if ( line[k] == needle[needle_ptr+1] )
			{
				links[line_ptr][needle_ptr].push_back(k);
				cout << k << " ";
			}
	}	

	cout << endl;
}

void search_needle_char_at(int line_ptr, int needle_ptr)
{
	if ( needle_ptr == nlen-1 ) // found one
	{
		ctr = (ctr + 1) % 10000;
	}	

	for (vector<int>::iterator iter = links[line_ptr][needle_ptr].begin();
		 iter != links[line_ptr][needle_ptr].end();
		 iter++)
	{
		if ( (*iter) < llen &&
			 needle_ptr < nlen && 
			 line[*iter] == needle[needle_ptr+1] )
			search_needle_char_at( (*iter), needle_ptr+1 );
	}	 
}

int main()
{
    FILE *fptr = fopen("in.in", "rb"),
         *fptr2 = fopen("C-test.out", "wb");

    if (fptr == NULL || fptr2 == NULL)
    {
        cout << "File Error!" << endl;
        return -1;
    }

    fscanf(fptr, "%d\n", &N);

	for (c=0; c<N; c++)
    {
		ctr = 0;
		
		int cc = 0;
		while ( (ch = getc(fptr)) != EOF && ch != '\n' ) 
		{
			line[cc++] = ch;
		}
		
		line[cc-1] = '\0';

		llen = strlen(line);

		for (i=0; i<llen; i++)
		{
			for (j=max(0, i+nlen-llen); j<min(i+1, nlen); j++)
			//for (j=0; j<1; j++)
			{
				links[i][j].clear();
				create_links_to_next(i, j);
			}
		}

		for (i=0; i<=llen-nlen; i++)
			search_needle_char_at(i, 0);

        fprintf(fptr2, "Case #%d: %04d\n", (c+1), ctr);
	}

    fclose(fptr);
    fclose(fptr2);

    fptr = NULL;
    fptr2 = NULL;

	getchar();
	
    return 0;
}
