#include <iostream> 
#include <string>
 #include <fstream> 
using namespace std ;
 int n_src ;
 string src ;
 const int n_ptrn = 19 ;
 const string ptrn = "welcome to code jam" ; 
 ifstream fin ( "C-small-attempt0.in" ) ;
 #define cin fin
 FILE * file ; 
int tbl [ 500 ] [ 19 ] ; 
int find_substring ( const int s_src , const int s_ptrn ) {
	 if ( tbl [ s_src ] [ s_ptrn ] != - 1 ) { 
		return tbl [ s_src ] [ s_ptrn ] ; 
		} 
		if ( n_src - s_src < n_ptrn - s_ptrn ) {
			 tbl [ s_src ] [ s_ptrn ] = 0 ;
			 return 0 ; 
			} 
		if ( n_src - s_src == n_ptrn - s_ptrn ) { 
			string sub_src = src. substr ( s_src , n_src - s_src ) ;
			string sub_ptrn = ptrn. substr ( s_ptrn , n_ptrn - s_ptrn ) ;
			 tbl [ s_src ] [ s_ptrn ] = ( sub_src == sub_ptrn ) ? 1 : 0 ; 
			return tbl [ s_src ] [ s_ptrn ] ; 
			} int total = 0 ; 
			// Skip current char 
			total += find_substring ( s_src + 1 , s_ptrn ) ; 
			total %= 10000 ; 
			// If current char matches 
			if ( src [ s_src ] == ptrn [ s_ptrn ] ) { 
				total += find_substring ( s_src + 1 , s_ptrn + 1 ) ; 
				total %= 10000 ; 
				} 
				tbl [ s_src ] [ s_ptrn ] = total ;
				 return total ; 
				} 
				int main ( ) { 
					file = fopen ( "b.out" , "w" ) ;
					 int N ;
					 cin >> N ;
					 getline ( cin , src ) ;
					 for ( int n = 0 ; n < N ; ++ n ) {
						 getline ( cin , src ) ; 
						memset ( tbl , - 1 , 500 * 19 ) ;
						 n_src = src. length ( ) ; 
						int cnt = find_substring ( 0 , 0 ) ;
						 fprintf ( file , "Case #%d: %04d\n" , n + 1 , cnt ) ;
						 } 
						return 0 ; 
						}