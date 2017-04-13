#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

// 1. find all sinks and anumerate them
// 2. for all cells
//		if cell free 
//			find path to sink or marked cell with entry ( keep structs for each cell hasEntry, and mark )
//			mark all path and change hasEntry statuses

// 3. for all cells find correct letters

// this algorithm needs to be prooved, but I don't want to think

const int maxAlitude = 20000; 
struct workData
{
	workData( int height ):
		height_( height ),
		mark_( 0 ),
		hasEntry_( true ),
		isSink_(false)
	{}

	int height_;
	int mark_;
	bool hasEntry_;
	bool isSink_;
};

typedef std::vector< std::vector< workData > > workMap_t;

void findAllSinks( workMap_t& map )
{
	size_t currentMark = 1;
	for ( size_t i = 0; i < map.size(); ++i )
	{
		bool isSink = true;
		for ( size_t j = 0; j < map[i].size(); ++j )
		{
			bool sink = 
				( i == 0 || map[i][j].height_ <= map[i - 1][j].height_ ) &&
				( i == map.size() - 1 || map[i][j].height_ <= map[i + 1][j].height_) &&
				( j == 0 || map[i][j].height_ <= map[i][j - 1].height_ ) &&
				( j == map[i].size() - 1 || map[i][j].height_ <= map[i][j + 1].height_);
			if ( sink )
			{
				map[i][j].mark_ = currentMark;
				map[i][j].isSink_ = true;

				++currentMark;
			}
		}
	}
}

typedef std::vector< std::pair< size_t, size_t > > path_t;

path_t findPath( size_t x, size_t y, workMap_t& map )
{
	path_t path;
	path.push_back( std::make_pair( x, y ) );

	std::pair< size_t, size_t > current( x, y );
	bool found = false;
	while ( !found )
	{
		std::pair< size_t, size_t > next;
		int currentDifference = 0;

		if ( current.first != 0 && 
			currentDifference > map[current.first - 1][current.second].height_ - map[current.first][current.second].height_ 
) //			 && ( /*map[current.first - 1][current.second].mark_ == 0 || */map[current.first - 1][current.second].hasEntry_) )
		{
			currentDifference = map[current.first - 1][current.second].height_ - map[current.first][current.second].height_;
			next = std::make_pair( current.first - 1, current.second );
		}
		if ( current.second != 0 && 
			currentDifference > map[current.first][current.second - 1].height_ - map[current.first][current.second].height_ 
) //			&& ( /*map[current.first][current.second - 1].mark_ == 0 || */map[current.first][current.second - 1].hasEntry_) )
		{
			currentDifference = map[current.first][current.second - 1].height_ - map[current.first][current.second].height_;
			next = std::make_pair( current.first, current.second - 1);
		}
		if ( current.second != map[current.first].size() - 1 && 
			 currentDifference > map[current.first][current.second + 1].height_ - map[current.first][current.second].height_ 
) //			 && ( /*map[current.first][current.second + 1].mark_ == 0 || */map[current.first][current.second + 1].hasEntry_) )
		{
			currentDifference = map[current.first][current.second + 1].height_ - map[current.first][current.second].height_;
			next = std::make_pair( current.first, current.second + 1 );
		}

		if ( current.first != map.size() - 1 && 
			currentDifference > map[current.first + 1][current.second].height_ - map[current.first][current.second].height_ 
			 )// && ( /*map[current.first + 1][current.second].mark_ == 0 || */map[current.first + 1][current.second].hasEntry_) )
		{
			currentDifference = map[current.first + 1][current.second].height_ - map[current.first][current.second].height_;
			next = std::make_pair( current.first + 1, current.second );
		}
		current = next;
		found = map[current.first][current.second].mark_ != 0;
		path.push_back( current );
	}
	return path;
}

void markPath( workMap_t& map, const path_t& path )
{
	size_t i = path.size() - 2;
	for ( ; i > 0; --i )
	{
		map[path[i].first][path[i].second].mark_ = map[path[i + 1].first][path[i + 1].second].mark_;
		if ( !map[path[i + 1].first][path[i + 1].second].isSink_ )
		{
			map[path[i + 1].first][path[i + 1].second].hasEntry_ = false;
		}

	}
	map[path[i].first][path[i].second].mark_ = map[path[i + 1].first][path[i + 1].second].mark_;
}


std::map< int, char >
assignLetters( workMap_t& map )
{
	std::map< int, char > result;
	char currentLetter = 'a';
	for ( size_t i = 0; i < map.size(); ++i )
	{
		for ( size_t j = 0; j < map[i].size(); ++j )
		{
			if ( result.find( map[i][j].mark_ ) == result.end() )
			{
				result[ map[i][j].mark_ ] = currentLetter;
				++currentLetter;
			}
		}
	}
	return result;
}

void outputResults( workMap_t& map, std::map< int, char >& l)
{
	for ( size_t i = 0; i < map.size(); ++i )
	{
		for ( size_t j = 0; j < map[i].size(); ++j )
		{
			std::cout << l[ map[i][j].mark_ ];
			if ( j < map[i].size() - 1 )
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void solve( workMap_t& map )
{
	findAllSinks( map );
	for ( size_t i = 0; i < map.size(); ++i )
	{
		for ( size_t j = 0; j < map[i].size(); ++j )
		{
			if ( map[i][j].mark_ == 0 )
			{
				path_t path = findPath( i, j, map );
				markPath(map, path);
			}
		}
	}
	std::map< int, char > l = assignLetters( map );
	outputResults(map, l);

}

void processData( std::istream& inp )
{
	size_t height, width;
	inp >> height >> width;
	std::string tmp;
	std::getline( inp, tmp );

	workMap_t map;
	for ( size_t i = 0; i < height; ++i )
	{
		map.push_back( std::vector< workData >( ) );
		for ( size_t j = 0; j < width; ++j )
		{
			int altitude;
			inp >> altitude;
			map.back().push_back( workData( altitude ) );
		}
		std::getline( inp, tmp );
	}

	solve( map );
}

int main()
{
	std::ifstream finp( "c:\\dev\\code_jam\\test2\\debug\\B-large.in" ); //
	size_t dataCount;
	finp >> dataCount;
	std::string tmp;
	std::getline( finp, tmp );
	for ( size_t i = 0; i < dataCount; ++i )
	{
		std::cout << "Case #" << i + 1 << ":" << std::endl;
		processData( finp );
	}
}