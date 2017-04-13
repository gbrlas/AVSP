#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

int T, W, H, i, j, c;

int emap[100][100], labels[100][100],
    flow_di[100][100], flow_dj[100][100];

bool par_open = false;

bool is_valid(int a, int b)
{
    return ( a>=0 && a<=H-1 && b>=0 && b<=W-1 );
}

int nb_elv(int a, int b, int d_i, int d_j)
{
    if ( is_valid(a+d_i, b+d_j) )
        return emap[a + d_i][b + d_j];

    return 10000;
}

int nb_lbl(int a, int b, int d_i, int d_j)
{
    if ( is_valid(a+d_i, b+d_j) )
        return labels[a + d_i][b + d_j];

    return -2;
}

int main()
{
    FILE *fptr = fopen("in.in", "rb"),
         *fptr2 = fopen("B-small.out", "wb");

    if (fptr == NULL || fptr2 == NULL)
    {
        cout << "File Error!" << endl;
        return -1;
    }

    fscanf(fptr, "%d\n", &T);

    for (c=0; c<T; c++)
    {
        fscanf(fptr, "%d %d\n", &H, &W);

        for (i=0; i<H; i++)
            for (j=0; j<W; j++)
                fscanf(fptr, "%i\n", &emap[i][j]);

        int l_ctr = 0;

        for (i=0; i<H; i++)
            for (j=0; j<W; j++)
            {
                labels[i][j] = -1;
                flow_di[i][j] = 0;
                flow_dj[i][j] = 0;
            }

        int cur_lbl = 0;

        for (i=0; i<H; i++)
            for (j=0; j<W; j++)
            {
                int best_elv = 10000;

                if ( nb_elv(i, j, -1, 0) < emap[i][j] && nb_elv(i, j, -1, 0) < best_elv)
                {
                    flow_di[i][j] = -1;
                    flow_dj[i][j] = 0;

                    best_elv = nb_elv(i, j, -1,0);
                }

                if ( nb_elv(i, j, 0, -1) < emap[i][j] && nb_elv(i, j, 0, -1) < best_elv)
                {
                    flow_dj[i][j] = -1;
                    flow_di[i][j] = 0;

                    best_elv = nb_elv(i, j, 0,-1);
                }

                if ( nb_elv(i, j, 0, 1) < emap[i][j] && nb_elv(i, j, 0, 1) < best_elv)
                {
                    flow_dj[i][j] = 1;
                    flow_di[i][j] = 0;

                    best_elv = nb_elv(i, j, 0,1);
                }

                if ( nb_elv(i, j, 1, 0) < emap[i][j] && nb_elv(i, j, 1, 0) < best_elv)
                {
                    flow_di[i][j] = 1;
                    flow_dj[i][j] = 0;

                    best_elv = nb_elv(i, j, 1,0);
                }

                if (best_elv == 10000)
                {
                    flow_di[i][j] = 0;
                    flow_dj[i][j] = 0;
                    labels[i][j] = cur_lbl++;
                    cout << i << "--" << j << endl;
                }
            }

        char *label_conv = new char[cur_lbl];
        memset(label_conv, -1, cur_lbl);

        bool change = true;
        while (change)
        {
            change = false;

            for (i=0; i<H; i++)
                for (j=0; j<W; j++)
                {
                    if ( labels[i][j] != -1 )
                    {
                        if ( nb_lbl(i, j, 0, -1) == -1 &&
                             flow_dj[i][j-1] == 1 )
                        {
                            labels[i][j-1] = labels[i][j];
                            change = true;
                        }

                        if ( nb_lbl(i, j, 0, 1) == -1 &&
                             flow_dj[i][j+1] == -1 )
                        {
                            labels[i][j+1] = labels[i][j];
                            change = true;
                        }

                        if ( nb_lbl(i, j, -1, 0) == -1 &&
                             flow_di[i-1][j] == 1 )
                        {
                            labels[i-1][j] = labels[i][j];
                            change = true;
                        }

                        if ( nb_lbl(i, j, 1, 0) == -1 &&
                             flow_di[i+1][j] == -1 )
                        {
                            labels[i+1][j] = labels[i][j];
                            change = true;
                        }
                    }
                }
        }

        char label = 'a';
        for (i=0; i<H; i++)
            for (j=0; j<W; j++)
                if ( label_conv[labels[i][j]] == -1 )
                    label_conv[labels[i][j]] = label++;


        fprintf(fptr2, "Case #%d:\n", (c+1));

        for (i=0; i<H; i++)
        {
            for (j=0; j<W-1; j++)
            {    fprintf(fptr2, "%c ", label_conv[labels[i][j]]);
                cout << label_conv[labels[i][j]] << " ";
            }
            fprintf(fptr2, "%c\n", label_conv[labels[i][W-1]]);
            cout << label_conv[labels[i][W-1]] << endl;

        }
    }

    fclose(fptr);
    fclose(fptr2);

    fptr = NULL;
    fptr2 = NULL;

    return 0;
}
