#include "../../../template.h"
#include "boost/lambda/lambda.hpp"

template<typename T>
void my_stov(string &s, vector<T> &v) {
    istringstream s1(s);
    for (T v1; s1 >> v1; v.push_back(v1));
}

int my_atoi(string &s) {
    int a = 0;
    for (int i=0; i<s.length(); i++) {
        a= a*10 + (s[i] - '0');
    }
    return a;
}

int main(void) {
    int T;
    cin >> T;
    cin.ignore();
    string s;
    vector<string> v;
    vector<int> scores;
    

    for (int x=1; x<=T; x++) {
        getline(cin, s, '\n');
        v.clear();
        scores.clear();        
        my_stov(s, v);
        

        int N = my_atoi(v[0]);
        int S = my_atoi(v[1]);
        int p = my_atoi(v[2]);
        for (int i=0; i<N; i++) {
            scores.push_back(my_atoi(v[3+i]));
        }

        int curS = S;
        int noofstars = 0;
        
        for (int i=0; i<scores.size(); i++) {
            int best = 0;
            if ((scores[i] % 3) == 2) {
                // 2x + x - 1 = n || x + 2(x - 2) = n
                best = (scores[i] + 1) / 3;
                if (best < p) {
                    if (curS && scores[i] + 4 <= 30 &&
                        scores[i] > 4) {
                        best = (scores[i] + 4) / 3;
                        if (best >= p) {
                            noofstars++;
                            curS--;
                        }
                    }
                } else {
                    noofstars++;
                }
            } else {
                // x + 2(x - 1) = n
                if ((scores[i] % 3) == 1) {
                    best = (scores[i] + 2) / 3;
                    if (best >= p) {
                        noofstars++;
                    }
                } else {
                    // 3x = n || x + (x - 1) + (x - 2) = n
                    best = (scores[i]) / 3;
                    if (best < p) {
                        if (curS && scores[i] + 3 <= 30 &&
                            scores[i] > 3) {
                            best = (scores[i] + 3) / 3;
                            if (best >= p) {
                                noofstars++;
                                curS--;
                            }
                        }
                    } else {
                        noofstars++;
                    }
                }
            }
        }
        cout << "Case #" << x << ": " << noofstars << endl;
    //for_each(v.begin(), v.end(), cout << boost::lambda::_1 << ' ');
    }
}
