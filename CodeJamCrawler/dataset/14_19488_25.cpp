#include<stdio.h>
int main()
{
    int a[5][5],b[5][5];
    int i,n,m,t,ctr,j,sr=1;
    FILE *fr=fopen("input1.in","r");
    FILE *fw=fopen("output2","w");

    fscanf(fr,"%d",&t);
    while(t--)
    {
        ctr=0;
        fscanf(fr,"%d",&n);
       for(i=1;i<=4;i++)
          for(j=1;j<=4;j++)
            fscanf(fr,"%d",&a[i][j]);
        fscanf(fr,"%d",&m);
    for(i=1;i<=4;i++)
       for(j=1;j<=4;j++)
          fscanf(fr,"%d",&b[i][j]);

     for(i=1;i<=4;i++)
       {
           for(j=1;j<=4;j++)
           {

              if(b[m][i]==a[n][j])
              {
                  if(ctr>0)
                     break;
                 ctr=a[n][j];
              }
            }
           if(j<=4)
              break;
    }
    if(i<=4)
      {
          fprintf(fw,"Case #%d: Bad magician!\n",sr++);
           continue;
      }
    if(ctr==0)
       fprintf(fw,"Case #%d: Volunteer cheated!\n",sr++);
    else
       fprintf(fw,"Case #%d: %d\n",sr++,ctr);
}
return 0;
}
