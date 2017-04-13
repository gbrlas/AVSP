#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

struct str_less : public binary_function <string, string, bool> 
{
  bool operator()(
     const string& _Left, 
     const string& _Right
	 ) const{	return strcmp( _Left.c_str(), _Right.c_str())<0;}
};

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
		unsigned ret=0;
		unsigned engs_num;
		fs >> engs_num;
		fs.getline ( buffer, 120 );
		unsigned i;
		set< string, str_less > engs;
		for ( i=0; i<engs_num; i++ ){
			string s;
			fs.getline ( buffer, 120 );
			s = buffer;
			engs.insert(s);
		}
		unsigned qry_num;
		fs >> qry_num;
		fs.getline ( buffer, 120 );
		set< string, str_less > cand_engs = engs;
		while (qry_num--){
			string s;
			fs.getline ( buffer, 120 );
			s = buffer;
			cand_engs.erase( s );
			if( cand_engs.size()==0 ){
				cand_engs = engs;
				ret++;
				cand_engs.erase( s );
			}
		}
		cout << "Case #" << caseNum++ << ": " << ret <<endl;
	}
	fs.close();
	return 0;
}