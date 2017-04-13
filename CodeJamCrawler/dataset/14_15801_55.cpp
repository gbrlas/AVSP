#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int norm( double* n, double* k, int size )
{
	set<double> naomi, ken;
	int point = 0;
	for( int i = 0; i < size; ++i )
		naomi.insert( n[ i ] ), ken.insert( k[ i ] );
	while( !naomi.empty() )
	{
		if( *naomi.begin() > *--ken.end() )
			++point;
		ken.erase( *naomi.begin() < *--ken.end()? *upper_bound( ken.begin(), ken.end(), *naomi.begin() ) : *ken.begin() );
		naomi.erase( *naomi.begin() );
	}
	return point;
}
int cheat( double* n, double *k, int size )
{
	set<double> naomi, ken;
	int point = 0;
	for( int i = 0; i < size; ++i )
		naomi.insert( n[ i ] ), ken.insert( k[ i ] );
	for( set<double>::iterator it = naomi.begin(); it != naomi.end(); ++it )
		if( *it < *ken.begin() )
			ken.erase( *--ken.end() );
		else
			ken.erase( *ken.begin() ), ++point;
	return point;
}

int main()
{
	int t, size;
	double naomi[ 1000 ], ken[ 1000 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%lf", naomi+i );
		for( int i = 0; i < size; ++i )
			scanf( "%lf", ken+i );
		sort( naomi, naomi+size );
		sort( ken, ken+size );
		printf( "Case #%d: %d %d\n", n, cheat( naomi, ken, size ), norm( naomi, ken, size ) );
	}
}
