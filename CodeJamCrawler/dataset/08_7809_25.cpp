/*!
 	@file	engine.h
	@brief	Interface for the Engine class
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <limits>

class Engine
{
public:
	Engine( const std::string& name ) :
		m_name( name ),
		m_queryIndexes()
	{}

	Engine( const Engine& rhs ) :
		m_name( rhs.m_name )
	{}

	~Engine()
	{}

	//public accessors
	std::string name() const
	{
		return m_name;
	}

	unsigned int nextAppearance() const
	{
		if( m_queryIndexes.size() >= 1 )
		{
			return m_queryIndexes.at( 0 );
		}
		else
		{
			return std::numeric_limits<unsigned int>::max();
		}
	}

	//operators
	bool operator==( const std::string& name )
	{
		return name == m_name;
	}

	//public methods
	void addQuery( unsigned int index )
	{
		m_queryIndexes.push_back( index );
	}

	void clearAppearancesBefore( unsigned int index )
	{
		while( m_queryIndexes.size() > 0 && m_queryIndexes.at( 0 ) <= index )
		{
			m_queryIndexes.erase( m_queryIndexes.begin() );
		}
	}

private:
	std::string					m_name;
	std::vector<unsigned int>	m_queryIndexes;

	//assignment is not allowed
	Engine& operator=( const Engine& rhs )
	{}
};

#endif //ENGINE_H