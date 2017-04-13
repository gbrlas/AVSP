#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 400
#define PEOPLE_NUM 100

int getCaseSize(){
  int caseSize = 0;  
  char inputBuffer[BUFFER_SIZE] = {0};

  fgets(inputBuffer, BUFFER_SIZE, stdin);
  sscanf(inputBuffer, "%d", &caseSize);

  return caseSize;
}

void outputResult(int caseNum, int result){
  printf("Case #%d: %d\n", caseNum, result);
}

void getData(int* people, int* surprised, int* basePoint, int*
 eachPoints){
  int i = 0;
  char inputBuffer[BUFFER_SIZE] = {0};
  va_list arg;
  char* p;

  fgets(inputBuffer, BUFFER_SIZE, stdin);
  sscanf(inputBuffer, "%d %d %d", people, surprised, basePoint);

  p = strtok(inputBuffer, " ");
  p = strtok(NULL, " ");
  p = strtok(NULL, " ");
  for(i=0; i<*people; i++){
    p = strtok(NULL, " ");
    sscanf(p, "%d", &eachPoints[i]);
  }
}

int howManyGotBetterPoints(int people, int surprised, int basePoint, int* eachPoints){
  int i = 0;
  int result = 0;
  int oneJudge = 0, surplus = 0;

  for(i=0; i<people; i++){
    oneJudge = eachPoints[i] / 3;
    surplus = eachPoints[i] % 3;
    if (oneJudge >= basePoint){
      ++result;
    }
    else if (oneJudge + 1 >= basePoint){
      if (surplus > 0){
        ++result;
      }
      else if ((surprised > 0) && ((oneJudge - 1) >= 0)){
        --surprised;
        ++result;
      }
    }
    else if ((oneJudge + 2 >= basePoint) && surplus == 2){
      if (surprised > 0){
        --surprised;
        ++result;
      }
    }
  }

  return result;
}

int main(){
  int i = 0, caseSize = 0, result = 0;
  int googlers = 0, surprised = 0, basePoints = 0;
  int eachGooglerPoints[PEOPLE_NUM] = {0};

  caseSize = getCaseSize();

  for  (i = 0; i < caseSize; i++){
    getData(&googlers, &surprised, &basePoints, eachGooglerPoints);

    result = howManyGotBetterPoints(googlers, surprised, basePoints, eachGooglerPoints);

    outputResult(i+1, result);
  }

  return 0;
}
