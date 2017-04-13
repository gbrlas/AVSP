#include<stdio.h>
#include<stdlib.h>

main()
{
   int card1[4][4],card2[4][4],temp[4];
   int r1,r2,t,i,j,amt,done,card,k;
   FILE *fp,*fpo;
   fp=fopen("sample.in","r");
   fpo=fopen("output.txt","w");
   fscanf(fp,"%d",&t);
   for(k=0;k<t;k++)
   {
       amt=0;
       fscanf(fp,"%d",&r1);
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
               fscanf(fp,"%d",&card1[i][j]);
           }
       }
       for(i=0;i<4;i++)
       {
           temp[i]=card1[r1-1][i];
       }
       fscanf(fp,"%d",&r2);
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
               fscanf(fp,"%d",&card2[i][j]);
           }
       }
       for(i=0;i<4;i++)
       {
           done=0;
           for(j=0;j<4 && !done;j++)
           {
               if(temp[i]==card2[r2-1][j])
               {
                   amt++;
                   done=1;
                   card=temp[i];
               }
           }
       }
       if(amt==0)
       {
           fprintf(fpo,"Case #%d: Volunteer cheated!\n",k+1);
       }
       else if(amt==1)
       {
           fprintf(fpo,"Case #%d: %d\n",k+1,card);
       }
       else
       {
           fprintf(fpo,"Case #%d: Bad Magician!\n",k+1);
       }
   }
   fclose(fpo);
   fclose(fp);
}
