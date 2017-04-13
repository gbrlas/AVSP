#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>

using namespace std;

template< typename type > type readOne()
{
    type res;
    char inp[5000];
    gets( inp );
    stringstream ss( inp );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char inp[5000];
    gets( inp );
    stringstream ss( inp );
    for ( type t; ss >> t; ) res.push_back( t );
    return res;
}

long double 
poww(int val, int n){
    long double ans = 1;
    for(int i = 0; i < n; i++){
        ans *= val;
    }
    return ans;
}

long double  doCase(){
    string message  = readOne<string>();

    map<char, int> maps;
    for(int i = '0'; i <= '9'; i++) maps[i] = -1;
    for(int i = 'a'; i <= 'z'; i++) maps[i] = -1;
    
    int base = 0;
    for(int i  = 0; i < message.size(); i++){
        if( i == 0){
            maps[message[0]] = 1;
            continue;
        }
        if(maps[message[i]] != -1) continue;
        maps[message[i]] = base;
        base ++;
        if(base == 1) base = 2;
    }
    if (base == 0) base = 2;
    long double ret = 0;
    long double val = poww(base, message.size() - 1);
    for(int i  = 0; i < message.size(); i++){
        ret += val * maps[message[i]];
        val /= base;
    }
    return ret;
}


int main()
{
    int cases = readOne<int>(); // cases
    for (int caseno = 1; caseno <= cases; caseno++){
        printf("Case #%d: %.Lf\n",caseno, doCase());
    }
    return 0;
}
