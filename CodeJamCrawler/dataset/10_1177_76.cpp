#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int caseN;
  cin >> caseN;

  for (int i = 1; i <= caseN; ++i) {
    cout << "Case #" << i << ": ";

    int R, k, N;
    cin >> R >> k >> N;

    int width[N];
    for (int i = 0; i < N; ++i)
      cin >> width[i];

    int sumFrom[N];
    int lengthFrom[N];
    int sum = 0;
    int length = 0;

    for (int i = 0; i < N; ++i) {
      while (sum + width[(i + length) % N] <= k && length < N) {
        sum += width[(i + length) % N];
        length++;
      }
      sumFrom[i] = sum;
      lengthFrom[i] = length;
      //cout << i << ": " << sum << " " << length << endl;

      sum -= width[i];
      length--;
    }
    // simulate
    long long earn = 0;
    int now = 0;
    /*
       cout << endl << "==============" << endl;
       cout << R << " " << k << endl;
       for (int i = 0; i < N; ++i)
       printf("%4d", width[i]);
       cout << endl << "------------------------" << endl;
       */
    for (int i = 0; i < R; ++i) {
      /*
         for (int j = 0; j < now; ++j)
         cout << "    ";
         for (int j = 0; j < lengthFrom[now]; ++j)
         printf("%4d", width[(j + now) % N]);
         */
      earn += sumFrom[now];

      //      cout << " => " << sumFrom[now] << " " << earn << endl;

      now += lengthFrom[now];
      now %= N;
    }
    cout << earn;

    cout << endl;
  }

  return 0;
}

