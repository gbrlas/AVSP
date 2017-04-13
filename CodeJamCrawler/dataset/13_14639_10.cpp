#include "common.h"
#include <algorithm>

class iter{
public:
  unsigned int i;
  unsigned long temp_S;
  iter():i(0),temp_S(0){
  }
};

iter getInsertions(const unsigned long& A, const unsigned long& S){
  iter temp;
  temp.temp_S = A;
  if(A > 1){
    int div = (S - 1)/(A - 1);
    unsigned long int prod = 1;
    while(prod <= div){
      prod = prod*2;
      temp.i += 1;
    }
    temp.temp_S = S + prod*A - prod + 1;
    return temp;
  }else{
    temp.i = 100;
    temp.temp_S = A;
  }
}

int main(int argc, char** argv){  
  string infile;
  string outfile;
  ifstream ptr;
  ofstream optr;
  get_file_names(outfile,infile,argc,argv);
  int T;
  if(T = file_read(ptr,infile.c_str())){
    string test;
    optr.open(outfile.c_str());
    for(int i = 0; i < T; i++){
      unsigned long A, N;
      vector<unsigned long> arr;
      ptr>>A>>N;
      arr.resize(N);
      for(int n = 0; n < N; n++)
	ptr>>arr[n];
      sort(arr.begin(), arr.end());
      unsigned int num = 0;
      for(int n = 0; n < N; n++){
	iter temp;
	temp = getInsertions(A,arr[n]);
	if(temp.i >= N - n){
	  num += N - n;
	  break;
	}
	A = temp.temp_S;
	num += temp.i;
      }
      stringstream test;
      test<<num;
      cout<<test.str()<<"\n";
      file_write(optr,i+1,test.str());      
    }
  }
}
