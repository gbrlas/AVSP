#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
long long int x;
long long int y;
}point;
bool cmp(const point &x,const point &y)
{
    return x.x<y.y;
}
int dots=0;
   char arr[10][10];
char won;
bool check_col();
bool check_row();
bool check_dig();
  int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("out.txt","w",stdout);
   int t,i,i2,i3;
   bool f=0;

   scanf("%d\n",&t);
   for(i=1;i<=t;i++)
   {
       f=0;
       dots=0;
       scanf("%s%s%s%s",arr[0],arr[1],arr[2],arr[3]);
        f=check_col();
        if(!f)
        f=check_row();
        if(!f)
        f=check_dig();
            if(f)
        {
            printf("Case #%d: %c won\n",i,won);
        }
         else if(dots)
            {
                printf("Case #%d: Game has not completed\n",i);
                continue;
            }
        else
        printf("Case #%d: Draw\n",i);

   }
}

bool check_col()
{
   //printf("in 1\n");
    int i,i2;
    bool f=0;
    char key;
    for(i=0;i<4&&!f;i++)
    {
        for(i2=0,key=arr[i2][i],f=1;i2<4;i2++)
        {

                if(arr[i2][i]=='.')
                {
                    dots++;
                    f=0;
                    break;
                }
                if(arr[i2][i]!=key&&(arr[i2][i]!='T'))
                f=0;
               // printf("%d %d %d\n",f,i,i2);
        }
        if(arr[i2][3]=='.')
            dots++;
        if(f)
        {
            for(i2=0;i2<4;i2++)
                if(arr[i2][i]!='T')
                {
                    won=arr[i2][i];
                    break;
                }
           // printf("%c\n",won);
                return 1;
        }
    }
    return 0;
}
bool check_row()
{
   //printf("in 2\n");
    int i,i2;
    bool f=0;
    char key;
    for(i2=0;i2<4&&!f;i2++)
    {

        for(i=0,key=arr[i2][i],f=1;i<4;i++)
        {

                 if(arr[i2][i]=='.')
                {
                    dots++;
                    f=0;
                    break;
                }
                if(arr[i2][i]!=key&&(arr[i2][i]!='T'))
                f=0;
             //  printf("%d\n",f);

        }
        if(arr[i2][3]=='.')
                    dots++;
        if(f)
        {
            for(i=0;i<4;i++)
                if(arr[i2][i]!='T')
                {
                    won=arr[i2][i];
                    break;
                }
            //  printf("%c\n",won);
                return 1;
        }
    }
    return 0;
}
bool check_dig()
{
   // printf("in3\n");
    int i,i2;
    bool f=1;
    char key;
    for(i2=0,i=0,key=arr[i][i2];i2<4&&f;i2++,i++)
    {
                 if(arr[i2][i]=='.')
                {
                    dots++;
                    f=0;
                    break;
                }
                if(arr[i2][i]!=key&&(arr[i2][i]!='T'))
                f=0;
      //          printf("%d 1\n",f);
    }
  if(f)
        {
            for(i=0,i2=0;i<4;i++,i2++)
                if(arr[i2][i]!='T')
                {
                    won=arr[i2][i];
                    break;
                }
        //        printf("%c\n",won);
                return 1;
        }
        f=1;
     for(i2=0,i=3,key=arr[i2][i];i2<4&&f;i2++,i--)
    {
                 if(arr[i2][i]=='.')
                {
                    dots++;
                    f=0;
                    break;
                }
                if(arr[i2][i]!=key&&(arr[i2][i]!='T'))
                f=0;
//                printf("%d 2\n",f);
    }
       if(f)
        {
                for(i2=0,i=3;i2<4;i2++,i--)
                if(arr[i2][i]!='T')
                {
                    won=arr[i2][i];
                    break;
                }
  //              printf("%c\n",won);
                return 1;
        }
    return 0;
}
