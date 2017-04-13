#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cassert>

using namespace std;


int main()
{
    int T, C, D, N;
    cin >> T;
    map <pair<char, char>, char > combine_rules;
    map <char, char> oppose_rules;
    vector <char> s;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        s.clear();
        combine_rules.clear();
        oppose_rules.clear();
        cin >> C;
        char a, b, c;
        for (int j = 1; j <= C; j++)
        {
            // read combine rules
            cin >> a >> b >> c;
            combine_rules[make_pair(a, b)] = c;
            combine_rules[make_pair(b, a)] = c;
        }
        cin >> D;
        for (int j = 1; j <= D; j++)
        {
            cin >> a >> b;
            oppose_rules[a] = b;
            oppose_rules[b] = a;
        }
        cin >> N;
        for (int j =1 ; j <= N; j++)
        {
            cin >> a;
            // check combine rules
            if (s.size())
            {
                char last = *(s.rbegin());
                if (combine_rules.count(make_pair(last, a)))
                {
                    b = combine_rules[make_pair(last, a)];
                    s[s.size() - 1] = b;
                } else
                    s.push_back(a);
            } else 
            {
                s.push_back(a);
            }
            if (s.size() > 1)
            {
                // check clear rules
                b = s[s.size() - 1];
                if (oppose_rules.count(b))
                {
                    for (int k = 0; k + 1 < s.size(); k++)
                        if (s[k] == oppose_rules[b])
                        {
                            s.clear();
                            break;
                        }
                }
            }
        }
        // now we have the string
        cout << "[";
        for (int j = 0; j < s.size(); j++)
        {
            cout << s[j];
            if (j < s.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
