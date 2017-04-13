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

map<string,int> F;

char tmp[1<<15];

int ins(string s){
    map<string,int>::iterator i=F.find(s);
    if(i!=F.end())return i->second;
    int res=F.size();
    return F[s]=res;
}

int f(string s){
    map<string,int>::iterator i=F.find(s);
    return i==F.end()?F.size():i->second;
}

vector<int> A,B;
int G[128][1024];

int g(int i,int j){
    if(j>=B.size())return 0;
    int &res=G[i][j];
    if(res<0){
        res=B.size();
        if(A[i]==B[j]){
            for(int k=0;k<A.size();++k)
                if(k!=i)
                    res<?=g(k,j+1)+1;
        }else res=g(i,j+1);
    }
    return res;
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    for(int T=atoi(gets(tmp)),tc=0;tc++<T;){
        F.clear();
        int n=atoi(gets(tmp));
        A.clear(),B.clear();
        for(int i=0;i<n;++i){
            gets(tmp);
            A.push_back(ins(tmp));
        }
        n=atoi(gets(tmp));
        for(int i=0;i<n;++i){
            gets(tmp);
            B.push_back(ins(tmp));
        }
        int res=B.size();
        memset(G,-1,sizeof G);
        for(int i=0;i<A.size();++i)res<?=g(i,0);
        printf("Case #%d: %d\n",tc,res);
    }
    return 0;
}
