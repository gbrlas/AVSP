#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0
// Thanks to http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// for this code.
 
// A utility function to print an array
void printArray (int arr[], int n, char* result_str);
 
// A utility function to check if num has all 9s
int AreAll9s (int num[], int n );
 
// Returns next palindrome of a given number num[].
// This function is for input type 2 and 3
void generateNextPalindromeUtil (int num[], int n )
{
    // find the index of mid digit
    int mid = n/2;
 
    // A bool variable to check if copy of left side to right is sufficient or not
    bool leftsmaller = false;
 
    // end of left side is always 'mid -1'
    int i = mid - 1;
 
    // Begining of right side depends if n is odd or even
    int j = (n % 2)? mid + 1 : mid;
 
   // Initially, ignore the middle same digits 
    while (i >= 0 && num[i] == num[j])
        i--,j++;
 
    // Find if the middle digit(s) need to be incremented or not (or copying left 
    // side is not sufficient)
    if ( i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    // Copy the mirror of left to tight
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
 
    // Handle the case where middle digit(s) must be incremented. 
    // This part of code is for CASE 1 and CASE 2.2
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        // If there are odd digits, then increment
        // the middle digit and store the carry
        if (n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        // Add 1 to the rightmost digit of the left side, propagate the carry 
        // towards MSB digit and simultaneously copying mirror of the left side 
        // to the right side.
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; // copy mirror to right
        }
    }
}
 
// The function that prints next palindrome of a given number num[]
// with n digits.
void generateNextPalindrome( int num[], int n, char* result_str)
{
    int i;
 
    //printf("\nNext palindrome is:\n");
 
    // Input type 1: All the digits are 9, simply o/p 1
    // followed by n-1 0's followed by 1.
    if( AreAll9s( num, n ) )
    {
        sprintf(result_str, "1");
        for( i = 1; i < n; i++ )
            sprintf(result_str + strlen(result_str), "0" );
        sprintf(result_str + strlen(result_str), "1" );
    } else  {
    	// Input type 2 and 3
        generateNextPalindromeUtil ( num, n);
 
        // print the result
        printArray (num, n, result_str);
    }
}
 
// A utility function to check if num has all 9s
int AreAll9s( int* num, int n )
{
    int i;
    for( i = 0; i < n; ++i )
        if( num[i] != 9 )
            return 0;
    return 1;
}
 
/* Utility that prints out an array on a line */
void printArray(int arr[], int n, char* result_str)
{
    int i;
    for (i=0; i < n; i++){
	    sprintf(result_str + strlen(result_str), "%d", arr[i]);
	}
}
 
void get_next_palyn(char* init, char* result) {
	int len = strlen(init);
	int* num = malloc(sizeof(int)*len);
	int i;
	for(i=0;i<len;i++) {
		num[i]=init[i] - '0';
	}

	char *result_str=malloc(256);
	memset(result_str, 0, 256);
    generateNextPalindrome( num, len, result_str );
	sprintf(result, result_str, sizeof(result_str));
}
