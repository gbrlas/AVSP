#include<stdio.h>
#include<math.h>
#include<conio.h>
main()
{
 int i,t;
 double n;
 long int divi,k;
 FILE *fr= fopen("ans1.txt","w");
 FILE *fp=fopen("my1.txt","r");
 fscanf(fp,"%d",&t);
  for(i=1;i<=t;i++)
  {
  fscanf(fp,"%lf %ld",&n,&k);
  divi=(long int)pow(2.0,n);
  if(k%divi==divi-1)
  {
   fprintf(fr,"Case #%d ON\n",i);
  }
  else
  {
    fprintf(fr,"Case #%d OFF\n",i);
  }

  }
  fclose(fp);
  fclose(fr);
getch();
}