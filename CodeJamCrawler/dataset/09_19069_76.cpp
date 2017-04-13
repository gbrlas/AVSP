#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int L, D, N, R = 0;
vector<set<string> > vs;

void Parse(string& c, int j, string& s)
{
    if (j < c.size())
    {
        if (c[j] == '(')
        {
            j++;
            int k = j;
            while (c[k] != ')')
                k++;                

            while (j < k )
            {
                s += c[j];
                if (vs[s.size()-1].find(s) != vs[s.size()-1].end() )
                    Parse(c, k+1, s);

                s.erase(s.end()-1);
                j++;
            }            
        }
        else
        {
            s += c[j];
            if (vs[s.size()-1].find(s) != vs[s.size()-1].end() )
                Parse(c, j+1, s);
            s.erase(s.end()-1);
        }
    }
    else
        R++;

}

int main()
{
    ifstream cin("A-large.in");
    ofstream cout("A-large.out");
    cin>>L>>D>>N;

    vs.resize(L);

    for (int i = 0; i < D; i++)
    {
        string s;
        cin>>s;
        string c;
        for (int j = 0; j < L; j++)
        {
            c += s[j];
            vs[j].insert(c);
        }
    }

    for (int i = 0; i < N; i++)
    {
        R = 0;
        string c, s = "";
        cin>>c;

        Parse(c, 0, s);

        cout<<"Case #"<<i+1<<": "<<R<<endl;
    }

    return 0;
}