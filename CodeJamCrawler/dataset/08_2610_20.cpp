#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int s;

void makePattern(vector<vector<int> >&ps, vector<int> p, int d)
{
    if(d==p.size()-1)
    {
        ps.push_back(p);
        return;
    }
    for(int i=d; i<p.size(); i++)
    {
        vector<int> tmp=p;
        swap(tmp[d], tmp[i]);
        makePattern(ps, tmp, d+1);
    }
}
int compress(const string&str);
int runlength(const vector<int>&p, const string&str)
{
    string tmp;
    tmp.resize(p.size());
    int ret=0;
    string next;

    for(int j=0; j<str.size(); j+=p.size())
    {
        tmp.clear();
        for(int i=0; i<p.size() && j + p[i] < str.size() ; i++)
        {
            tmp.push_back(str[j + p[i]]);
        }
//        string::iterator it=unique(tmp.begin(), tmp.end());

//        tmp.erase(it, tmp.end());
//        ret+=tmp.size();
        next+=tmp;
    }

    return unique(next.begin(), next.end())-next.begin();
//    if(str.size() == ret)
        return ret;

//    return runlength(p, next);
}

int compress(const string&str)
{
    vector<vector<int> > patterns;
    vector<int> pattern(s);
    for(int a=0; a<s; a++)
    {
        pattern[a]=a;
    }

    makePattern(patterns, pattern, 0);

    int ret=100000;
    for(int a=0; a<patterns.size(); a++)
        ret = min(ret, runlength(patterns[a], str));
    return ret;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;

        string str;
        getline(cin, str);
        getline(cin, str);

        cout << "Case #" << i+1 << ": " << compress(str) << endl;
    }
    return 0;
}
