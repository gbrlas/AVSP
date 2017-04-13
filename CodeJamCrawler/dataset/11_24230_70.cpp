#include<iostream>
#include<stdio.h>

using namespace std;

int arr[100];
int maxindex;

int convertobin( int num )
{
    int k;
    int i =0;
    while( num > 0 )
    {
        k = num % 2;
        arr[i] = arr[i] + k;
        num = num / 2;
        i++;
        if( i > maxindex ) 
        {
            maxindex = i;
        }
    }
}

int checkans()
{
    int i;
    for(i=0;i<maxindex;i++)
    {
        if(arr[i]%2 != 0 )
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    int test;
    int i, j;
    int n, num, min, sum;
    FILE *fp, *fout;
    fp = fopen("input","r");
    fout = fopen("output","w");
    fscanf(fp,"%d",&test);
    for( i=0; i < test; i++ )
    {
        fscanf(fp,"%d",&n);
        sum = 0;
        maxindex = 0;
        for(j=0;j<30;j++)
        {
            arr[j] = 0;
        }
        for( j=0; j<n; j++ )
        {
            fscanf(fp,"%d",&num);
            if( j == 0)
            {
                min = num;
            }
            convertobin( num );
            sum = sum + num;
            if( num < min )
            {
                min = num;
            }
        }
        int a = checkans();
        fprintf(fout,"Case #%d: ",i+1);
        if( a )
        {
            fprintf(fout,"%d\n",sum-min);
        }
        else
        {
            fprintf(fout,"NO\n");
        }
     }
}

