#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>

using namespace std;

void Solve(){
    int L,D,N;
    cin>>L>>D>>N;
    
    vector<string> v;
    string s;
    for(int i=0;i<D;i++){
        cin>>s;
        v.push_back(s);
    }
    
    bool M[15][26];
    
    for(int i=1;i<=N;i++){
        cin>>s;
        memset(M,false,sizeof(M));
        
        for(int j=0,pos=0;j<L;j++){
            if(s[pos]=='('){
                pos++;
                for(;s[pos]!=')';pos++) M[j][s[pos]-'a']=true;
                pos++;
            }else{
                M[j][s[pos]-'a']=true;
                pos++;
            }
        }
        
        int cont=0;
        bool ok;
        
        for(int j=v.size()-1;j>=0;j--){
            ok=true;
            
            for(int k=0;k<L;k++) if(!M[k][v[j][k]-'a']) ok=false;
            
            if(ok) cont++;
        }
        
        cout<<"Case #"<<i<<": "<<cont<<endl;
    }
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    Solve();
    
    return 0;
}
