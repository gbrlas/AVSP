#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <iomanip>

namespace gcj
{
namespace task1
{
std::vector<double> solve( const std::vector< std::string >& resultsMatrix )
{
	const size_t playersCount = resultsMatrix.size();

	std::vector< std::vector< std::pair< int, bool > > > opponents;
	// prepare data
	for( int i = 0; i < playersCount; ++i)
	{
		std::vector< std::pair< int, bool > > tempOpponentsList;
		for (int j = 0; j < playersCount; ++j)
		{
			if ( resultsMatrix[i][j] != '.' )
			{
				tempOpponentsList.push_back( std::make_pair( j, resultsMatrix[i][j] == '1' ? true : false ) );
			}
		}
		opponents.push_back(tempOpponentsList);
	}


	std::vector< double > wps;
	std::vector< double > owps;
	std::vector< double > oowps;
	double summWp = 0;
	for( int i = 0; i < playersCount; ++i)
	{
		double winsCount = 0;
		double gamesCount = opponents[i].size();
		for (int j = 0; j < opponents[i].size(); ++j)
		{
			if (opponents[i][j].second) winsCount += 1;
		}
		wps.push_back( winsCount / gamesCount );
		summWp += winsCount / gamesCount;
	}

	for( int i = 0; i < playersCount; ++i)
	{
		double owp = 0;
		double gamesCount = opponents[i].size();
		for (int j = 0; j < opponents[i].size(); ++j)
		{
			int opponentNumber = opponents[i][j].first;
			
			owp += 
				( wps[opponentNumber] * double(opponents[opponentNumber].size())  + 
						( !opponents[i][j].second ? -1 : 0 ) ) / double( opponents[opponentNumber].size() - 1 );
		}
		owps.push_back( owp / gamesCount );
	}

	for( int i = 0; i < playersCount; ++i)
	{
		double oowp = 0;
		double gamesCount = opponents[i].size();
		for (int j = 0; j < opponents[i].size(); ++j)
		{
			oowp += owps[opponents[i][j].first];
		}
		oowps.push_back( oowp / gamesCount );
	}


	std::vector<double> result;
	for (int i = 0; i < playersCount; ++i)
	{
		double res = 0.25 * wps[i] + 0.5 * owps[i] + 0.25 * oowps[i];
		result.push_back(res);
	}
	return result;
}

void solve( std::istream& inp, std::ostream& out)
{
	size_t tests;
	inp >> tests;
	for ( size_t i = 0; i < tests; ++i )
	{
		size_t playersCount = 0;
		inp >> playersCount;
		std::vector< std::string > playersInfo;
		for (int j = 0; j < playersCount; ++j)
		{
			std::string str;
			inp >> str;
			playersInfo.push_back(str);

		}
		std::vector<double> r = solve(playersInfo);
		out << "Case #" << i + 1 << ": " << std::endl;
		for ( int j = 0; j < playersCount; ++j )
		{
			out << std::fixed <<std::setprecision( 6 ) << r[j] << std::endl;
		}
	}
}
}
}
int main()
{
	using namespace gcj::task1;
	solve( std::cin, std::cout );

	
}