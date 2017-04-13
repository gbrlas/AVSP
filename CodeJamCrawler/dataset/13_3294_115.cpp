
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

long double data[200];


int main(){

	int c;
	
	long double dt ;	

	char t [4][8] ;
	int  sd [4][4] ;

	int X  , dot ;

	cin >> c;
	for (int ci = 1 ; ci <= c ; ci++ ){
		cin >> t[0] >> t[1] >> t[2] >> t[3] ;
		dot = 0;
		
		for ( int sd1 = 0 ; sd1<4 ; sd1++ ){	
			for (int sd2 =0 ; sd2<4 ; sd2++){

			sd[sd1][sd2] = (t[sd1][sd2] == 'X' || t[sd1][sd2] == 'T' )? 1:0;
			sd[sd1][sd2] |= (t[sd1][sd2] == 'O' || t[sd1][sd2] == 'T' )? 2:0;
			if ( t[sd1][sd2] == '.' ) dot++;
			}
		}
		X=0;

	     X |= (sd[0][0] & sd[1][1] & sd[2][2] & sd[3][3]) ;
	     X |= (sd[0][3] & sd[1][2] & sd[2][1] & sd[3][0]) ;
              for ( int sd1 = 0 ; sd1<4 ; sd1++ ){
 	
				
				X |= (sd[sd1][0] & sd[sd1][1] & sd[sd1][2] & sd[sd1][3]) ;
				X |= (sd[0][sd1] & sd[1][sd1] & sd[2][sd1] & sd[3][sd1]) ;
		}

		cout << "Case #" << ci << ": " ;
		if (X) {
			cout << (X==1?"X":"O") << " won" << endl ;
		} else {
			cout << (dot? "Game has not completed" : "Draw" ) <<  endl ;
		}
	}

	return 0;
}


