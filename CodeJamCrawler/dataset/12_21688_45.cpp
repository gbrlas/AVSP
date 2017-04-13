#include<iostream>
using namespace std;
int main() {
    int arr[31][6]={{0,0,0,0,0,0},{0,0,1,0,0,0},{0,1,1,0,0,2},{1,1,1,0,1,2},{1,1,2,0,2,2},{1,2,2,1,1,3},{2,2,2,1,2,3},{2,2,3,1,3,3},
                    {2,3,3,2,2,4},{3,3,3,2,3,4},{3,3,4,2,4,4},{3,4,4,3,3,5},{4,4,4,3,4,5},{4,4,5,3,5,5},{4,5,5,4,4,6},{5,5,5,4,5,6},
                    {5,5,6,4,6,6},{5,6,6,5,5,7},{6,6,6,5,6,7},{6,6,7,5,7,7},{6,7,7,6,6,8},{7,7,7,6,7,8},{7,7,8,6,8,8},{7,8,8,7,7,9},
                    {8,8,8,7,8,9},{8,8,9,7,9,9},{8,9,9,8,8,10},{9,9,9,8,9,10},{9,9,10,8,10,10},{9,10,10,0,0,0},{10,10,10,0,0,0}
                   };
    int i,j,k,index;
    int t,n,s,p,count,temp,m;
    cin>>t;
    m=1;
    while(t--) {  
    cin>>n;
    int *score= new int[n];
    int *flag= new int[2*n];
    cin>>s;
    cin>>p;
    for(i=0;i<n;i++)
         cin>>score[i];
    count=0;
    for(i=0;i<2*n;i++)flag[i]=0;
    cout<<"Case #"<<m++<<": ";
    for(i=0;i<n;i++) {
       index = score[i];
       for(j=0;j<3;j++){
          if(arr[index][j]>=p){
              flag[i]=1;
               break;
          }
       }
       for(j=3;j<6;j++) {
          if(arr[index][j]>=p){
                flag[i+n]=1;
                break;
              }
          }  
     }
     for(i=0;i<n;i++) {
       if(flag[i]==1 && flag[i+n]==1) count++;
       if(flag[i]==0 && flag[i+n]==1 && s!=0){
          count++;
          s--;
       }
        if(flag[i]==1 && flag[i+n]==0) count++;
     }
     cout<<count;
     cout<<endl;
    }
    return 0;
}
