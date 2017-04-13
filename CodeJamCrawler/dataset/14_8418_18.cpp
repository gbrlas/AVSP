#include<stdio.h>
main()
{
      int cas,a,b,c,k,d;
      int i,j,l,win=0;
      FILE *p1,*p2;
      p1 = fopen("B-small-attempt0.in","r");
      p2 = fopen("output.in","w");
      fscanf(p1,"%d",&k);
      cas=1;
      while(k)
      {
              win=0;
            fscanf(p1,"%d %d %d",&a,&b,&c);
             for(i=0;i<a;i++)
            {
                              for(j=0;j<b;j++)
                              {
                                              d=i&j;
                                               for(l=0;l<c;l++)
                                               {           
                                                                                                              
                                                               if(d==l)
                                                              {
                                                                          win=win+1;
                                                              }
                                                              
                                               }               
                              }
            }
              fprintf(p2,"Case #%d: %d\n",cas,win);
              cas++;
              k--;     
      }
      fclose(p1);
      fclose(p2);
}
