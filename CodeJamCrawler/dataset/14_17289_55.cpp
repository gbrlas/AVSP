#include<stdio.h>
float max(float c[10],int n1);
void min(float a[10],int n1);
void main()
{
 int n,i,j,w,o,t,z;
 float a[1000],b[1000],k,nl,c[1000],d[1000];
 scanf("%d",&t);
 for(z=0;z<t;z++)
 {
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%f",&a[i]);
 for(i=0;i<n;i++)
 scanf("%f",&b[i]);
 w=0;
 o=0;
  for(j=0;j<n;j++)
   { 
       c[j]=a[j];
       d[j]=b[j];
   }
 for(j=0;j<n;j++)
 {
  nl=max(a,n);
  k=max(b,n);
  if(nl>k)
  {
       o++;
   for(i=0;i<n;i++)
   {
   if(a[i]==nl)
    a[i]=0;
    if(b[i]==k)
    b[i]=0;
   }
   }
   else
   {
   min(a,n);
   for(i=0;i<n;i++)
    if(b[i]==k)
    b[i]=0;
}
} 
  
    for(j=0;j<n;j++)
 {
  nl=max(c,n);
  k=max(d,n);
  if(k>nl)
  {
       w++;
    
   for(i=0;i<n;i++)
   {
   if(c[i]==nl)
    c[i]=0;
    if(d[i]==k)
    d[i]=0;
   }
   }
   else
   {
     
   min(d,n);
   for(i=0;i<n;i++)
    if(c[i]==nl)
    c[i]=0;
}
} 
 
   printf(" case #%d: %d %d\n",z+1,o,n-w);
 }
}
   float max (float c[10],int n1)
   {
     float t=0;
     int i;
     for(i=0;i<n1;i++)
     {
      if(c[i]>t)
      t=c[i];
      }
     return t;
     }
   void min(float a[10],int n1)
  {
    float t=1;
    int i;
    for(i=0;i<n1;i++)
    {
     if(a[i]!=0&&a[i]<t)
      t=a[i];
     }
     for(i=0;i<n1;i++)
     if(a[i]==t)
      a[i]=0;
    }
