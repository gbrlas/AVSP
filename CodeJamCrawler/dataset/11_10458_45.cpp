#include <stdio.h>
#include <string>

using namespace std;
int abs(int a){
    if(a<0)
        return -1*a;
    return a;
}
int main(){
    int T;
    int N;
    scanf("%d",&T);

    int i,j,k;
    int tt,to,tb;
    int po,pb;
    char r;
    char s[10];
    int p;
    int d;
    for(k=0;k<T;k++){
        scanf("%d",&N);
        tt=tb=to=0;
        po=pb=1;
        for(i=0;i<N;i++){
            scanf("%s %d",s,&p);
            r=s[0];
          //  printf("%c %d\n",r,p);
            if(r=='O'){
                d=abs(p-po);
                if(to+d <= tt){
                        tt++;
                        to=tt;
                }
                else{
                    tt=to+d+1;
                    to=tt;
                }
                po=p;
            }
            else{
                d=abs(p-pb);
                if(tb+d <= tt){
                        tt++;
                        tb=tt;
                }
                else{
                    tt=tb+d+1;
                    tb=tt;
                }
                pb=p;
            }
           // printf("%d %d %d, %d %d\n",tt,to,tb,po,pb);

        }
        printf("Case #%d: %d\n",k+1,tt);
    }




}
