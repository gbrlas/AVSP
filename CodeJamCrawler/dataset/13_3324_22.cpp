
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
//#include <iomanip>
#include <cstdlib>


using namespace std;

int compare( const void * a , const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

int solve(unsigned int ci){


  	int A , N , aN[128];
  	int steps_min  = 0 , steps_max = 0 ;
		int Amin , Amax ;

		cin >> A >> N ;

				
		for (unsigned int i = 1 ; i <= N ; ++i )		cin >> aN[i];

		qsort ( &aN[1] , N , sizeof(aN[0] ) , compare);
		

		steps_min = steps_max = 0 ;
		Amin = Amax = A; 

		int max_start = 0;

//		cout << "A is " << A << endl ;

    for (unsigned int i = 1; i <=N ; ++i ) {

// Need to flatten the problem.  If we can absorbe the next mote, this is always the cheapest option
// as it requires no change.  If we have to alter the motes, then need to look at which is cheaper.
// This will depend on what follows, so need to look ahead.

// It can never be more than deleting all the motes but adding some now may allow no changes at the end.

// I've already put the motes in order, so I know that the following motes are going to be larger.  
// Thus adding extra here definetely needed if to absorb following.  Only if the extras exceed the 
// number left though

//				cout << "i = " << i << " checking " << aN[i] << " min "<<  Amin << " max " << Amax << "mins " << steps_min  << "maxs " << steps_max <<endl  ;
					// calculate how many points to add
					  max_start = 0 ;

						int j = 0;
						for ( ; j < N - i + 1 ; ++ j ) {

								if (Amax > aN[i] ){
									Amax += aN[i] ;
									break ;
								}
//cout << "adding to max steps " << endl;	
							  Amax = Amax * 2 - 1 ;
								max_start ++ ;
					}
					
				if ( j == N - i + 1 ) {   // short cut.
						steps_min += max_start ;
						break ;
					}
				steps_max += max_start ;
				

				if ( Amin > aN[i] ) {  // unchanged can absorbe 
//				 cout << " min fit " ;
					Amin += aN[i] ;
				} else { 
 //         cout << " min fail " ;
					steps_min ++ ;
				}

	
				if (steps_max < steps_min ) {
//					cout << " max better " ;
					Amin = Amax ;
					steps_min = steps_max; 
				}

//				cout << endl ;
		}

		cout << "Case #" << ci << ": " ;
		cout << steps_min  << endl ;

	 return 0;
}

int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
}



