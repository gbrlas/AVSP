#include <iostream>
#include <map>
#include <string>

unsigned int solve( const std::string& input )
{
	std::map< char, unsigned int > digits;
	for ( std::string::const_iterator it = input.begin(); 
		  it != input.end(); 
		  ++it )
	{
		if ( digits.find( *it ) != digits.end() )
			continue;

		unsigned int val = 0;
		if ( digits.size() == 0 ) // all numbers should not begin from 0
		{
			val = 1;
		}
		else if ( digits.size() == 1 )
		{
			val = 0;
		}
		else
		{
			val = digits.size();
		}
		digits[*it] = val;
	}

	const unsigned int base = digits.size() == 1 ? 2 : digits.size();

	unsigned int result = 0;
	unsigned int multiplier = 1;
	for ( std::string::const_reverse_iterator it = input.rbegin(); 
	  it != input.rend(); 
	  ++it, multiplier *= base )
	{
		result += multiplier * digits[*it];
	}
	return result;
}

int
main()
{
	size_t tests = 0;
	std::cin >> tests;
	for ( size_t i = 1; i <= tests; ++i )
	{
		std::string input;
		std::cin >> input;
		if ( i != 1 ) { std::cout << "\n"; }
		std::cout << "Case #" << i << ": " << solve( input );
	}
}