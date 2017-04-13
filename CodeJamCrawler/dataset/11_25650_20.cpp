#include<iostream>

using namespace std;

int t,p1,p2,caso;
long long n;

int gcd(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

bool doit(){
    cin>>n;
    scanf("%d%d",&p1,&p2);
    if(p1==0){
        if(p2==100){
            return false;
        }
        return true;
    }
    if(p2==0){
        if(p1==0){
            return true;
        }
        return false;
    }
    if(p1==100){
        if(p2!=0){
            return true;
        }
        return false;
    }
    if(p2==100){
        if(p1==100){
            return true;
        }
        return false;
    }
    //cout<<n<<" "<<p1<<" "<<p2<<endl;
    int mcd=gcd(p1,100);
    //cout<<mcd<<endl;
    int a=p1/mcd;
    int b=100/mcd;
    //cout<<a<<" "<<b<<endl;
    if(n/b<1){
        return false;
    }
    return true;
}

int main(){
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        printf("Case #%d: ",++caso);
        if(doit()){
            puts("Possible");
        }
        else{
            puts("Broken");
        }
    }
}
