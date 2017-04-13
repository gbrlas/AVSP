#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        
        vector<vector<int> > grid(N, vector<int>(M));
        
        for(int n = 0; n < N; n++)
            for(int m = 0; m < M; m++)
                cin >> grid[n][m];
        
        bool possible = true;
        for(int k = 1; k <= 100; k++) {
            vector<bool> rfill(N, false);
            vector<bool> cfill(M, false);
            
            for(int n = 0; n < N; n++) {
                bool cur_good = true;
                for(int m = 0; m < M; m++)
                    cur_good = cur_good && grid[n][m] == k;

                rfill[n] = cur_good;
            }
            
            for(int m = 0; m < M; m++) {
                bool cur_good = true;
                for(int n = 0; n < N; n++)
                    cur_good = cur_good && grid[n][m] == k;
                
                cfill[m] = cur_good;
            }
            
            bool found_error = false;
            for(int n = 0; n < N && !found_error; n++)
                for(int m = 0; m < M && !found_error; m++)
                    if(grid[n][m] == k && !rfill[n] && !cfill[m])
                        found_error = true;
                    else if(grid[n][m] == k)
                        grid[n][m]++;
            
            if(found_error) {
                possible = false;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << (possible ? "YES" : "NO") << endl;
    }
}                
                        
                         
