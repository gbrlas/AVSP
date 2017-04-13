#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int fileRead(string filename);
long solve(long a, long b);
int isPalindrome (long x);


int main(int argc, char **argv)
{

  if (argc > 1)
    fileRead(argv[1]);
 
  return 0;
}

long solve(long a, long b){

  long res = 0, n = pow(10,50);
  long c, d;
 
  c = ceil(sqrt(a));
  d = floor(sqrt(b));
  
  for (long i=c;i<(d+1);i++){
    if (isPalindrome(i)){
      if (isPalindrome(pow(i,2)))
	res++;
    }      
  }

  return res;
  
}

int isPalindrome (long x){
  long rev = 0;
  long y = x;
  long dig;
  while (y > 0){
    rev = rev * 10 + y % 10;
    y = y / 10;
  }
   return (x == rev);
}


int fileRead(string filename){
  
  ifstream ifile(filename.c_str());

  if (ifile){
    long lines, a, b;
    
    ifile >> lines >> ws;   
    
    for (int j=0;j<lines;j++){
      ifile >> a >> b >> ws;
      cout << "Case #" << (j+1) << ": "<< solve(a, b) << endl;      
    }

    ifile.close();

  } else {
    cerr << "Can not open file " << filename << " !"<< endl;
    return 0;
  }

  return 1;

}


