#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "string.h"

#pragma warning( disable : 4996 )

int AddCorrect(int i1, int i2)
{
  return i1+i2;
}

int AddIncorrect(int i1, int i2)
{
  return i1 ^ i2;  // a bitwise exclusive OR should do the trick!
}

int permutations(int arr[], int num_ints)
{
  int max = 0;
  for (int i=0; i<num_ints; i++)
    if (arr[i]>max) max = arr[i];

  //Calculate the number of bits needed for the biggest number
  int bits = num_ints;

  //Do the sharing permutations.  increment a number and use the binary
  //0 or 1 for each bit to determine which party gets that number in 
  //their bag.
  //e.g.  1001  means A gets pieces 1 and 4, B gets 2 and 3.

  int max_correct = 0;
  int num_permutations = 1 << bits;
  for (int i=0; i<num_permutations; i++)
  {
    int sumA = 0;
    int sumB = 0;
    int badA = 0;
    int badB = 0;

    for (int b=bits-1; b>=0; b--)
    {
      if ((i>>b)&1)
      {
        sumA = AddCorrect  (sumA, arr[b]);
        badA = AddIncorrect(badA, arr[b]);
      }
      else
      {
        sumB = AddCorrect  (sumB, arr[b]);
        badB = AddIncorrect(badB, arr[b]);
      }
    }

    if ((sumA*sumB) && (badA==badB))
    {
      if (max_correct<sumA)
        max_correct = sumA;
    }
  }

  return max_correct;
}


void PrintArgs()
{
  printf("Args:  candy <input_file>\n");
}

int main(int c, char **args)
{
  int num_cases    = 0;

  if (c<2)
  {
    PrintArgs();
    return -1;
  }

  FILE *f = fopen(args[1], "r");
  if (!f)
  {
    printf("Error: Input file does not exist.\n");
    PrintArgs();
    return -1;
  }

  fscanf(f, "%d\n", &num_cases);
  for (int i=0; i<num_cases; i++)
  {
    int num_count = 0;
    fscanf(f, "%d\n", &num_count);
    int *arr = new int[num_count];

    for (int num=0; num<num_count; num++)
      fscanf(f, "%d ", &arr[num]);

    int res = permutations(arr, num_count);

    printf("Case #%d: ", i+1);
    if (res)
      printf("%d\n", res);
    else
      printf("NO\n");
  }

  fclose(f);
}