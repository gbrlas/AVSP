#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool isPalindrome(int number);

int main(int argc, const char * argv[])
{
    int nbCases;
    
    
    cin >> nbCases;
    
    for (int currentCase=1; currentCase<=nbCases; ++currentCase) {
        int a=0;
        int b=0;
        int nbFairAndSquare=0;
        
        //load interval
        cin >> a >> b;
        
        for (int number=a; number<=b; ++number) {
            if( isPalindrome(number) )
            {
                double squareRoot = sqrt(number);
                if (squareRoot == trunc(squareRoot) && isPalindrome(squareRoot)) {
                    ++nbFairAndSquare;
                }
            }
            
        }
        cout << "Case #" << currentCase << ": " << nbFairAndSquare << endl;
    }
    
}

bool isPalindrome(int number)
{
    int reverseNumber=0;
    int work=number;
    
    while(work>0){
        reverseNumber= reverseNumber*10 + work%10;
        work/=10;
    }
    return number==reverseNumber;
    
}
