#include <iostream>
#include <cstdio>
#define SIZE 4
using namespace std;

template<typename A, int size> class BoardTable
{
	public:
		void putValue(A ob, int index_row, int index_col);
		A getValue(int index_row, int index_col);
		bool win(A ob);
		bool isfilled();
	
	private:
		A board[size][size];
};

template<typename A, int size> void BoardTable<A, size>::putValue(A ob, int index_row, int index_col)
{
	board[index_row][index_col] = (A)ob;
}

template<typename A, int size> A BoardTable<A, size>::getValue(int index_row, int index_col)
{
	return ( board[index_row][index_col] );
}

template<typename A, int size> bool BoardTable<A, size>::isfilled()
{
	for ( int i = 0; i < size; ++i ) 
		for ( int j = 0; j < size; ++j )
			if ( this->getValue(i, j) == '.' )
				return 0;
	return 1;
}

template<typename A, int size> bool BoardTable<A, size>::win(A ob)
{
	//cout << "Now, checking for rows... " << endl;
	/* for the rows. */
	for ( int i=0; i < size; ++i ) {
		for ( int j=0; j < size; ++j ) {
		//	cout << " When i = " << i  << ", j = " << j << endl;
			if ( this->getValue(i, j) == ob || this->getValue(i, j) == 'T') {
			//	cout << "Inside first if" << endl;
				//cout << " i = " << i  << ", j = " << j << endl;
				if ( j == size - 1 )
					return true;
			} else
				break;
		}
	}
//	cout << endl << "Now, checking for cols... " << endl;
	
	/* for the cols. */
	for ( int j=0; j < size; ++j ) {
		for ( int i=0; i < size; ++i ) {
		//	cout << " When i = " << i  << ", j = " << j << endl;
			if ( this->getValue(i, j) == ob || this->getValue(i, j) == 'T' ) {
			//	cout << "Inside second if" << endl;
				//cout << " i = " << i  << ", j = " << j << endl;
				if ( i == size - 1 )
					return true;
			} else {
				//cout << " i = " << i  << ", j = " << j << endl;
				break;
				}
		}
	}
//	cout << "Now, checking for diagonals(1)... \n\n" << endl;
	
	/* for the diagonals. */
	int i, j;
	for ( i=0, j=0; i < size; ++i, ++j ) {
//	cout << " i = " << i  << ", j = " << j << endl;
		
		if ( this->getValue(i, j) == ob || this->getValue(i, j) == 'T' ) {
	//		cout << "Inside first diagonal" << endl;
			if ( j == size - 1 )
				return true;
		} else
			break;
	}
	
//	cout << "Now, checking for diagonals(2)... " << endl;
	for ( i=0, j=3; i < size; ++i, --j ) { 
	//	cout << " i = " << i  << ", j = " << j << endl;
		if ( this->getValue(i, j) == ob || this->getValue(i, j) == 'T' ) {
		//	cout << "Inside first diagonal" << endl;
			if ( i == size - 1 )
				return true;
		} else
			break;
	}
	return false;	/* when none condition satisfies, i.e. not in rows, not in cols, and not even in diagonals. */
}

int main(void)
{
	int testcases;
	cin >> testcases;

	BoardTable<char, SIZE> ticTac;
	for ( int i=1; i <= testcases; ++i ) {
		getchar(); 		/* for taking the '\n' */

		/* Now, taking the status of the board. */
		for ( int m=0; m < SIZE; ++m ) {
			for ( int n=0; n < SIZE; ++n )
				ticTac.putValue(getchar(), m, n);
			getchar();
		}
		
		if ( ticTac.win('O') ) {
			cout << "Case #" << i << ": " << "O won" << endl;
			continue;
		}
		if ( ticTac.win('X') ) {
			cout << "Case #" << i << ": " << "X won" << endl;
			continue;
		}
		
		if ( ticTac.isfilled() ) 
			cout << "Case #" << i << ": " << "Draw" << endl;
		else
			cout << "Case #" << i << ": " << "Game has not completed" << endl;
	
	}
	return 0;
}

	