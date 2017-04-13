#include<stdio.h>
#include<stdlib.h>
 int main()
 {
  int i,t,j,k,x,o,counter1,counter2,counter3,counter4,counter5,counter6,counter7,counter8,flag;
  char arr[4][4];

  scanf("%d%*c",&t);
  for(i=0;i<t;i++)
  {
   counter5=counter6=counter7=counter8=x=o=flag=0;
   for(j=0;j<4;j++)
   {
    for(k=0;k<4;k++)
     scanf("%c",&arr[j][k]);
    scanf("%*c");
   }
   scanf("%*c");
   /*for(j=0;j<4;j++)
   {
    for(k=0;k<4;k++)
     printf("%c ",arr[j][k]);
    printf("\n");
   }*/
   for(j=0;j<4;j++)
   {
    counter1=counter2=counter3=counter4=0;
    for(k=0;k<4;k++)
    {
     if(arr[j][k]=='X' || arr[j][k]=='T' )
      counter1++;
     if(arr[k][j]=='X' || arr[k][j]=='T' )
      counter2++;
     if(arr[j][k]=='O' || arr[j][k]=='T' )
      counter3++;
      if(arr[k][j]=='O' || arr[k][j]=='T' )
      counter4++;
      if(j==k && (arr[j][j]=='X' || arr[j][j]=='T'))
       counter5++;
      if(j==k && (arr[j][j]=='O' || arr[j][j]=='T'))
       counter6++;
      if(j+k==3 && (arr[j][k]=='X' || arr[j][k]=='T'))
       counter7++;
      if(j+k==3 && (arr[j][k]=='O' || arr[j][k]=='T'))
       counter8++;
      if(arr[j][k]=='.')
       flag=1;
     }
     if(counter1==4 || counter2==4)
      {
       x=1;
       break;
      }
     else if(counter3==4 || counter4==4)
      {
       o=1;
       break;
      }
    //printf("%d ",counter3);
    }
   if(counter5==4 || counter7==4)
    x=1;
    if(counter6==4 || counter8==4)
    o=1;
 if(x==1)
  printf("Case #%d: X won\n",i+1);
 else if(o==1)
  printf("Case #%d: O won\n",i+1);
 else
 {
   if(flag==1)
    printf("Case #%d: Game has not completed\n",i+1);
   else
    printf("Case #%d: Draw\n",i+1);
 }
}
return 0;
 }
