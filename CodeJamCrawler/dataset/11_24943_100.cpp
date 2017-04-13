#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int c,d,n;
string s,f[100],o[100];
char a[300][300];
bool b[300][300];

int main() {
    freopen("magicka.inp","r",stdin);
    freopen("magicka.out","w",stdout);
    int t;
    cin >> t;
    
        
    FOR(_,1,t) {
        cin >> c;
        
        for (int c1=0;c1<256;c1++)
            for (int c2=0;c2<256;c2++) {
                a[c1][c2]='!';
                b[c1][c2]=false;
            }
            
        FOR(i,1,c) {
            cin >> f[i];
            a [(int)f[i][0]] [(int)f[i][1]] = f[i][2];
            a [(int)f[i][1]] [(int)f[i][0]] = f[i][2];
        }
        cin >> d;
        FOR(i,1,d) {
            cin >> o[i];
            b [(int)o[i][0]] [(int)o[i][1]] = true;
            b [(int)o[i][1]] [(int)o[i][0]] = true;
        }
        cin >> n;
        cin >> s;
               
        string res="";
        int l=0;
        FOR(i,0,n-1) {
            
            char tmp;
            if (l>0) tmp=a[(int)s[i]][(int)res[l-1]];
            if (l>0 && tmp!='!') res[l-1]=tmp;
            else {
                bool opposed=false;
                FOR(j,0,l-1)
                    if (b[(int)s[i]][(int)res[j]]) {
                        opposed=true;
                        break;
                    }
                if (opposed) {
                    l=0;
                    res="";
                } else {
                    l++;
                    res+=s[i];
                }
            }
            
        }
        cout << "Case #"<<_<<": [";
        FOR(i,0,l-1) {
            cout << res[i];
            if (i!=l-1) cout <<", ";
        }
        cout <<"]\n";
    }
}