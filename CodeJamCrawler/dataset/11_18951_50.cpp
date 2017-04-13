#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <utility>

namespace gcj
{
namespace task2
{
int make_combinable(char c1, char c2)
{
	return std::min( c1, c2 ) << 8 | std::max( c1, c2 );
}


std::vector< char > solve( std::list< char >& input, 
						   const std::map< char, std::set< char > >& opposed, // contains ints for both opposed
						   const std::map< int, char >& combinable )
{
	std::vector< char > result;
	char top = 0;

	std::map< char, int > opposed1;
	while( !input.empty() )
	{
		top = result.empty() ? 0 : result.back();

		char next = input.front();
		input.pop_front();
		auto comb = combinable.find( make_combinable(top, next) );
		if (comb != combinable.end() )
		{
			input.push_front( comb->second );
			result.pop_back();
			if ( opposed1.find( top ) != opposed1.end() )
			{
				--opposed1[top];
				if ( opposed1[top] == 0) opposed1.erase( top );
			}
		}
		else 
		{
			auto opposedIt = opposed.find( next );
			if ( opposedIt != opposed.end() )
			{
				auto it = opposedIt->second.begin();
				for ( ; 
						it != opposedIt->second.end();
						++it )
				{
					if ( opposed1.find( *it ) != opposed1.end() )
					{
						opposed1.clear();
						result.clear();
						break;
					}
				}

				if ( it == opposedIt->second.end() )
				{
					++opposed1[next];
					result.push_back(next);
				}
				
			}
			else
			{
				result.push_back(next);
			}
		}
	}
	return result;
}

void solve(std::istream& inp)
{
	size_t tests;
	inp >> tests;
	for ( size_t i = 0; i < tests; ++i )
	{

		size_t D;
		inp >> D;
		std::map<int, char> combinable;
		for ( size_t j = 0; j < D; ++j )
		{
			std::string combinable_word;
			inp >> combinable_word;
			combinable[make_combinable(combinable_word[0], combinable_word[1])] = combinable_word[2];
		}

		size_t N;
		inp >> N;
		std::map< char, std::set< char > > opposite;
		for ( size_t j = 0; j < N; ++j )
		{
			std::string opposite_word;
			inp >> opposite_word;
			opposite[opposite_word[0]].insert( opposite_word[1] );
			opposite[opposite_word[1]].insert( opposite_word[0] );
		}

		size_t P;
		inp >> P;
		std::string task;
		inp >> task;
		std::list< char > input ;
		for (size_t j = 0; j < P; ++j )
		{
			input.push_back( task[j] );
		}
		
		std::vector< char > result = solve(input, opposite, combinable);
		
		
		
		std::cout << "Case #" << i + 1 << ": " << "[";
		for ( auto it = result.begin(); it != result.end(); ++it )
		{
			if ( it != result.begin() )
			{
				std::cout << ", ";
			}
			std::cout << *it;
		}

		std::cout << "]" << std::endl;
	}
}

}
}
int main()
{
	using namespace gcj::task2;
	solve( std::cin );
}