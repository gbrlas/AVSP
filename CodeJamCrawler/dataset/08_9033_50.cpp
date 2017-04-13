#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

unsigned minutes( unsigned h, unsigned m )
{
	return h*60+m;
}

int main( int argc, char* argv[] )
{
	char buffer[128];
	fstream   fs;
	if (argc<2)
		return -1;
	fs.open( argv[1] );
	int q;
	fs >> q;
	fs.getline ( buffer, 120 );
	int caseNum=1;
	while(q--){
		unsigned tat;
		unsigned na;
		unsigned nb;
		fs >> tat >> na >> nb;
		fs.getline ( buffer, 120 );
		unsigned i;
		map< unsigned, int > change_a;
		map< unsigned, int > change_b;
		typedef pair <unsigned, int> Int_Pair;
		for ( i=0; i<na; i++ ){
			unsigned m1, h1, m2, h2, time;

			fs.getline ( buffer, 120 );
			sscanf( buffer, "%u:%u %u:%u", &h1, &m1, &h2, &m2 );
			time = minutes( h1, m1 );
			change_a[time] -= 1;

			time = minutes( h2, m2 );
			change_b[time+tat] += 1;
		}
		for ( i=0; i<nb; i++ ){
			unsigned m1, h1, m2, h2, time;

			fs.getline ( buffer, 120 );
			sscanf( buffer, "%u:%u %u:%u", &h1, &m1, &h2, &m2 );
			time = minutes( h1, m1 );
			change_b[time] -= 1;

			time = minutes( h2, m2 );
			change_a[time+tat] += 1;
		}
		map< unsigned, int >::iterator iter;
		int balance=0;
		int ra=0;
		for( iter=change_a.begin(); iter!=change_a.end(); iter++ ){
			balance += (*iter).second;
			if ( balance<0 ){
				ra += -balance;
				balance=0;
			}
		}
		balance=0;
		int rb=0;
		for( iter=change_b.begin(); iter!=change_b.end(); iter++ ){
			balance += (*iter).second;
			if ( balance<0 ){
				rb += -balance;
				balance=0;
			}
		}
		cout << "Case #" << caseNum++ << ": " << ra << " " << rb <<endl;
	}
	fs.close();
	return 0;
}