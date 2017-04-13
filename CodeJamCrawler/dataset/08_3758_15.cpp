#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
int n;
int tree[10001];
int save[10001][2];
bool gates[10001];
bool change[10001];
int mi(int a,int b){
    if (a==-1) return b;
    if (b==-1) return a;
    return a<b?a:b;
}
int nc(int p,int v){
    if (tree[p]==v) return 0;
    if (tree[p]!=2) return 999999;
    //tree[p]==2
    if (save[p][v]!=-1) return save[p][v];
    int min=-1;
    if (gates[p]){
        if (v==1){
            min = mi(min,nc(p*2,1)+nc(p*2+1,1));
            if (change[p]) min = mi(min,1+mi(nc(p*2,1)+nc(p*2+1,0),nc(p*2,0)+nc(p*2+1,1)));
        }
        if (v==0){
            min = mi(min,nc(p*2,0)+nc(p*2+1,0));
            min = mi(min,nc(p*2,0)+nc(p*2+1,1));
            min = mi(min,nc(p*2,1)+nc(p*2+1,0));
        }
    }else{
        if (v==1){
            min = mi(min,nc(p*2,1)+nc(p*2+1,1));
            min = mi(min,nc(p*2,0)+nc(p*2+1,1));
            min = mi(min,nc(p*2,1)+nc(p*2+1,0));
        }
        if (v==0){
            min = mi(min,nc(p*2,0)+nc(p*2+1,0));
            if (change[p]) min = mi(min,1+mi(nc(p*2,1)+nc(p*2+1,0),nc(p*2,0)+nc(p*2+1,1)));
        }

    }
    save[p][v]=min;
    return min;
}
int main(){
    cin>>n;
    for (int l=0;l<n;l++){
        int m,v;
        cin>>m>>v;
        //int tree[m+1];
        //bool gates[1+(m-1)/2];
        //bool change[1+(m-1)/2];
        for (int i=1;i<=m;i++) tree[i]=-1;
        for (int i=1;i<=(m-1)/2;i++){
            cin>>gates[i]>>change[i];
        }
        for (int i=1+(m-1)/2;i<=m;i++) cin>>tree[i];
        int count = 0;
        for (int i=m-1;i>1;i-=2){
            int a = tree[i];
            int b = tree[i+1];
            int p = i>>1;
            if (!change[p]){
                if (gates[p]){
                    if (a==2){
                        if (b==0) tree[p]=0;
                        else tree[p]=2;
                    }else if (b==2){
                        if (a==0) tree[p]=0;
                        else tree[p]=2;
                    }else{
                        tree[p]=a&b;
                    }
                }else{
                    if (a==2){
                        if (b==1) tree[p]=1;
                        else tree[p]=2;
                    }else if (b==2){
                        if (a==1) tree[p]=1;
                        else tree[p]=2;
                    }else{
                        tree[p]=a|b;
                    }
                }
            }else{
                if (a==2||b==2){
                    tree[p]=2;
                    continue;
                }
                if (a&&b) tree[p]=1;
                else if (!a&&!b) tree[p]=0;
                else tree[p]=2;
            }
        }
        cout<<"Case #"<<(l+1)<<": ";
        if (tree[1]!=2&&tree[1]!=v) cout<<"IMPOSSIBLE\n";
        else{
            for (int i=1;i<=m;i++){
                save[i][0]=-1;
                save[i][1]=-1;
            }
            count = nc(1,v);
            cout<<count<<endl;
        }
    }
    return 0;
}
