// GCJ2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"

int getIndex(int x, int y, int W)
{
    return y*W+x;
}

char drawpath(int x, int y, int H, int W, char basin, int* elevations, char* basins, char target)
{
    int idx = getIndex(x,y,W);
    int currElevation = elevations[idx];
    int dir[4];
    int lowest;

    while(basins[idx] == target)
    {
        basins[idx] = basin;

        memset(dir,-1,4*sizeof(int));
        lowest = 65000;
        //can we go south?
        if((y+1)<H)
            if(elevations[getIndex(x,y+1,W)] < elevations[idx])
            {
                dir[3] = elevations[getIndex(x,y+1,W)]; //yes
                lowest = dir[3];
            }
        //can we go east?
        if((x+1)<W)
            if(elevations[getIndex(x+1,y,W)] < elevations[idx])
            {
                dir[2] = elevations[getIndex(x+1,y,W)]; //yes
                if(dir[2] <= lowest)
                    lowest = dir[2];
            }
        //can we go west?
        if(x>0)
            if(elevations[getIndex(x-1,y,W)] < elevations[idx])
            {
                dir[1] = elevations[getIndex(x-1,y,W)]; //yes
                if(dir[1] <= lowest)
                    lowest = dir[1];
            }
        //can we go north?
        if(y>0)
            if(elevations[getIndex(x,y-1,W)] < elevations[idx])
            {
                dir[0] = elevations[getIndex(x,y-1,W)]; //yes
                if(dir[0] <= lowest)
                    lowest = dir[0];
            }

        if(dir[0] == lowest)
            --y;
        else if(dir[1] == lowest)
            --x;
        else if(dir[2] == lowest)
            ++x;
        else if(dir[3] == lowest)
            ++y;
        idx = getIndex(x,y,W);
    }
    return basins[idx];
}

int findNextBasin(char* basins, int H, int W)
{
    for(int i=0;i<H*W;++i)
    {
        if(basins[i]==' ')
            return i;
    }
    return H*W;
}

int _tmain(int argc, _TCHAR* argv[])
{
    if(argc!=2)
    {
        fprintf(stderr,"usage: %s infile\n",argv[0]);
        exit(0);
    }
    FILE* inFile = fopen(argv[1],"rt");
    if(!inFile)
    {
        fprintf(stderr,"Could not open %s\n",argv[1]);
        exit(0);
    }
    char outFileName[256] = {0};
    sprintf(outFileName,"%s.out.txt",argv[1]);
    FILE* outFile = fopen(outFileName,"wt");
    if(!outFile)
    {
        fprintf(stderr,"Could not open %s\n",outFileName);
        exit(0);
    }

    tokenizer t(inFile);

    int numMaps = atoi(t.getToken());
    int HEIGHT,WIDTH;
    int* thisMap;
    char* thisBasin;
    char currBasinLetter;
    char retval;
    int currBasin;
    for(int i=1;i<=numMaps;++i)
    {
        HEIGHT = atoi(t.getToken());
        WIDTH = atoi(t.getToken());
        thisMap = new int[HEIGHT*WIDTH];
        thisBasin = new char[HEIGHT*WIDTH];
        for(int j=0;j<HEIGHT*WIDTH;++j)
        {
            thisMap[j] = atoi(t.getToken());
            thisBasin[j] = ' ';
        }
        currBasinLetter = 'a';
        while((currBasin = findNextBasin(thisBasin,HEIGHT,WIDTH)) != HEIGHT*WIDTH)
        {
            retval = drawpath(currBasin%WIDTH,currBasin/WIDTH,HEIGHT,WIDTH,currBasinLetter,thisMap,thisBasin,' ');
            if(retval < currBasinLetter)
                drawpath(currBasin%WIDTH,currBasin/WIDTH,HEIGHT,WIDTH,retval,thisMap,thisBasin,currBasinLetter);
            else
                ++currBasinLetter;
        }

        fprintf(stderr,"Last Basin: %c\n",--currBasinLetter);

        fprintf(outFile,"Case #%d:\n",i);
        for(int rows=0; rows<HEIGHT;++rows)
        {
            for(int cols=0;cols<WIDTH;++cols)
            {
                fprintf(outFile,"%c ",thisBasin[rows*WIDTH+cols]);
            }
            fprintf(outFile,"\n");
        }

        delete[] thisBasin;
        delete[] thisMap;
    }

    fclose(inFile);
    fclose(outFile);

	return 0;
}

