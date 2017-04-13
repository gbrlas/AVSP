#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

int map[MAX][MAX];
char value[MAX][MAX];

int HEIGHT;
int WIDTH;

char endPoint(int h, int w);

int main(int argc, char **argv)
{

	int n;
	int height;
	int width;

	int h;
	int w;

	int i,j,k,l,m,c;

	int sink;

	int north, south, east, west;

	int direction;
	int min;

	int ch;

	scanf("%d", &n);

	//iterate on map
	for(i=0;i<n;i++){

		scanf("%d %d", &height, &width);

		h=w=0;

		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
				scanf("%d", &map[k][j]);
			}
		}
		
		HEIGHT=height;
		WIDTH=width;

		//initialize value
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
				value[k][j]='*';
			}
			//printf("\n");
		}


		printf("Case #%d:\n", i+1);

		sink='A';

		//mark sink first
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
				//determine north south east west
				
				//NORTH
				if(k==0){
					north=10001;
				}
				else{
					north=map[k-1][j];
				}

				//SOUTH
				if(k==height-1){
					south=10001;
				}
				else{
					south=map[k+1][j];
				}

				//WEST
				if(j==0){
					west=10001;
				}
				else{
					west=map[k][j-1];
				}

				//EAST
				if(j==width-1){
					east=10001;
				}
				else{
					east=map[k][j+1];
				}

				//mark sink
				c=map[k][j];
				if(c<=north && c<=south && c<=east && c<=west){
					value[k][j]=sink++;
					//printf("Got one sink at [%d, %d] with label : %c\n", k, j, sink-1);
				}
			}
		}


		///printf value map
		//print map
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
			//	printf("%c ", value[k][j]);
			}
		//	printf("\n");
		}


		///////////////////////////////
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){

				value[k][j]=endPoint(k, j);
			//	printf("+recording %c at [%d, %d]\n", value[k][j], k, j);
		///////////below for*2
			}
		}

		sink='a';
		//convert labels in order
		///////////////////////////////
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
				if(isupper(value[k][j])){
					ch=value[k][j];
					
						for(l=0;l<height;l++)
							for(m=0;m<width;m++)
								if(value[l][m]==ch)
									value[l][m]=sink;
					value[k][j]=sink;
					sink++;
				}
			}
		}

		///printf value map
		//print map
		for(k=0;k<height;k++){
			for(j=0;j<width;j++){
				printf("%c ", value[k][j]);
			}
			printf("\n");
		}

	}
}


char endPoint(int h, int w){

	char ch;
	int direction;
	int min;
	int north, south, east, west;

	//printf("recursing on %d, %d\n", h, w);
	//if sink, or already determined
	if(value[h][w]!='*')
		return value[h][w];

	if(h==0){
		north=10001;
	}
	else{
		north=map[h-1][w];
	}
	
	if(h==HEIGHT-1){
		south=10001;
	}
	else{
		south=map[h+1][w];
	}

	if(w==0){
		west=10001;
	}
	else{
		west=map[h][w-1];
	}
	
	if(w==WIDTH-1){
		east=10001;
	}
	else{
		east=map[h][w+1];
	}

	min=10001;

	//printf("North: %d, South: %d, East: %d, West: %d\n", north, south, east, west);

	//determine which way to flow
	if(min>=south){
		direction=SOUTH;
		min=south;
	}
	if(min>=east){
		direction=EAST;
		min=east;
	}
	if(min>=west){
		direction=WEST;
		min=west;
	}
	if(min>=north){
		direction=NORTH;
		min=north;
	}

	if(direction==NORTH){
		return endPoint(h-1,w);
	}
	else if(direction==SOUTH){
		return endPoint(h+1,w);
	}
	else if(direction==EAST){
		return endPoint(h,w+1);
	}
	else if(direction==WEST){
		return endPoint(h,w-1);
	}

	printf("it shouldn't be come\n");
	return 0;
}