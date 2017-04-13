// fas.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
    int t=0, n=0, m=0;
    int a[100][100];
    int arr[100][100];
    int rcmax[2][100];
    int max=0, brk=0;

    scanf("%d", &t);

    for (int i=0; i<t; ++i)
    {
        scanf("%d%d", &n, &m);

        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                scanf("%d", &a[j][k]);
            }
        }

        //take row max
        for (int j=0; j<n; ++j)
        {
            max = a[j][0];
            for (int k=1; k<m; ++k)
            {
                if (a[j][k] > max)
                {
                    max = a[j][k];
                }
            }
            rcmax[0][j] = max;
        }

        //take column max
        for (int k=0; k<m; ++k)
        {
            max = a[0][k];
            for (int j=1; j<n; ++j)
            {
                if (a[j][k] > max)
                {
                    max = a[j][k];
                }
            }
            rcmax[1][k] = max;
        }

        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                arr[j][k] = 100;
            }
        }

        //span through rows of arr
        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                arr[j][k] = rcmax[0][j];
            }
        }

        //span through columns of arr
        for (int k=0; k<m; ++k)
        {
            for (int j=0; j<n; ++j)
            {
                if (arr[j][k] > rcmax[1][k])
                {
                    arr[j][k] = rcmax[1][k];
                }
            }
        }

        brk = 0;
        //compare arrays: a and arr
        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                if (arr[j][k] != a[j][k])
                {
                    brk = 1; break;
                }
            }
            if (brk)
            {
                break;
            }
        }

        if (brk)
        {
            printf("Case #%d: NO\n", i+1);
        }
        else
        {
            printf("Case #%d: YES\n", i+1);
        }
    }

	return 0;
}
