#include <cstdio>
#include <iostream> 
#include <string>
using namespace std;
 

#define trace(x...) 

int main(){
        int n, in = 1;  
        char frase[101];
        
        scanf("%d", &n);
       
	   fflush(stdin);
		scanf("%*c");
        while (n--){
                scanf("%[^\n]\n", frase); 
                //gets(frase);
				//fflush(stdin);
				//getline(cin, frase);
                for ( int i = 0 ; frase[i] ; ++i ){
					trace(
							printf("entrou\n");
					)
					switch ( frase[i] ){
						case 'a': frase[i] = 'y';
								  break;
						case 'b': frase[i] = 'h'; break;
						case 'c': frase[i] = 'e'; break; 
						case 'd': frase[i] = 's'; break; 
						case 'e': frase[i] = 'o'; break; 
						case 'f': frase[i] = 'c'; break; 
						case 'g': frase[i] = 'v'; break; 
						case 'h': frase[i] = 'x'; break; 
						case 'i': frase[i] = 'd'; break; 
						case 'j': frase[i] = 'u'; break; 
						case 'k': frase[i] = 'i'; break; 
						case 'l': frase[i] = 'g'; break; 
						case 'm': frase[i] = 'l'; break; 
						case 'n': frase[i] = 'b'; break; 
						case 'o': frase[i] = 'k'; break; 
						case 'p': frase[i] = 'r'; break; 
						case 'q': frase[i] = 'z'; break; 
						case 'r': frase[i] = 't'; break; 
						case 's': frase[i] = 'n'; break; 
						case 't': frase[i] = 'w'; break; 
						case 'u': frase[i] = 'j'; break; 
						case 'v': frase[i] = 'p'; break; 
						case 'w': frase[i] = 'f'; break; 
						case 'x': frase[i] = 'm'; break; 
						case 'y': frase[i] = 'a'; break; 
						case 'z': frase[i] = 'q'; break; 
					}		

                }
                
                printf("Case #%d: %s\n", in++, frase);
        }
        
 
        return 0;
}
