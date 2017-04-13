#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int L, D, N;
    cin >> L >> D >> N;
    vector<string> words;
    for(int i = 0; i < D; i++) {
        string w;
        cin >> w;
        words.push_back(w);
    }
    for(int i = 0; i < N; i++) {
        string p;
        vector<string> patterns;
        cin >> p;
        for(int j = 0; j != p.length(); j++) {
            string t;
            if(p[j] != '(') {
                t = p[j];
                patterns.push_back(t);
                continue;
            }
            while(p[++j] != ')') {
                t += p[j];
            }
            patterns.push_back(t);
        }
        int score = 0;
        for(vector<string>::iterator it = words.begin();
                                    it != words.end();
                                    it++) {
            int fail = 0;
            for(int j = 0; j < L; j++) {
                if(patterns[j].find((*it)[j]) >= patterns[j].length()) {
                    fail = 1;
                    break;
                }
            }
            if(fail == 0) {
                score++;
            }
        }
        cout << "Case #" << i + 1 << ": " <<score << endl;
    }
    return 0;
}
