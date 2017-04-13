#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

typedef std::vector< std::set< char > > fuzzy_word_t;

fuzzy_word_t readWord( std::istream& inp )
{
	enum state
	{
		waiting_word_symbol,
		waiting_variant_symbol,
	};
	std::string line;
	std::getline( inp, line );
	state current_state = waiting_word_symbol;
	fuzzy_word_t result;
	for ( std::string::const_iterator it = line.begin();
		it != line.end();
		++it )
	{
		if ( current_state == waiting_word_symbol )
		{
			std::set< char > l;
			if ( *it == '(' )
			{
				current_state = waiting_variant_symbol;
			}
			else
			{
				l.insert( *it );				
			}
			result.push_back( l );
		}
		else if ( current_state = waiting_variant_symbol )
		{
			std::set< char > l;
			if ( *it == ')' )
			{
				current_state = waiting_word_symbol;
			}
			else
			{
				result.back().insert( *it );	
			}
		}
	}
	return result;
}
typedef std::vector< std::string > vocabulary_t;

std::string
readVocabularyWord( std::istream& inp )
{
	std::string line;
	std::getline( inp, line );
	return line;
}
bool match( const std::string& word, const fuzzy_word_t& fuzzy_word )
{
	if ( word.length() != fuzzy_word.size() )
	{
		return false;
	}
	for ( size_t i = 0; i < word.length(); ++i )
	{
		if ( fuzzy_word[i].find( word[i] ) == fuzzy_word[i].end() )
			return false;
	}
	return true;

}
size_t calculateCases( const vocabulary_t& voc, const fuzzy_word_t& word )
{
	size_t result = 0;
	for ( vocabulary_t::const_iterator it = voc.begin();
		it != voc.end();
		++it )
	{
		if (match( *it, word ))
		{
			++result;
		}
	}
	return result;

}

int
main()
{
	std::ifstream finp( "A-large.in" );
	size_t L = 0;
	size_t D = 0;
	size_t N = 0;

	
	finp >> L >> D >> N;
	std::string tmp;
	std::getline( finp, tmp );
	vocabulary_t voc;
	for ( size_t i = 0; i < D; ++i )
	{
		voc.push_back( readVocabularyWord( finp ) );
	}
	for ( size_t i = 0; i < N; ++i )
	{
		fuzzy_word_t word = readWord( finp );
		size_t cases = calculateCases( voc, word );
		std::cout << "\nCase #" << i + 1 << ": " << cases;
	}
}
