#include<stdio.h>

char arr[50][50];

int replacetiles( int row, int col){
	if(arr[row][col] == '#' && arr[row][col+1] == '#' && arr[row+1][col] == '#' && arr[row+1][col+1] == '#'){
		arr[row][col] = '/';
		arr[row][col+1] = '\\';
		arr[row+1][col] = '\\';
		arr[row+1][col+1] = '/';
		return 1;
	}
	return 0;
}

int main(){

	int numbers[2000];
	int numTest, rows,cols;
	int t, ii, jj;
	scanf("%d", &numTest);
	char ch;

	for(t=0;t<numTest; t++)
	{
		int flag = 1;
		scanf("%d", &rows);
		scanf("%d", &cols);
		scanf("%c", &ch);
		for(ii=0;ii<rows;ii++){
			for(jj=0;jj<cols;jj++){
				scanf("%c",&arr[ii][jj]);
			}
			scanf("%c", &ch);
		}

		for(ii=0;ii<rows-1;ii++){
                        for(jj=0;jj<cols-1;jj++){
                                if(arr[ii][jj] == '#') {
					if(replacetiles(ii,jj) == 0){
						flag = 0;
						break;
					}
				}
                        }
			if(flag ==0)break;
                }
		for(ii=0;ii<rows;ii++){
                        for(jj=0;jj<cols;jj++){
				if(arr[ii][jj] == '#')
					flag = 0;
			}
		}
		
		printf("Case #%d:\n", t+1);
		if(flag ==1) {	
			for(ii=0;ii<rows;ii++){
				for(jj=0;jj<cols;jj++){
					printf("%c",arr[ii][jj]);
				}
				printf("\n");
			}
		}else {
			 printf("Impossible\n");
		}
		
	}

	return 0;
}

