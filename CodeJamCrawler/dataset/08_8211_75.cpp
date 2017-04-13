// train_timetable.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


std::size_t to_minutes( const std::string & time )
{
	const int hours = std::atoi( std::string( time, 0, 2 ).c_str() );
	const int minutes = std::atoi( std::string( time, 3, 2 ).c_str() );
	assert( ( hours < 24 ) && ( minutes < 60 ) );
	return static_cast< std::size_t >( ( hours * 60 ) + minutes );
}


typedef std::pair< std::size_t, std::size_t > trip;
typedef std::vector< trip > trip_table;
typedef trip_table::const_iterator trip_table_it;

bool earlier_trip( const trip & t1, const trip & t2 )
{
	return ( t1.first < t2.first );
}


void get_departures( trip_table_it first, trip_table_it last,
                     std::size_t turn_around,
					 std::vector< std::size_t > & departures )
{
	departures.clear();
	for ( trip_table_it i( first ); i != last; ++i )
	{
		const std::size_t dep_time = i -> second + turn_around;
		departures.push_back( dep_time );
	}
	std::sort( departures.begin(), departures.end() );
}


void get_trains_needed( const trip_table & A, const trip_table & B, std::size_t turn_around,
					   std::size_t & A_needed, std::size_t & B_needed )
{
	const trip_table_it A_end( A.end() ), B_end( B.end() );
	trip_table_it A_it( A.begin() ), B_it( B.begin() );

	std::vector< std::size_t > A_dep, B_dep;
	get_departures( A.begin(), A_end, turn_around, B_dep );
	get_departures( B.begin(), B_end, turn_around, A_dep );

	A_needed = 0; B_needed = 0;
	std::vector< std::size_t >::const_iterator A_dep_it( A_dep.begin() );
	std::vector< std::size_t >::const_iterator B_dep_it( B_dep.begin() );
	const std::vector< std::size_t >::const_iterator A_dep_end( A_dep.end() );
	const std::vector< std::size_t >::const_iterator B_dep_end( B_dep.end() );

	while ( ( A_it != A_end ) || ( B_it != B_end ) )
	{
		if ( ( A_it != A_end ) &&
			 ( ( B_it == B_end ) ||
			   ( A_it -> first < B_it -> first ) ) )
		{
			if ( ( A_dep_it != A_dep_end ) &&
			     ( *A_dep_it <= A_it -> first ) )
			{
				++A_dep_it;
			}
			else
			{
				++A_needed;
			}
			++A_it;
		}
		else
		{
			if ( ( B_dep_it != B_dep_end ) &&
			     ( *B_dep_it <= B_it -> first ) )
			{
				++B_dep_it;
			}
			else
			{
				++B_needed;
			}
			++B_it;
		}
	}
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
			std::size_t turn_around = 0;
			input >> turn_around;

			std::size_t NA = 0, NB = 0;
			input >> NA >> NB;

			trip_table A_table;
			for ( std::size_t j = 0; j < NA; ++j )
			{
				std::string arrival, departure;
				input >> arrival >> departure;
				
				const std::size_t arrival_time = to_minutes( arrival );
				const std::size_t departure_time = to_minutes( departure );
				A_table.push_back( std::make_pair( arrival_time, departure_time ) );
			}
			std::sort( A_table.begin(), A_table.end(), earlier_trip );

			trip_table B_table;
			for ( std::size_t k = 0; k < NB; ++k )
			{
				std::string arrival, departure;
				input >> arrival >> departure;

				const std::size_t arrival_time = to_minutes( arrival );
				const std::size_t departure_time = to_minutes( departure );
				B_table.push_back( std::make_pair( arrival_time, departure_time ) );
			}
			std::sort( B_table.begin(), B_table.end(), earlier_trip );

			std::size_t A_trains = 0, B_trains = 0;
			get_trains_needed( A_table, B_table, turn_around, A_trains, B_trains );

			output << "Case #" << i + 1 << ": " <<
				A_trains << " " << B_trains << std::endl;
		}
	}
}


int main( int, char ** )
{
	try
	{
		// solve( "sample.in", "sample.out" );
		solve( "B-small-attempt0.in", "B-small-attempt0.out" );
	}
	catch ( std::exception & ex )
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
	return 0;
}

