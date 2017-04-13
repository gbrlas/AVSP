#include <stdio.h>
#include <stdlib.h>

void bubble(float *a,int n)
{
int i,j;
float temp;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j]) {
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
int main()
{   freopen("D-large.in","r",stdin);
    freopen("D out.txt","w",stdout);
    int i,k,j,m,N,n,flag,score;
    float a[1000],b[1000];
scanf("%d",&N);
for(i=0;i<N;i++)
{  score=0;
    scanf("%d",&n);
for(j=0;j<n;j++)
   scanf("%f",&a[j]);
for(j=0;j<n;j++)
   scanf("%f",&b[j]);
bubble(a,n);
bubble(b,n);

j=m=n-1;
k=0;
for(m=n-1;m>=0;m--)
{if(a[j]<b[m])
  {
  k++;
  }
   else
  {
   score+=1;
   j--;
  }
}

//for(k=0;k<n;k++)
//printf("%f",b[k]);
//for(k=0;k<n;k++)
//printf("%f",b[k]);
 printf("Case #%d: %d ",i+1,score);
j=m=n-1;
k=0;
for(m=n-1;m>=0;m--)
{if(b[j]<a[m])
  {
  k++;
  }
   else
  {
   j--;
  }
}
printf("%d\n",k);

}
return 0;
}
