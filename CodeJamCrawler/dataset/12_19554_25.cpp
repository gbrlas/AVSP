#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

char adapt(const char th){
    string rt;
    int buf = th;
    switch(buf){
    case 'a':
	rt += 'y';
	break;
    case 'b':
	rt += 'h';
	break;
    case 'c':
	rt += 'e';
	break;
    case 'd':
	rt += 's';
	break;
    case 'e':
	rt += 'o';
	break;
    case 'f':
	rt += 'c';
	break;
    case 'g':
	rt += 'v';
	break;
    case 'h':
	rt += 'x';
	break;
    case 'i':
	rt += 'd';
	break;
    case 'j':
	rt += 'u';
	break;
    case 'k':
	rt += 'i';
	break;
    case 'l':
	rt += 'g';
	break;
    case 'm':
	rt += 'l';
	break;
    case 'n':
	rt += 'b';
	break;
    case 'o':
	rt += 'k';
	break;
    case 'p':
	rt += 'r';
	break;
    case 'q':
	rt += 'z';
	break;
    case 'r':
	rt += 't';
	break;
    case 's' :
	rt += 'n';
	break;
    case 't':
	rt += 'w';
	break;
    case 'u':
	rt += 'j';
	break;
    case 'v':
	rt += 'p';
	break;
    case 'w':
	rt += 'f';
	break;
    case 'x':
	rt += 'm';
	break;
    case 'y':
	rt += 'a';
	break;
    case 'z':
	rt += 'q';
	break;
    case ' ':
	rt += ' ';
	break;
    }
    char rtc = rt[0];
    return rtc;
}

void translater(char *input,char *output){
    char tmp = input[0];
    int i = 0;
    bool flg;
    do{
	output[i++] = adapt(tmp);
	tmp = input[i];
	if(isalpha(tmp)){
	    flg = true;
	}else if(tmp == ' '){
	    flg = true;
	}else{
	    flg = false;
	}
    }while(flg);
}
void clear(char *output){
    for(int i=0;i<256;i++){
	output[i] = 0;
    }
}

int main(){
    ifstream ifs("input_a.txt");
    ofstream ofs("output_a.txt");
    char *input = new char[256];
    char *output = new char[256];
    
    ifs.getline(input,256);
    int num_problem = atoi(input);
    int this_problem;
    for(this_problem = 0 ; this_problem < num_problem ; this_problem++){
	ifs.getline(input,256);
	clear(output);
	translater(input,output);
	ofs << "Case #" << this_problem+1 << ": " << output << endl;
    }
    delete[] input;
    delete[] output;
    return 0;
}
