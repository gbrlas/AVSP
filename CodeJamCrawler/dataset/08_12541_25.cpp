#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

int Score(string s)
{
    return unique(s.begin(), s.end()) - s.begin();
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int    k;
        string S;
        cin >> k >> S;

        vector<int> perm;
        for(int j = 0; j < k; ++j)
            perm.push_back(j);
        
        int best = S.size();
        do
        {
            string permuted;
            for(size_t j = 0; j < S.size(); ++j)
            {
                int base = j / k;
                int rule = j - base * k;
                permuted.push_back(S[k * base + perm[rule]]);
            }

            best = min(best, Score(permuted));
        }
        while(next_permutation(perm.begin(), perm.end()));

        cout << "Case #" << (i + 1) << ": " << best << endl;
    }

    return 0;
}
