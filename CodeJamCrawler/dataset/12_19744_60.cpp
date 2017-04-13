#include <iostream>
using namespace std;

int T, N, S, p, arr[1000];

int main(){
    
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    
    cin >> T;
    
    for(int a=0; a<T; a++){
            
            cout << "Case #" << a+1 << ": ";
            
            cin >> N >> S >> p;
            
            int ns, s, noofns = 0, noofs = 0;
            
            for(int b=0; b<N; b++){
                     cin >> arr[b];
                     
                     if(arr[b]%3==0){
                         ns = arr[b]/3;
                         s = arr[b]/3+1;
                     }
                     if(arr[b]%3==1){
                         ns = arr[b]/3+1;
                         s = arr[b]/3+1;
                     }
                     if(arr[b]%3==2){
                         ns = arr[b]/3+1;
                         s = arr[b]/3+2;
                     }
                     
                     
                     if(arr[b]==0){
                         ns = 0;
                         s = 0;
                     }
                     
                     if(ns>=p) noofns++;
                     if(s>=p) noofs++;
                     
            }
            
            cout << min(noofns+S,noofs) << endl;
    }
    
    return 0;
}
            
            
