#include<stdio.h>
#include<bits/stdc++.h>
int main()
{

int t,w;

scanf("%d",&t);
for(w=1;w<=t;w++)
{
int a[40][40],b[40][40],g,h;
int bb[10],aa[10];
int i,j,k,e,y,ff;
   scanf("%d",&g);

     for(i=0;i<4;i++)
     {
     for(j=0;j<4;j++)
     {
      scanf("%d",&a[i][j]);
     }
     }

    scanf("%d",&h);
     for(i=0;i<4;i++)
     {
     for(j=0;j<4;j++)
     {
      scanf("%d",&b[i][j]);
     }
     }

    for(i=0;i<4;i++)
    {
       aa[i]=a[g-1][i];
       bb[i]=b[h-1][i];

    }



   int f=0,ss;
   for(y=0;y<4;y++)
   {
      for(e=0;e<4;e++)
      {
       if(aa[y]==bb[e])
       {

          f++;
          ss=aa[y];

       }
      }
   }
   if(f>1)
   {
   printf("Case #%d: Bad magician!\n",w);
   continue;
   }
   if(f==0)
    {
    printf("Case #%d: Volunteer cheated!\n",w);
    continue;
    }

     if(f==1)
    {
      printf("Case #%d: %d \n",w,ss);
      continue;
    }

}
return 0;
}
