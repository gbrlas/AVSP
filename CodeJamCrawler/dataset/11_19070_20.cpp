#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
    int t, n, i, j, k, total[1001], won[1001];
    double  wp[1001], owp[1001], oowp[1001], totowp, totoowp, rpi[1001];
    char sched[1001][1001];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
           printf("Case #%d:\n",i+1);
           scanf("%d",&n);
           for(j=0;j<n;j++)
                  scanf("%s",sched[j]);
           for(j=0;j<n;j++)
           {
                  won[j] = 0;
                  total[j] = 0;
                  for(k=0;k<n;k++)
                  {
                         if(sched[j][k] == '1')
                              won[j]++;
                         if((sched[j][k] == '1')||(sched[j][k] == '0'))
                              total[j]++;
                  }
                  wp[j] = (float)won[j]/total[j];                  
           }
           for(j=0;j<n;j++)
           {
                  totowp = 0;
                  for(k=0;k<n;k++)
                  {
                         if(sched[j][k] != '.')
                         {
                               if(sched[j][k] == '0')
                                      totowp += (float)(won[k]-1)/(total[k]-1);
                               if(sched[j][k] == '1')
                                      totowp += (float)(won[k])/(total[k]-1);
                         }
                  }
                  owp[j] = (float)totowp/total[j];
           }
            for(j=0;j<n;j++)
           {
                  totoowp = 0; 
                  for(k=0;k<n;k++)
                  {
                         if(sched[j][k] != '.')
                         {
                               totoowp += owp[k];
                         }
                  }
                  oowp[j] = (float)totoowp/total[j];
           }
           for(j=0;j<n;j++)
           {
                 rpi[j] = 0.25*wp[j] + 0.50*owp[j] + 0.25*oowp[j];
                 cout << rpi[j] << endl;
                 
           }
    }
    return 0;   
}

           
                               
                                
