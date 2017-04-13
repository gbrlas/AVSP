#include "common.h"

int getStatus(const string& test){
  int freq[3];
  for(int i = 0; i < 3; i++)
    freq[i] = 0;
  for(int i = 0; i < 4; i++){
    if(test[i] == '.')
      return 2;
    if(test[i] == 'X')
      freq[0] += 1;
    if(test[i] == 'O')
      freq[1] += 1;
    if(test[i] == 'T')
      freq[2] += 1;
  }
  if(freq[2] > 1)
    return 3;
  if((freq[0] + freq[2]) == 4)
    return 0;
  if((freq[1] + freq[2]) == 4)
    return 1;
  return 3;
}

int main(int argc,char** argv){
  string infile;
  string outfile;
  ifstream ptr;
  ofstream optr;
  get_file_names(outfile,infile,argc,argv);
  int N;
  string code[4];
  code[0] = "X won";
  code[1] = "O won";
  code[2] = "Game has not completed";
  code[3] = "Draw";
  if(N = file_read(ptr,infile.c_str())){
    optr.open(outfile.c_str());
    for(int n = 0; n < N; n++){
      if(n != 0){
	string test;
	getline(ptr,test);
      }
      string test[10];
      for(int l = 0; l < 4; l++)
	getline(ptr,test[l]);
      for(int i = 0; i < 4; i++){
	for(int l = 0; l < 4; l++)
	  test[i + 4] += test[l][i];
	test[8] += test[i][i];
	test[9] += test[i][3-i];
      }
      // if(n == N-1)
      // 	for(int i = 0; i < 10; i++)
      // 	  cout<<"\n"<<test[i];
      int status = 4;
      for(int i = 0; i < 10; i++){
	int temp = getStatus(test[i]);
	if(status > temp)
	  status = temp;
	if(status < 2)
	  break;
      }
      cout<<"\n"<<code[status];
      file_write(optr,n+1,code[status]);
    }
  }  
  cout<<"\n";
  return 0;
}
