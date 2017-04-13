#include<iostream>

using namespace std;

int t,n,l,h,v[100],caso;

int doit(){
    scanf("%d%d%d",&n,&l,&h);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int res=l;res<=h;++res){
        bool enc=true;
        for(int i=0;i<n;++i){
            if(!(v[i]%res==0||res%v[i]==0)){
                enc=false;
                break;
            }
        }
        if(enc){
            return res;
        }
    }
    return -1;
}

int main(){
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        printf("Case #%d: ",++caso);
        int aux=doit();
        if(aux!=-1){
            printf("%d\n",aux);
        }
        else{
            puts("NO");
        }
    }
}
