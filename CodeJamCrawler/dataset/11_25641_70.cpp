#include<iostream>

using namespace std;

int t,n;
long long num;

void doit(){
    scanf("%d",&n);
    //cout<<n<<endl;
    long long suma=0LL;
    int menor=10000000;
    long long Xor=0LL;
    for(int i=0;i<n;++i){
        cin>>num;
        //cout<<num<<" ";
        suma=suma+num;
        if(num<menor)menor=num;
        Xor^=num;
    }
    ////puts("");
    //cout<<suma<<" "<<menor<<" "<<Xor<<endl;
    if(Xor==0){
        cout<<suma-menor<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    scanf("%d",&t);
    //cout<<t<<endl;
    for(int i=1;i<=t;++i){
        cout<<"Case #"<<i<<": ";
        doit();
    }
}
