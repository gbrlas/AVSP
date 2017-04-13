#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> word;

bool match(char c, string letters)
{
   for(int i=0; letters[i]!='\0'; i++)
   {
      if(c == letters[i]) return true;
   }
   return false;
}


int calcNumWords(string testWord, int wordSize)
{
   vector<string>letters;
   string tempStr;
   
   for(int i=0,j=0; i<testWord.length(); i++,j++)
   {
      int k=0;
      tempStr = "";
      if(testWord[i] == '(')
        while(testWord[++i] != ')')
           tempStr += testWord[i];
      else
        tempStr += testWord[i];
 
      letters.push_back(tempStr);
   }
   
   int count = 0;
   for(int i=0; i<word.size(); i++)
   {
      int j=0;
      for(; j<wordSize; j++)
      {
         if(!match(word[i][j], letters[j]))
           break;
      }
      if(j == wordSize)
         count++;
   }
   return count;
}

main()
{
   int L, D, N;
   fstream input_file("Input.txt",ios::in);
   fstream output_file("Output.txt",ios::out);
   
   input_file >> L;
   input_file >> D;
   input_file >> N;
   
   string temp;
   for(int i=0; i<D; i++)
   {
      input_file >> temp;
      word.push_back(temp);
   }
     
   int count;
   for(int i=0; i<N; i++)
   {
      input_file >> temp;
      count = calcNumWords(temp, L);
      output_file << "Case #" << i+1 << ": " << count <<endl;
   }
}
