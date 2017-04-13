#include <cstdio>
#include <algorithm>
using namespace std;

bool test(int a, int b){
    if(a<b)swap(a,b);
    bool win = true;
    while(1){
        if(a==b){
            win = !win;
            return win;
        }
        if(a/b>=2){
            return win;
        }
        else{
            a-=b;
            swap(a,b);
            win = !win;
        }
    }
}

int main(){
    FILE *fin = freopen("C-small-attempt0.in","r",stdin);
    FILE *fout= freopen("C-small-attempt0.out","w",stdout);
    int T,t,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        printf("Case #%d: ",t);
        int A1,A2,B1,B2;
        scanf("%d %d %d %d",&A1,&A2,&B1,&B2);
        long long res=0;
        for(i=A1;i<=A2;i++)for(j=B1;j<=B2;j++){
            if(test(i,j))res++;
        }
        printf("%I64d\n",res);
    }
}
