/* PROGRAM TO FIND THE MINIMUN NUMBER OF SWITHCES NEEDED FOR A CENTRAL SYSTEM
   TO DIRECT SET OF QUERIES ACROSS DIFFERENT SEARCH ENGINES*/
#include<stdio.h>
#include<string.h>
struct time
{
 int hour;
 int minute;
}ab[100][2],ba[100][2],t1,t2;
void read();
int timediff(struct time ,struct time);
int alg(struct time a[][2], int na,struct time b[][2], int nb,int tt);
void main()
{
 /*t1.hour=0; t1.minute=0;
 t2.hour=23; t2.minute=30;
 printf(" \ndiference is %d", timediff(t1,t2));*/

read();
}
void read()
{
 FILE *fip,*fop;
 int nocase,caseread=0,na,nb,tt,naread=0,nbread=0,h,m,natrains,nbtrains;
 char ifilename[25],ofilename[25],tempc;
 printf("\n\nenter the input filename along with path and extension\n");
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
   fscanf(fip,"%d%d%d",&tt,&na,&nb);
   printf("\n%d%d%d",tt,na,nb);
   naread=nbread=0;
   while(naread<na)
   {
    fscanf(fip,"%d%c%d",&ab[naread][0].hour,&tempc,&ab[naread][0].minute);
    fscanf(fip,"%d%c%d",&ab[naread][1].hour,&tempc,&ab[naread][1].minute);
    //printf("\n%d%c%d  ",ab[naread][0].hour,tempc,ab[naread][0].minute);
    //printf("%d%c%d",ab[naread][1].hour,tempc,ab[naread][1].minute);
    naread++;
   }
   while(nbread<nb)
   {
    fscanf(fip,"%d%c%d",&ba[nbread][0].hour,&tempc,&ba[nbread][0].minute);
    fscanf(fip,"%d%c%d",&ba[nbread][1].hour,&tempc,&ba[nbread][1].minute);
    //printf("\n%d%c%d  ",ba[nbread][0].hour,tempc,ba[nbread][0].minute);
    //printf("%d%c%d",ba[nbread][1].hour,tempc,ba[nbread][1].minute);
    nbread++;
   }
   natrains=alg(ab,na,ba,nb,tt);
   nbtrains=alg(ba,nb,ab,na,tt);
   ++caseread;
   fprintf(fop,"Case #%d: %d %d\n",caseread,natrains,nbtrains);
  }
 }
 fclose(fop);
 fclose(fip);
}
int timediff(struct time t1 ,struct time t2)
{
 int diff = (t1.hour*60+t1.minute)-(t2.hour*60+t2.minute);
 return diff;
}

int alg(struct time ab[][2], int na,struct time ba[][2], int nb,int tt)
{
 int naread=0,nbread=0,ntrains=na,bstart=0,min=0,minindex=-1,diff;//ntrains
  struct time t1,t0;
 for(naread=0;naread<na;naread++)
 {
  min=1440;
  minindex=-1;
  for(nbread=bstart;nbread<nb;nbread++)
  {
   diff=timediff(ab[naread][0],ba[nbread][1]);
   if(diff>=tt)
   {
    if(min>diff)
    {
     min=diff;
     minindex=nbread;
     printf("\n%d\n",minindex);
    }
   }
  }
  if(minindex!=-1)
  {
   ntrains--;
   //swapba(bstart,minindex);
   t0=ba[bstart][0];
   t1=ba[bstart][1];
   ba[bstart][0]=ba[minindex][0];
   ba[bstart][1]=ba[minindex][1];
   ba[minindex][0]=t0;
   ba[minindex][1]=t1;
   bstart++;
  }
 }
 return ntrains;
}