#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/regex.hpp>
using namespace std;

string to_regex(const string& source)
{
    string res = source;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == '(')
            res[i] = '[';
        if (res[i] == ')')
            res[i] = ']';
    }
    return "^" + res + "$";
}
int main()
{
    int l, d, n;
    {
        string header;
        getline(cin, header);
        
        stringstream s(header);
        s >> l >> d >> n;
    }

    vector<string> dictionary;
    dictionary.resize(d);
    
    for (int i = 0; i < d; ++i) {
        string s;
        getline(cin, s);
        dictionary[i] = s;
    }

    for (int i = 0; i < n; ++i) {
        int res = 0;
        string s;
        getline(cin, s);
        boost::regex e(to_regex(s));
        for (int j = 0; j < d; ++j) {
            if (boost::regex_match(dictionary[j], e))
                ++res;
        }
        cout << "Case #" << i+1 << ": " << res << endl;
    }
    return 0;
}
