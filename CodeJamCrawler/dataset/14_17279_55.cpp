#include<stdio.h>

int main()

{

int cou,s,i,j,k,l,a[5][5],b[5],t,row,rows;

scanf("%d",&t);

for(i=1;i<=t;i++)

{

cou=0;

scanf("%d",&row);

for(j=1;j<=4;j++)

{

for(k=1;k<=4;k++)

{

scanf("%d",&a[j][k]);

}

}

for(l=1;l<=4;l++)

{

b[l]=a[row][l];

}

scanf("%d",&rows);

//printf("%d\n",rows);

for(j=1;j<=4;j++)

{

for(k=1;k<=4;k++)

{

scanf("%d",&a[j][k]);

//if(j==rows)

//printf("%d\n",a[rows][k]);

}

}

for(j=1;j<=4;j++)

{

for(k=1;k<=4;k++)

{

if(b[j]==a[rows][k])

{

cou++;

s=j;

}

}

}

if(cou==1)

{

printf("case #%d: %d \n",i,b[s]);

}

else if(cou==0)

{

printf("Case #%d: Volunteer cheated!\n",i);

}

else

{

printf("case #%d: Bad magician!\n",i);

}

}

return 0;

}
