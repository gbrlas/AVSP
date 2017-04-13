//
//  File.c
//  ppppp
//
//  Created by Dingcheng Wang on 3/5/14.
//  Copyright (c) 2014 Dingcheng Wang. All rights reserved.
//

#include <stdio.h>
#define ARRSIZE 9

int main() {
    int numOfCase,K,cnt,result=0;
    unsigned int A,B;
    scanf("%d",&numOfCase);
    for(int z=1;z<=numOfCase;z++){
        cnt = 0;
        scanf("%d",&A );
        scanf("%d",&B );
        scanf("%d",&K );
        for(int i=0;i<A;i++)
        {
            for(int j=0;j<B;j++)
            {
                result = i & j;
                if(result<K)
                    cnt++;
                    
            }
        }
        
        printf("Case #%d: %d\n",z,cnt);

    }
    
    
}
