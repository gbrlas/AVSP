#define __DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int keyIndex[] = {97, 100, 103, 106, 109, 112, 116, 119};
ifstream inputFile;
ofstream outputFile;

void OpenInputFile(char* filename);
void OpenOutputFile(char* filename);
char KeyPadNumOf(int asciiCode);
void FindSolution(int numCase, string inputStr);

int main()
{
    OpenInputFile("C-large-practice.in");
    OpenOutputFile("output.out");

    if (inputFile.is_open())
    {
       string readInt; int numCase;
       getline(inputFile, readInt);
       numCase = atoi (readInt.c_str());
       
       string temp;
       for (int i = 0; i < numCase; ++i)
       {
           getline(inputFile, temp);
           FindSolution(i, temp);
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

char KeyPadNumOf(int asciiCode)
{
    char returnValue = '.';
    switch (asciiCode)
    {      
       case 32:
            returnValue = '0';
            break;
       case 97 ... 99: 
            returnValue = '2';
            break;
       case 100 ... 102:
            returnValue = '3';
            break;
       case 103 ... 105:
            returnValue = '4';
            break;
       case 106 ... 108:
            returnValue = '5';
            break;
       case 109 ... 111:
            returnValue = '6';
            break;
       case 112 ... 115:
            returnValue = '7';
            break;
       case 116 ... 118:
            returnValue = '8';
            break;
       case 119 ... 122:
            returnValue = '9';
            break;
    }
    return returnValue;
}

void FindSolution(int numCase, string inputStr)
{     
#ifdef __DEBUG
       cout << numCase << "," << inputStr << "\n";
#endif
     string parsedString = "";
     char last = '-';
     for (int i = 0; i < inputStr.size(); ++i)
     {
          int asciiCode = int(inputStr[i]);
          char keypad = KeyPadNumOf(asciiCode);
          
          if (keypad == last)
          {
             parsedString.append(" ");
          }
          
          stringstream ss;
          string keypadInStr;
          ss << keypad;
          ss >> keypadInStr;
          
          if (asciiCode >= 97)
          {
             int repeatedPress = asciiCode - keyIndex[keypad - int('2')];
    
#ifdef __DEBUG
       cout << asciiCode << "," << keypad << "," << keypadInStr << "," << repeatedPress << "\n";
#endif
    
              for (int j = 0; j <= repeatedPress; ++j)
              {
                  parsedString.append(keypadInStr);
              }
          }
          else if (asciiCode == 32)
          {
              parsedString.append(keypadInStr);
          }
          last = keypad;     
     }
     cout << "parsed word: " << parsedString << "\n";
     outputFile << "Case #" << numCase + 1 << ": " << parsedString << "\n";
}
