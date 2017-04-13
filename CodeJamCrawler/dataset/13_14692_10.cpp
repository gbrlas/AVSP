#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(int);
bool isSquare(int);
bool fairAndSquare(int);
int numFS(int,int);

int main (int argc, char* argv[]) {
   FILE *infile;
   infile = fopen("input", "r");
   int n = 1;
   int temp;
   fscanf(infile,"%d",&temp);
   while (!feof(infile) && n <= temp) {
      int a = 0;
      int b = 0;
      fscanf(infile,"%d %d",&a, &b);
      //printf("The numbers printed here are: %d and %d\n", a, b);
      printf("Case #%d: %d\n", n, numFS(a, b));
      n++;
   }
   fclose(infile);
   return EXIT_SUCCESS;
}

bool isPalindrome (int n) {
   int reverse = 0;
   int temp = n;
   
   while (temp != 0) {
      // left shifts reverse's digits by 1
      reverse = reverse * 10;
      // adds the last digit of temp into reverse
      reverse = reverse + temp % 10;
      // right shifts temp's digit by 1
      temp = temp/10;
   }
   if ( n == reverse ) {
      return true;
   } else {
      return false;
   }
}

bool isSquare (int n) {
   // finds the closest root to the number
   long closestRoot = (long) sqrt(n);
   // checks if the root^2 is same as original number
   return n == closestRoot * closestRoot;
}

// checks if n is palindrome, perfect square, and its sqrt is palindrome
bool fairAndSquare (int n) {
   return (isPalindrome(n) && isSquare(n) && isPalindrome(sqrt(n)));
}

// checks number of fair and square numbers between a and b
int numFS (int a, int b) {
   int total = 0;
   for(; a <= b; a++) {
      if (fairAndSquare(a)) {
         total++;
      }
   }
   return total;
}