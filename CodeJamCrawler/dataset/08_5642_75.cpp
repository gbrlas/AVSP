#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
double f, R, t, r, g;

#define ZERO 0.000000000000001

typedef struct Point_
{
	double x;
	double y;
} Point;

double dist1( Point p )
{
	return sqrt( p.x*p.x + p.y*p.y );
}

double dist2( Point p1, Point p2 )
{
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

int isInner( Point p, double RR )
{
	return dist1( p ) <= RR;
}

double fgetRect( double x, double y )
{
	if ( x < 0 )
		return 0;

	if ( y < 0 )
		return 0;

	return (x) * (y);
}

double fgetEmptyRect( double x, double y )
{
	if ( x - 2*f < 0 )
		return 0;

	if ( y - 2*f < 0 )
		return 0;

	return (x - 2*f) * (y - 2*f);
}

double getRect( Point p, Point q )
{
	double x = fabs( p.x - q.x );
	double y = fabs( p.y - q.y );

	return fgetRect( x, y );
}

double getEmptyRect( Point p, Point q )
{
	double x = fabs( p.x - q.x );
	double y = fabs( p.y - q.y );

	return fgetEmptyRect( x, y );
}

double getSector( Point p1, Point p, Point p2, double RR )
{
	double area = 0.0;

	double x = dist2( p1, p2 );
	if ( x < ZERO )
			return 0.0;

	double katet = sqrt( RR * RR - x*x/4 );
	double alpha = 2 * atan( x / (2*katet) );

	area += 0.5 * alpha * RR * RR;
    area -= x * katet / 2;
	area += 0.5 * fabs(p1.x-p2.x) * fabs( p1.y-p2.y );

	return area;
}

double analyze( Point p11, Point p22, Point p33, Point p44 )
{
	Point p1, p2, p3, p4;

	p1.x = p11.x + f;
	p1.y = p11.y - f;

	p2.x = p22.x - f;
	p2.y = p22.y - f;

	p3.x = p33.x - f;
	p3.y = p33.y + f;

	p4.x = p44.x + f;
	p4.y = p44.y + f;

	double RR = R - f - t;

	int in1 = isInner( p1, RR );
	int in2 = isInner( p2, RR );
	int in3 = isInner( p3, RR );
	int in4 = isInner( p4, RR );

	// case #1
	double area = 0.0;

	if ( in1 && in2 && in3 && in4 )
	{
		area += fgetRect( g - 2*f, g - 2*f );
	}

	if ( in1 && (!in2)&& in3 && in4 )
	{
		Point p12;
		p12.x = sqrt( RR*RR - p2.y * p2.y );
		p12.y = p1.y;

		Point p23;
		p23.x = p2.x;
		p23.y = sqrt( RR*RR - p2.x * p2.x );

		Point p123;
		p123.x = p12.x;
		p123.y = p23.y;

		area += getRect( p4, p12 );
		area += getRect( p4, p23 );
		area -= getRect( p4, p123 );
		area += getSector( p12, p123, p23, RR );
	}

	// case #2
	if ( in1 && (!in2)&& (!in3) && in4 )
	{
		Point p12;
		p12.x = sqrt( RR*RR - p2.y * p2.y );
		p12.y = p1.y;

		Point p34;
		p34.x = sqrt( RR*RR - p3.y * p3.y );
		p34.y = p3.y;

		Point p;
		p.x = p12.x;
		p.y = p4.y;

		area += getRect( p4, p12 );
		area += getSector( p12, p, p34, RR );
	}

	// case #3
	if ( (!in1) && (!in2)&& in3 && in4 )
	{
		Point p14;
		p14.x = p1.x;
		p14.y = sqrt( RR*RR - p1.x * p1.x );

		Point p23;
		p23.x = p2.x;
		p23.y = sqrt( RR*RR - p2.x * p2.x );

		Point p;
		p.x = p1.x;
		p.y = p23.y;

		area += getRect( p4, p23 );
		area += getSector( p14, p, p23, RR );
	}

	// case #4
	if ( (!in1) && (!in2)&& (!in3) && in4 )
	{
		Point p14;
		p14.x = p1.x;
		p14.y = sqrt( RR*RR - p1.x * p1.x );

		Point p34;
		p34.x = sqrt( RR*RR - p3.y * p3.y );
		p34.y = p3.y;

		area += getSector( p14, p4, p34, RR );
	}

	return area;
}

double findAnswer()
{
	double emptyArea = 0;
	double wholeArea = 3.14159265358979323846 * R * R / 4;

	double y = r + g;

	Point p1, p2, p3, p4;
	Point p11, p22, p33, p44;

	while( y < R + 4*g + 4*r )
	{
		p2.x = r + g;
		p2.y = y;

		p1.x = p2.x - g;
		p1.y = p2.y;

		p3.y = p2.y - g;
		p3.x = p2.x;

		p4.x = p2.x - g;
		p4.y = p2.y - g;

		// first
		emptyArea += analyze( p1, p2, p3, p4 );

		p11 = p1;
		p22 = p2;
		p33 = p3;
		p44 = p4;
		
		// next
		while( true )
		{
			p11.x = p11.x + g + 2*r;
			p22.x = p22.x + g + 2*r;
			p33.x = p33.x + g + 2*r;
			p44.x = p44.x + g + 2*r;

			double area = analyze( p11, p22, p33, p44 );
			if ( area < ZERO )
					break;
			
			emptyArea += area;
		}

		y += 2*r + g;
	}

	return 1 - (emptyArea / wholeArea);
}

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "input.txt", "r" );
	FILE* fout = fopen( "output.txt", "w" );

	fscanf( fin, "%d", &N );

	for( int i=1; i<=N; i++ )
	{
		fscanf( fin, "%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g );

		double x = findAnswer();
		fprintf( fout, "Case #%d: %.6f\n", i, x );
		printf( "Case #%d: %.6f\n", i, x );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
