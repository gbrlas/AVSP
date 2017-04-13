#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

#define R_SIZE 256

using namespace std;

class Solver{
private:
    int count;
    int lower,upper,keta;
    int second;
    char *char_first,*char_second;
    bool head_check(){
	if((char_first[0] == '0') ||
	   (char_second[0] == '0')){
	    return true;
	}else{
	    return false;
	}
    }
    void clear(){
	for(int i=0;i<keta+1;++i){
	    char_first[i] = '\0';
	    char_second[i] = '\0';
	}
    }
public:
    Solver(){};
    ~Solver(){
	delete[] char_first;
	delete[] char_second;
    }
    void set_data(int low,int up,int kt){
	count = 0;
	lower = low;
	upper = up;
	keta = kt;
	char_first = new char[keta+1];
	char_second = new char[keta+1];
    }
    int answer(){
	for(int i=lower;i<=upper;++i){
	    clear();
	    snprintf(char_first,keta+1,"%d",i);
	    for(int j=1;j<keta;++j){
		for(int k=0;k<keta;++k){
		    char_second[k] = char_first[(k+j)%keta];
		    second = atoi(char_second);
		}
		if(head_check())continue;
		if((second > i) &&
		   (second <= upper)){
		    cout << i << ":" << second << endl;
		    count++;
		}
	    }
	}
	return count;
    }
};

int main(){
    ifstream ifs("input_c.txt");
    char *tmp = new char[R_SIZE];
    ifs.getline(tmp,R_SIZE);
    int num_problem = atoi(tmp);
    int lower,upper,keta;
    Solver *people = new Solver[num_problem]();
    ofstream ofs("output_c.txt");
    for(int i=0;i<num_problem;++i){
	ifs.getline(tmp,R_SIZE);
	lower = atoi(tmp);
	keta = log10(static_cast<double>(lower))+1;
	if(keta == 1){
	    ofs << "Case #" << i+1 <<": 0" << endl;
	    continue;
	}
	upper = atoi(tmp+keta);
	people[i].set_data(lower,upper,keta);
	ofs << "Case #" << i+1 << ": " << people[i].answer() << endl;
    }
    delete[] people;
    return 0;
}
	    
