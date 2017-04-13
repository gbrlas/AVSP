#include <iostream>
#include <cstdio>
#include <string>
#include "bigint/BigIntegerLibrary.hh"
#include "bigint/BigInteger.cc"
#include "bigint/BigUnsigned.cc"
#include "bigint/BigIntegerUtils.cc"
#include "bigint/BigIntegerAlgorithms.cc"
#include "bigint/BigUnsignedInABase.cc"
//To judges:
//The above lib is found here:
//http://mattmccutchen.net/bigint/

#define abs(x) ((x)<0?-(x):(x))

using namespace std;

BigInteger a[1000];
BigUnsigned b[1000],g,f;
string s;
int i,N,c,C;
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&C);
    for(c=1;c<=C;++c){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            cin>>s;
            a[i] = stringToBigInteger(s);
        }
        for(i=1;i<N;i++)b[i] = stringToBigUnsigned(bigIntegerToString(abs(a[i] - a[i-1])));
        g = b[1];
        for(i=2;i<N;i++)g = gcd(g,b[i]);
        f = stringToBigUnsigned(bigIntegerToString(a[0]));
        f = f%g;
        if(f==0){
            g=0;
        }
        else{
            g-=f;
        }
        cout<<"Case #"<<c<<": "<<g<<endl;
    }
}
