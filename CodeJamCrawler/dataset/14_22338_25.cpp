/*
Cristian David González González.
Problem B.
*/
#include <iostream>

using namespace std;

double tiempoRequerido( void);
double c, f, x;

int main ( void )
{
   int i, t;
   cin >> t;
   cout.setf( ios::fixed, ios::floatfield );
   cout.precision( 7 );
   for ( i = 1; i <= t; i++ )
   {
      cin >> c >> f >> x;
      cout << "Case #" << i << ": " << tiempoRequerido() << endl;
   }
   return 0;
}

double tiempoRequerido( void )
{
   int i;
   double gSeg(2);
   double tiempoGranjas(0);
   double granja(0), ahorrar(0);
   do
   {
      ahorrar = x / gSeg + tiempoGranjas;
      tiempoGranjas += c / gSeg;
      gSeg += f;
      if ( ahorrar <= x / gSeg + tiempoGranjas )
         return ahorrar;
   }while( 1 );
}
