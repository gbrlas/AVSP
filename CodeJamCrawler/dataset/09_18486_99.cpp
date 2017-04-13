#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

const std::string pattern = "welcome to code jam";
typedef std::vector< std::vector< int > > cache_t;
size_t count( size_t N, size_t M, const std::string& word, cache_t& cache )
{
	if ( N == pattern.length() )
	{
		cache[N][M] = 1;
		return 1;
	}
	if ( cache[N][M] != -1 )
		return cache[N][M];

	size_t result = 0;

	for ( size_t i = M; i < word.length(); ++i )
	{
		if ( word[i] == pattern[N])
		{
			result += count( N + 1, i, word, cache );
		}
	}
	result %= 10000;
	cache[N][M] = static_cast< int > ( result );
	return result;
}

cache_t createCache( size_t width, size_t height )
{
	cache_t result;
	for ( size_t i = 0; i < height; ++i)
	{
		result.push_back( std::vector< int >( width, -1 ) );
	}
	return result;
}
int main()
{
	//std::cout << count( 0, 0, "wweellccoommee to code qps jam");
	std::ifstream finp( "C-large.in" ); // c:\\dev\\code_jam\\test3\\debug\\
	size_t recordsCount;
	finp >> recordsCount;
	std::string tmp;
	std::getline( finp, tmp );
	for ( size_t i = 0; i < recordsCount; ++i )
	{
		std::string inputString;
		std::getline( finp, inputString );
		std::cout << "Case #" << i + 1 << ": " << std::setw( 4 ) << std::setfill('0') << count( 0, 0, inputString, createCache( inputString.length() + 1, pattern.length() + 1 ) ) << "\n";

	}
}