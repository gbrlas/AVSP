#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char combine(vector<string> comb,char a,char b){
    for(int i=0;i<comb.size();i++){
        if((comb[i][0]==a && comb[i][1]==b) || (comb[i][0]==b && comb[i][1]==a))
            return comb[i][2];
    }
    return '-';
}

bool opposed(vector<string> opp,vector<char> v,char c){
    for(int i=0;i<v.size();i++){
        char cc = v[i];
        for(int j=0;j<opp.size();j++){
            if((opp[j][0]==c && opp[j][1]==cc) || (opp[j][0]==cc && opp[j][1]==c))
                return true;
        }
    }
    return false;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("magicka.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int c,d,n;
        char ch;
        string s;
        vector<string> comb;
        vector<string> opp;
        vector<char> elems;
        cin>>c;
        for(int j=0;j<c;j++){
            cin>>s;
            comb.push_back(s);
        }
        cin>>d;
        for(int j=0;j<d;j++){
            cin>>s;
            opp.push_back(s);
        }
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>ch;
            if(elems.size()>0){
                char cm = combine(comb,elems.back(),ch);
                if(cm!='-'){
                    elems.pop_back();
                    elems.push_back(cm);
                }
                else{
                    bool op = opposed(opp,elems,ch);
                    if(op)
                        elems.clear();
                    else
                        elems.push_back(ch);
                }
            }
            else
                elems.push_back(ch);
        }
        cout<<"Case #"<<i+1<<": [";
        for(int j=0;j<elems.size();j++){
            cout<<elems[j];
            if(j!=elems.size()-1)
                cout<<", ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
