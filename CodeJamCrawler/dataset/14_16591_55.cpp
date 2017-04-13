#include<stdio.h>
main()
{
   int t,i;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
     int n,y=0,z=0,j,k,q;
     scanf("%d",&n);
     float a[n],b[n],t,c[n];
     for(j=0;j<n;j++)
     {
      scanf("%f",&a[j]);
     }
     for(j=0;j<n;j++)
     {
      scanf("%f",&b[j]);
     }
     for(j=0;j<n;j++)
     { 
       
       for(k=j+1;k<n;k++)
       {
         if(a[j]>a[k])
         {
             t=a[j];
             a[j]=a[k];
             a[k]=t;
         }
        if(b[j]>b[k])
        {
             t=b[j];
             b[j]=b[k];
             b[k]=t;      
        }
        }
     }
     for(j=0;j<n;j++)
       c[j]=b[j];
     q=n;
     for(j=0;j<n;j++)
     {
       for(k=0;k<q;k++)
       {
          if(b[k]>a[j])
          {
           b[k]=0;
           break;
          }
         if(k==q-1)
         z++;
        }
      }
      for(j=0;j<n;j++)
      {
       for(k=0;k<q&&k>=0;k++)
       {
         if(a[j]>c[k])
         {
          y++;
          c[k]=1;
          break;
         }
         if(k==q-1)
         {
           q--;
         }
      }
     } 
      

    
     
    printf("Case #%d: %d %d\n",i+1,y,z);
   }
}
