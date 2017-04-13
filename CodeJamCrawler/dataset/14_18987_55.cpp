#include<stdio.h>
#include<stdlib.h>

void merge(double arra[],int p,int q,int r)
{
  int n1,n2,i,j,k,l;
  n1=q-p+1;
  n2=r-q;
  //printf("%d %d %d\n",p,q,r);
  //printf("%d %d %d\n",p,q,r);
  double *L,*R;
  L=(double *)malloc((n1+1)*sizeof(double));
  R=(double *)malloc((n2+1)*sizeof(double));
    
  for(i=0;i<n1;i++)
    L[i]=arra[p+i];
   
  L[n1]=10;  
       
  for(i=0;i<n2;i++)
    R[i]=arra[q+i+1];
  
  R[n2]=10;
  
  i=0;
  j=0;
  for(k=p;k<=r;k++)
  {
   if(L[i]<=R[j])
   {
    arra[k]=L[i];
    i++;
   }
   else
   {
    arra[k]=R[j];
    j++;
   }
  }
}

void mergesort(double arr[],int p,int r)
{

 int q;
 if(p<r)
 {
  
  q=(p+r)/2;
 // printf("%lld %lld %lld\n",p,q,r);
  mergesort(arr,p,q);
  mergesort(arr,q+1,r);
  merge(arr,p,q,r);  
  } 
}

int main()
{
 double *A,*B;
 int T,N,i,j,k,y,z,count,count1;
 FILE *f=fopen("D-small-attempt0.txt","r");
 FILE *fp=fopen("output3.txt","w");
 
 fscanf(f,"%d",&T);
 
 for(i=0;i<T;i++)
 {
  count=0;
  count1=0;
  fscanf(f,"%d",&N);
  A=(double *)malloc(N*sizeof(double));
  B=(double *)malloc(N*sizeof(double));
  
  for(j=0;j<N;j++)
    fscanf(f,"%lf",&A[j]);
  
  for(j=0;j<N;j++)
    fscanf(f,"%lf",&B[j]);
    
  mergesort(A,0,N-1);
  mergesort(B,0,N-1);
  
  k=0;
  for(j=0;j<N;j++)
  {
   if(B[j]>A[k])
   {
    count++;
    k++;
   }
  }
  z=N-count;
  
  k=0;
  for(j=0;j<N;j++)
  {
   if(A[j]>B[k])
   {
    count1++;
    k++;
   }
  }
  y=count1;        
  
  fprintf(fp,"Case #%d: %d %d\n",i+1,y,z);
 }

 return 0;
}
