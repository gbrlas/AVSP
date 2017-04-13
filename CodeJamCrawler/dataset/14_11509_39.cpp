#include<stdio.h>
#include<algorithm>
int main()
{
int t,w,e=1;
scanf("%d",&t);
  for(w=1;w<=t;w++)
  {
   int k,coun;
   int t,i,w,s=0,j;
   scanf("%d",&k);
   float a[10000],b[10000],aaa[10000],bbb[10000];
   float u[10000],v[10000],aa[10000],bb[10000];
    for(i=0;i<k;i++)
    {
    scanf("%f",&a[i]);
   u[i]=a[i];
    }

    for(i=0;i<k;i++)
   {
   scanf("%f",&b[i]);
   v[i]=b[i];
   }

std::sort(a,a+k);
std::sort(u,u+k);
std::sort(b,b+k);
std::sort(v,v+k);
coun=0;

for(j=0;j<k;j++)
{
 for(i=0;i<k;i++)
 {
     if(b[i])
     {
         if(b[i]>a[j])
         {
             b[i]=0;
             coun++;
             break;
         }
     }
 }

}
coun=k-coun;


std::reverse(v,v+k);

int c=0;j=0;
s=k-1;
for(i=0;i<k;i++)
{
    if(a[i]<v[s])
    {
        if(a[i]<v[j])
        {
            a[i]=0;
            v[j]=0;
            j++;
        }
    }
    else if(a[i]>v[s])
    {
        c++;
        s--;
    }

}

printf("Case #%d: %d %d \n",e++,c,coun);
}

return 0;
}
