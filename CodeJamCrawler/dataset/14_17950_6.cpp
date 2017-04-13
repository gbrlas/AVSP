#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n1,n2,x;
    int first[4][4],second[4][4],pos1,count=0,ans;
    scanf("%d",&x);
    for(t=0;t<x;t++){
        count=0;
        scanf("%d",&n1);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&first[i][j]);
            }
        }
        pos1=n1-1;
        scanf("%d",&n2);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&second[i][j]);
            }
            if(i==n2-1){
                if((second[i][0]==first[pos1][0])||(second[i][0]==first[pos1][1])||(second[i][0]==first[pos1][2])||(second[i][0]==first[pos1][3])){
                    count++;
                }
                if((second[i][1]==first[pos1][0])||(second[i][1]==first[pos1][1])||(second[i][1]==first[pos1][2])||(second[i][1]==first[pos1][3])){
                    count++;
                }
                if((second[i][2]==first[pos1][0])||(second[i][2]==first[pos1][1])||(second[i][2]==first[pos1][2])||(second[i][2]==first[pos1][3])){
                    count++;
                }
                if((second[i][3]==first[pos1][0])||(second[i][3]==first[pos1][1])||(second[i][3]==first[pos1][2])||(second[i][3]==first[pos1][3])){
                    count++;
                }
     
            }
        }
        if(count==0){
            printf("Case #%d: Volunteer cheated!\n",t+1);
        }
        if(count>1){
            printf("Case #%d: Bad magician!\n",t+1);
        }
        if(count==1){
            if((first[n1-1][0]==second[n2-1][0])||(first[n1-1][0]==second[n2-1][1])||(first[n1-1][0]==second[n2-1][2])||(first[n1-1][0]==second[n2-1][3])){
                ans=first[n1-1][0];
            }
            if((first[n1-1][1]==second[n2-1][0])||(first[n1-1][1]==second[n2-1][1])||(first[n1-1][1]==second[n2-1][2])||(first[n1-1][1]==second[n2-1][3])){
                ans=first[n1-1][1];
            }
            if((first[n1-1][2]==second[n2-1][0])||(first[n1-1][2]==second[n2-1][1])||(first[n1-1][2]==second[n2-1][2])||(first[n1-1][2]==second[n2-1][3])){
                ans=first[n1-1][2];
            }
            if((first[n1-1][3]==second[n2-1][0])||(first[n1-1][3]==second[n2-1][1])||(first[n1-1][3]==second[n2-1][2])||(first[n1-1][3]==second[n2-1][3])){
                ans=first[n1-1][3];
            }
            printf("Case #%d: %d\n",t+1,ans);
        }
        
    }
    return 0;
}