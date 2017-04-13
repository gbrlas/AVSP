#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

const int READ_SIZE = 10000; // 100MB
const int WRITE_SIZE = 1000; // 1MB

class ProblemSolver
{
private:
    int testCaseNumber;
    int rows;
    int cols;
    int mines;
    unsigned int permuteCount;
    char *mineField;
    char **mineMatrix;
    char solutionLine[WRITE_SIZE];
public:
    void initializeValues(int t, int r, int c, int m)
    {
        this->testCaseNumber = t;
        this->rows = r;
        this->cols = c;
        this->mines = m;
        this->permuteCount = 0;
    }
    void printValues()
    {
        // print privates
    }
    char *printSolution()
    {
        return this->solutionLine;
    }
    void fillMineFieldTest()
    {
        this->mineField = new char[this->rows*this->cols];
        // test with example on problem description, a 5x10 with 7 mines clicked at 2,2
        strcpy(this->mineField, "*..*...**.....*..........*............*...........");
    }
    void fillMineField()
    {
        int area = this->rows*this->cols;
        this->mineField = new char[area];
        for(int i = 0; i < area; i++)
        {
            mineField[i] = '.';
        }
        for(int i = 0; i < this->mines; i++)
        {
            mineField[i] = '*';
        }
    }
    void printMineField()
    {
        int area = this->rows*this->cols;
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = i*this->cols; j < (area/this->rows)+(i*this->cols); j++)
            {
                cout << this->mineField[j];
            }
            cout << endl;
        }
    }
    void printMineMatrix()
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->cols; j++)
            {
                cout << this->mineMatrix[i][j];
            }
            cout << endl;
        }
    }
    void processMineField(int clickRow, int clickCol)
    {
        // declare a 2D array now
        this->mineMatrix = new char*[this->rows];
        for(int i = 0; i < this->rows; i++)
        {
            mineMatrix[i] = new char[this->cols];
        }

        // fill it with the field
        int area = this->rows*this->cols;
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = i*this->cols, k = 0; j < (area/this->rows)+(i*this->cols), k < this->cols; j++, k++)
            {
                mineMatrix[i][k] = this->mineField[j];
            }
        }

        // code check
        // printMineMatrix(); // print 2D array to check
        // cout << endl;
        
        processMineNeighbors(clickRow, clickCol);
    }
    void processMineNeighbors(int selectedRow, int selectedCol)
    {
        // if the selection is a bomb
        if(mineMatrix[selectedRow][selectedCol] == '*')
        {
            return; // loser
        }

        // do check the perimeter

        // first countNeighbors if they haven't already been counted
        int bombs;
        if(mineMatrix[selectedRow][selectedCol] == '.')
        {
            bombs = countMineNeighbors(selectedRow, selectedCol);
        }
        // dont process again if they are counted
        else
        {
            return;
        }

        // if there's no bombs process the neighbor cells
        if(bombs == 0)
        {
            for(int i = selectedRow-1; i <= selectedRow+1; i++)
            {
                for(int j = selectedCol-1; j <= selectedCol+1; j++)
                {
                    if(j < 0 || j > this->cols-1)
                    {
                        continue;
                    }
                    if(i < 0 || i > this->rows-1)
                    {
                        continue;
                    }
                    if(i == selectedRow && j == selectedCol)
				        continue;

                    this->processMineNeighbors(i,j);
                }
            }
        }
    }
    int countMineNeighbors(int selectedRow, int selectedCol)
    {
        int bombs = 0;
        for(int i = selectedRow-1; i <= selectedRow+1; i++)
        {
            for(int j = selectedCol-1; j <= selectedCol+1; j++)
            {
                if(j < 0 || j > this->cols-1)
                {
                    continue;
                }
                if(i < 0 || i > this->rows-1)
                {
                    continue;
                }
                if(i == selectedRow && j == selectedCol)
				    continue;

			    if(mineMatrix[i][j] == '*')
				    bombs++;
            }
        }

        // mark the number of bombs there
        mineMatrix[selectedRow][selectedCol] = bombs+48;

        return bombs;
    }
    void solve()
    {
        int area = this->rows*this->cols;
        fillMineField();
        do
        {
            //printMineField();
            for(int i = 0; i < this->rows; i++)
            {
                for(int j = 0; j < this->cols; j++)
                {
                    // process field at every possible click and check if it was a perfect win
                    processMineField(i,j);
                    if(checkSolution())
                    {
                        // it was a perfect win so format the output properly
                        for(int i = 0; i < this->rows; i++)
                        {
                            for(int j = 0; j < this->cols; j++)
                            {
                                if(this->mineMatrix[i][j] != '*')
                                {
                                    this->mineMatrix[i][j] = '.';
                                }
                            }
                        }
                        this->mineMatrix[i][j] = 'c';
                        //printMineMatrix();
                        string s = "Case #";
                        char tn[50];
                        sprintf(tn, "%d", this->testCaseNumber);
                        s += tn;
                        s += ":\n";
                        for(int i = 0; i < this->rows; i++) 
                        {
                            for(int j = 0; j < this->cols; j++) 
                            {
                                s += mineMatrix[i][j];
                            }
                            s += "\n";
                        }
                        strcpy(this->solutionLine, s.c_str());
                        //cout << printSolution() << endl;
                        return;
                    }
                    //printMineMatrix();
                }
            }
            //printMineField();
            this->permuteCount++;
            if(permuteCount > 50000) // looks like there will be an overflow
            {
                break;
            }
        } while( next_permutation(this->mineField, this->mineField+area) );

        // there were no combinations for a perfect win
        //cout << "no solution" << endl;
        string s = "Case #";
        char tn[50];
        sprintf(tn, "%d", this->testCaseNumber);
        s += tn;
        s += ":\n";
        s += "Impossible";
        strcpy(this->solutionLine, s.c_str());
        //cout << printSolution() << endl;
    }
    bool checkSolution()
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->cols; j++)
            {
                if(this->mineMatrix[i][j] == '.')
                {
                    return false;
                }
            }
        }
        return true;
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

    //ProblemSolver mineTest;
    //mineTest.initializeValues(1,5,5,7);

    //mineTest.fillMineField();
    //mineTest.printMineField();
    //mineTest.processMineField(4,9);
    //mineTest.printMineMatrix();

    //mineTest.solve();

    readFile("C-small-attempt1.in", input);
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
        int mineValues[3];
        int ci = 0, numberIndex = 0;
        char number[1000];
        for(int j = 0; j < strlen( fileContents[i+1] ) + 1; j++)
        {
            if(fileContents[i+1][j] == ' ' || fileContents[i+1][j] == NULL)
            {
                number[numberIndex] = NULL;
                mineValues[ci] = atoi(number);
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
        sprintf(p1, "%d", mineValues[0]);
        sprintf(p2, "%d", mineValues[1]);
        sprintf(p3, "%d", mineValues[2]);
        cout << p1 << " " << p2 << " " << p3 << " " << endl;
        */
        
        ps[i].initializeValues(i+1, mineValues[0], mineValues[1], mineValues[2]);
        //ps[i].printValues();
        
        ps[i].solve();
        //cout << ps[i].printSolution() << endl;
        strcpy(printContents[i], ps[i].printSolution());

    }
    return testCases;
}