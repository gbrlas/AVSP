#include<stdio.h>
#include<string.h>

int main()
{
    FILE *inFile;
    FILE *outFile;
    inFile = fopen("D:/A-large.in","r");
    outFile = fopen("D:/A-result.txt","w");
    long int cases;
    long int i,q = 1;
    long int n,k;
    long int digtal;

    fscanf( inFile , "%d" , &cases );

    while ( cases-- )
    {
        fscanf( inFile,"%d%d" ,&n,&k);
        digtal = 1;
        for ( i=0 ; i<n ; i++ ) digtal *= 2;
        //printf("%d",digtal);
        if ( (k+1)%digtal == 0 )
        {
            fprintf(outFile,"Case #%d: ON\n",q++);
        } else
        {
            fprintf(outFile,"Case #%d: OFF\n",q++);
        }

    }

    return 0;
}
