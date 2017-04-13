//
//  main.c
//  Csmall
//
//  Created by Dingcheng Wang on 12/4/14.
//  Copyright (c) 2014 Dingcheng Wang. All rights reserved.
//

#include <stdio.h>
void insertion(int [],int);
int main(void)
{
    int numOfCase,num,block,y,z,n,m,p;
    double Naomi[10],Ken[10],tmp;
    scanf("%d",&numOfCase);
    num = numOfCase+1;
    while(numOfCase>0){
        y=0;
        z=0;
        n=0;
        m=0;
        p=0;
        scanf("%d",&block);
        for(int i=0;i<block;i++)
            scanf("%lf",&Naomi[i]);
        for(int i=0;i<block;i++)
            scanf("%lf",&Ken[i]);
        //sort Naomi

            for(int k=0;k<block;k++){
                for(int i=k-1;i>=0;i--){
                    if(Naomi[i]>Naomi[i+1]){
                        tmp = Naomi[i];
                        Naomi[i] = Naomi[i+1];
                        Naomi[i+1] = tmp;
                    }
                    else
                        break;
                }
                for(int i=k-1;i>=0;i--){
                    if(Ken[i]>Ken[i+1]){
                        tmp = Ken[i];
                        Ken[i] = Ken[i+1];
                        Ken[i+1] = tmp;
                    }
                    else
                        break;
                }
            }
            //test

//        for(int i=0;i<block;i++)
//            printf(" %lf",Naomi[i]);
//        printf("\n");
//        for(int i=0;i<block;i++)
//            printf(" %lf",Ken[i]);
        //compare Naomi and Ken
        for(int i=0;i<block;i++){
            if(Naomi[i]>Ken[i+n]&&(i+n<block)){
                while(Naomi[i]>Ken[i+n]){
                    n++;
                    if(i+n==block)
                        break;
                }
                
            }
            if(i+n==block)
            {
                z=block - i;
                break;
            }
        }
        while(m<block){
            if(Naomi[m]>Ken[p])
            {
                m++;
                y++;
                p++;
            }
            else{
                m++;
            }
        }
        printf("Case #%d: %d %d\n",num-numOfCase,y,z);
        numOfCase--;
    }
    return 0;
}


