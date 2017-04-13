/*************************************************************************
  > File Name: pB.cpp
  > Author: rockwyc992
  > Mail: rockwyc992@gmail.com 
  > Created Time: 西元2014年04月12日 (週六) 12時33分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;
double cost, gain, goal;
double rate, sec, min;

int main()
{
    scanf("%d", &T);
    for(int t=1 ; t<=T ; t++)
    {
        rate = 2.0;
        sec = 0.0;
        min = 100000.0;
        scanf("%lf%lf%lf", &cost, &gain, &goal);
        for(int i=0 ; ; i++)
        {
            if(min < sec + goal / rate)
                break;
            min = sec + goal / rate;
            sec += cost / rate;
            rate += gain;
        }
        printf("Case #%d: %.7lf\n", t, min);
    }
    return 0;
}

