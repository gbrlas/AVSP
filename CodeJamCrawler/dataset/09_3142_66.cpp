#include <algorithm>
#include <iostream>

#define D(x)

using namespace std;

char result[100][100];
int altitudes[100][100];
int numSet;
int H, W;

typedef struct {
  int row;
  int col;
} coord;

void findFlows(char basin, int startRow, int startCol);

coord findLowestNeighbor(int startRow, int startCol) {
  // Find the lowest neighbor of the square we are on:
  // with correct tie-breaking
  int lowestNeighbor = altitudes[startRow][startCol];
  int lowestRow = startRow;
  int lowestCol = startCol;
  if (startRow > 0) {
    // Check square above
    if (altitudes[startRow - 1][startCol] < lowestNeighbor) {
      lowestNeighbor = altitudes[startRow - 1][startCol];
      lowestRow = startRow - 1;
      lowestCol = startCol;
    }
  }
  if (startCol > 0) {
    // Check square to left
    if (altitudes[startRow][startCol - 1] < lowestNeighbor) {
      lowestNeighbor = altitudes[startRow][startCol - 1];
      lowestRow = startRow;
      lowestCol = startCol - 1;
    }
  }

  if (startCol < W - 1) {
    // Check square to right
    if (altitudes[startRow][startCol + 1] < lowestNeighbor) {
      lowestNeighbor = altitudes[startRow][startCol + 1];
      lowestRow = startRow;
      lowestCol = startCol + 1;
    }
  }

  if (startRow < H - 1) {
    // Check square below
    if (altitudes[startRow + 1][startCol] < lowestNeighbor) {
      lowestNeighbor = altitudes[startRow + 1][startCol];
      lowestRow = startRow + 1;
      lowestCol = startCol;
    }
  }

  coord result;
  result.row = lowestRow;
  result.col = lowestCol;
  return result;
}

void findInwardFlows(char basin, int startRow, int startCol) {
  D(cerr << "Finding inward flow to " << startRow << ", " << startCol << endl);
  if (startRow > 0) {
    // Check square above
    coord lowestNeighbor = findLowestNeighbor(startRow - 1, startCol);
    D(cerr << "Top flows to " << lowestNeighbor.row << ", " << lowestNeighbor.col << " (" << result[startRow - 1][startCol] << ")" << endl);
    // If I am the lowest neighbor, mark that cell if not already marked, and find its inward flows.
    if (lowestNeighbor.row == startRow && lowestNeighbor.col == startCol && result[startRow - 1][startCol] == '-') {
      numSet++;
      result[startRow - 1][startCol] = basin;
      D(cerr << startRow << ", " << startCol << " had inward flow from " << startRow - 1 << ", " << startCol << endl);
      findInwardFlows(basin, startRow - 1, startCol);
    }
  }
  if (startCol > 0) {
    // Check square to left
    coord lowestNeighbor = findLowestNeighbor(startRow, startCol - 1);
    D(cerr << "Left flows to " << lowestNeighbor.row << ", " << lowestNeighbor.col << " (" << result[startRow][startCol - 1] << ")" << endl);
    // If I am the lowest neighbor, mark that cell if not already marked, and find its inward flows.
    if (lowestNeighbor.row == startRow && lowestNeighbor.col == startCol && result[startRow][startCol - 1] == '-') {
      numSet++;
      result[startRow][startCol - 1] = basin;
      D(cerr << startRow << ", " << startCol << " had inward flow from " << startRow << ", " << startCol - 1 << endl);
      findInwardFlows(basin, startRow, startCol - 1);
    }
  }
  if (startRow < H - 1) {
    // Check square below
    coord lowestNeighbor = findLowestNeighbor(startRow + 1, startCol);
    D(cerr << "Bottom flows to " << lowestNeighbor.row << ", " << lowestNeighbor.col << " (" << result[startRow + 1][startCol] << ")" << endl);
    // If I am the lowest neighbor, mark that cell if not already marked, and find its inward flows.
    if (lowestNeighbor.row == startRow && lowestNeighbor.col == startCol && result[startRow + 1][startCol] == '-') {
      numSet++;
      result[startRow + 1][startCol] = basin;
      D(cerr << startRow << ", " << startCol << " had inward flow from " << startRow + 1 << ", " << startCol << endl);
      findInwardFlows(basin, startRow + 1, startCol);
    }
  }

  if (startCol < W - 1) {
    // Check square to right
    coord lowestNeighbor = findLowestNeighbor(startRow, startCol + 1);
    D(cerr << "Right flows to " << lowestNeighbor.row << ", " << lowestNeighbor.col << " (" << result[startRow][startCol + 1] << ")" << endl);
    // If I am the lowest neighbor, mark that cell if not already marked, and find its inward flows.
    if (lowestNeighbor.row == startRow && lowestNeighbor.col == startCol && result[startRow][startCol + 1] == '-') {
      numSet++;
      result[startRow][startCol + 1] = basin;
      D(cerr << startRow << ", " << startCol << " had inward flow from " << startRow << ", " << startCol + 1 << endl);
      findInwardFlows(basin, startRow, startCol + 1);
    }
  }
}


