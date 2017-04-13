/*
    12 April, 2014
*/
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,tc,mark[20],i,j,x,rec,k,l,r1;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aans0.out","w",stdout);


    cin >> T;
    tc = 0;
    while(tc < T){
        tc++;
        memset(mark, 0, sizeof(mark));
        for(l= 0; l < 2; l++){
            cin >> r1;


            for(i = 0; i < 4;i++){
                for(j = 0; j < 4; j++){
                        cin >> x;
                    if(i+1 == r1) mark[x]++;
                }

            }
        }
        k = 0;
        for(i = 1; i < 17; i++){
            if(mark[i]==2){
                    k++;
                    rec = i;
            }
        }
        printf("Case #%d: ",tc);
        if(k == 0) printf("Volunteer cheated!\n");
        if(k == 1) printf("%d\n",rec);
        if(k > 1) printf("Bad magician!\n");

    }

    return 0;
}

