#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,B;
    long long ans;
    string s;
    bool used[26];
    
    scanf("%d\n",&T);
    
    
    for(int tc=1;tc<=T;tc++){
        cin>>s;
        
        map<char,int> M;
        
        B=2;
        memset(used,false,sizeof(used));
        
        for(int i=0;i<s.size();i++){
            if(M.find(s[i])!=M.end()) continue;
            for(int j=0;j<9;j++){
                if(used[j]) continue;
                if(i==0 && j==0) continue;
                used[j]=true;
                M[s[i]]=j;
                B=max(B,j+1);
                break;
            }
        }
        
        ans=0;
        
        for(int i=0;i<s.size();i++) ans=ans*B+M[s[i]];
        
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    
    return 0;
}
