#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,n;
    char a[100],b[100];
    cin>>t;
    for(int i=0;i<t;i++){
            int nextin1=0,nextin2=0,count1=0,count2=0,count=0;
            char atemp,btemp;
            cin>>n;
            cin>>a;
            cin>>b;
            while(1){
                     atemp=a[nextin1];
                     btemp=b[nextin2];
                     count1=0;
                     count2=0;
                     if(atemp=='\0' && btemp=='\0'){
                                 cout<<"Case #"<<i+1<<": "<<count<<"\n";
                                 break;    
                          }
                     else if(atemp!=btemp){
                                      cout<<"Case #"<<i+1<<": Fegla Won\n";
                                      break;
                          }
                     else{
                          while(a[nextin1]==atemp){
                                              count1++;
                                              nextin1++;
                                              }
                          while(b[nextin2]==btemp){
                                              count2++;
                                              nextin2++;
                                              }
                          count=count+abs(count1-count2);
                          }                     
                  }
            }
    return 0;
}
