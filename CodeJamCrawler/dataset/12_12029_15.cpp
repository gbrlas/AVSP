#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <time.h>

using namespace std;

//const char* lookuptable = "abcdefghijklmnopqrstuvwxyz";
const char* lookuptable = "yhesocvxduiglbkrztnwjpfmaq";

bool parseInputFile(ifstream& inFile, ofstream& outFile);
bool parseTestCase(ifstream& inFile, ofstream& outFile, int tc);

int main(int argc, char* argv[]) 
{
	time_t t = 0;
	clock_t clk1 = clock();

    ifstream inFile;
    ofstream outFile;

    if (argc != 5) {
        cerr << "Usage is -in <infile> -out <outfile>" << endl ;
        exit(0);
    } else {
        char *inFileName = NULL, *outFileName = NULL;
        for (int i = 1; i < argc; ++i) {
            if(i != argc - 1) {
                if (!strcmp(argv[i], "-in")) {
                    inFileName = argv[++i];
                } else if (!strcmp(argv[i], "-out")) {
                    outFileName = argv[++i];
                } else {
                    cerr << endl << "Not enough or invalid arguments, please try again." << endl;
                    exit(0);
                }
            }
        }
        if(inFileName) {
            inFile.open(inFileName, ios::in);
            if(inFile.is_open()) {
                ;
            } else {
                cerr << "Error: Input file "<< inFileName << " cannot be opened." << endl;
                exit(0);
            }
        } else {
            cerr << "Error: Input file not specified." << endl;
            exit(0);
        }
        if(outFileName) {
            outFile.open(outFileName);
            if(outFile.is_open()) {
                ;
            } else {
                cerr << "Error: Output file "<< outFileName << " cannot be opened." << endl;
                exit(0);
            }
        }else {
            cerr << "Error: Output file not specified." << endl;
            exit(0);
        }

		//parseInputFile(inFile, outFile);
		parseInputFile(inFile, outFile);
		
		cout << "Time taken : " << (clock() - clk1) << "ms" << endl;
        return 0;
    }
}

bool parseInputFile(ifstream& inFile, ofstream& outFile)
{
    int noOfTestCases = 0;
    inFile >> noOfTestCases;
	string str;
	getline(inFile, str);
	
    for(int tc = 1; tc <= noOfTestCases; ++tc) {
		parseTestCase(inFile, outFile, tc);
    }
	return true;
}

bool parseTestCase(ifstream& inFile, ofstream& outFile, int tc)
{
    string line;
	getline(inFile, line);

	const char* str = line.c_str();
	unsigned len = line.length();
	
	string line2;
	const char* prevChar = NULL;
	for(unsigned i = 0; i < len; ++i) {
		if(str[i] == ' ') {
			line2 += " ";
		} else {
			line2 += lookuptable[str[i] - 'a'];
		}
	}

	outFile << "Case #" << tc << ": " << line2 << endl;

	return true;
}

