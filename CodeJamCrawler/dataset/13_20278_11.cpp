#include <iostream>
#include <fstream>
#include <inttypes.h>
using namespace std;

int how_many_circles(int64_t, int64_t);

int main(int argc, const char* argv[]){
	int test_num;
  //unsigned long long int r, t;
	string line;
	ifstream input;
	ofstream output;
	output.open("output.txt");
  input.open(argv[1]);
	if(input.is_open()){
		input >> test_num;
		getline(input, line);//\n
    int64_t* r = new int64_t[test_num];
		int64_t* t = new int64_t[test_num];
		for(int i=0; i < test_num; i++){
      input >> r[i] >> t[i];
			//cout << r[i] << " " << t[i] << endl;
		}

		for(int i=0; i < test_num; i++){
			output << "Case #" << i+1 << ": " << how_many_circles(r[i], t[i]) << endl;
		}
  }
}

int how_many_circles(int64_t r, int64_t t){
  int c = 0;
	while(t > 0){
		t = t- (2*r + 1);
  	if(t >= 0){ 
	  	c++;
			r += 2;
	  }
	}

  return c;
}
