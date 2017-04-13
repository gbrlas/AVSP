#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ex[26];

int l,d,n;
char word[5010][20];
char qs[1000];
int cb[510][16][30],cbnum,pcnt=0;
int len,corr;


main()
{
    int i,j,k;
    for(i=0;i<510;i++)for(j=0;j<16;j++)for(k=0;k<30;k++)cb[i][j][k]=0;
    for(i=0;i<26;i++)ex[i]=0;
    scanf("%d%d%d",&l,&d,&n);
    for(i=0;i<d;i++)
    {
        scanf("%s",word[i]);
    }

    for(i=0;i<n;i++)
    {
      pcnt=0;
      cbnum=0;

      scanf("%s",qs);
      len=strlen(qs);
      for(j=0;j<len;j++)
      {
        if(qs[j]=='(')
        {
           j++;
           while(qs[j]!=')')
           {
               cb[i][cbnum][qs[j++]-'a']=1;
           }
           cbnum++;
        }
        else
        {
        cb[i][cbnum++][qs[j]-'a']=1;
        }
      }
      for(j=0;j<d;j++)
      {
          corr=1;
          for(k=0;k<l;k++)if(cb[i][k][word[j][k]-'a']==0){ corr=0; break; }
          if(corr==1)pcnt++;
      }
      printf("Case #%d: %d\n",i+1,pcnt);
    }
}
