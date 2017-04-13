/*Shashank Shekhar JUET*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
 
using namespace std;
 
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x);
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl

int main()
{
   int tc=0,t=0;
   scanf("%d",&tc);
   for(t=1;t<=tc;t++)
   {
    char ar[5][5],arm[5][5];
    int i=0,j=0,score=0;
    bool nc=false,found=false;
    for(i=0;i<4;i++)
        scanf("%s",&arm[i]);

    for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
       ar[i][j]=arm[i][j];
        }

       /* for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
        printf("%c",ar[i][j]);
        printf("\n");}*/

        for(i=0;i<4;i++)
        {  score=0;
            for(j=0;j<=2;j++)
            {
               if(ar[i][j]!=(int)'.')
               {
                   if(ar[i][j+1]!=(int)'T'&&ar[i][j]==ar[i][j+1])
                    score++;
                    else if(ar[i][j+1]==(int)'T')
                    {
                        score++;
                        ar[i][j+1]=ar[i][j];
                    }
                   else if(ar[i][j]==(int)'T')
                       {
                         ar[i][j]=ar[i][j+1];
                       score++;
                       }
               }
               else nc=true;
            }
            if(score==3)
            {
                printf("Case #%d: %c won\n",t,ar[i][0]);
                i=5;
                found=true;
                goto next;
            }
        }
        if(i==5)
            continue;


             for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
       ar[i][j]=arm[i][j];
        }


            for(j=0;j<4;j++)
        {  score=0;
            for(i=0;i<=2;i++)
            {
               if(ar[i][j]!=(int)'.')
               {
                   if(ar[i+1][j]!=(int)'T'&&ar[i][j]==ar[i+1][j])
                    score++;
                    else if(ar[i+1][j]==(int)'T')
                    {
                        score++;
                        ar[i+1][j]=ar[i][j];
                    }
                   else if(ar[i][j]==(int)'T')
                       {
                         ar[i][j]=ar[i+1][j];
                       score++;
                       }
               }
               else nc=true;
            }
            if(score==3)
            {
                printf("Case #%d: %c won\n",t,ar[0][j]);
                found=true;
                j=5;
                goto next;
            }
        }
        if(j==5)
            continue;

for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
       ar[i][j]=arm[i][j];
        }



        {  score=0;
            for(i=0;i<=2;i++)
            { j=i;
               if(ar[i][j]!=(int)'.')
               {
                   if(ar[i+1][j+1]!=(int)'T'&&ar[i][j]==ar[i+1][j+1])
                    score++;
                    else if(ar[i+1][j+1]==(int)'T')
                    {
                        score++;
                        ar[i+1][j+1]=ar[i][j];
                    }
                   else if(ar[i][j]==(int)'T')
                       {
                         ar[i][j]=ar[i+1][j+1];
                       score++;
                       }
               }
               else nc=true;
            }
            if(score==3)
            {
                printf("Case #%d: %c won\n",t,ar[0][0]);
                found=true;
               i=5;
               goto next;
            }
        }
        if(i==5)
            continue;



            for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
       ar[i][j]=arm[i][j];
        }



        score=0;
            for(i=3;i>=1;i--)
            { j=3-i;
               if(ar[i][j]!=(int)'.')
               {
                   if(ar[i-1][j+1]!=(int)'T'&&ar[i][j]==ar[i-1][j+1])
                    score++;
                    else if(ar[i-1][j+1]==(int)'T')
                    {
                        score++;
                        ar[i-1][j+1]=ar[i][j];
                    }
                   else if(ar[i][j]==(int)'T')
                       {
                         ar[i][j]=ar[i-1][j+1];
                       score++;
                       }
               }
               else nc=true;
            }
            if(score==3)
            {
                printf("Case #%d: %c won\n",t,ar[3][0]);
                found=true;
               i=5;
               goto next;
            }

        if(i==5)
            continue;
     if(!found)
     {if(nc)
    printf("Case #%d: Game has not completed\n",t);
    else
        printf("Case #%d: Draw\n",t);
     }
  next:printf("");

   }



    return 0;
}