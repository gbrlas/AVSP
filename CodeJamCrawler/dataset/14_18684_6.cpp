#include<stdio.h>
int main()
{
int i,j,k,t=0,r1,z,r2,a[10][10],y,b[10][10],c=0,x;
scanf("%d",&t);
for(z=1;z<=t;z++)
{c=0;
scanf("%d",&r1);

for(i=1;i<=4;i++)
{
for(j=1;j<=4;j++)
{
scanf("%d",&a[i][j]);
}
}
scanf("%d",&r2);

for(i=1;i<=4;i++)
{
for(j=1;j<=4;j++)
{
scanf("%d",&b[i][j]);
}
}

for(j=1;j<=4;j++)
{
    x=a[r1][j];
    for(k=1;k<=4;k++)

    {
        if(b[r2][k]==a[r1][j])
           {
             c++;
            y=a[r1][j];
           }
    }

}
if(c==0)
   printf("Case #%d: Volunteer cheated!\n",z);
else if(c==1)
   printf("Case #%d: %d\n",z,y);
else if(c>=2)
    printf("Case #%d: Bad magician!\n",z);

}
return 0;
}
