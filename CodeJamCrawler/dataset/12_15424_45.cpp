#include <fstream>
#include <iostream>
using namespace std;
int main(){
    int t,i,n,s,p,j,ti;
    ifstream in ("B-small-attempt2.in");
    ofstream out ("o.out");
    in>>t;
    int a,b,c;
    for (i = 1;i<=t;i++){
        int res = 0;
        in>>n>>s>>p;
        for (j = 1;j<=n;j++){
            in>>ti;
            bool dif = false;
            int r = 0;
            for (a = 10;a>= max (p,ti/3);a--){
                for (c = a;c>=a-2;c--){
                    b = ti-a-c;
                    if (a>=b && b>=c && b>=0 && c>=0){
                       if (a-c < 2){
                          dif = true;        
                       }
                       r++;
                    }       
                }    
            }
            if (r>0){
               if (dif == false && s>0){
                  res++;
                  s--;        
               }
               if (dif == true){
                  res++;        
               }
            }
        }
        out<<"Case #"<<i<<": "<<res<<"\n";                  
    }   
}
