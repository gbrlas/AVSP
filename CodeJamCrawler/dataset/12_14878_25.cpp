#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream inputFile;
ofstream outputFile;

void OpenInputFile(char* filename);
void OpenOutputFile(char* filename);
void FindSolution(int caseNum, int minNumber, int maxNumber);

int main()
{
    OpenInputFile("C-small-attempt0.in");
    OpenOutputFile("output.out");

    if (inputFile.is_open())
    {
       string inputCaseNum;
       getline(inputFile, inputCaseNum);
       int caseNum = atoi(inputCaseNum.c_str());
       
       for (int i = 0; i < caseNum; ++i)
       {
           int minNumber, maxNumber;
           inputFile >> minNumber;
           inputFile >> maxNumber;
           if (maxNumber >= minNumber)
           {
              FindSolution(i, minNumber, maxNumber);
           }
       }
    }
    else
    {
        cout << "Failed to open input file.\n";
    }
    
    inputFile.close();
    outputFile.close();
    
    cin.get();
    cin.get();
    return 0;
}

void OpenInputFile(char* filename)
{
     inputFile.open(filename);
}

void OpenOutputFile(char* filename)
{
     outputFile.open(filename);
}

void FindSolution(int caseNum, int minNumber, int maxNumber)
{
     int totalAns = 0;
     string lastM = "";
     for (int i = minNumber; i < maxNumber; ++i)
     {
         char intInStr[7];
         itoa(i, intInStr, 10);
         string str(intInStr);
         for (int j = 1; j < str.size(); ++j)
         {
             string pair;
             pair.append(str.substr(j, str.size() - j));
             pair.append(str.substr(0, j));
             int pairInInt = atoi(pair.c_str());
             if (pairInInt > i && pairInInt <= maxNumber && pairInInt >= minNumber)
             {
                if (pair != lastM)
                {
                   ++totalAns;
                }
                lastM = pair;
             }
         }
     }
     outputFile << "Case #" << caseNum + 1 << ": " << totalAns << endl;
}
