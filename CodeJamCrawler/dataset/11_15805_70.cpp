#include<stdio.h>

int main()
{
int i,j,k,l,c,d,n,e,m,N,C[26][26],D[26][26],L[100];
char c1,c2,c3,ch;

scanf("%d",&N);


for(n=1;n<=N;n++)
{
                 
for(i=0;i<26;i++)
for(j=0;j<26;j++)
   {C[i][j]=-1;D[i][j]=0;}

scanf("%d",&c);
for(i=0;i<c;i++)
                {
                ch=' ';
                while(ch==' ')
                scanf("%c",&ch);
                c1=ch;
                //scanf("%c",&c1);
                scanf("%c",&c2);
                scanf("%c",&c3);
                C[c1-'A'][c2-'A']=c3-'A';
                C[c2-'A'][c1-'A']=c3-'A';
                }

scanf("%d",&d);
for(i=0;i<d;i++)
                {
                ch=' ';
                while(ch==' ')
                   scanf("%c",&ch);
                   c1=ch;

                   //scanf("%c",&c1);
                   scanf("%c",&c2);
                   D[c1-'A'][c2-'A']=1;
                   D[c2-'A'][c1-'A']=1;

               }

l=0;

scanf("%d",&e);
for(i=0;i<e;i++)
{
m=0;
ch=' ';
while(ch==' ')
   scanf("%c",&ch);
if(l>0)
   {
   if(C[L[l-1]][ch-'A']!=-1)
       {
      // printf("|rep%c%c%c|",L[l-1]+'A',ch,C[L[l-1]][ch-'A']+'A');
       
       L[l-1]=C[L[l-1]][ch-'A'];
       m=1;
       ch=L[l-1]+'A';
       //printf("|rep%c%c%c|",ch,);
       //continue;
       }    
   }
for(j=0;j<l;j++)
   {
   if(D[L[j]][ch-'A']==1)
       {l=0;             
       m=1;
      // printf("|del%c|",ch);
       
       }
   }
if(m==0)
  {
  L[l]=ch-'A';
  l++;
  }
//printf("|%d->%c",l,L[l-1]+'A');
}


printf("Case #%d: [",n);
for(i=0;i<l;i++)
{
if(i==0)
printf("%c",L[i]+'A');
else                
printf(", %c",L[i]+'A');
}

printf("]\n");

}


return 0;
}
