#include<stdio.h>
#include<iostream>
using namespace std;
//#include<conio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
              int n;
              
              scanf("%d",&n);
              int i=0;
              int oc=1,bc=1;
              int no,bo;
              char c[101][2];
              int m[101];
              for(i=0;i<n;i++)
                scanf("%s%d",&c[i],&m[i]);
            
            
              int nextc[101];
              int nextb[101];
              int cl=0,bl=0;
              for(i=0;i<n;i++)
              {
                if(c[i][0]=='O')
                  nextc[cl++]=m[i];
                else
                 nextb[bl++]=m[i];
              }
              no=nextc[0];
              bo=nextb[0];
              int ko=1,kb=1;
              int time=0;
              i=0;
              char to=c[0][0];
              i=1;
              int flag=0;
              while(i<=n)
              {
                flag=0;
                 if(no>oc)
                  oc++;
                 else if(no<oc)                 
                  oc--;
                else if(to=='O'&&no==oc)
                  {
                     no=nextc[ko];
                     to=c[i][0];
                     ko++;
                     i++;
                     flag=1;
                  }
                
                if(bo<bc)
                  bc--;
                 else if(bo>bc)
                  bc++;
                 
                 else if(to=='B'&&bo==bc&&flag==0)
                 {
                    bo=nextb[kb];
                    kb++;
                    to=c[i][0];
                    i++;
                 }
                 time++;
              }
              cout<<"Case #"<<cas<<": "<<time<<"\n";
               cas++;  
                 
                
    }
   // getch();
}
              
