#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main() {

  // Opening an input and output file.
  ifstream infile; 
  ofstream outfile;
  infile.open("input.in", ios::out);
  outfile.open("output.out", ios::in | ios::trunc); 

  // Reading the test cases value;
  char sTestCases[3], ch;
  int iTestCases, cTestCase = 1, i=0;
  
  while((ch = infile.get()) != '\n') sTestCases[i++] = ch;
  sTestCases[i] = '\0';
  iTestCases = atoi(sTestCases); 

  // Language Mapping array.
  char lMap[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 
                   'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
  char uMap[26] = {'Y', 'H', 'E', 'S', 'O', 'C', 'V', 'X', 'D', 'U', 'I', 'G', 'L', 
                   'B', 'K', 'R', 'Z', 'T', 'N', 'W', 'J', 'P', 'F', 'M', 'A', 'Q'};

  // Running the test cases.
  char cStr[100], gStr[100];
  int strLen;

  while(iTestCases--) {
    // Getting current string from input file.
    strLen = 0;
    while((ch = infile.get()) != '\n') {
      cStr[strLen++] = ch; 
    }
   
    // Converting the string into googlerese language. 
    for(i = 0; i < strLen; i++) {
      // Space char.
      if(isspace(cStr[i])) {
        gStr[i] = cStr[i]; 
      }
      else if(islower(cStr[i])) {
        gStr[i] = lMap[cStr[i] - 97];
      }
      else {
        gStr[i] = uMap[cStr[i] - 65];
      }
    }

    // putting the string in output file. 
    outfile << "Case #" << cTestCase << ": ";
    for(i = 0; i < strLen; i++) outfile.put(gStr[i]);
    if(iTestCases > 0)outfile << "\n";

    cTestCase++;
    outfile.flush();
  }

  // Closing the files.
  infile.close();
  outfile.close();
  return 0;
}
