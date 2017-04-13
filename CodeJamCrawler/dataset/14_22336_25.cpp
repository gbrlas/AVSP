/*
Cristian David González González.
Problen A
*/
#include <iostream>

using namespace std;

int main ( void )
{
   short cartas1[4][4], cartas2[4][4];
   short row1, row2, iguales, card;
   short i, j, k, t;
   cin >> t;
   for ( i = 0; i < t; i++ )
   {
      cin >> row1;
      for ( j = 0; j < 4; j++ )
         for ( k = 0; k < 4; k++ )
            cin >> cartas1[j][k];
      cin >> row2;
      for ( j = 0; j < 4; j++ )
         for ( k = 0; k < 4; k++ )
            cin >> cartas2[j][k];
      iguales = 0;
      row1--;
      row2--;
      for ( j = 0; j < 4; j++ )
         for ( k = 0; k < 4; k++ )
            if ( cartas1[row1][j] == cartas2[row2][k] )
            {
               iguales++;
               card = cartas1[row1][j];
            }
     cout << "Case #" << i+1 << ": ";
     if ( iguales )
     {
        if ( iguales == 1 ) cout << card << endl;
        else cout << "Bad magician!" << endl;
     }
     else cout << "Volunteer cheated!" << endl;
   }
   return 0;
}
