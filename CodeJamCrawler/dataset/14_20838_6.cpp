using namespace std;

#include <cstdio>
#include <vector>

#define NUM_ROWS 4
#define NUM_COLS 4

int arr1 [NUM_ROWS][NUM_COLS];
int arr2 [NUM_ROWS][NUM_COLS];

int main () {
  int numTests;
  scanf("%d", &numTests);

  for (int t = 0; t < numTests; t++) {
    int answer1, answer2;
    scanf("%d", &answer1);

    for (int i = 0; i < NUM_ROWS; i++) {
      for (int j = 0; j < NUM_COLS; j++) {
        scanf("%d", &(arr1[i][j]));
      }
    }

    scanf("%d", &answer2);
    for (int i = 0; i < NUM_ROWS; i++) {
      for (int j = 0; j < NUM_COLS; j++) {
        scanf("%d", &(arr2[i][j]));
      }
    }

    int answer;
    int numAnswers = 0;
    for (int i = 0; i < NUM_COLS; i++) {
      for (int j = 0; j < NUM_COLS; j++) {
        if (arr1[answer1 - 1][i] == arr2[answer2 - 1][j]) {
          answer = arr1[answer1 - 1][i];
          numAnswers++;
        }
      }
    }

    printf("Case #%d: ", t + 1);
    if (numAnswers == 0) {
      printf("Volunteer cheated!\n");
    } else if (numAnswers > 1) {
      printf("Bad magician!\n");
    } else {
      printf("%d\n", answer);
    }
  }

  return 0;
}
