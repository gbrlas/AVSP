#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

    ifstream cin("testA.in");
    ofstream cout("testA.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        vector<vector<int>> A(5, vector<int> (5, 0));
        vector<vector<int>> B = A;
        vector<int> freq(50, 0);
        
        int poz1; cin >> poz1;

        for(int i = 1; i <= 4; ++i)
            for(int j = 1; j <= 4; ++j) {
                cin >> A[i][j];
                if(i == poz1)
                    freq[A[i][j]]++;
            }   
        
        int poz2; cin >> poz2;

        for(int i = 1; i <= 4; ++i)
            for(int j = 1; j <= 4; ++j) {
                cin >> B[i][j];
                if(i == poz2)
                    freq[B[i][j]]++;
            }
    
        int ans = 0;
        int state = 0;

        for(int i = 1; i <= 16; ++i)
            if(freq[i] == 2) {
                if(ans == 0) {
                    ans = i;
                    state = 1;
                } else {
                    state = 2;
                }
            }

        cout << "Case #" << t_case << ": ";
        if(!state)
            cout << "Volunteer cheated!\n";
        else if(state == 2)
            cout << "Bad magician!\n";
        else
            cout << ans << "\n";
    }
}
