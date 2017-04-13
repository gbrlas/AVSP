#include <iostream>
#include <map>

int main(int argc, char *argv[])
{
	using namespace std;
	
	int cases;
	cin >> cases;
	
	for ( int c=0; c<cases; ++c )
	{
		int search_engines;
		cin >> search_engines;
		
		typedef map< std::string, int > engines_t;
		engines_t engines;

		std::string line;

		for( int j=0; j<search_engines; ++j )
		{
			getline(cin, line);
			if ( line.size () == 0 ) // skiping empty line: char '\n' after reading number: cin >> search_engines;
				j--;
			else
				engines.insert( make_pair( line, 0 ) );
		}

		int queries, changes=0;
		cin >> queries;

		for( int q=0; q<queries; ++q)
		{
			getline(cin, line);
			if ( line.size() == 0 )
			{
				q--;
				continue;
			}

			engines_t::iterator x = engines.find( line );
			x->second ++;

			int untouched = 0;
			for( engines_t::iterator i=engines.begin(), e=engines.end(); i!=e; ++i)
				if( i->second == 0 )
					if ( ++untouched > 1 )
						break;
			if( untouched == 0 )
			{
				for( engines_t::iterator i=engines.begin(), e=engines.end(); i!=e; ++i)
					i->second = 0;
				changes ++;
				x->second ++;
			}
		}

		cout << "Case #" << c+1 << ": " << changes << endl;
	}

	return EXIT_SUCCESS;
}
