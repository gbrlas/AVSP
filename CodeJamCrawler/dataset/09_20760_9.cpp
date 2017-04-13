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

int doCase(){
    // vector<int> item  = readMulti<int>();
    vector<string> item2  = readMulti<string>();
    for(int i = 0; i < item2.size(); i++) 
        cout << item2[i];
    cout << endl;
    return 0;
}

int count_num( int num, int digit ){

    int ret = 0;
    while( num > 0 ){
	if( (num % 10) == digit ){
	    ret++;
	}
	num /= 10;
    }

    return ret;
}

int doit( int num ){

    int ret;
    int digit[9] = {0,0,0,0,0,0,0,0,0};
    int tmp_num = num;
    int first_digit = 0;

    while( tmp_num > 0){
	digit[(tmp_num%10)-1]++;
	tmp_num/=10;
    }

    ret = num + 1;
    while(1){
	int good = 1;
	for( int i = 0; i < 9; i++ ){
	    if( digit[i] != count_num( ret, i+1 ) ){
		good = 0;
	    }
	}

	if( good ) break;
	ret++;
    }

    return ret;
}


int main()
{
    int cases = readOne<int>(); // cases
    for (int caseno = 1; caseno <= cases; caseno++){
	int num = readOne<int>();
//	doit( num );
        cout << "Case #" << caseno << ": " << doit(num) << endl; // call doCase()
    }
    return 0;
}
