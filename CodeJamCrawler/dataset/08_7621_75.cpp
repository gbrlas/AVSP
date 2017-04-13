#include "stdafx.h"

#include <string.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{

	int i,j,k,p;

	int numCase = 0;
	int numEngine = 0;
	int numQuery = 0;

	int switchCount = 0;

	int updateCount = 0;
	int engineUpdate[100];

	char query[101];
	char engineName[100][101];

	FILE *fp;

	fp = fopen("small.txt","r");

	fscanf(fp, "%d", &numCase);



	for(i=0; i<numCase; i++){
		fscanf(fp, "%d", &numEngine);
		fgetc(fp);
		for(j=0; j<numEngine; j++){
			//fscanf(fp, "%s", engineName[j]);
			fgets(engineName[j],101,fp);
			engineUpdate[j] = 0;
		}

		fscanf(fp, "%d", &numQuery);
		fgetc(fp);

		updateCount = 0;
		switchCount = 0;
		for(j=0; j<numQuery; j++){
			fgets(query,101,fp);

			for(k=0; k<numEngine; k++){
				if(strcmp(query, engineName[k]) == 0){

					if(engineUpdate[k] == 0){
						if(updateCount == numEngine - 1){
							for(p=0; p<numEngine; p++){
								engineUpdate[p] = 0;
							}
							engineUpdate[k] = 1;
							updateCount = 1;
							switchCount++;
						}
						else{
							engineUpdate[k] = 1;
							updateCount++;
						}
					}
					break;
				}
			}
		}

		printf("Case #%d: %d\n", i+1, switchCount);
	}



	getch();
	return 0;
}