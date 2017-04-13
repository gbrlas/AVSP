#include <iostream>
#include <sstream>
#include <math.h>

bool palins[10000];

void findPalins() {
   for (int i=0; i<10000; i++) {
      palins[i] = false;
      int reversei = 0;
      int n = i;
      while(n > 0) {
	 reversei = reversei*10 + (n%10);
	 n = n / 10;
      }
      if (i == reversei) 
	 palins[i] = true;
   }   
}

int main() {
   int numTests = 0;
   std::cin >> numTests;
   findPalins();
   
   for (int t=0; t<numTests; t++) {
      int numPalins = 0;
      int a = 0;
      int b = 0;
      std::cin >> a >> b;
      int bsqrt = floor(sqrt(b));		
      for (int i=ceil(sqrt(a)); i<=bsqrt; i++) {
	 if (palins[i*i] && palins[i]) {
	    numPalins++;
	 }
      }
      std::cout << "Case #" << t+1 <<": " << numPalins << std::endl;
   }
   return 0;
}
