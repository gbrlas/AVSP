#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using namespace std;

bool is_happy(int base, int n)
{
    set<int> history;
    history.insert(n);

    for(int i = 0 ; i < 10000000 ; ++i){
        if(n == 1)
            return true;
        int m = 0;
        while(n){
            int rest = n % base;
            m += rest * rest;
            n -= rest;
            n /= base;
            //cerr << rest << " ";
        }
        n = m;
        //cerr << endl;

        if(n == 0 || history.find(n) != history.end())
            return false;
        history.insert(n);
    }

    cerr << "BAD!" << endl;
    exit(0);
}

int main()
{
    string line;
    
    int T;
    cin >> T;
    getline(cin, line);

    for(int X = 1 ; X <= T ; ++X){
        vector<int> bases;
        getline(cin, line);
        istringstream ss(line);
        copy(istream_iterator<int>(ss), istream_iterator<int>(),
             back_inserter(bases));

        int n;
        for(n = 2 ; n < INT_MAX ; ++n){
            bool happy = true;
            foreach(int b, bases){
                if(!is_happy(b, n)){
                    happy = false;
                    break;
                }
            }
            if(happy)
                break;
        }
        cout << "Case #" << X << ": " << n << endl;
    }

    return 0;
}
