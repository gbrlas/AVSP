#include <iostream>
#include "stdio.h"

using namespace std;

#define AS_SIZE 4

int count_common(int a[], int b[], int size, int *last_common)
{
    int counter = 0;
    for (int i=0; i<size; i++)
    {
        printf ("a[i] : %d\n", a[i]);
        printf ("b[i] : %d\n", b[i]);
        if (a[i] == b[i])
        {
            counter++;
            *last_common = a[i];
        }
    }
    return counter;
}

int main()
{
    int num_of_case = -1;
    cin >> num_of_case;
    int data_a[AS_SIZE+1][AS_SIZE+1];
    int data_b[AS_SIZE+1][AS_SIZE+1];
    int pos_a = -1;
    int pos_b = -1;

    for (int i=1; i<1+num_of_case; i++)
    {
        cin >> pos_a;
        //cout << pos_a << endl;

        for (int j=1; j<1+AS_SIZE; j++)
        {
            for (int k=1; k<1+AS_SIZE; k++)
            {
                scanf ("%d", &data_a[j][k]);
            }
        }
        //cout << "here pos_a : " << pos_a << endl;

        cin >> pos_b;

        for (int j=1; j<1+AS_SIZE; j++)
        {
            for (int k=1; k<1+AS_SIZE; k++)
            {
                scanf ("%d", &data_b[j][k]);
            }
        }

        int common_num = 0;
        int common_data = -1;
        //cout << "pos_a : " << pos_a << endl;
        //cout << "pos_b : " << pos_b << endl;
        //common_num = count_common (&data_a[pos_a][1], &data_b[pos_b][1], AS_SIZE, &common_data);
        for (int m=1; m<1+AS_SIZE; m++)
        {
            //printf ("a[i] : %d\n", data_a[pos_a][m]);
            //printf ("b[i] : %d\n", data_b[pos_a][m]);
            for (int n=1; n<1+AS_SIZE; n++)
            {
                if (data_a[pos_a][m] == data_b[pos_b][n])
                {
                    common_num++;
                    common_data = data_a[pos_a][m];
                }
            }
        }


        printf ("Case #%d: ", i);
        if (0 == common_num)
        {
            printf ("Volunteer cheated!\n");
        }
        else if (1 == common_num)
        {
            printf ("%d\n", common_data);
        }
        else
        {
            printf ("Bad magician!\n");
        }

    }

    return 0;
}
