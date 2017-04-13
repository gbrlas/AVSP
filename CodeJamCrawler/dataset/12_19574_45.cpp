#include <iostream>
#include<vector>
using namespace std;

typedef struct {
    int v[3];
} trip;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    
    for(int c = 1; c <= T; c++) {
        int N, S, p;
        cin >> N >> S >> p;
        
        vector<int> tots(N);
        vector<trip> scores(N);
        
        for(int i = 0; i < N; i++)
            cin >> tots[i]; 
        
        for(int i = 0; i < N; i++) {
            
            int rem = tots[i] % 3;
            
            scores[i].v[0] = scores[i].v[1] = scores[i].v[2] = tots[i] / 3;
            scores[i].v[0] += rem;
            
            if(rem == 2) {
                scores[i].v[0]--;
                scores[i].v[1]++;
            }
        }
        
        int count = 0;
        for(int i = 0; i < N; i++) {
            
            if(scores[i].v[0] >= p) {
                count++;
                continue;
            }
            
            while(true) {
                
                bool at = true, bt = true;
                if(scores[i].v[0] == 10)
                    break;
                
                if(scores[i].v[1] == 0 && scores[i].v[2] == 0)
                    break;
                
                if(scores[i].v[0] == scores[i].v[1] + 2 ||
                scores[i].v[0] == scores[i].v[2] + 2) 
                    break;
                    
                if(scores[i].v[1] > 0 && 
                scores[i].v[0] + 1 <= min(scores[i].v[1] - 1, scores[i].v[2]) + 2) {
                    scores[i].v[0]++;
                    scores[i].v[1]--;
                }
                else at = false;
                
                if(scores[i].v[2] > 0 && 
                scores[i].v[0] + 1 <= min(scores[i].v[1], scores[i].v[2] - 1) + 2) {
                    scores[i].v[0]++;
                    scores[i].v[2]--;
                }
                else bt = false;
                
                if(!at && !bt) break;
            }
            
            if(S > 0 && scores[i].v[0] >= p) {
                count++;
                S--;
            }
        }    
        
        cout << "Case #" << c << ": " << count << endl;
    }
    
    return 0;
}