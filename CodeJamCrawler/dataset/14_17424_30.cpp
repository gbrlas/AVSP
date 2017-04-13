#include <iostream>
#include <cstdio>

using namespace std;

bool check(int p, int q){
    while (true){
            if (p == 0 && q == 1)
                return 1;
            if (p == 1 && q == 1)
                return 1;
            if (p == 0 && q == 0)
                return 0;
            if (p == 1 && q == 0)
                return 0;
            if (q % 2 == 1){
                return 0;
            }
            long long x = q / 2;
            if (x <= p){
                if (check(p - x, x)){
                    return 1;
                }
                else
                    return 0;
            }
            q = x;
        }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
    long long p, q;
    char c;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int cnt = 0;
        cout << "Case #" << i + 1 << ": ";
        cin >> p >> c >> q;
        while (true){
            cnt++;
            if (q % 2 == 1){
                cout << "impossible";
                break;
            }
            long long x = q / 2;
            if (x <= p){
                if (check(p - x, x)){
                   cout << cnt;
                    break;
                }
            }
            q = x;
        }
        cout << endl;
    }
    return 0;
}
