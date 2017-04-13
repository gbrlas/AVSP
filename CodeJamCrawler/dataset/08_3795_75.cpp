#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

ofstream cout("B-small-attempt3.out");
ifstream cin ("B-small-attempt3.in");


int readTime()
{
    string str;
    cin>>str;
    int h = (str[0] - '0')*10 + (str[1] - '0');
    int m = (str[3] - '0')*10 + (str[4] - '0');
    return h * 60 + m;
}

int countDelta(const vector<pair<int, bool> >& v)
{
    int currentA = 0, countA = 0;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        // going
        if (v[i].second)
        {
            if (currentA == 0)
                countA ++;
            else
                --currentA;
        }
        else // coming
        {
            currentA ++;
        }
    }
    return countA;
}

int main()
{

    int count = 0;
    cin >> count;
    for (int t = 1; t <= count; ++t)
    {
        int nA, nB, dur;
        cin>>dur;
        cin>>nA>>nB;
        vector<pair<int, bool> > a, b;
        a.reserve(nA + nB);
        b.reserve(nA + nB);
        for (int i = 0; i < nA; ++i)
        {
            int begin = readTime();
            int end = readTime();
            a.push_back(pair<int, bool>(begin, true));
            b.push_back(pair<int, bool>(end + dur, false));
         }

        for (int i = 0; i < nB; ++i)
        {
            int begin = readTime();
            int end = readTime();
            b.push_back(pair<int, bool>(begin, true));
            a.push_back(pair<int, bool>(end + dur, false));
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int countA = countDelta(a);
        int countB = countDelta(b);
        
        cout<< "Case #"<<t<<": "<<countA<<" " << countB<<endl;
    }

    return 0;
}


