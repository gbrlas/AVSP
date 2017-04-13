/*************************************************************************
  > File Name: pA.cpp
  > Author: rockwyc992
  > Mail: rockwyc992@gmail.com 
  > Created Time: 西元2014年04月12日 (週六) 11時24分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;

int ch;

int map1[4];
int map2[4];

std::vector<int> match;

int main()
{
    scanf("%d", &T);
    for(int t=1 ; t<=T ; t++)
    {
        match.clear();
        scanf("%d", &ch);
        for(int i=1 ; i<=4 ; i++)
        {
            if(i == ch)
            {
                for(int j=0 ; j<4 ; j++)
                {
                    scanf("%d", map1+j);
                }
            }
            else
            {
                for(int j=0 ; j<4 ; j++)
                {
                    scanf("%*d");
                }
            }
        }
        scanf("%d", &ch);
        for(int i=1 ; i<=4 ; i++)
        {
            if(i == ch)
            {
                for(int j=0 ; j<4 ; j++)
                {
                    scanf("%d", map2+j);
                }
            }
            else
            {
                for(int j=0 ; j<4 ; j++)
                {
                    scanf("%*d");
                }
            }
        }

        for(int i=0 ; i<4 ; i++)
        {
            for(int j=0 ; j<4 ; j++)
            {
                if(map1[i] == map2[j])
                {
                    match.push_back(map1[i]);
                }
            }
        }

        printf("Case #%d: ", t);

        if(match.size() == 1)
        {
            printf("%d\n", match[0]);
        }
        else if(match.size() == 0)
        {
            puts("Volunteer cheated!");
        }
        else
        {
            puts("Bad magician!");
        }
    }
    return 0;
}

