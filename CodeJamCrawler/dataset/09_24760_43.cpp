#include <iostream>

using namespace std;

string target = "welcome to code jam";

unsigned long long search(unsigned long long pos, const string& sample, unsigned long long startindex) {
    if(pos >= target.length())
	return 1;


    unsigned long long counter = 0;
    
    for(unsigned long long i = startindex; i < sample.length(); i++)
	if(sample[i] == target[pos]) {
	    counter += search(pos+1, sample, i+1);
	}
	
    return counter;
}

int main(int argc, char *argv[]) {    
    printf("%04llu\n", search(0, string(argv[1]), 0) % 10000);
    
    return EXIT_SUCCESS;
}
