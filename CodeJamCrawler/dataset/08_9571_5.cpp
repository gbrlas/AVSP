#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<complex>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;



int main()
{
    ifstream fin("D.in");
    ofstream fout("D.out");
    int N, k;
    long long best, curr, pos;
    string s;
    char s2[5000];
    char c;
    fin >> N;
    vector<int> perm;
    
    for (int casenum = 1; casenum <= N; casenum++)
    {
        fout << "Case #" << casenum << ": ";
        fin >> k;
        fin >> s;
        best = 10000;

        perm.clear();
        for (int i = 0; i < k; i++)
        {
            perm.push_back(i);
        }
        do
        {
            curr = 0;
            pos = 0;
            for (int j = 0; j <= s.length()-k; j+=k)
            {
                for (int i = 0; i < k; i++)
                {
                    s2[pos] = s[j+perm[i]];
                    pos++;
                }
            }
            c = 'A';
            for (int m = 0; m < s.length(); m++)
            {
                if (s2[m] != c)
                {
                    curr++;
                    c = s2[m];
                }
            }
            /*cout << curr << endl;
            for (int i = 0; i < k; i++)
                cout << perm[i];
            cout << endl;
            for (int i = 0; i < s.length(); i++)
                cout << s2[i];
            cout << endl;*/
            if (curr < best)
                best = curr;
        }  while (next_permutation(perm.begin(), perm.end()));
        fout << best << endl;
    }
}
