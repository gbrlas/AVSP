#include<iostream>
using namespace std;
int pow(int count){
    int power=1;
    for(int i=0;i<count;i++)
       power=power*10;
    return power;
}
int main() {
    int a,b,temp,counta,countb,j,comp,t,q=1;
    int i,num,inc;
    cin>>t;
    while(t--) 
    {
    cin>>a>>b;
    counta=0;
    inc=0;
    temp=a;
    cout<<"Case #"<<q++<<": ";
    while(temp>0){
        counta++;
        temp/=10;
    }
    for(i=a;i<=b;i++){
        comp=i;
        for(j=0;j<counta-1;j++) {
           temp=i%10;
           num=i/10;
           num=temp*pow(counta-1)+num;
           if(num <= b && num>=a && num!=comp) {
                inc++;
           }
           i=num;
        }
        i=comp;
    }
    cout<<inc/2;
    cout<<endl;
    }
    return 0;
}
