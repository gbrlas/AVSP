#include <iostream>
#include <fstream>
using namespace std;

const int READ_SIZE = 10000; // 100MB
const int WRITE_SIZE = 1000; // 1MB

class ProblemSolver
{
private:
    int testCaseNumber;
    double C;
    double F;
    double X;
    char solutionLine[WRITE_SIZE];
public:
    void initializeValues(int t, double c, double f, double x)
    {
        this->testCaseNumber = t;
        this->C = c;
        this->F = f;
        this->X = x;
    }
    void printValues()
    {
        // not printing with precision
        cout << "cost of farm: " << this->C << endl;
        cout << "increase in cps: " << this->F << endl;
        cout << "goal:" << this->X << endl;
    }
    char *printSolution()
    {
        return this->solutionLine;
    }
    void solve()
    {
        double secondsToGoal, secondsToFarm, cookiesAsec=2,
            secondsAfterFarmToGoal, minimalTime=0;
        while(true) // works if goal achievable
        {
            secondsToGoal = this->X / cookiesAsec;
            secondsToFarm = this->C / cookiesAsec;
            secondsAfterFarmToGoal = secondsToFarm+(this->X/(cookiesAsec+this->F));
            if(secondsToGoal < secondsAfterFarmToGoal)
            {
                minimalTime += secondsToGoal;
                sprintf(this->solutionLine, "Case #%d: %.7f", this->testCaseNumber, minimalTime);
                break;
            }
            else
            {
                minimalTime += secondsToFarm;
                cookiesAsec += this->F;
            }
        }
    }
};

void readFile(char *fileName, char fileContents[][READ_SIZE]);
void writeFile(char *fileName, char fileContents[][WRITE_SIZE], int lines);
void printFileContents(char fileContents[][READ_SIZE], int lines);
int parseContents(char fileContents[][READ_SIZE], char printContents[][WRITE_SIZE]);

int main()
{
    static char input[READ_SIZE][READ_SIZE]; // looks like the input file wont be larger than what can fit in RAM
    char output[WRITE_SIZE][WRITE_SIZE];
    int testCases;

    readFile("B-large.in", input);
    //printFileContents(input, 10);
    testCases = parseContents(input, output);
    cout << "there were " << testCases << " test cases" << endl;
    writeFile("output.txt", output, testCases);
    return 0;
}

void readFile(char *fileName, char fileContents[][READ_SIZE])
{
    ifstream inFile(fileName);
	if(inFile.fail())
	{
		cout << "could not load file" << endl;
	}

	for(int i = 0; !inFile.eof(); i++)
	{
		inFile.getline(fileContents[i],READ_SIZE);
	}
	inFile.close();
}

void writeFile(char *fileName, char fileContents[][WRITE_SIZE], int lines)
{
    ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for(int i = 0; i < lines; i++)
        {
            outFile.write(fileContents[i], strlen(fileContents[i]));
            outFile << "\n";
        }
        outFile.close();
    }
    else
    {
        cout << "could not save file" << endl;
    }
}

void printFileContents(char fileContents[][READ_SIZE], int lines)
{
    for(int i = 0; i < lines; i++)
    {
        cout << fileContents[i] << endl;
    }
}

int parseContents(char fileContents[][READ_SIZE], char printContents[][WRITE_SIZE])
{
    int testCases = atoi(fileContents[0]);
    ProblemSolver *ps = new ProblemSolver[testCases];

    for(int i = 0; i < testCases; i++)
    {
        double cookieValues[3];
        int ci = 0, numberIndex = 0;
        char number[1000];
        for(int j = 0; j < strlen( fileContents[i+1] ) + 1; j++)
        {
            if(fileContents[i+1][j] == ' ' || fileContents[i+1][j] == NULL)
            {
                number[numberIndex] = NULL;
                cookieValues[ci] = atof(number);
                strcpy(number, "");
                ci++;
                numberIndex = 0;
            }
            else
            {
                number[numberIndex] = fileContents[i+1][j];
                numberIndex++;
            }            
        }

        // code check
        /*
        char p1[50], p2[50], p3[50];
        sprintf(p1, "%.7f", cookieValues[0]);
        sprintf(p2, "%.7f", cookieValues[1]);
        sprintf(p3, "%.7f", cookieValues[2]);
        cout << p1 << " " << p2 << " " << p3 << " " << endl;
        */
        
        ps[i].initializeValues(i+1, cookieValues[0], cookieValues[1], cookieValues[2]);
        //ps[i].printValues();
        
        ps[i].solve();
        //cout << ps[i].printSolution() << endl;
        strcpy(printContents[i], ps[i].printSolution());
        
    }
    return testCases;
}