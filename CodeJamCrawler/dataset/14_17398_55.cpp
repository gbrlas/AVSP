#include <iostream>
#include <cstdio>

using namespace std;

int t;
double c, f, x;

int main(){
    freopen("Bin.txt", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> c >> f >> x;
        double nowv = 2;
        double nowt = 0;
        double ans = x / 2;
        for (int i = 1; i <= (int)(x); i++){
            nowt = nowt + c / (nowv);
            nowv = 2 + i * f;
            if (nowt + x / nowv < ans){
                ans = nowt + x / nowv;
            }
        }
        cout << "Case #" << k + 1 << ": ";
        printf("%.10lf", ans);
        cout << endl;
    }
}
