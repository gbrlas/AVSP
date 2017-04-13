// GCJ3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"

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
 char* currToken = t.getToken();

 int numCases = atoi(currToken);
 char currLine[600];
 int currLength;
 int x[19] = {0};
 int count;

 for(int i=1; i<=numCases;++i)
 {
  memset(currLine,0,600);
  strcpy(currLine,t.getToken());
  currLength = strlen(currLine);
  count = 0;

  for(x[0]=0;x[0]<=currLength-19;++x[0])
   if(currLine[x[0]] == 'w')
    for(x[1]=x[0]+1;x[1]<=currLength-18;++x[1])
     if(currLine[x[1]] == 'e')
      for(x[2]=x[1]+1;x[2]<=currLength-17;++x[2])
       if(currLine[x[2]] == 'l')
        for(x[3]=x[2]+1;x[3]<=currLength-16;++x[3])
         if(currLine[x[3]] == 'c')
          for(x[4]=x[3]+1;x[4]<=currLength-15;++x[4])
           if(currLine[x[4]] == 'o')
            for(x[5]=x[4]+1;x[5]<=currLength-14;++x[5])
             if(currLine[x[5]] == 'm')
              for(x[6]=x[5]+1;x[6]<=currLength-13;++x[6])
               if(currLine[x[6]] == 'e')
                for(x[7]=x[6]+1;x[7]<=currLength-12;++x[7])
                 if(currLine[x[7]] == ' ')
                  for(x[8]=x[7]+1;x[8]<=currLength-11;++x[8])
                   if(currLine[x[8]] == 't')
                    for(x[9]=x[8]+1;x[9]<=currLength-10;++x[9])
                     if(currLine[x[9]] == 'o')
                      for(x[10]=x[9]+1;x[10]<=currLength-9;++x[10])
                       if(currLine[x[10]] == ' ')
                        for(x[11]=x[10]+1;x[11]<=currLength-8;++x[11])
                         if(currLine[x[11]] == 'c')
                          for(x[12]=x[11]+1;x[12]<=currLength-7;++x[12])
                           if(currLine[x[12]] == 'o')
                            for(x[13]=x[12]+1;x[13]<=currLength-6;++x[13])
                             if(currLine[x[13]] == 'd')
                              for(x[14]=x[13]+1;x[14]<=currLength-5;++x[14])
                               if(currLine[x[14]] == 'e')
                                for(x[15]=x[14]+1;x[15]<=currLength-4;++x[15])
                                 if(currLine[x[15]] == ' ')
                                  for(x[16]=x[15]+1;x[16]<=currLength-3;++x[16])
                                   if(currLine[x[16]] == 'j')
                                    for(x[17]=x[16]+1;x[17]<=currLength-2;++x[17])
                                     if(currLine[x[17]] == 'a')
                                      for(x[18]=x[17]+1;x[18]<=currLength-1;++x[18])
                                       if(currLine[x[18]] == 'm')
                                       {
                                        ++count;
                                        count%=10000;
                                       }

  fprintf(outFile,"Case #%d: %04d\n",i,count);
 }
 fclose(inFile);
 fclose(outFile);
 return 0;
}
