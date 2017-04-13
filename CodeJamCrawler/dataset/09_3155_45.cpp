#include <algorithm>
#include <iostream>

using namespace std;

typedef char longNum[25];

void getNextNum(longNum prev) {
  int lastIndex = strlen(prev);

  for (int i = lastIndex - 2; i >= 0; i --) {
    // Choose a number to try to move downward.
    char numToMove = prev[i];
    
    int swapIndex = 100;
    for (int j = i + 1; j < lastIndex; j++) {
      if (numToMove < prev[j]) {
	if (swapIndex == 100 || prev[j] < prev[swapIndex]) {
	  swapIndex = j;
	}
      }
    }
    
    if (swapIndex != 100) { // Then we bubble this number down and return
      prev[i] = prev[swapIndex];
      for (int j = swapIndex; j > i + 1; j--) {
	prev[j] = prev[j - 1];
      }
      prev[i + 1] = numToMove;
      sort(prev + i + 1, prev + lastIndex);
      return;
    }
  }

  for (int i = 0; i < lastIndex; i++) {
    if (prev[i] == '0') { prev[i] = 'A'; }
  }

  // If we get here, then we need to add a digit.
  prev[lastIndex] = '0'; // 0 < all digits.
  prev[lastIndex + 1] = '\0';
  sort(prev, prev + lastIndex + 1);
  prev[0] = prev[1];
  prev[1] = '0';

  for (int i = 0; i < lastIndex + 1; i++) {
    if (prev[i] == 'A') { prev[i] = '0'; }
  }

  sort(prev + 1, prev + lastIndex + 1);


  return;
}

int main() {

  int numCases;
  cin >> numCases;

  longNum curNum;

  for (int casei = 1; casei <= numCases; casei++) {
    
    cin >> curNum;

    getNextNum(curNum);

    cout << "Case #" << casei << ": " << curNum << endl;
  }

  return 0;
}
