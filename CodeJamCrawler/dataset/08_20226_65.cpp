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

struct Point {
  int a;
  int b;
  Point(const int a, const int b) : a(a%1000), b(b%1000) { };
  Point() : a(0), b(0) { };
};

Point operator*(const Point& u, const Point& v) {
  return Point(u.a * v.a + 5 * u.b * v.b, u.a * v.b + u.b * v.a);
};

int calc(long long n) {
  Point powers[128];
  powers[0] = Point(3, 1);
  for (int i = 1; i < 128; i++)
    powers[i] = powers[i-1] * powers[i-1];
  Point p(1, 0);
  for (int k = 0; k < 32; k++)
    if (((n >> k) & 1) == 1)
      p = p * powers[k];
  return (2 * p.a - 1 + 1000) % 1000;
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
    
  
