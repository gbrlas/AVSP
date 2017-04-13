#include <stdio.h>
#include <algorithm>
#include <inttypes.h>
#include <set>
using namespace std;

struct Cnum{
    char digits[9];
    char len;

    Cnum(int x){
        int i=0,k=1;
        for(;x>0;k*=10,++i){
            digits[i]=x%k;
            x/=k;
        }
        len=i;
    }

    Cnum(char *s){
        int i=0;
        for(;s[i];++i);
        len=i;
        i-=1;
        for(int k=0;i>=0;--i,++k)
            digits[k]=s[i]-'0';
    }

    Cnum(Cnum &x){
        len = x.len;
        for(int i=0;i<len;++i) digits[i]=x.digits[i];
    }

    Cnum inc(){
        for(int i=0;i<len;++i){
            if(digits[i]+1>9)
                digits[i]=0;
            else{
                digits[i]+=1;
                break;
            }
        }
        return *this;
    }

    int val(){
        int res=0;
        for(int i=0,k=1;i<len;++i,k*=10){
            res+=digits[i]*k;
        }
        return res;
    }

    int shift(){
        int k=1;
        for(;k<len;k++){
            for(int i=len-1;i>=0;--i){
                digits[i+1]=digits[i];
            }
            digits[0]=digits[len];
            if(digits[len-1])break;
        }
        return k;
    }

    bool operator <(Cnum &a){
        for(int i=len-1;i>=0;--i){
            if(digits[i]<(a.digits[i])) return true;
            else if(digits[i]>(a.digits[i])) return false;
        }
        return false;
    }

    bool operator <=(Cnum&a){
        for(int i=len-1;i>=0;--i){
            if(digits[i]<(a.digits[i])) return true;
            else if(digits[i]>(a.digits[i])) return false;
        }
        return true;
    }

};

int main(){

    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);

    int n;
    char ina[10],inb[10];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        set< pair<int,int> > qw;
        scanf("%s %s",ina,inb);
        Cnum a(ina);
        Cnum b(inb);
        Cnum x(ina);
        if(a.len != 1)
            while(x<b){
                Cnum shifted(x);
                for(int j=0;j<a.len;){
                    j+=shifted.shift();
                    if(shifted<=b && x<shifted && a<=shifted)
                        qw.insert(pair<int,int>(x.val(),shifted.val()));
                }
                x.inc();
            }
        printf("Case #%d: %ld\n",i+1,qw.size());
    }
    return 0;
}
