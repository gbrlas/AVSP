/* 
 * File:   main.cpp
 * Author: Jagan
 *
 * Created on 12 April, 2014, 10:40 AM
 */
#include<stdio.h>
#include <cstdlib>

using namespace std;

int main() {
    FILE *in,*out;
    int cards1[4][4],cards2[4][4],result,i,start,testCase,ans1,ans2;
    in=fopen("G://A-small-attempt0.in","r");
    out=fopen("G://A-small-attempt0.out","w");
    fscanf(in,"%d",&testCase);
    for(i=0;i<testCase;i++){
        start=(-1);
        fscanf(in,"%d",&ans1);
        for(int j=0;j<4;j++){
        for(int jj=0;jj<4;jj++){
            fscanf(in,"%d",&cards1[j][jj]);
        }
        }
        fscanf(in,"%d",&ans2);
        for(int j=0;j<4;j++){
        for(int jj=0;jj<4;jj++){
            fscanf(in,"%d",&cards2[j][jj]);
        }
        }
        
        for(int k=0;k<4;k++){
            for(int l=0;l<4;l++){
                if(cards1[ans1-1][k]==cards2[ans2-1][l]){
                    result=cards2[ans2-1][l];
                    start++;
                }
            }
        }
        if(start==0)fprintf(out,"Case #%d: %d\n",i+1,result);
        if(start==-1)fprintf(out,"Case #%d: Volunteer cheated!\n",i+1);
        if(start>0)fprintf(out,"Case #%d: Bad magician!\n",i+1);
        
    }
    fclose(in);
    fclose(out);

    return 0;
}

