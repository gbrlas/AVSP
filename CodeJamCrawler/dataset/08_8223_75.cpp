// fly_swatter.cpp : Defines the entry point for the console application.
//

#define _USE_MATH_DEFINES

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


bool is_inside( double x, double y, double r )
{
	return ( ( x * x ) + ( y * y ) ) < ( r * r );
}


double calc_integral( double x, double R )
{
	const double R2 = R * R;
	return ( ( x * sqrt( R2 - x * x ) ) + ( R2 * asin( x / R ) ) ) / 2;
}


double get_safe_area( double x, double y, double gap, double r )
{
	if ( !is_inside( x, y, r ) ) { return 0.0; }

	const double x2 = x + gap;
	const double y2 = y + gap;
	const double r2 = r * r;

	if ( is_inside( x2, y2, r ) ) { return ( gap * gap ); }

	const double p1_x = x;
	const double p1_y = sqrt( r2 - ( x * x ) );

	double left = p1_x;
	if ( p1_y > y2 ) { left = sqrt( r2 - ( y2 * y2 ) ); }

	const double p2_x = sqrt( r2 - ( y * y ) );
	const double p2_y = y;

	double right = p2_x;
	if ( p2_x > x2 ) { right = x2; }

	double area =
		calc_integral( right, r ) - calc_integral( left, r );
	area -= ( right - left ) * y;
	if ( left > p1_x ) { area += ( left - p1_x ) * gap; }

	return area;
}


void solve( const std::string & input_name, const std::string & output_name )
{
	std::ifstream input;
	std::ofstream output;
	input.open( input_name.c_str() );
	output.open( output_name.c_str() );
	if ( input.is_open() && output.is_open() )
	{
		std::size_t size = 0;
		input >> size;

		for ( std::size_t i = 0; i < size; ++i )
		{
			double f = 0.0, R = 0.0, t = 0.0, r = 0.0, g = 0.0;
			input >> f >> R >> t >> r >> g;

			const double ring_thickness = t + f;
			const double string_radius = r + f;
			const double gap = g - ( 2 * f );

			const double total_area = ( M_PI * R * R ) / 4;
			double safe_area = 0.0;

			if ( gap > 0 )
			{
				double y = string_radius;
				const double internal_radius = R - ring_thickness;
				while ( y < internal_radius )
				{
					double x = string_radius;
					while ( x < internal_radius )
					{
						safe_area += get_safe_area( x, y, gap, internal_radius );
						x += gap + ( 2 * string_radius );
					}
					y += gap + ( 2 * string_radius );
				}
			}

			const double hit_area = total_area - safe_area;
			const double probability = hit_area / total_area;

			output << "Case #" << i + 1 << ": " <<
				std::setiosflags( std::ios_base::fixed ) << std::setprecision( 6 ) <<
				probability << std::endl;
		}
	}
}


int main( int, char ** )
{
	try
	{
		// solve( "sample.in", "sample.out" );
		solve( "C-small-attempt0.in", "C-small-attempt0.out" );
	}
	catch ( std::exception & ex )
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
	return 0;
}
