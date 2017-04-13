#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int a,b,k;
        _if >> a >> b >> k;

        int res = 0;
        for(int j=0;j<a;j++){
            for(int l=0;l<b;l++){
                if((j&l)<k) res++;
            }
        }

        cout << a << " " << b << " " << k << endl;

        _of << "Case #" << i+1 << ": " << res << endl;
    }
}
