#include <iostream>
using namespace std ;
int main () {
	unsigned long T ;
	int a[16] , b[16] ;
	int x , y ;
	int p[4] , q[4] ;
	cin >> T ;
	for(unsigned long i = 0 ; i < T ; i++) {
		cin >> x ;
		for(int j = 0 ; j < 16; j++)
			cin >> a[j] ;
		cin >> y ;
		for(int j = 0 ; j < 16; j++)
			cin >> b[j] ;
		p[0] = a[4 * x - 4] ;
		p[1] = a[4 * x - 3] ;
		p[2] = a[4 * x - 2] ;
		p[3] = a[4 * x - 1] ;
		q[0] = b[4 * y - 4] ;
		q[1] = b[4 * y - 3] ;
		q[2] = b[4 * y - 2] ;
		q[3] = b[4 * y - 1] ;
		int count = 0 ;
		int m[4] ;
		for(int j = 0 ; j < 4 ; j++)
			for(int k = 0 ; k < 4 ; k++)
				if(p[j] == q[k]) {
					count++ ;
					m[count - 1] = p[j]; 
				}
		if(count == 1)
			cout << "Case #" << i + 1 << ": " << m[0] << endl ;
		else if(count == 0)
			cout << "Case #" << i + 1 << ": Volunteer cheated!" << endl ;
		else 
			cout << "Case #" << i + 1 << ": Bad magician!" << endl ;
	}
}
