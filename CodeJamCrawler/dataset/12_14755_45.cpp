#include <iostream>
#include <vector>

using namespace std;

//const int MAX = 2000000;

int len(int n){
    int ret = 0;
    while(n > 0) {
        n /= 10;
        ++ret;
    }
    return ret;
}

int pow10(int k) {
    int ret = 1;
    for(int i = 0; i < k; ++i){
        ret *= 10;
    }
    return ret;
}

int recycle(int n, int l, int p){
    int d = pow10(p);   
    int e = pow10(l-p);
    return n / d + (n % d) * e;
}

long long calc(int A, int B) {
    long long cnt = 0;
    for(int i = A; i <= B; ++i){
        int l = len(i); 
        for(int j = 1; j < l; ++j) {
            int r = recycle(i, l, j);
            if(i < r && r <= B) {
                //cout << i << " " << r;
                //cout << " o";
                //cout << cnt << endl;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main(void){
    int T;
    cin >> T;
    int A, B;
    for(int i = 1; i <= T; ++i) {
        cin >> A >> B;
        cout << "Case #" << i << ": " << calc(A, B) << endl;
    }
    return 0;
}
