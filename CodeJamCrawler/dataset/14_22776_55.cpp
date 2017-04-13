#include<iostream>
using namespace std;
int main(){
    int a[2][4],count,row[2],flag,ans,temp;
    cin>>count;
    for(int i=0;i<count;i++){
            for(int j=0;j<2;j++){
                    cin>>row[j];
                    for(int k=0;k<4;k++){                            
                            for(int l=0;l<4;l++){
                                    cin>>temp;
                                    if(k==(row[j]-1)){
                                                      a[j][l]= temp;
                                                      }                                    
                                    }                                                                          
                            }
                    }
            flag=0;
            for(int j=0;j<4;j++){
                    for(int k=0;k<4;k++){
                            if(a[0][j]==a[1][k]){
                                                 ans=a[0][j];
                                                 flag++;
                                                 break;                                                 
                                                 }
                            }
                    }
            cout<<"Case #";
            cout<<i+1;
            cout<<": ";            
            if(flag==0){
                        cout<<"Volunteer cheated!";
                        }
            else if(flag==1){
                 cout<<ans;
                 }
            else{
                 cout<<"Bad magician!";
                 }
            cout<<"\n";
            }            
}
