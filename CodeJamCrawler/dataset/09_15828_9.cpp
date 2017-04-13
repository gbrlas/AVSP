#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    freopen("precalc.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    map< vector<int>, int > M;
    string s;
    
    vector<int> v;
    int x;
    
    while(getline(cin,s)){
        istringstream is(s);
        v.clear();
        while(is>>x) v.push_back(x);
        int ans=v.back();
        v.pop_back();
        if(v.size()>3) continue;
        M[v]=ans;
    }
    
    freopen("A-small-attempt0.in","r",stdin);
    
    int T;
    char c;
    scanf("%d\n",&T);
    
    for(int tc=1;tc<=T;tc++){
        printf("Case #%d: ",tc);
        
        v.clear();
        x=0;
        
        while(1){
            scanf("%c",&c);
            if(isdigit(c)) x=x*10+c-'0';
            else if(c=='\n'){
                if(x>0) v.push_back(x);
                break;
            }else{
                if(x!=0) v.push_back(x);
                x=0;
            }
        }
        
        sort(v.begin(),v.end());
        printf("%d\n",M[v]);
    }
    
    return 0;
}
