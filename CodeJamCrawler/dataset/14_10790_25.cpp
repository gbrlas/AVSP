#include<stdio.h>
#include<stdlib.h>

main()
{
   int t,done,k;
   double c,f,x,time,timeprev,rate;
   FILE *fp,*fpo;
   fp=fopen("cookie.in","r");
   fpo=fopen("cookieOutput.txt","w");
   fscanf(fp,"%d",&t);
   for(k=0;k<t;k++)
   {
       time=0;
       done=0;
       rate=2;
       timeprev=time;
       fscanf(fp,"%lf",&c);
       fscanf(fp,"%lf",&f);
       fscanf(fp,"%lf",&x);
       timeprev=x/rate;
       while(!done)
       {
           time=time+c/rate;
           rate=rate+f;
           time=time+x/rate;
           if(timeprev>=time)
           {
               timeprev=time;
               time=time-x/rate;
           }
           else
           {
               done=1;
           }
       }
       fprintf(fpo,"Case #%d: %.7lf\n",k+1,timeprev);
   }
   fclose(fpo);
   fclose(fp);
}
