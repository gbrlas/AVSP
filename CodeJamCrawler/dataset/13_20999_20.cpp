#include <iostream>

int colVict[2][4]; // 4 ways to win on a column
int rowVict[2][4]; // 4 ways to win on a row
int diagVict[2][2]; // 2 ways to win on a diagonal
int numPeriods = 0;

void clear() {
   diagVict[0][0] = 0;
   diagVict[0][1] = 0;
   diagVict[1][0] = 0;
   diagVict[1][1] = 0;
   for(int i=0; i<2; i++) {
      for (int j=0; j<4; j++) {
	 colVict[i][j] = 0;
	 rowVict[i][j] = 0;
      }
   }
   numPeriods = 0;
}

int main() {
   int numTests = 0;
   std::cin >> numTests;

   for (int t=0; t<numTests; t++) {
      std::cout << "Case #" << t+1 <<": ";
      
      clear();
            
      for (int i=0; i<4; i++) {
	 std::string line;
	 std::cin >> line;
	
	 for (int j=0; j<4; j++) {
	    if (line[j] == 'T') {
	       
	       colVict[0][j]++;
	       rowVict[0][i]++;
	       if (i==j)
		  diagVict[0][0]++;
	       if (i+j==3)
		  diagVict[0][1]++;

	       colVict[1][j]++;
	       rowVict[1][i]++;
	       if (i==j)
		  diagVict[1][0]++; 
	       if (i+j==3)
		  diagVict[1][1]++;
	       
	    } else if (line[j] == 'X' ) {
	       
	       colVict[0][j]++;
	       rowVict[0][i]++;
	       if (i==j)
		  diagVict[0][0]++;
	       if (i+j==3)
		  diagVict[0][1]++;
	       	       
	    } else if (line[j] == 'O') {
	       
	       colVict[1][j]++;
	       rowVict[1][i]++;
	       if (i==j)
		  diagVict[1][0]++; 
	       if (i+j==3)
		  diagVict[1][1]++;
	       
	    } else {
	       numPeriods++;
	    }
	 }
      }
      bool done = false;
      for (int i=0; i<4; i++) {
	 if (colVict[0][i]==4 || rowVict[0][i]==4 || diagVict[0][0]==4 || diagVict[0][1]==4) {
	    std::cout << "X won" << std::endl;
	    done = true;
	    i=5;
	 } else if (colVict[1][i]==4 || rowVict[1][i]==4 || diagVict[1][0]==4 || diagVict[1][1]==4) {
	    std::cout << "O won" << std::endl;
	    done = true;
	    i=5;
	 } else if (numPeriods == 0) {
	    std::cout << "Draw" << std::endl;
	    done = true;
	    i=5;
	 }
      }
      if (!done) {
	 std::cout << "Game has not completed" << std::endl;
      }
   }
   return 0;
}

