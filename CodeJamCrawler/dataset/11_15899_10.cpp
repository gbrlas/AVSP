#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#define maxSize 15
using namespace std;
int getXOR(long int array[maxSize], int arraySize);
int main()
{
    FILE *outFile;
    outFile = fopen("outfile.txt", "w");
    ifstream inFile("C-small-attempt1.in");
    char in[256];
    inFile.getline(in, 256);
    int x = atoi(in);
    int outerLoop;
    for (outerLoop = 0; outerLoop < x; outerLoop++)
    {
        int caseSize;
        inFile.getline(in, 256);
        caseSize = atoi(in);
        stringstream ss (stringstream::in | stringstream::out);
        inFile.getline(in, 256);
        ss << in;
        int arrayIndex;
        long int array[maxSize];
        for (arrayIndex =0 ; arrayIndex < caseSize; arrayIndex++)
        {

            ss >>  array[arrayIndex];
        }
        long int smallestValue ;
        int val = getXOR(array, caseSize);
        int i; long int  sum = 0;
        if (caseSize > 0)
        {
            smallestValue = array[0];
        }

        for (i=0; i<caseSize; i++)
        {

            if (array[i] < smallestValue)
                smallestValue = array[i];
            sum = sum + array[i];
        }
        sum = sum - smallestValue ;
        if (val == 0)
        {
            fprintf(outFile, "Case #%d: %ld\n",(outerLoop+1) ,sum);
        }
        else
        {
            fprintf(outFile, "Case #%d: NO\n", (outerLoop+1));
        }

    }
    fclose(outFile);
    return 0;
}



int getXOR(long int array[maxSize], int arraySize)
{
    long int minVal ;
    if (arraySize > 0)   minVal = array[0];
                    else       return 0;
    int xorValue = 0;
    int i;
    for (i=0; i<arraySize; i++)
    {
          xorValue = xorValue ^ array[i];
    }

   return xorValue;
}
