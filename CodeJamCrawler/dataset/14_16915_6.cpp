#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

bool parseInputFile(ifstream& inFile, ofstream& outFile);
bool parseTestCase(ifstream& inFile, ofstream& outFile, int tc);
void commonNumber(vector<int> &v1, vector<int> &v2, int &result);

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
		
		//cout << "Time taken : " << (clock() - clk1) << "ms" << endl;
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
	int row;
	vector<int> v1;
	vector<int> v2;

	int set = 1;

	while (1) {
		inFile >> row;
		int skipLines = row + 1;
		while (skipLines) {
			getline(inFile, line);
			skipLines--;
		}

		stringstream iss(line);
		int num;
		while (iss >> num) {
			if (set == 1)
				v1.push_back(num);
			else
				v2.push_back(num);
		}
		skipLines = 4 - row;
		while (skipLines) {
			getline(inFile, line);
			skipLines--;
		}
		
		// breaking condition
		if (set == 2) {
			break;
		} else {
			set = 2;
		}
	}

	int result = 0;
	commonNumber(v1, v2, result);
	if (result == 0) {
		outFile << "Case #" << tc << ": " << "Volunteer cheated!" << endl;
	} else if (result == -1) {
		outFile << "Case #" << tc << ": " << "Bad magician!" << endl;
	} else {
		outFile << "Case #" << tc << ": " << result << endl;
	}
	return true;
}

//result = 0 ==> Case #3: Volunteer cheated!
//result = 1-16  ==>  Case #1: <answer>
//result = -1 ==>  Case #2: Bad magician!
void commonNumber(vector<int> &v1, vector<int> &v2, int &result)
{
	result = 0;

	for (std::vector<int>::iterator it1 = v1.begin() ; it1 != v1.end(); ++it1) {
		for (std::vector<int>::iterator it2 = v2.begin() ; it2 != v2.end(); ++it2) {
			if (*it1 == *it2) {
				if (result != 0) {
					result = -1;
					return;
				} else {
					result = *it1;
				}
			}
		}
	}
}
