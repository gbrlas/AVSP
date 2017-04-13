#include <iostream>
#include <cstdio>

using namespace std;

int t, a[4][4], numb1[4], numb2[4];

int main(){
    freopen("Aout.txt", "r", stdin);
    freopen("Aout2.txt", "w", stdout);
    cin >> t;
    for (int k = 0; k < t; k++){
        int ans1, ans2;
        cin >> ans1;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 4; i++){
            numb1[i] = a[ans1 - 1][i];
        }
        cin >> ans2;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 4; i++){
            numb2[i] = a[ans2 - 1][i];
        }
        int cnt = 0;
        int numb;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (numb1[i] == numb2[j]){
                    cnt++;
                    numb = numb1[i];
                }
            }
        }
        cout << "Case #" << k + 1 << ": ";
        if (cnt == 0){
            cout << "Volunteer cheated!" << endl;
        }
        if (cnt == 1){
            cout << numb << endl;
        }
        if (cnt > 1){
            cout << "Bad magician!" << endl;
        }
    }
    return 0;
}
