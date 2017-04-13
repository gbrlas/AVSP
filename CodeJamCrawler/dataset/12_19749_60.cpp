#include <iostream>
#include <cstring>
using namespace std;

int T, A, B, pwof, tconut;

bool used[2000050];

void find_pwof(){
     int t, tA = A;
     while(tA>0){
                t++;
                tA/=10;
     }
     pwof = 1;
     for(int a=1; a<t; a++) pwof*=10;
}
     
     

int main(){
    
    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small.out","w",stdout);
    
    cin >> T;
    
    for(int a=0; a<T; a++){
            memset(used,false,sizeof(used));
            cout << "Case #" << a+1 << ": ";
            tconut =0;
            cin >> A >> B;
            find_pwof();
            
            for(int i=A; i<=B; i++){
                    
                    if(!used[i]){
                                 used[i]=true;
                                 int conut = 0;
                                 int j = i;
                                 do{
                                    int lno = j%10;
                                    j/=10;
                                    j+=(lno*pwof);
                                    
                                    if(j>=A&&j<=B&&used[j]==false){
                                        used[j]=true;
                                        conut++;
                                    }
                                    
                                 } while(j!=i);
                                 
                                 tconut+=(conut)*(conut+1)/2;
                                 
                    }
            }
            
            cout << tconut << endl;
            
    }
    //system("PAUSE");
    return 0;
}
                    
