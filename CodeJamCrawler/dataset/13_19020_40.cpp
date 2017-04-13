#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;

int len(ll n){
        int i=0;
        while(n){
                n/=10;
                i++;
        }
        return i;
}

int pal(ll nn){
        ll n=nn;
        int k;
        ll no=0;
        int i=len(n);
        int c=0;
        while(n){
                k=n%10;
                no+=k*pow(10,i-1-c);
                n/=10;
                c++;
        }
        if(no==nn)
                return 1;
        else
                return 0;
}

int sq(ll n){
        ll a=sqrt(n);
        if(a*a == n)
                return 1;
        return 0;
}

int check(ll n){
        if(sq(n)){
                if(pal(n) && pal(sqrt(n))) return 1;
        }
        return 0;
}

int main(){
        int t;
        cin >> t;
        //      cout << sq(8898289) ;
        int tot=t;
        while(t--){
                ll a,b;
                cin >> a >> b;
                cout << "Case #" << tot-t<< ": " ;

                //functinality :
                ll i,c=0;
                for(i=a;i<=b;i++){
                        if(check(i)) c++;
                }
		cout << c << endl;

        }

        return 0;
}
