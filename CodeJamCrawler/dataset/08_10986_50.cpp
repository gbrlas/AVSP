#include <iostream>
#include <map>
#include <list>

struct train {
	train( int s, int e, bool st )
		: start(s), end(e), station( st ) {}
	int start, end;
	bool station; // true for A=>B, false for B=>A
	bool operator < ( const train & o ) {
		return start < o.start;
	}
};

int main(int argc, char *argv[])
{
	using namespace std;
	
	int cases;
	cin >> cases;
	
	for ( int c=0; c<cases; ++c )
	{
		int turnaround, NA, NB;
		cin >> turnaround >> NA >> NB;
		
		list< train > tracks;
		
		for ( int i=0; i<NA+NB; ++i)
		{
			int h1, m1, h2, m2; char sem;
			cin >> h1 >> sem >> m1 >> h2 >> sem >> m2;
			tracks.push_back( train( h1*60 + m1, h2*60 + m2, i<NA ) );
		}
		tracks.sort();

		int A=0, B=0;
		list< int > B_trains, A_trains;

		for( list<train>::iterator i=tracks.begin(), e=tracks.end(); i!=e; ++i)
			if ( i->station )
			{
				if ( A_trains.size() && A_trains.front() <= i->start )
					A_trains.pop_front();
				else
					A++;
				B_trains.push_back( i->end + turnaround );
				B_trains.sort();
			}
			else
			{
				if ( B_trains.size() && B_trains.front() <= i->start )
					B_trains.pop_front();
				else
					B++;
				A_trains.push_back( i->end + turnaround );
				A_trains.sort();
			}
		cout << "Case #" << c+1 << ": " << A << " " << B << endl;
	}

	return EXIT_SUCCESS;
}
