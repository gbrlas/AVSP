#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int MXN = 200002;
int trie[MXN][37];
int val[MXN];
int s,ans;
string str;
void insert(string str) {
    int k = 0,t;
    int last = 1;
    for(int i =0; i<str.length();i++ ){ 
        if(str[i]=='/') t = 0;
        else if(str[i]>='0' && str[i]<='9') t=str[i]-'0'+1;
        else t=str[i]-'a'+11;
        if(i>0 && (!val[k]) && t==0){
            val[k]=1;
            ans++;
            //cout<<str<<' '<<i<<endl;
        }
        if(trie[k][t]){
            k = trie[k][t];
        }else {
            /*if(last==0 && t!=0 || t==0) {
                ans++;
                last  = 1;
                cout<<str<<' '<<i<<endl;
            }*/
            s++;
            trie[k][t]=s;
            k = s;
        }
    }
    if(!val[k]) {
        val[k]=1;
        ans++;
           // cout<<str<<" end"<<endl;
    }
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    int cn, n ,m;
    s = MXN - 2;
    string str;
    scanf("%d",&cn);
    for (int ci = 0; ci < cn; ci++) {
        memset(trie, 0, sizeof(trie));
        memset(val, 0, sizeof(val));
        scanf("%d%d",&n,&m);
        ans = 0;
        s=0;
        for(int i=1;i<=n;i++) {
            cin>>str;
            insert(str);
        }
        ans = 0;
        for(int i=1;i<=m;i++) {
            cin>>str;
            insert(str);
        }
        printf("Case #%d: %d\n",ci+1,ans);

    }
    return 0;
}
