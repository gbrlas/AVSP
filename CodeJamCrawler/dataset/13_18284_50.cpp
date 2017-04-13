#include <cstdio>
#include <vector>
#include <algorithm>

#define N 1000

using namespace std;

typedef long long int ll;

bool pal(ll x)
{
  vector<int> digits;
  while(x)
  {
    digits.push_back(x % 10);
    x /= 10;
  }

  vector<int> rdigits = digits;
  reverse(rdigits.begin(), rdigits.end());

  return rdigits == digits;
}

int main()
{
  vector<ll> numbers;
  for(ll i = 1; i <= N; ++i)
  {
    if(pal(i) && pal(i*i))
    {
      numbers.push_back(i * i);
    }
  }

  int t;
  scanf("%d", &t);
  int a, b;
  for(int i = 0; i < t; ++i)
  {
    scanf("%d %d", &a, &b);
    int counter = 0;
    for(size_t j = 0; j < numbers.size(); ++j)
    {
      if(a <= numbers[j] && numbers[j] <= b)
      {
        counter += 1;
      }
    }

    printf("Case #%d: %d\n", i + 1, counter);
  }

  return 0;
}
