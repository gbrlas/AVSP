#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int64;
int gcd(int64 a, int64 b){
    return a ? gcd(b % a, a) : b;
}
int main(){
    int C;
    cin >> C;
    int64 t[1000];
    for(int i = 0; i < C; ++i){
        int N;
        cin >> N;
        for(int j = 0; j < N; ++j) cin >> t[j];
        sort(t, t + N);
        int64 g = 0;
        for(int j = 0; j < N - 1; ++j){
            if(g == 0) g = t[j + 1] - t[j];
            else{
                if(t[j + 1] == t[j]) continue;
                g = gcd(g, t[j + 1] - t[j]);
            }
        }
        int64 y;
        if(t[0] % g == 0) y = 0;
        else y = (t[0] / g + 1) * g - t[0];
		cout << "Case #" << i + 1 << ": " << y << endl;
    }

}

