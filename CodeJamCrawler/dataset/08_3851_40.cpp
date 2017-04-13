#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;


int numGroups(const string& s)
{
    int count = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    ifstream cin("D-small-attempt0.in");
    ofstream cout("D-small-attempt0.out");

    int testNum = 0;
    cin >> testNum;
    for(int test = 1; test <= testNum; ++test)
    {
        int result = 0;
        string s, s1;
        int k = 0;
        cin >> k;
        cin >> s;
        s1 = s;
        vector<int> p(k);
        for (int i = 0; i < k; ++i)
        {
            p[i] = i;
        }
        int minVal = 1000000;
        do 
        {
            for (int i = 0; i < s.size(); ++i)
            {
                int pos = k * (i / k) + p[i % k];
                s1[pos] = s[i];
            }
            int v = numGroups(s1);
            if (v < minVal)
            {
                minVal = v;
            }
        } while(next_permutation(p.begin(), p.end()));

        cout << "Case #" << test <<": " << minVal <<endl;
    }

    return 0;
}