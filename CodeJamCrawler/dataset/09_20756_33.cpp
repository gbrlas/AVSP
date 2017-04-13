#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>

using namespace std;

template< typename type > type readOne()
{
    type res;
    char inp[5000];
    
    gets( inp );
    stringstream ss( inp );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char inp[5000];
    
    gets( inp );
    stringstream ss( inp );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

int doit( int num_word, vector<string> dictionary, string word ){

    vector<string> div_word;
    int pos = 0;
    int num = 0;

    for( int i = 0; i < num_word; i++ ){
        if( word[pos] != '(' ){
            div_word.push_back( &word[pos] );
            pos++;
        }
        else{
            pos++;  /*'('‚ÌŽŸ‚Éi‚ß‚é*/
            int beg_pos = pos;
            while( word[pos] != ')' ){
                pos++;
            }
            div_word.push_back( word.substr( beg_pos, pos - beg_pos) );
            pos++; /* ')'‚ÌŽŸ‚Éi‚ß‚é */
        }
    }

    /*
    for(int i = 0; i < div_word.size(); i++ ){
        for( int j = 0; j < div_word[i].size(); j++ ){
            printf("%c", div_word[i][j] );
        }
        printf("\n");
    }
    */

    for( int i = 0; i < dictionary.size(); i++ ){
        int flag = 1;
        int good = 0;
        for( int j = 0; j < num_word; j++ ){
            char a_word = dictionary[i][j];

//            printf("a_word: %c   ", a_word );
            for( int k = 0; k < div_word[j].size(); k++ ){
//                printf("%c  ", div_word[j][k]);
                if( a_word == div_word[j][k] ){
                    good++;
                    break;
                }

            }
//            printf("\n");

            
        }

//        printf("\n\n");

        if( good == num_word ) num++;
    }
    

    return num;
}

int main()
{
    vector <int> cases = readMulti<int>();
    vector <string> dictionary;

    int num_word = cases[0];

    for( int i = 0; i < cases[1]; i++ ){
        dictionary.push_back( readOne<string>() );
    }
    
    for (int caseno = 1; caseno <= cases[2]; caseno++){
        string word = readOne<string>();
        printf("Case #%d: %d\n", caseno, doit( num_word, dictionary, word ) );
    }
    
	return 0;
}
