#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <iostream.h>

int main(int argc, char ** argv)
{
	int	T,
		K,
		N;
	int i, j, k;
	int status,
		patten;

	char result[4];
	
	freopen("p1is.txt", "r", stdin);
	freopen("p1os.txt", "w", stdout);
	
	cin >> T;
	for ( i=0; i<T; i++ )
	{
		cin >> N >> K;
		status = 0;
		patten = ( 1 << N ) - 1;

		if ( ( K & patten ) == patten )
			strcpy( result, "ON" );
		else 
			strcpy( result, "OFF" );


		cout << "Case #" << i+1 << ": " << result << endl;
	}
	
	return 0;
}