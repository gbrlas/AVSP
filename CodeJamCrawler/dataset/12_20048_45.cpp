#include <stdio.h>

#define MAX_CHARS_IN_LINE 100+1

char convertArray[][2] = {
{'a','y'},
{'b','h'},
{'c','e'},
{'d','s'},
{'e','o'},
{'f','c'},
{'g','v'},
{'h','x'},
{'i','d'},
{'j','u'},
{'k','i'},
{'l','g'},
{'m','l'},
{'n','b'},
{'o','k'},
{'p','r'},
{'q','z'},
{'r','t'},
{'s','n'},
{'t','w'},
{'u','j'},
{'v','p'},
{'w','f'},
{'x','m'},
{'y','a'},
{'z','q'}
};

char decodeGooglerese(char input){
  char result = ' ';

  if ((input >= 'a') && (input <= 'z')){
      result = convertArray[input - 'a'][1];
  }

  return result;
}

void convertString(){
  int caseSize = 0, i = 0, j = 0;
  char inputBuffer[MAX_CHARS_IN_LINE+1] = {0};

  fgets(inputBuffer, MAX_CHARS_IN_LINE+1, stdin);
  sscanf(inputBuffer, "%d", &caseSize);
  for (i = 0; i < caseSize; i++){
    fgets(inputBuffer, MAX_CHARS_IN_LINE+1, stdin);
    printf("Case #%d: ", i+1);
    for(j = 0; (inputBuffer[j] != '\0') && (j < MAX_CHARS_IN_LINE); j++){
      printf("%c", decodeGooglerese(inputBuffer[j]));
    }
    printf("\n");
  }
}

int main(){
  convertString();

  return 0;
}
