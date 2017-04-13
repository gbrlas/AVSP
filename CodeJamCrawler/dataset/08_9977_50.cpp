/* PROGRAM TO FIND THE MINIMUN NUMBER OF SWITHCES NEEDED FOR A CENTRAL SYSTEM
   TO DIRECT SET OF QUERIES ACROSS DIFFERENT SEARCH ENGINES*/
#include<stdio.h>
#include<string.h>
void main()
{
 FILE *fip,*fop;
 int nocase,nosearcheng,noquery,caseread=0,searchread=0,queryread=0,noswitch[21],cfoundflag=1,matchfound=0,foundflag[101],startmatchindex=0;
 char searcheng[101][101],newlinec,*ifilename,query[101],*ofilename;
 printf("enter the input filename along with path and extension\n");
 scanf("%s",ifilename);
 printf("enter the output filename along with path and extension\n");
 scanf("%s",ofilename);
 fip=fopen(ifilename,"r");
 fop=fopen(ofilename,"w");
 if(fip==NULL)
  printf("Input file is not opening");
 else  if(fop==NULL)
  printf("Output file is not opening");
 else
 {
  fscanf(fip,"%d",&nocase);
  printf("%d",nocase);
  while(caseread<nocase)
  {
   if(feof(fip))
    break;
   searchread=0;
   fscanf(fip,"%d",&nosearcheng);
   while(searchread<nosearcheng)
   {
    newlinec=getc(fip);
    fscanf(fip,"%[^\n]s",searcheng[searchread]);
    foundflag[searchread++]=0;
   }
   matchfound=0;
   cfoundflag=1;
   queryread=0;
   fscanf(fip,"%d",&noquery);
   while(queryread<noquery)
   {
    newlinec=getc(fip);
    fscanf(fip,"%[^\n]s",query);
    if(queryread==0)
    {
    for(searchread=0;searchread<nosearcheng;searchread++)
     {
      if(!strcmp(query,searcheng[searchread]))
      {
       foundflag[searchread]++;
       startmatchindex=searchread;
       break;
      }
     }
    }
    for(searchread=0;searchread<nosearcheng;searchread++)
    {
     if((foundflag[searchread]<cfoundflag)&&(startmatchindex!=searchread))
     {
      if(!strcmp(query,searcheng[searchread]))
      {
       foundflag[searchread]++;
       matchfound++;
       break;
      }
     }
    }
    if(matchfound==(nosearcheng-1))
    {
     cfoundflag++;
     matchfound=0;
     startmatchindex=searchread;
     foundflag[searchread]++;
    }
    queryread++;
   }
   ++caseread;
   fprintf(fop,"Case #%d: %d\n",caseread,cfoundflag-1);
  }
 }
 fclose(fop);
 fclose(fip);
}