#include <iostream>
#include <cstdio>
using namespace std;

int t,n;
int bpos,opos,total,time;

int abs(int x){
    if (x>0) return x;
    return 0-x;
}

int main(){
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    char ch,opt;
    int pos;
    scanf("%d",&t);
    for (int ttt=1;ttt<=t;ttt++){
        scanf("%d",&n);
        //cout<<n<<endl;
        time=total=0;
        opos=bpos=1;
        int acc=0;
        for (int i=1;i<=n;i++){
            scanf(" %c%d",&ch,&pos);
            //cout<<ch<<pos<<endl;
            if (i==1) opt=ch;
            if (ch=='O'){
                time = abs(pos-opos);
                if (opt!=ch){
                    time-=acc;
                    acc=0;
                }
                if (time<0) time=0;
                time++;
                acc += time;
                total+=time;
                opos = pos;
            }else{
                time = abs(pos-bpos);
                if (opt!=ch){
                    time-=acc;
                    acc=0;
                }

                if (time<0) time=0;
                time++;
                acc += time;
                total+=time;
                bpos = pos;
            }
            opt=ch;
            //cout<<total<<endl;
        }
        printf("Case #%d: %d\n",ttt,total);
    }
    return 0;
}
