#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GINTN(A) (fscanf(stdin,"%ld\n",&(A)))
#define GINT(A) (fscanf(stdin,"%ld",&(A)))
#define GBIG(A) (fscanf(stdin,"%lld",&(A)))
#define GSTR(A) (gets(A))
#define ARRAY(T,V,N) T* V = ((T*)malloc(sizeof(T)*N))

typedef long long BIG;

int cmp( const void* a, const void* b )
	{
	return ( *((BIG*)a) - *((BIG*)b) );
	}


char* v1 = "our language is impossible to understand";
char* r1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char* v2 = "there are twenty six factorial possibilities";
char* r2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char* v3 = "so it is okay if you want to just give up";
char* r3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

char key[26] = {};

int main( int argc, char* argv[] )
	{
	for( int i = 0; i < 26; i++ )
		key[ i ] = '*';

	key['y'-'a'] = 'a';
	key['e'-'a'] = 'o';
	key['q'-'a'] = 'z';

	int len = strlen(v1);
	for( int i = 0; i < len; i++ ) 
		{ if( !isspace(v1[i] ) ) key[ r1[i]-'a' ] = v1[i]; }
	len = strlen(v2);
	for( int i = 0; i < len; i++ ) 
		{ if( !isspace(v2[i] ) ) key[ r2[i]-'a' ] = v2[i]; }
	len = strlen(v3);
	for( int i = 0; i < len; i++ ) 
		{ if( !isspace(v3[i] ) ) key[ r3[i]-'a' ] = v3[i]; }

	int m = 0;
	bool test[26]; memset( test, 0, sizeof(test) );
	for( int i = 0; i < 26; i++ )
		{
		test[ key[i]-'a' ]++;
		if( key[i] == '*' ) m = i;
		}
	for( int i = 0; i < 26; i++ )
		{
		if( test[i] == 0 ) key[m] = i+'a';
		//printf( "%c\n", key[i] );
		}

	char buff[4096];

	long tests; GINTN(tests);

	for( int t = 0; t < tests; t++ )
		{
		char str[101]; memset( str, 0, sizeof(str) );
		char res[101]; memset( res, 0, sizeof(res) );
		
		GSTR(str);

		const int len = strlen(str);

		for( int i = 0; i < len; i++ )
			{
			char in = str[i];

			res[i] = ( isspace(in) ? ' ' : key[str[i]-'a']);
			}
		res[len] = 0;

		printf( "Case #%d: %s\n", t+1, res );
		}

	return 0;
	}
