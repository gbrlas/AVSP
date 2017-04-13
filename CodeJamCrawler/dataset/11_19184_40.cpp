#include<iostream>
using namespace std;
int main(){
    int n,te,r;
    cin>>te;
    r=te;
    while(te--){
        cin>>n;
        int co=0,tgo=0,tgb=0,cb=0,k,c,oj=0,bj=0,tim=0,a[n],o[n],b[n];
        char t[n];
        for(int i=0;i<n;i++){
            cin>>t[i];
            if(t[i]=='O'){
                cin>>o[oj++];
            }
            else{
                cin>>b[bj++];
            }
        }
        oj=0;bj=0;
        for(int i=0;i<n;i++){
            if(t[i]=='O'){
                c=tim-tgo;
                if(oj==0){
                    k=o[oj]-1;}
                else{
                    k=o[oj]-o[oj-1];
                    if(k<0)
                    k*=(-1);
                }
                oj++;
                k-=c;
                if(k>0){
                    tim+=k;
                }
                tim++;
                tgo=tim;
            }
            else{
                c=tim-tgb;
                if(bj==0){
                    k=b[bj]-1;}
                else{
                    k=b[bj]-b[bj-1];
                    if(k<0)
                    k*=(-1);
                }
                bj++;
                k-=c;
                if(k>0){
                    tim+=k;
                }
                tim++;
                tgb=tim;
            }
        }
        printf("Case #%d: %d\n",r-te,tim);
    }
    return 0;
}
