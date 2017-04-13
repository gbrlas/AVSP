#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

void file_read(stringstream& str, ifstream& file_ptr){
  string line;
  getline(file_ptr, line);
  str.clear();
  str.str(line);
}

void file_write(ofstream& file_ptr, int case_num, const string& str){
  if(case_num != 1)
    file_ptr<<"\n";
  file_ptr<<"Case #"<<case_num<<": "<<str;
}

void get_file_names(string& outfile, string& infile, int argc, char* argv[]){
  outfile = "output.txt";
  infile = "input.txt";
  if(argc > 1)
    infile = argv[1];
  if(argc > 2)
    outfile = argv[2];
}
