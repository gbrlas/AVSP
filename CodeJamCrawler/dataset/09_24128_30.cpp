
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100
int width;
int height;

int grid[256][256];
int done[256][256];
int label[256][256];

int samplesize;
int nexti,nextj;
int nextColor='a';


int trav(int i , int j) {

	int lowest=grid[i][j];

	if (done[i][j]==2){
		return 0;
	}

	//printf("now at %d %d\n",i,j);
		

	done[i][j] = 1;

	nexti=i;
	nextj=j;

	//N
	if (i > 0) {
		if (  grid[i-1][j] < lowest && grid[i-1][j] < grid[i][j] ) {
			lowest = grid[i-1][j];
			nexti=i-1;
			nextj=j; 
		}
	}

	//W
	if (j > 0) {
		if ( grid[i][j-1] < lowest && grid[i][j-1] < grid[i][j]  ) {
			lowest = grid[i][j-1];
			nexti=i;
			nextj=j-1; 
		}
	}

	
	//E
	if (j < width-1) {
		if ( grid[i][j+1] < lowest &&  grid[i][j+1] < grid[i][j] ) {
			lowest = grid[i][j+1];
			nexti=i;
			nextj=j+1; 
		}
	}
	
	//S
	if (i < height-1) {
		if ( grid[i+1][j] < lowest &&   grid[i+1][j] < grid[i][j]) {
			lowest = grid[i+1][j];
			nexti=i+1;
			nextj=j; 
		}
	}

	
	
	
	
	
	
	

	if ( nexti==i && nextj==j) {
		//printf("sink!\n");
		colornow(nextColor++);
	} else {
		
		if ( !done[nexti][nextj]) { 
	
			//printf("Now %d at %d %d, moving to %d %d with val %d\n", grid[i][j],i,j,nexti,nextj,grid[nexti][nextj]);
			trav(nexti,nextj);
		} else {
			//printf("meet the drain of %d %d\n",nexti,nextj);
			colornow(label[nexti][nextj]);
			
		}
	}
}

//-----------------
int colornow(int color) {
	int i,j;
	for ( i=0; i < height; i++){
		for ( j=0; j < width ; j++) {
			
			if (done[i][j]==1) {
				label[i][j]=color;
				done[i][j]=2;
			}	
		}
	}
	
	return 0;
}

int disp(){
	int i,j;
	for ( i=0; i < height; i++){
		for ( j=0; j < width ; j++) {
			
			printf("%c ",label[i][j]);
		}
		printf("\n");
	}
}

//--------------------
int solve() {


	int i,j;

	//printf("W: %d, H:%d\n",width,height);
	
	for ( i=0; i < height; i++){
		for ( j=0; j < width ; j++) {
			
			trav(i,j);
			
		}
	}
		
	

	return 0;
}


//-------------------------------
int main(int argc, char *argv[]) {

	int s,i,j;
	
	FILE *fp = fopen(argv[1],"r");
	char buffer[BUF_SIZE];
		
	fscanf(fp, "%d", &samplesize);
	//samplesize= 1;	

	for ( s=0; s< samplesize; s++ ) {
		
		printf("Case #%d: \n",s+1);

		fscanf(fp,"%d %d ", &height, &width);
		nextColor=97;

		for ( i=0; i < height; i++){
			for ( j=0; j < width ; j++) {
			
				grid[i][j] = -1;
				done[i][j] = 0;
				label[i][j] = 0;

				fscanf(fp, "%d", &grid[i][j] );
			}
					
		}

		solve();
		disp();
		//printf("\n");
		/*
		for ( i=0; i < height; i++){
			for ( j=0; j < width ; j++) {
				printf( "%d ", grid[i][j] );
			}
			printf("\n");
					
		}
		*/
		
	}

	fclose(fp);

		
	
	return 0;
}


