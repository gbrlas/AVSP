#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t,n;
    double naomi[10],ken[10];            //change size to 1000 for large set
    cin>>t;
    for(int i=0;i<t;i++){
            cin>>n;
            for(int j=0;j<n;j++){
                    cin>>naomi[j];
                    }
            for(int j=0;j<n;j++){
                    cin>>ken[j];
                    }
            sort(naomi,naomi+n);
            sort(ken,ken+n);
            cout<<"Case #"<<i+1<<": ";
            int flag=0;
            for(int j=0;j<n;j++){     //deceit
                    int somet=0;
                    double temp=naomi[j];
                    for(int k=0;k<n;k++){
                            if(temp<ken[k]){
                                                break;
                                                }
                            else{
                                 if(ken[k]>0){
                                              somet++;
                                              ken[k]=ken[k]*(-1);
                                              break;
                                              }                            
                                 }
                            }                   
                    if(somet==0)flag++;                    
                    }
            cout<<(n-flag);
            for(int j=0;j<n;j++){
                    if(ken[j]<0){ken[j]=ken[j]*(-1);}
                    }
            flag=0;                  //When she plays War
            for(int j=0;j<n;j++){                    
                    double temp=naomi[j];
                    for(int k=0;k<n;k++){
                            if(temp<ken[k]){
                                            ken[k]=ken[k]*(-1);
                                            flag+=1;
                                            break;
                                            }
                            }                    
                    }
            cout<<" "<<(n-flag);
            cout<<"\n";
            }
}
