#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int file_read(ifstream& file_ptr,const char* file_name){
  int N;
  file_ptr.open(file_name);
  if(file_ptr.is_open()){
    file_ptr>>N;
    string temp;
    getline(file_ptr,temp);
    return N;
  }
  else
    return 0;
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
