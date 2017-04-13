#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int qq=1; qq<=T; ++qq) {
        int A[4][4], B[4][4], a, b;
        int q[100] = {0};

        cin >> a;
        for(int i=0; i<4; ++i) for(int j=0; j<4; ++j){
            cin >> A[i][j];
            if(i==a-1) ++q[A[i][j]];
        }

        cin >> b;
        for(int i=0; i<4; ++i) for(int j=0; j<4; ++j){
            cin >> B[i][j];
            if(i==b-1) ++q[B[i][j]];
        }

        int twos=0, ans;
        for(int i=1; i<=16; ++i) {
            if(q[i]==2){ ++twos; ans=i; }
        }

        cout << "Case #" << qq << ": ";
        if(twos >= 2) cout << "Bad magician!\n";
        else if(twos == 1) cout << ans << '\n';
        else cout << "Volunteer cheated!\n";
    }
    return 0;
}
