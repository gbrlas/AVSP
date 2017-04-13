#include "stdio.h"

#include <iostream>
#include <algorithm>

// taken from http://stackoverflow.com/questions/2211915/combination-and-permutation-in-c/2212063#2212063
 template <typename Iterator>
   inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
   {
      if ((first == last) || (first == k) || (last == k))
         return false;
      Iterator itr1 = first;
      Iterator itr2 = last;
      ++itr1;
      if (last == itr1)
         return false;
      itr1 = last;
      --itr1;
      itr1 = k;
      --itr2;
      while (first != itr1)
      {
         if (*--itr1 < *itr2)
         {
            Iterator j = k;
            while (!(*itr1 < *j)) ++j;
            std::iter_swap(itr1,j);
            ++itr1;
            ++j;
            itr2 = k;
            std::rotate(itr1,j,last);
            while (last != j)
            {
               ++j;
               ++itr2;
            }
            std::rotate(k,itr2,last);
            return true;
         }
      }
      std::rotate(first,k,last);
      return false;
   }

int sumCandy( int* values, int count ) {
	int result = 0;
	for ( int i = 0; i < count; ++i ) {
		result += values[ i ];
	}
	return result;
}

int xorCandy( int* values, int count ) {
	int result = 0;
	for ( int i = 0; i < count; ++i ) {
		result ^= values[ i ];
	}
	return result;
}

int main(int argc, char* argv[])
{
	int TestCases;
	scanf( "%d", &TestCases );

	for ( int Test = 0; Test < TestCases; ++Test )
	{
		// get the data
		int NumCandy;
		scanf( "%d", &NumCandy );
		int* Candy = new int[NumCandy];

		for ( int i = 0; i < NumCandy; ++i ) {
			scanf( "%d", &Candy[i] );
			if ( i < NumCandy - 1 ) {
				scanf( " " );
			}
		}

		std::sort( &Candy[0], &Candy[NumCandy] );

		int* CandyPots[2];
		int MaxValue = -1;
		// enumerate all combinations of candy pots
		for ( int Size = 1; Size <= ( NumCandy / 2 ); ++Size ) {
			int Combos = 0;
			do {
				/*for ( int x = 0; x < NumCandy; ++x ) {
					if ( x == Size ) {
						std::cout << " ";
					}
					std::cout << Candy[x];
				}
				std::cout << "\n";*/
				++Combos;
				
				if ( xorCandy( &Candy[ 0 ], Size ) == xorCandy( &Candy[ Size ], NumCandy - Size ) ) {
					MaxValue = std::max( MaxValue, std::max( sumCandy( &Candy[ 0 ], Size ), sumCandy( &Candy[ Size ], NumCandy - Size ) ) );
				}
			} while( next_combination(&Candy[0], &Candy[Size], &Candy[NumCandy]) );
			//std::cout << "Count: " << NumCandy << " Size: " << Size << " NumCombos: " << Combos << "\n";
		}

		std::cout << "Case #" << Test + 1 << ": ";

		if ( MaxValue >= 0 ) {
			std::cout << MaxValue;
		} else {
			std::cout << "NO";
		}

		std::cout << "\n";

		// clean up
		delete[] Candy;
	}

	return 0;
}

