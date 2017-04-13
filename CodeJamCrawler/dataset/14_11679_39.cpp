//
//  main.c
//  wangdingcheng
//
//  Created by Dingcheng Wang on 12/4/14.
//  Copyright (c) 2014 Dingcheng Wang. All rights reserved.
//

#include <stdio.h>
int main(void){
    int numOfCase, row1,row2,squareGrid1[4][4],squareGrid2[4][4];
    int sameNum,num=0,totalCase;
    scanf("%d",&numOfCase);
    totalCase = numOfCase;
    while(numOfCase>0){
        scanf("%d",&row1);
        for(int i = 0; i < 4;i++)
            for(int j =0;j<4;j++)
                scanf("%d",&squareGrid1[i][j]);
        scanf("%d",&row2);
        for(int i = 0; i < 4;i++)
            for(int j =0;j<4;j++)
                scanf("%d",&squareGrid2[i][j]);
        sameNum = 0;
        for(int k=0;k<4;k++){
            for(int i = 0; i<4;i++)
                if(squareGrid1[row1-1][k]==squareGrid2[row2-1][i]){
                    sameNum++;
                    num=squareGrid1[row1-1][k];
                }
        }
        if(sameNum==0)
            printf("Case #%d: Volunteer cheated!\n",totalCase-numOfCase+1);
        else if(sameNum==1)
            printf("Case #%d: %d\n",totalCase-numOfCase+1,num);
        else
            printf("Case #%d: Bad magician!\n",totalCase-numOfCase+1);
        numOfCase--;
    }
    return 0;
    
}

