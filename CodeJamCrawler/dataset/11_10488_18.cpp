#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <ctype.h>
#include <math.h>

#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <complex>
#define ll long long
#define MAXN 10000
using namespace std;

int abs(ll a){ return a>=0? a: -1*(a);}
int maior(ll a,ll b){ return a>b? a: b;}
int menor(ll a,ll b){ return a<b? a: b;}
ll mdc(ll a,ll b){
    if(b==0)
        return a;
    return mdc(b,a%b);
}

int main(int argc,char *argv[]){
    int T;
    ll max,min;
    int N;
    ll v[MAXN];;
    cin>>T;
    ll i,j,k;
    ll mdcV;

    for(k=1;k<=T;k++){
        cin>>N>>min>>max;

        for(i=0;i<N;i++)
            cin>>v[i];
      //  mdcV=v[0];
      //  bool ok=true;
       /* for(i=0;i<N;i++){
            for(j=i+1;j<N;j++){
                //if(v[i]%v[j] && v[j]%v[i]){
                  //  ok=false;
                    //printf("NOOK %d %d %lld %lld\n",i,j,v[i],v[j]);
                   // goto FIM;

                //}
                mdcV=mdc(mdcV,mdc(v[i],v[j]));
            }
        }
        FIM:
        */
        ll x;

        printf("Case #%d: ",k);
        /*if(!ok){
            cout<<"NO"<<endl;
            continue;
        }
        */
        bool ok=false;
    //    cout<<"MIMMAX "<<min<<" "<<max<<endl;
      //  printf("MDC: %lld\n ",mdcV);
        for(i=min;i<=max;i++){

            bool b=true;
            x=i;
            for(j=0;j<N;j++){
                if(v[j]%x && x%v[j]){
                    b=false;
                    break;
                }
            }
            if(b){
              //  cout<<"MIMMAX "<<min<<" "<<max<<endl;
               // printf("OK %lld\n",x);
                ok=true;
                break;
            }
        }
        if(ok){
            cout<<x<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
