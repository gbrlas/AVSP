#include <stdio.h>
#include <iostream>

using namespace std;

int tc, N, k;

int main(){
    freopen("A-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++){
        cin >> N >> k;
        cout << "Case #" << TC << ": ";
        int mod = (1 << N)-1;
        k &= mod;
        //cout << k << " " << mod << endl;
        if (k == mod) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    return 0;
}
