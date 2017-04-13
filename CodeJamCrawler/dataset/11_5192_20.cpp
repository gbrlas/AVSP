#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024*1024

int main(int argc, char* argv[])
{

  FILE *in = fopen( argv[1], "r");
  char buf[BUF_SIZE];

  fgets(buf, BUF_SIZE, in);
  int testCase = atoi(buf);

  printf("test case = %d times\n", testCase);

  FILE* out = fopen( "out.txt", "w");
  
  for(int test = 0; test < testCase; ++test)
    {
        int Bplace = 1, Oplace = 1;
	int BrestTime = 0, OrestTime = 0;
	int totalTime = 0;
  
	fgets(buf, BUF_SIZE, in);

	printf("test%d : buf = %s",test, buf);

	char *p = strtok( buf, " /\n");

	while( (p = strtok(NULL, " /\n")) != NULL )
	  {
	    int time;
	    char *q = strtok(NULL, " /\n");
	    int next = atoi(q);
	    if( strcmp( p, "O" ) == 0){
	      time = abs(Oplace - next) - OrestTime + 1;
	      if(time <= 0 ) time = 1;
	      Oplace = next;
	      OrestTime = 0;
	      BrestTime += time;
	    }else if( strcmp( p, "B") == 0){
	      time = abs(Bplace - next) - BrestTime + 1;
	      if(time <= 0 ) time = 1;
	      Bplace = next;
	      BrestTime = 0;
	      OrestTime += time;
	    }else{
	      printf("error in detecting next p = %s\n", p);
	    }

	    totalTime += time;

	  }
	printf( "Case #%d:%d\n", test+1, totalTime);
	fprintf(out, "Case #%d: %d\n", test+1, totalTime);

    }

  fclose(in);
  fclose(out);

  return 0;
}
