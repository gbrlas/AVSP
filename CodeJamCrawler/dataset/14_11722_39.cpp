//
//  main.c
//  Bsmall
//
//  Created by Dingcheng Wang on 12/4/14.
//  Copyright (c) 2014 Dingcheng Wang. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int numOfCase=0,end,num;
    double time, prdct;
    double C, F, X;
    scanf("%d",&numOfCase);
    num = numOfCase+1;
    while(numOfCase>0){
        time = 0.0;
        prdct = 2.0;
        end = 0;
        scanf("%lf",&C);
        scanf("%lf",&F);
        scanf("%lf",&X);
        while(end==0){
            if(C/prdct+X/(prdct+F)<X/prdct)
            {
                time += C/prdct;
                prdct += F;
            }
            else{
                time += X/prdct;
                end = 1;
            }
        }
        printf("Case #%d: %0.7lf\n",num-numOfCase,time);
        numOfCase--;
    }
    return 0;
}

