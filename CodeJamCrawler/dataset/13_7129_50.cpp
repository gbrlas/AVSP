/*	Written By:		Kumar Subham
 *	Date:			13-Apr-2013
 *	Email:			krsubham@gmail.com
 */

#include <iostream>
#include <set>

using namespace std;

template<typename A> class Lawn
{
	public:
		Lawn(int r, int c) {
			row = r;
			col = c;
		}
		
		void setValue(A& ob, int indexRow, int indexCol);
		A getValue(int indexRow, int indexCol);
		
		int getRow();
		int getCol();
		
		void grazeAll(A ob);
		void grazeRow(A& ob, int indexRow);
		void grazeCol(A& ob, int indexCol);
		void grazePattern(Lawn& lawnPattern, A ob);
		
		bool equals(Lawn& l1);
		
	private:
		int row;
		int col;
		A field[100][100];
};

template<typename A> int Lawn<A>::getRow()
{
	return ( this->row );
}

template<typename A> int Lawn<A>::getCol()
{
	return ( this->col );
}

template<typename A> bool Lawn<A>::equals(Lawn& l1)
{
	for ( int i=0; i < l1.getRow(); ++i ) 
		for ( int j=0; j < l1.getCol(); ++j ) 
			if ( this->getValue(i, j) != l1.getValue(i, j) ) 
				return false;
	return true;
}

template<typename A> void Lawn<A>::setValue(A& ob, int indexRow, int indexCol)
{
	field[indexRow][indexCol] = (A)ob;
}

template<typename A> A Lawn<A>::getValue(int indexRow, int indexCol)
{
	return ( field[indexRow][indexCol] );
}

template<typename A> void Lawn<A>::grazeAll(A ob)
{
	for (int i=0; i < this->getRow(); ++i )
		for (int j=0; j < this->getCol(); ++j )
			this->setValue(ob, i, j);
}

template<typename A> void Lawn<A>::grazeRow(A& ob, int indexRow)
{
	for ( int k=0; k < this->getCol(); ++k ) 
		this->setValue(ob, indexRow, k);
}

template<typename A> void Lawn<A>::grazeCol(A& ob, int indexCol)
{
	for ( int k=0; k < this->getRow(); ++k ) 
		this->setValue(ob, k, indexCol);
}

template<typename A> void Lawn<A>::grazePattern(Lawn& lawnPattern, A ob)
{
	/* for the row. */
	for ( int i=0; i < this->getRow(); ++i ) {
		if ( lawnPattern.getValue(i, 0) == ob ) {
			for ( int j=0; j < this->getCol(); ++j ) {
				if ( lawnPattern.getValue(i, j) != ob ) 
					break;
				if ( j == this->getCol() - 1 )
					this->grazeRow(ob, i);
			}
		}
	}
	
	/* for the col. */
	for ( int j=0; j < this->getCol(); ++j ) {
		if ( lawnPattern.getValue(0, j) == ob ) {
			for ( int i=0; i < this->getRow(); ++i ) {
				if ( lawnPattern.getValue(i, j) != ob )
					break;
				if ( i == this->getRow() - 1 ) 
					this->grazeCol(ob, j);
			}
		}
	}
}

int main()
{
	int testcases;
	cin >> testcases;
	
	for ( int k=1; k <= testcases; ++k ) {
		int n, m;
		cin >> n >> m;
		
		Lawn<int> lawnUngrazed(n, m), lawnGrazed(n, m);
		int temp;
		
		for ( int i=0; i < n; ++i ) {
			for ( int j=0; j < m; ++j ) {
				cin >> temp;
				lawnGrazed.setValue(temp, i, j);
			}
		}
		
		set<int> uniqueHeight;
		for ( int i=0; i < n; ++i )
			for ( int j=0; j < m; ++j )
				uniqueHeight.insert( lawnGrazed.getValue(i, j) );
		
		set<int>::iterator p = uniqueHeight.end();
		p--;	/* Now, it points to the max. element in the set. */
		lawnUngrazed.grazeAll(*p);
		
		p--; /* Now, it points to the second max. element. in the set. */
		
		for ( int i=1; i <= uniqueHeight.size() - 1; ++i, --p )
			lawnUngrazed.grazePattern(lawnGrazed, *p);
	
		if ( lawnGrazed.equals(lawnUngrazed) ) 
			cout << "Case #" << k << ": YES" << endl;
		else
			cout << "Case #" << k << ": NO" << endl;
	
	}
	return 0;
}

