#include <iostream>
#include <map>
#include <string>

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
	for ( size_t i = 1; i <= tests; ++i )
	{
		std::string input;
		unsigned long int N, K;
		std::cin >> N >> K;
		if ( i != 1 ) { std::cout << "\n"; }
		std::cout << "Case #" << i << ": " << ( solve( N, K ) ? "ON" : "OFF" );
	}
}