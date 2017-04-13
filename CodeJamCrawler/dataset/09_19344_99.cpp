#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string sen = "welcome to code jam";

int solve() {
  string line;
  vector<int> sol( 19, 0 );

  
  getline( cin, line );
  for( int i = 0; i < (int)line.size(); ++i ) {
    for( int j = 0; j < 19; ++j )
      if( line[i] == sen[j] ) {
	if( !j ) ++sol[0];
	else sol[j] = (sol[j]+sol[j-1])%10000;
      }
  }

  return sol[18];
}

int main() {
  int ntp;
  
  scanf( "%d\n", &ntp );
  for( int i = 0; i < ntp; ++i ) 
    printf( "Case #%d: %04d\n", i+1, solve() );

  return 0;
}
