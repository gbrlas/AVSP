#include<stdio.h>
#include<stdlib.h>

int main()
{
 int T,flag,i,j,k;
 double C,F,X,time1,time2,tmp,coin,tem,temp,time;
 FILE *f=fopen("B-small-attempt0.txt","r");
 FILE *fp=fopen("output1.txt","w");
 fscanf(f,"%d",&T);
 for(i=0;i<T;i++)
 {
  flag=0;
  coin=2;
  time2=0;
  fscanf(f,"%lf%lf%lf",&C,&F,&X);
  time1=X/coin;
  
  tmp=C/coin;
  coin=coin+F;
  tem=X/coin;
  time2=time2+tmp;
  //time2=tmp+tem;
  
  if((time2+tem)<time1)
  { 
  while(1)
  {
   temp=X/coin;
   time1=time2+temp;
   
   tmp=C/coin;
   coin=coin+F;
   tem=X/coin;
   time2=time2+tmp;
   
   if((time2+tem)>time1)
   {
     flag=1;
     break; 
   } 
      
  }
  }
  fprintf(fp,"Case #%d: %lf\n",i+1,time1); 
 }
 
 return 0;
}
