#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int T; cin >> T; 
    for(int t=0; t<T; ++t){
        int N, S, P; 
        cin >> N >> S >> P;
        //cout << P << endl;
        int m = 0;
        for(int n=0; n<N; ++n){
            int x; cin >>x;
            if(x==0){
                if(P==0) 
                    m++;
            }
            else if(x==1){
                if(P<=1)
                    m++;
            }
            else if((x%3)==0){
                //cout << 1 <<" "<< x/3 << "->"<<P << endl;
                if(x/3>=P)
                    m++;
                else if(x/3+1>=P && S){
                    m++;
                    --S;
                }
            }
            else if((x%3)==1){
                //cout << 2 <<" "<< x/3+1<<"->"<<P << endl;
                if(x/3+1>=P)
                    m++;
            }
            else if((x%3)==2){
                //cout << 3 <<" " << x/3+2 <<"->" << P<< endl;
                if(x/3+1>=P)
                    m++;
                else if(x/3+2>=P && S){
                    m++;
                    --S;
                }
            }
            //cout << m << "m" << endl;
        }
        cout << "Case #" << t+1 << ": " << m << endl;

    }
    return 0;
}
