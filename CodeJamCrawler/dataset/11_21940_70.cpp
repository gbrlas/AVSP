#include <iostream>
#include <cstdio>
using namespace std;

int t,c,d,n;
string cstr[40],dstr[40],nstr;

char checkc(char a, char b){
    for (int i=0;i<c;i++){
        if ((cstr[i][0]==a&&cstr[i][1]==b)||(cstr[i][0]==b&&cstr[i][1]==a)) return cstr[i][2];
    }
    return '#';
}

bool checkd(char a, char b){
    for (int i=0;i<d;i++)
        if ((dstr[i][0]==a&&dstr[i][1]==b)||(dstr[i][0]==b&&dstr[i][1]==a)) return true;
    return false;
}

string change(string x){
    int len=x.length();
    string tp="";
    char ch;
    for (int i=1;i<len;i++){
        bool clear=false;

        ch=checkc(x[i],x[i-1]);
        if (ch!='#'){
            for (int j=0;j<i-1;j++) tp+=x[j];
            tp+=ch;
            for (int j=i+1;j<len;j++) tp+=x[j];
            return change(tp);
        }
        for (int j=0;j<i;j++){
            if (checkd(x[i],x[j])) clear=true;
        }
        if (clear){
            for (int j=i+1;j<len;j++) tp+=x[j];
            return change(tp);
        }
    }
    return x;
}

void print(string x){
    int len=x.length();
    printf("[");
    for (int i=0;i<len-1;i++)
        printf("%c, ",x[i]);
    if (len!=0) printf("%c",x[len-1]);
    printf("]\n");
}

int main(){
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    scanf("%d",&t);
    for (int ttt=1;ttt<=t;ttt++){
        scanf("%d",&c);
        for (int i=0;i<c;i++) cin>>cstr[i];
        scanf("%d",&d);
        for (int i=0;i<d;i++) cin>>dstr[i];
        scanf("%d",&n);
        cin>>nstr;
        //cout<<nstr<<endl;
        string af=change(nstr);
        printf("Case #%d: ",ttt);
        print(af);
    }
    return 0;
}
