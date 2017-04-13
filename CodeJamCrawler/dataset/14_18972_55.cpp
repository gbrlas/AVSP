#include<stdio.h>
#include<stdlib.h>

int main()
{
 int T,i,j,k,A[4][4],B[4],C[4],x,y,count,ele;
 FILE *f=fopen("A-small-attempt1.txt","r");
 FILE *fp=fopen("output.txt","w");
 
 fscanf(f,"%d",&T);
 
 for(i=0;i<T;i++)
 {
  count=0;
  fscanf(f,"%d",&x);
  
  for(j=0;j<4;j++)
   for(k=0;k<4;k++)
    fscanf(f,"%d",&A[j][k]);
  
  for(j=0;j<4;j++)
   B[j]=A[x-1][j];
   
  fscanf(f,"%d",&y);
  
  for(j=0;j<4;j++)
   for(k=0;k<4;k++)
    fscanf(f,"%d",&A[j][k]);
  
  for(j=0;j<4;j++)
   C[j]=A[y-1][j];
   
  for(j=0;j<4;j++)
  {
   for(k=0;k<4;k++)
   {
    if(B[j]==C[k])
    {
     ele=B[j];
     count++;
    }
   }
  }  
  if(count==1)
    fprintf(fp,"Case #%d: %d\n",i+1,ele);
  else if(count==0)
    fprintf(fp,"Case #%d: Volunteer cheated!\n",i+1);
  else
    fprintf(fp,"Case #%d: Bad magician!\n",i+1);    
 }

 return 0;
}
