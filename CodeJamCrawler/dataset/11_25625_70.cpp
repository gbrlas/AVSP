#include<iostream>

using namespace std;

int n;
string res[6]={"","Sheldon","Leonard","Penny","Rajesh","Howard"};

int f(int x){
    if(x<6)return x;
    if(x%2==0){
        return f((x-4)/2);
    }
    return f((x-5)/2);
}

int main(){
    cin>>n;
    int pos=f(n);
    cout<<res[pos]<<endl;
}
