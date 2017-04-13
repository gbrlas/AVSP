#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define REP(i,n)    for(int i=0;i<n;++i)

string line(){
    string res; getline(cin,res);
    return res;
}

string T;
set<string> S;

struct node{
    int l,r;
    string key;
    double p;
    node(){l=r=-1; key=""; p=0; }
}a[128];
int q;

int ii,root;

char ps(){ while(T[ii]==' ')++ii; return T[ii]; }
void go(char c){ for(;T[ii] && T[ii]!=c;++ii); ii+=T[ii]==c; }

string token(){
    ps();
    string res;
    for(;T[ii]!=' ' && T[ii]!='(' && T[ii]!=')';++ii)res+=T[ii];
    return res;
}

double D(const string&s){
    double res=-1;
    sscanf(s.data(),"%lf",&res);
    return res;
}

int parse(){
    if(ps()=='('){
        int res=q++;
        a[res]=node();
        ++ii;
        a[res].p=D(token());
        string x=token();
        if(x.size()){
            a[res].key=x;
            a[res].l=parse();
            a[res].r=parse();
        }
        go(')');
        return res;
    }
    return -1;
}

void Solve(){
    int n;
    cin>>n;
    line();
    T="";
    REP(j,n)T+=line()+" ";
    ii=q=0,root=parse();
    int tt; cin>>tt;
    REP(ttt,tt){
        string s;
        cin>>s;
        int k;
        cin>>k;
        S.clear();
        REP(j,k){
            string v;
            cin>>v;
            S.insert(v);
        }
        double res=1;
        for(int x=root;~x;){
            res*=a[x].p;
            if(S.count(a[x].key)){
                x=a[x].l;
            }else x=a[x].r;
        }
        printf("%.7lf\n",res);
    }
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d:\n",a);
    return 0;
}
