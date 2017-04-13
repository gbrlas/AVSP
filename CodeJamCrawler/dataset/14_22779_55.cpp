#include<iostream>
using namespace std;
int main(){
    int t;
    double c,f,x,time,temp,r;
    cin>>t;
    r=2;
    for(int i=0;i<t;i++){
            cin>>c>>f>>x;
            time=x/2;
            temp=c/r;
            while(1){
                    r+=f;
                    temp+=(x/r);
                    if(temp<time)time=temp;
                    else break;
                    temp-=(x/r);
                    temp+=(c/r);
                    }
            cout.precision(9);
            cout<<"Case #"<<(i+1)<<": "<<time<<"\n";
            r=2;
            }
}
