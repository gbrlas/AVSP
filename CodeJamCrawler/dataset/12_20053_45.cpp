#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

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

void getData(int* min, int* max){
  char inputBuffer[BUFFER_SIZE] = {0};

  fgets(inputBuffer, BUFFER_SIZE, stdin);
  sscanf(inputBuffer, "%d %d", min, max);
}

int largerThanSelf(char* buffer, int numberOfDigits, int lotate){
  int j = 0;
	int result = 0;
	int judge = 0;
	int ref = 0, search = 0;
	
    for(j=0; j < numberOfDigits; j++){
      ref = buffer[numberOfDigits -1 - j];
      if (lotate - 1 - j < 0){
        search = buffer[numberOfDigits + lotate - 1 - j];
      }
      else{
        search = buffer[lotate - 1 - j];
      }
      if (ref > search){
        break;
      }
      else if(ref < search){
        judge = 1;
		  break;
      }
    }

	return judge;
}

int lessThanMax(char* buffer, char* maxBuffer, int numberOfDigits, int lotate){
	int i=0;
	int judge = 0;
	int ref = 0, search = 0;

	for(i=0; i < numberOfDigits; i++){
		ref = maxBuffer[numberOfDigits -1 - i];
		if (lotate - 1 - i < 0){
			search = buffer[numberOfDigits + lotate -1 - i];
		}
		else{
			search = buffer[lotate -1 -i];
		}

		if (ref < search) {
			break;
		}
		else if (ref > search){
			judge = 1;
			break;
		}
	}
	if (i == numberOfDigits) {
		judge = 1;
	}
	return judge;
}

typedef struct list_struct{
	struct list_struct* next;
	int result;
}list;

int addResultList(char* buffer, int numberOfDigits, int lotate, list** resultList){
	int judge = 1;
	int i = 0;
	int	 nowResult = 0;
	int search = 0;
	list* addCell;
	list* searchCell = *resultList;
	
	nowResult += buffer[lotate];
	for (i=0; i<numberOfDigits-1; i++) {
		if (lotate - 1 - i < 0){
			search = buffer[numberOfDigits + lotate -1 - i];
		}
		else{
			search = buffer[lotate -1 -i];
		}
		nowResult += search * pow(10,numberOfDigits -1 - i);
	}

	if (*resultList == NULL) {
		*resultList = (list*)malloc(sizeof(list));
		if (resultList == NULL) {
			return 0;
		}
		(*resultList)->result = nowResult;
		(*resultList)->next = NULL;
	}else {
		while (searchCell != NULL) {
			if (searchCell->result == nowResult) {
				judge = 0;
				break;
			}
			searchCell = searchCell->next;
		}
		if (judge == 1) {
			addCell = (list*)malloc(sizeof(list));
			if (addCell == NULL) {
				return 0;
			}
			addCell->result = nowResult;
			addCell->next = NULL;
			for(searchCell = *resultList; searchCell->next != NULL; searchCell = searchCell->next){
			}
			searchCell->next = addCell;
		}
	}
	return judge;
}

void delResultList(list** resultList){
	list* searchCell = *resultList;
	list* searchCellTmp;
	*resultList = NULL;

	while(searchCell != NULL){
		searchCellTmp = searchCell->next;
		free(searchCell);
		searchCell = searchCellTmp;
	}
}

int searchRecycledPairs(int min, int max){
  int i = 0, nowNum = 0, lotate = 0;
  int tmp = 0;
  int judge = 0;
  int result = 0;
  int numberOfDigits = 0;
  char buffer[BUFFER_SIZE] = {0};
  char maxBuffer[BUFFER_SIZE] = {0};
  list* resultList = NULL;
	
  i = 1;
  while(pow(10, i) <= max){
    i++;
  }
  numberOfDigits = i;

	tmp = max;
	for(i=0; i < numberOfDigits; i++){
		maxBuffer[i] = tmp % 10;
		tmp = tmp / 10;
	}

  for(nowNum=min; nowNum<max; nowNum++){
      tmp = nowNum;
    for(i=0; i < numberOfDigits; i++){
      buffer[i] = tmp % 10;
      tmp = tmp / 10;
    }

	for(lotate=1; lotate < numberOfDigits; lotate++){
		judge = largerThanSelf(buffer, numberOfDigits, lotate);
		if (judge == 1){
			judge = lessThanMax(buffer, maxBuffer, numberOfDigits, lotate);
			if (judge == 1) {
				judge = addResultList(buffer, numberOfDigits, lotate, &resultList);
				if (judge == 1){
					result++;
				}
			}
		}
	}
	  delResultList(&resultList);
  }

  return result;
}

int main(){
  int i = 0, caseSize = 0, result = 0;
  int min = 0, max = 0;

  caseSize = getCaseSize();

  for  (i = 0; i < caseSize; i++){
    getData(&min, &max);

    result = searchRecycledPairs(min, max);

    outputResult(i+1, result);
  }

  return 0;
}
