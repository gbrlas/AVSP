
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str_teststring ;
int i_wordlength;
int i_result ;
int i_words;

void wordgenerate( int i_pos , string str_symbols[] ,  string str_wordlist[]  ){

	int i ;

// Check the current word
	for ( i = 0 ; i < i_words ; i++ ) {
	//	cout << "Compare " << str_teststring << str_wordlist[i] <<endl; 
		if ( 0 ==  str_teststring.compare ( 0 , i_pos ,  str_wordlist[i] , 0 , i_pos )){
			if ( i_pos == i_wordlength ) {
				i_result++;
				return;
			} else {
				for ( i = 0 ; i < str_symbols[i_pos].size() ; i++ ) {
					str_teststring.replace( i_pos , 1 , str_symbols[i_pos].substr(i,1));
					wordgenerate( i_pos + 1 , str_symbols , str_wordlist ) ;
				
				}
				return ;
			}
		}
	} 

}


main(){

	int i_cases;

	int i , j  , k  ;
	long long c ;
	int i_pos , i_pos2 ;
	

	
	string str_symbols;


	cin >> i_wordlength >> i_words >> i_cases ;

	string str_word , str_words[i_words] ;
	
	string	str_charset[i_words];


	for (  i = 0 ; i < i_words ; i++ ){
		cin >> str_word;
		str_words[i] = str_word ;

		for ( j = 0 ; j < i_wordlength ; j++ ){
			if  ( string::npos ==  str_charset[j].find ( str_word.substr ( j , 1 ) , 0 )) {
				str_charset[j].append (  str_word.substr ( j , 1 ) );
			}

		}
	}
// cout << "SDF" << endl ;
	//sort(str_words, str_words[i+1]);
	
	for ( i = 0 ; i < i_cases ; i++ ){
		cin >> str_word;

		i_pos = 0 ;

// Parse the case word
//
		string  str_symbols[i_wordlength];

		for ( j = 0 ; j < i_wordlength ; j++ ){
			
			if (0 == str_word.compare ( i_pos , 1 , "(" )) {
			   i_pos2 = str_word.find( ")" , i_pos+1);

			   for ( k = i_pos +1 ; k < i_pos2 ; k++ ){
			   	if (  string::npos  !=  str_charset[j].find ( str_word.substr ( k , 1 ) , 0 )) {
					
				   str_symbols[j] +=  str_word.substr ( k , 1 ); // str_word.substr ( i_pos + 1 , i_pos2 - i_pos - 1 );
			   	}
			   }

			   // remove ant characters not in the word list

			   //str_symbols.push_back ( str_word.substr ( i_pos + 1 , i_pos2 - i_pos - 1 ));

			   
			   i_pos = i_pos2 + 1 ;

			} else {
			   str_symbols[j] = str_word.substr( i_pos , 1);
			   // str_symbols.push_back ( str_word.substr ( i_pos ,1 )) ; 
			   i_pos++ ;
			}

		}
	
// Dump the symbos

 		
// Create a list of words for the test casei
		i_result = 0;
		wordgenerate (0 , str_symbols , str_words );

		cout << "Case #" << (i +1) << ": " << i_result << endl ;
	}

	return 0;
}

