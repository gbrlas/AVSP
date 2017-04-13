#include "iostream"
#include "vector"
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int palin(int num)
{
  char n[100];

  sprintf(n, "%d", num);
  int len = strlen(n);
  for(int i = 0; i < len/2; i++)
    {
      if(n[i] != n[len - i -1]) return 0;
    }
  return 1;
}

int main()
{
  int cases = 0;
  cin >> cases;
  const int cas = cases;

  vector<int> output;

  for(int c = 0; c < cas; c++)
    {
      int a = 0, b = 0;
      int count = 0;

      scanf("%d %d", &a, &b);

      for(int i = ceil(sqrt(a)); i <= sqrt(b); i++)
	{
	  if(palin(i) && palin(i*i)) count++;
	}
      output.push_back(count);
    }

  for(int c = 0; c < cas; c++)
    {
      printf("Case #%d: %d\n", c+1, output[c]);
      //      cout << *it << endl;
    }
}
