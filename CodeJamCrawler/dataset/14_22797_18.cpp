#include<iostream>
using namespace std;
int main(){
    int t,a,b,k,c;
    cin>>t;
    for(int i=0;i<t;i++){
            c=0;
            cin>>a>>b>>k;
            for(int j=0;j<a;j++){
                    for(int l=0;l<b;l++){
                            if((j&l)<k)c++;
                            }
                    }
            cout<<"Case #"<<i+1<<": "<<c<<"\n";
            }
    return 0;
}
