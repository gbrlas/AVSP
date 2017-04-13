#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, a[1000],b[1000];

int main(){
    freopen("Cin.txt", "r", stdin);
    freopen("Cout.txt", "w", stdout);
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> n;
        double x;
        for (int i = 0; i < n; i++){
            cin >> x;
            a[i] = (int)(x * 100000000);
        }
        for (int i = 0; i < n; i++){
            cin >> x;
            b[i] = (int)(x * 100000000);
        }
        sort(a, a + n);
        sort(b, b + n);
        int posmx = n - 1;
        int posmn = 0;
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < n; i++){
            if (a[i] > b[posmx]){
                ans1++;
                posmn++;
            } else {
                if (a[i] > b[posmn]){
                    posmn++;
                    ans1++;
                } else {
                    posmx--;
                }
            }
        }
        bool check[n];
        for (int i = 0; i < n; i++){
            check[i] = false;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (b[j] > a[i] && (check[j] == false)){
                    check[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (check[i] == false){
                ans2++;
            }
        }
        cout << "Case #" << k + 1 << ": ";
        cout << ans1 << ' ' << ans2 << endl;
    }
}
