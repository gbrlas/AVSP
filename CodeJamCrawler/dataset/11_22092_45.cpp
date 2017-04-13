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

int move( int cur, int goal ){
    
    if( cur == goal ) return cur;
    if( cur < goal  ) return cur+1;
    if( cur > goal  ) return cur-1;
    return cur;
}

int main()
{
    int cases = readOne<int>(); // cases
    for (int caseno = 1; caseno <= cases; caseno++){
	vector<string> data = readMulti<string>();
	vector<int> a(1024);
	vector<int> b(1024);
	vector<string> turn;
	int num = atoi( data[0].c_str() );

	for( int i = 0; i < a.size(); i++ ){
	    a[i] = 0; b[i] = 0;
	}
	
	int a_num = 0, b_num = 0;
	for( int i = 1; i < data.size(); i+=2 ){
	    if( data[i] == "O"){
		a[a_num] = atoi( data[i+1].c_str() );
		a_num++;
	    } else if ( data[i] == "B" ) {
		b[b_num] = atoi( data[i+1].c_str() );
		b_num++;
	    } else {
		return 0;
	    }
	    turn.push_back( data[i] );
	}

	int a_pos = 1;
	int b_pos = 1;
	int a_g = 0;
	int b_g = 0;
	int index = 0;
	int cnt = 0;
	while( 1 ){
	    int tmp_a = move( a_pos, a[a_g] );
	    int tmp_b = move( b_pos, b[b_g] );

	    /*
	    cout << "a_pos: " << a_pos;
	    cout << " b_pos: " << b_pos;
	    cout << " a_goal: " << a[a_g];
	    cout << " b_goal: " << b[b_g];
	    cout << " next: " << turn[index];
	    cout << endl;
	    */

	    if( turn[index] == "O" && a_pos == tmp_a ){
		index++;
		a_g++;
		//printf("bush A\n");
	    } else if( turn[index] == "B" && b_pos == tmp_b ){
		index++;
		b_g++;
		//printf("bush b\n");
	    }


	    a_pos = tmp_a;
	    b_pos = tmp_b;
	    cnt++;
	    if( index >= num ) break;
	}
        cout << "Case #" << caseno << ": " << cnt << endl; // call doCase()
    }
    return 0;

}
