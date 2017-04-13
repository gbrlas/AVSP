#include<stdio.h>
main()
{
      int k,y=1,cas;
      double c,x,f,r,t1,t2,t=0;
      FILE *p1,*p2;
      p1 = fopen("B-small-attempt1.in","r");
      p2 = fopen("output","w");
      fscanf(p1,"%d",&k);
      cas=1;
      while(k)
      {
              t=0;
              r=2;
              y=1;
              fscanf(p1,"%lf %lf %lf",&c,&f,&x);
              if(x<c)
              t=x/r;
              else
              {
                  while(y)
                  {
                          t1=c/r + x/(r+f);
                          t2=x/r;
                          if(t1<t2)
                          {
                                   t=t+c/r;
                                   r=r+f;
                          }
                          else
                          {
                              t=t+t2;
                              y=0;
                          }
                  }
              }
              fprintf(p2,"Case #%d: %.7lf\n",cas,t);
              cas++;
              k--;     
      }
      fclose(p1);
      fclose(p2);
}
