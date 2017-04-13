#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

vector<char> *pattern;
int L, D, N, i, c;

char words[5000][20], temp[1024], ch;

bool par_open = false;

int main()
{
    FILE *fptr = fopen("C-small-practice.in", "rb"),
         *fptr2 = fopen("A-small-attempt0.out", "wb");

    if (fptr == NULL || fptr2 == NULL)
    {
        cout << "File Error!" << endl;
        return -1;
    }

    fscanf(fptr, "%d %d %d\n", &L, &D, &N);

    pattern = new vector<char>[L];

    for (i=0; i<D; i++)
        fscanf(fptr, "%s\n", &words[i]);

    for (c=0; c<N; c++)
    {
        fscanf(fptr, "%s\n", &temp);
        int ptr = -1;

        for (i=0; i<L; i++)
            pattern[i].clear();

        for (i=0; i<strlen(temp); i++)
        {
            if ( temp[i] == '(' )
            {
                par_open = true;
                ptr++;
            }
            else if ( temp[i] == ')' )
                par_open = false;
            else
            {
                if (!par_open)
                    ptr++;

                pattern[ptr].push_back( temp[i] );
            }
        }

        int ctr = D;

        for (i=0; i<D; i++)
        {
            for (int j=0; j<L; j++)
                if ( find( pattern[j].begin(), pattern[j].end(), words[i][j] ) == pattern[j].end() ) // NOT FOUND
                {
                    ctr--;
                    break;
                }
        }

        fprintf(fptr2, "Case #%d: %d\n", (c+1), ctr);

    }

    fclose(fptr);
    fclose(fptr2);

    fptr = NULL;
    fptr2 = NULL;

    return 0;
}
