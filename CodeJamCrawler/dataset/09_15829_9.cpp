#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX 200000
bool happy[11][MAX];

int find(vector<int> v){
    for(int i=1;i<MAX;i++){
        bool ok=true;
        for(int j=0;j<v.size() && ok;j++) if(!happy[v[j]][i]) ok=false;
        if(ok) return i;
    }
    
    return -1;
}

int main(){
    freopen("precalc.txt","w",stdout);
    
    bool visited[MAX];
    
    for(int b=2;b<=10;b++){
        cout<<"base : "<<b<<endl;
    for(int i=1;i<MAX;i++){
        int aux=i,aux2,d;
        //cout<<i<<endl;
        memset(visited,false,sizeof(visited));
        visited[i]=true;
        while(1){
            aux2=0;
            while(aux!=0){
                d=aux%b;
                aux/=b;
                aux2+=d*d;
            }
            aux=aux2;
            //cout<<aux<<" ";
            if(aux>=MAX || visited[aux]){
                happy[b][i]=false;
                break;
            }else if(aux==1){
                happy[b][i]=true;
                break;
            }else if(aux<i){
                happy[b][i]=happy[b][aux];
                break;
            }
            
            visited[aux]=true;
        }
        //cout<<endl;
        //if(happy[b][i]) cout<<"happy : "<<i<<endl;
    }
    //cout<<endl;
    }
    
    vector<int> v;
    int ans;
    
    for(int mask=1;mask<(1<<9);mask++){
        v.clear();
        for(int i=0;i<9;i++) if(mask & (1<<i)) v.push_back(i+2);
        
        ans=find(v);
        
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<ans<<endl;
    }
    
    return 0;
}
