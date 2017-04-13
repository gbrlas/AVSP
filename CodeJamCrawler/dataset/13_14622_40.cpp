#include "common.h"

bool isPalindrome(unsigned long i){
  if(i/10 == 0)
    return true;
  else{
    stringstream str;
    str<<i;
    string num = str.str();
    int length = num.size();
    for(int i = 0; i < length/2; i++)
      if(num[i] != num[length - i - 1])
	return false;
    return true;
  }
}

int main(int argc,char** argv){
  string infile;
  string outfile;
  ifstream ptr;
  ofstream optr;
  get_file_names(outfile,infile,argc,argv);
  int N;
  if(N = file_read(ptr,infile.c_str())){
    optr.open(outfile.c_str());
    for(int n = 0; n < N; n++){
      unsigned long result = 0;      
      unsigned long A,B;
      unsigned long a,b;
      ptr>>A>>B;
      a = sqrt(A);
      b = sqrt(B);
      if(A > a*a)
	a++;
      for(unsigned long i = a; i <= b; i++)
	if(isPalindrome(i))
	  if(isPalindrome(i*i))
	    result++;
      stringstream str;
      str<<result;
      cout<<"\n"<<str.str();
      file_write(optr,n+1,str.str());
    }
  }  
  cout<<"\n";
  return 0;
}
