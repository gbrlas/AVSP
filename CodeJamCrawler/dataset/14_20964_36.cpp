#include <iostream>
#include <fstream>
using namespace std;

const int READ_SIZE = 10000; // 100MB
const int WRITE_SIZE = 1000; // 1MB

class ProblemSolver
{
private:
    int testCaseNumber;
    int firstAnswer;
    int secondAnswer;
    int firstLayout[4][4];
    int secondLayout[4][4];
    char solutionLine[WRITE_SIZE];
public:
    void initializeValues(int t, int f, int s, int (*fl)[4], int (*sl)[4])
    {
        this->testCaseNumber = t;
        this->firstAnswer = f;
        this->secondAnswer = s;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                this->firstLayout[i][j] = fl[i][j];
                this->secondLayout[i][j] = sl[i][j];
            }
        }
    }
    void printValues()
    {
        cout << "first answer: " << this->firstAnswer << endl;
        cout << "second answer: " << this->secondAnswer << endl;

        cout << "first arrangement:" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << this->firstLayout[i][j] << " ";
            }
            cout << endl;
        }

        cout << "second arrangement:" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << this->secondLayout[i][j] << " ";
            }
            cout << endl;
        }
    }
    char *printSolution()
    {
        return this->solutionLine;
    }
    void solve()
    {
        int magicNumber;
        int matchCount=0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(firstLayout[firstAnswer-1][i] == secondLayout[secondAnswer-1][j])
                {
                    magicNumber = firstLayout[firstAnswer-1][i];
                    sprintf(this->solutionLine, "Case #%d: %d", this->testCaseNumber, magicNumber);
                    matchCount++;
                    if(matchCount > 1)
                    {
                        sprintf(this->solutionLine, "Case #%d: Bad magician!", this->testCaseNumber);
                        return;
                    }
                }
            }
        }
        if(matchCount == 0)
        {
            sprintf(this->solutionLine, "Case #%d: Volunteer cheated!", this->testCaseNumber);
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

    readFile("A-small-practice.in", input);
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
        int firstAnswer = atoi(fileContents[10*(i+1)-9]);
        int secondAnswer = atoi(fileContents[10*(i+1)-4]);

        int col = 0, numberIndex = 0;
        char number[10];

        int firstArrangement[4][4];        
        for(int h = 0; h < 4; h++)
        {
            for(int j = 0; j < strlen( fileContents[10*(i+1)-((h-8)*-1)] ) + 1; j++)
            {
                if(fileContents[10*(i+1)-((h-8)*-1)][j] == ' ' || fileContents[10*(i+1)-((h-8)*-1)][j] == NULL)
                {
                    number[numberIndex] = NULL;
                    firstArrangement[h][col] = atoi(number);
                    strcpy(number, "");
                    col++;
                    numberIndex = 0;
                }
                else
                {
                    number[numberIndex] = fileContents[10*(i+1)-((h-8)*-1)][j];
                    numberIndex++;
                }            
            }
            col = 0;
        }

        int secondArrangement[4][4];        
        for(int h = 0; h < 4; h++)
        {
            for(int j = 0; j < strlen( fileContents[10*(i+1)-((h-3)*-1)] ) + 1; j++)
            {
                if(fileContents[10*(i+1)-((h-3)*-1)][j] == ' ' || fileContents[10*(i+1)-((h-3)*-1)][j] == NULL)
                {
                    number[numberIndex] = NULL;
                    secondArrangement[h][col] = atoi(number);
                    strcpy(number, "");
                    col++;
                    numberIndex = 0;
                }
                else
                {
                    number[numberIndex] = fileContents[10*(i+1)-((h-3)*-1)][j];
                    numberIndex++;
                }            
            }
            col = 0;
        }

        // code check
        /*
        cout << "first answer: " << firstAnswer << endl;
        cout << "second answer: " << secondAnswer << endl;

        cout << "first arrangement:" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << firstArrangement[i][j] << " ";
            }
            cout << endl;
        }

        cout << "second arrangement:" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << secondArrangement[i][j] << " ";
            }
            cout << endl;
        }
        */

        ps[i].initializeValues(i+1, firstAnswer, secondAnswer, firstArrangement, secondArrangement);
        ps[i].printValues();
        
        ps[i].solve();
        cout << ps[i].printSolution() << endl;
        strcpy(printContents[i], ps[i].printSolution());
        
    }
    return testCases;
}