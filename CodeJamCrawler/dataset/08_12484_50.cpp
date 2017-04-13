#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
T CastLine(std::istream &str)
{
    // Read the line in
    string dummy;
    getline(str, dummy);

    // Cast to our desired type
    T            ret;
    stringstream ss(dummy);
    ss >> ret;

    // Return it
    return ret;
}

pair<size_t, size_t> FindBest(const vector<string> &engines, const vector<string> &queries, size_t first_index, size_t prev_engine)
{
    // Consider all of the engines that we can choose
    pair<size_t, size_t> ret(first_index, prev_engine);
    for(size_t i = 0; i < engines.size(); ++i)
    {
        if(i == prev_engine)
            continue;

        // Run through the queries
        size_t j = first_index;
        for(; j < queries.size(); ++j)
        {
            if(queries[j] == engines[i])
                break;
        }

        // If we choose engine i here we will have to change engine at j
        if(j > ret.first)
            ret = make_pair(j, i);
    }

    return ret;
}

int main()
{
    int num = CastLine<int>(cin);
    for(int i = 0; i < num; ++i)
    {
        string dummy;

        int s = CastLine<int>(cin);
        vector<string> engines(s);
        for(int j = 0; j < s; ++j)
            getline(cin, engines[j]);
        
        int q = CastLine<int>(cin);
        vector<string> queries(q);
        for(int j = 0; j < q; ++j)
            getline(cin, queries[j]);

        int                  ret = 0;
        pair<size_t, size_t> best(0, engines.size());
        while(true)
        {
             best = FindBest(engines, queries, best.first, best.second);
             if(best.first == queries.size())
                 break;

             ++ret;
        }

        cout << "Case #" << (i + 1) << ": " << ret << endl;
    }

    return 0;
}
