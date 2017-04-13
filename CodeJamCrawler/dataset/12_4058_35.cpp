#include<iostream>
#include<fstream>
using namespace std;

int n, s, p, totalScore[100];

int bestResultGoogler() {

  int i, reminder, cnum, count = 0;
  for(i = 0; i < n; i++) {
    cnum = totalScore[i];
    reminder = cnum % 3; 
    // Case 1.
    if(reminder == 0) {
      if((cnum / 3) >= p) count++;
      else if(cnum > 0 && ((cnum / 3) + 1) >= p && s > 0) {
        count++; s--;
      }
    }
    // Case 2.
    else if(reminder == 1) {
      if(((cnum+2) / 3) >= p) count++; 
    }
    // Case 3.
    else {
      if(((cnum+1) / 3) >= p) count++;
      else if(((cnum+4) / 3) >= p && s > 0) {
        count++; s--;
      }
    }
  }
  return count;
}

int main() {

  // Opening input and output files.
  ifstream infile;
  ofstream outfile;
  infile.open("input.in", ios::in);
  outfile.open("output.out", ios::out | ios::trunc);

  // Getting number of testcases.
  char cBuff[4], ch;
  int iTestCases, cTestCase = 1, i = 0;
  while((ch = infile.get()) != '\n') cBuff[i++] = ch;
  cBuff[i] = '\0';
  iTestCases = atoi(cBuff);
  
  // Running test cases.
  int pos, maxValue;
  while(iTestCases--) {
    pos = 0;
    // Getting N, S, P and integers. 
    i = 0;
    while((ch = infile.get()) != ' ') cBuff[i++] = ch;
    cBuff[i] = '\0';
    n = atoi(cBuff); 

    i = 0;
    while((ch = infile.get()) != ' ') cBuff[i++] = ch;
    cBuff[i] = '\0';
    s = atoi(cBuff);

    i = 0;
    while((ch = infile.get()) != ' ') cBuff[i++] = ch;
    cBuff[i] = '\0';
    p = atoi(cBuff);
  
    while(!infile.eof() && ch != '\n') {
      i = 0;
      while(!infile.eof() && (ch = infile.get()) != ' ' && ch != '\n') cBuff[i++] = ch;
      cBuff[i] = '\0';
      totalScore[pos++] = atoi(cBuff);
    } 

    // Logic.
    maxValue = bestResultGoogler();
    //cout << maxValue << endl;

    // Putting value in output file.
    outfile << "Case #" << cTestCase << ": " << maxValue;
    if(iTestCases > 0) outfile << "\n";

    cTestCase++;
    outfile.flush(); 
  }
  
  // Closing input files.
  infile.close();
  outfile.close();
  return 0;
}