void findOutwardFlows(char basin, int startRow, int startCol) {
  //  D(cerr << "Finding outflow out of " << startRow << ", " << startCol << endl);
  // Find the lowest neighbor of the square we are on:
  coord lowestNeighbor = findLowestNeighbor(startRow, startCol);

  if ((lowestNeighbor.row != startRow || lowestNeighbor.col != startCol) && altitudes[startRow][startCol] > altitudes[lowestNeighbor.row][lowestNeighbor.col]) {
    //D(cerr << "Sending flow of " << basin << " to my lowest neighbor, " << lowestNeighbor.row << ", " << lowestNeighbor.col << endl);
    // we put our flow out to this cell, if it has not been previously marked;
    if (result[lowestNeighbor.row][lowestNeighbor.col] == '-') {
      findFlows(basin, lowestNeighbor.row, lowestNeighbor.col);
    }
    // otherwise, we don't have to do anything, since the cell has been marked, it has been fully processed.
  }

}

// We start a basin of letter basin at space startRow x startCol.
// We find every square that flows into or out of that basin, remembering to increment numSet
void findFlows(char basin, int startRow, int startCol) {
  result[startRow][startCol] = basin;
  numSet++;

  findOutwardFlows(basin, startRow, startCol);
  findInwardFlows(basin, startRow, startCol);
}


int main() {

  int T;
  cin >> T;
  for (int casei = 1; casei <= T; casei++) {
    D(cerr << "CASE " << casei << endl);
    cin >> H >> W;
    
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
	cin >> altitudes[i][j];
      }
    }
    
    for (int i = 0; i < H; i++) {
      fill(result[i], result[i] + W + 1, '-'); // Set an initial dummy value;
    }
    
    int lastInitialRow, lastInitialCol; // The last character that started a flow. indicates where a letter "starts" lexicographically.
    lastInitialRow = lastInitialCol = 0;
    numSet = 0;
    char lastUsed = 'a';
    findFlows('a', lastInitialRow, lastInitialCol);
    while (numSet < H*W) {
      lastUsed++;
      bool done = false;
      // Find the next legal starting points.
      for (int i = lastInitialCol + 1; i < W && !done; i++) {
	if (result[lastInitialRow][i] == '-') {
	  done = true;
	  lastInitialCol = i;
	}
      }
      for (int i = lastInitialRow + 1; i < H && !done; i++) {
	for (int j = 0; j < W && !done; j++) {
	  if (result[i][j] == '-') {
	    done = true;
	    lastInitialRow = i;
	    lastInitialCol = j;
	  }
	}
      }
      if (!done) { // Something went wrong and we couldn't find the next starting place even though we aren't done.
	cerr << "SOMETHING IS HORRIBLY WRONG! Couldn't find starting point!" << endl;
	// We just pretend we're done so we get a printout.
	numSet = H*W;
      } else {
	findFlows(lastUsed, lastInitialRow, lastInitialCol);
      }
    }


    cout << "Case #" << casei << ":" << endl;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
	cout << result[i][j] << " ";
      }
      cout << endl;
    }

  }
  return 0;
}
