#include <iostream>
#include <string>
#include <algorithm>

std::string next_permutation( const std::string& current_number )
{
	std::string result( current_number );
	if ( std::next_permutation( result.begin(), result.end() ) )
	{
		return result;
	}
	else
	{
		result.insert( 1, 1, '0' );
		std::sort( result.begin(), result.end() );
		std::swap( result[ result.find_first_not_of('0') ],  result[0] );
		return result;
	}

}

int main()
{
	size_t tests;
	std::cin >> tests;
	for ( size_t i = 0; i < tests; ++i )
	{
		std::string number;
		std::cin >> number;
		if ( i != 0 ) std::cout << "\n";
		std::cout << "Case #" << i + 1 << ": " << next_permutation( number );
	}
}