#include<stdio.h>
main()
{
      int t,no,i,j,dws,ws,tno,cas;
      float n[1000],k[1000],temp,nt[1000];
      FILE *p1,*p2;
      p1 = fopen("D-large.in","r");
      p2 = fopen("output","w");
      fscanf(p1,"%d",&t);
      cas=1;
      while(t)
      {
              dws=0;
              ws=0;
              fscanf(p1,"%d",&no);
              tno=no;
              for(i=0;i<no;i++)
              {
                               fscanf(p1,"%f",&n[i]);
                               nt[i]=n[i];
              }            
              for(i=0;i<no;i++)
              {
                         for(j=0;j<no-i-1;j++)
                         if(n[j]>n[j+1])
                         {
                                        temp=n[j];
                                        n[j]=n[j+1];
                                        n[j+1]=temp;
                         }
              }
              for(i=0;i<no;i++)
              fscanf(p1,"%f",&k[i]);              
              for(i=0;i<no;i++)
              {
                         for(j=0;j<no-i-1;j++)
                         if(k[j]>k[j+1])
                         {
                                        temp=k[j];
                                        k[j]=k[j+1];
                                        k[j+1]=temp;
                         }
              }               
              while(no>1)
              {
                       
                       if(n[0]<k[0]||n[no-1]<k[no-1])
                         {
                          for(i=0;i<no-1;i++)
                          n[i]=n[i+1];
                          no--;                  
                         }
                         else
                         {
                             no--;
                             dws++;
                         }               
              }
              if(n[0]>k[0])
              dws++;
              no=tno;
              for(i=0;i<no;i++)
              {
                         for(j=0;j<no-i-1;j++)
                         if(nt[j]>nt[j+1])
                         {
                                        temp=nt[j];
                                        nt[j]=nt[j+1];
                                        nt[j+1]=temp;
                         }
              }                                       
              while(no>1)
              {
                       
                       if(k[0]<nt[0]||k[no-1]<nt[no-1])
                         {
                          for(i=0;i<no-1;i++)
                          k[i]=k[i+1];
                          no--;                  
                         }
                         else
                         {
                             no--;
                             ws++;
                         }               
              }
              if(nt[0]<k[0])
              ws++;              
              ws=tno-ws;
              fprintf(p2,"Case #%d: %d %d\n",cas,dws,ws);
              cas++;
              t--;     
      }
      fclose(p1);
      fclose(p2);      
}
