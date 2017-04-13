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

//int MultibaseHappiness(vector <int> bases);

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

string intToBit( int a ){
    
    string res;
    string tmp;
    
    while( a > 0 ){
	int r = a % 2;
	stringstream ss;
	ss << r;
	tmp += ss.str();
	a /= 2;
    }
    for(int i = tmp.size() - 1; i >= 0; i-- ){
	res += tmp[i];
    }
    return res;
}

int main()
{
    int cases = readOne<int>(); // cases
    for (int caseno = 1; caseno <= cases; caseno++){
	bool flag = true;
	int num = readOne<int>(); // num
	vector<int> candy = readMulti<int>();
	vector<string> b_candy;
	for(int i = 0; i < candy.size(); i++ ){
	    b_candy.push_back( intToBit(candy[i]) );
	}
	
	int max_digit = 0;
	for( int i = 0; i < b_candy.size(); i++ ){
	    int tmp = b_candy[i].length();
	    max_digit = max( max_digit, tmp );
	}

	for( int i = 0; i < b_candy.size(); i++ ){
	    if( b_candy[i].length() < max_digit ){
		int tmp = max_digit - b_candy[i].length();
		string add;
		while( tmp > 0 ){
		    add+="0";
		    tmp--;
		}
		b_candy[i] = add + b_candy[i];
	    }
	}
	
	for( int i = 0; i < max_digit; i++ ){
	    int cnt = 0;
	    for( int j = 0; j < b_candy.size(); j++ ){
		if( i < b_candy[j].length() && b_candy[j][i] == '1' ){
		    cnt++;
		}
	    }
	    if( cnt % 2 != 0 ) {
		flag = false;
		break;
	    }
	}
	if( flag == false ){
	    cout << "Case #" << caseno << ": " << "NO" << endl;
	    continue;
	} 
	
	int ans = 0;
	sort( candy.begin(), candy.end() );
	for( int i = 1; i < candy.size(); i++ ){
	    ans+=candy[i];
	}
	
	cout << "Case #" << caseno << ": " << ans << endl;

    }
    return 0;

}
