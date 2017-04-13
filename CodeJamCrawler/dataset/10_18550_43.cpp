#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
bool solve( unsigned long int N, unsigned long int K )
{
//	std::cout << "N = " << N << " K = " << K << std::endl;
	unsigned long int onState = ( 1 << ( N ) ) - 1;
	//std::cout << "OnState = " << onState << std::endl;
	return ( onState & K ) == onState;
}

int
main()
{
	size_t tests = 0;
	std::cin >> tests;
	for ( size_t test = 1; test <= tests; ++test )
	{
		std::string input;
		unsigned long int R, k, N;
		std::cin >> R >> k >> N;
		std::vector< int > groups;
		for ( size_t i = 0; i < N; ++i )
		{
			unsigned int gi;
			std::cin >> gi;
			groups.push_back( gi );
		}

		std::vector< std::pair< unsigned long int, unsigned int > > groups_of_groups;
		for ( size_t i = 0; i < N; ++i )
		{
			unsigned long int sum = 0;
			size_t j = 0;
			for ( ; j < N; ++j )
			{
				unsigned long int current_group = groups[ ( i + j ) % N ];
				if ( ( sum + current_group ) <= k )
					sum += current_group;
				else
				{
					break;
				}
			}
			groups_of_groups.push_back( std::make_pair( sum, ( i + j ) % N ) );
		}
		
		unsigned long int result = 0;
		unsigned int current = 0;
		for ( unsigned int i = 0; i < R; ++i )
		{
			result += groups_of_groups[ current ].first;
			current = groups_of_groups[ current ].second;
		}

		if ( test != 1 ) { std::cout << "\n"; }
		std::cout << "Case #" << test << ": " << result;
	}
}