#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <string>
using namespace std;

char to_english(char c){
      if(c == 'a') return 'y';
      else if(c == 'b') return 'h';
      else if(c == 'c') return 'e';
      else if(c == 'd') return 's';
      else if(c == 'e') return 'o';
      else if(c == 'f') return 'c';
      else if(c == 'g') return 'v';
      else if(c == 'h') return 'x';
      else if(c == 'i') return 'd';
      else if(c == 'j') return 'u';
      else if(c == 'k') return 'i';
      else if(c == 'l') return 'g';
      else if(c == 'm') return 'l';
      else if(c == 'n') return 'b';
      else if(c == 'o') return 'k';
      else if(c == 'p') return 'r';
      else if(c == 'q') return 'z';
      else if(c == 'r') return 't';
      else if(c == 's') return 'n';
      else if(c == 't') return 'w';
      else if(c == 'u') return 'j';
      else if(c == 'v') return 'p';
      else if(c == 'w') return 'f';
      else if(c == 'x') return 'm';
      else if(c == 'y') return 'a';
      else if(c == 'z') return 'q';
      else return c;
     
     }

void solve(){
     char buffer[110];
     cin.getline(buffer, 110);
     string G(buffer);
     for(int i=0; i<G.size(); i++){
             printf("%c", to_english(G[i]));
             }
     }

int main(void){
    int t;
    cin >> t;
    getchar();
    for(int i=1; i<=t; i++) {
            cout << "Case #" << i << ": ";
            solve();
            cout << endl;
            }
    return 0;
    }
