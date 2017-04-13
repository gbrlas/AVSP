/*
 * Google Code Jam 2008
 * Round 1A
 * Problem C: 
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 999999

int calc(long long n) {
  int amod1000 = 1;
  int bmod1000 = 0;
  for (int step = 0; step < n; step++) {
    int newa = 3*amod1000 + 5*bmod1000;
    int newb = amod1000 + 3*bmod1000;
    amod1000 = newa % 1000;
    bmod1000 = newb % 1000;
  }
  return (2 * amod1000 - 1 + 1000) % 1000;

}


int main(int argc, char *argv[])
{
  int C;
  cin >> C;
  for (int tc = 1; tc <= C; tc++) {
    long long n;
    cin >> n;
    int ret = calc(n);
    printf("Case #%d: %03d\n", tc, ret);
  }
  return 0;
}
    
  
