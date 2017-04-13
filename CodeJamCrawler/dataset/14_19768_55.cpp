#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
int search(int a,int arr[4]);

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("magic_trick.txt", "w", stdout);
    int t;
    int count;
    scanf("%d",&t);
    int i,j,k,index;
    int ans1,ans2,x;
    int row1[4],row2[4];
    int board1[4][4],board2[4][4];
    for(i = 1;i <= t;i++)
    {

        scanf("%d",&ans1);
        for(j = 0;j < 4;j++)
            for(k = 0;k < 4;k++)
                scanf("%d",&board1[j][k]);
        scanf("%d",&ans2);
        for(j = 0;j < 4;j++)
            for(k = 0;k < 4;k++)
                scanf("%d",&board2[j][k]);
        for(j = 0;j < 4;j++)
        {
            row1[j] = board1[ans1-1][j];
            row2[j] = board2[ans2-1][j];
        }
         count = 0;
        for(j = 0;j < 4;j++)
        {
           x = search(row1[j],row2);
           if(x!=-1)
           {
               count++;
               index = x;
           }
           if(count > 1)
           {
               index = -2;

           }

        }
        if(count == 0)
        {
            index = -3;
        }
        if(index == -2)
        {
            printf("case #%d: Bad magician! \n",i);
        }
        else if(index == -3)
        {
             printf("case #%d: Volunteer cheated! \n",i);
        }
        else
            printf("case #%d: %d\n",i,row2[index]);
    }
    return 0;
}

int search(int a,int arr[4])
{
    int i;
    for(i = 0;i < 4;i++)
    {
        if(arr[i] == a)
            return i;

    }
    return -1;
}
