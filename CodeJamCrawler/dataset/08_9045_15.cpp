#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

unsigned minutes( unsigned h, unsigned m )
{
	return h*60+m;
}

int main( int argc, char* argv[] )
{
	char buffer[12800];
	fstream   fs;
	if (argc<2)
		return -1;
	fs.open( argv[1] );
	int q;
	fs >> q;
	fs.getline ( buffer, 120 );
	int caseNum=1;
	while(q--){
		unsigned p;
		unsigned k;
		unsigned l, ll;
		fs >> p >> k >> l;
		fs.getline ( buffer, 120 );
		ll=l;
		vector<unsigned> probs;
		while( ll-- ){
			unsigned prob;
			fs >> prob;
			probs.push_back(prob);
		}
		fs.getline ( buffer, 12000 );

		sort( probs.rbegin(), probs.rend() );
		long long res=0;

		unsigned i;
		for ( i=0; i<l; i++ ){
			long long a = (probs[i]) *(i/k+1);
			res += long long(probs[i]) *(i/k+1);
		}
		cout << "Case #" << caseNum++ << ": " << res << endl;
	}
	fs.close();
	return 0;
}