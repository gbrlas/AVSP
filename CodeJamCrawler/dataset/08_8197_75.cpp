// saving_the_universe.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>


typedef std::vector< std::string >::const_iterator vec_iter;

int get_switches( vec_iter engines_begin, vec_iter engines_end,
                  vec_iter queries_begin, vec_iter queries_end )
{
	int num = 0;
	vec_iter sq( queries_begin );
	while ( sq != queries_end )
	{
		std::size_t max_len = 0;
		for ( vec_iter it( engines_begin ); it != engines_end; ++it )
		{
			const std::string cur_engine = *it;
			vec_iter q( sq );
			while ( q != queries_end )
			{
				if ( *q == cur_engine ) { break; }
				++q;
			}
			const std::size_t len = ( q - sq );
			if ( len > max_len ) { max_len = len; }
		}

		sq += max_len;
		if ( sq != queries_end ) { ++num; }
	}
	return num;
}


void solve( const std::string & input_name, const std::string & output_name )
{
	std::ifstream input;
	std::ofstream output;
	input.open( input_name.c_str() );
	output.open( output_name.c_str() );
	if ( input.is_open() && output.is_open() )
	{
		std::size_t size = 0;
		input >> size;

		for ( std::size_t i = 0; i < size; ++i )
		{
			std::size_t number_of_engines = 0;
			input >> number_of_engines;

			std::vector< std::string > engines;
			for ( std::size_t j = 0; j < number_of_engines; ++j )
			{
				std::string engine;
				while ( engine.empty() )
				{
					std::getline( input, engine );
				}
				engines.push_back( engine );
			}

			std::size_t number_of_queries = 0;
			input >> number_of_queries;

			std::vector< std::string > queries;
			for ( std::size_t j = 0; j < number_of_queries; ++j )
			{
				std::string query;
				while ( query.empty() )
				{
					std::getline( input, query );
				}
				queries.push_back( query );
			}

			int min = std::numeric_limits< int >::max();
			const vec_iter end( engines.end() );
			for ( vec_iter it( engines.begin() ); it != end; ++it )
			{
				const int switches =
					// get_switches( engines, it, queries.begin(), queries.end() );
					get_switches( engines.begin(), engines.end(),
					              queries.begin(), queries.end() );
				if ( switches < min ) { min = switches; }
			}

			output << "Case #" << i + 1 << ": " << min << std::endl;
		}
	}
}


int main( int, char ** )
{
	try
	{
		solve( "sample.in", "sample.out" );
		// solve( "A-small-attempt0.in", "A-small-attempt0.out" );
		solve( "A-small-attempt1.in", "A-small-attempt1.out" );
	}
	catch ( std::exception & ex )
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
	return 0;
}
