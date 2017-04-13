
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;



int main(){

	int c,x,y;
	bool Cancut ;

	int  mt, m [128][128] ;
	int xmax[128],ymax[128] ;

	
	cin >> c;
	for (int ci = 1 ; ci <= c ; ci++ ){
		cin >> y >> x ;
		//cout << y << " " << x << endl;

		for (int xi = 1 ; xi <= x ; xi++ ){
			xmax[xi] = 0 ; 
		}

		for (int yi = 1 ; yi <= y ; yi ++){
			ymax[yi] = 0 ;

			for (int xi = 1 ; xi <= x ; xi ++ ){
				cin >> mt ;
				//cout << mt << " " ;
				m[xi][yi] = mt; 
                                if ( mt > xmax[xi] ) xmax[xi] = mt ;
                                if ( mt > ymax[yi] ) ymax[yi] = mt ;
			}
			//cout << endl ;
		}

		Cancut = true;

                for (int xi = 1 ; xi <= x ; xi ++){
                        for (int yi = 1 ; yi <= y ; yi ++ ){
				if ( m[xi][yi] < xmax[xi] && m[xi][yi] < ymax[yi] ){
					Cancut = false;
					break;
				}
			}
			if (!Cancut) break;
		}

				
// calculate the minimum and maximum for each row and column
// either the row or the column maximum cannot exceed the node value

// piece of cake!

 				
	
		cout << "Case #" << ci << ": " ;
		cout << (Cancut?"YES":"NO") << endl ;
	}

	return 0;
}


