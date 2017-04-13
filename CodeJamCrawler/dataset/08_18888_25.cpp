/*Google Code Jam - Saving The Universe
By: Arthur A. Sabintsev (Glorious.Lovemaker)
http://www.lazyrussian.com || lazyrussian@gmail.com
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

//Declare Variables
ifstream inputFile;
ofstream outputFile;
int N, S, Q, Y;


int main()
{

  //Open the Files
  inputFile.open("A-large.in", ios::in);
  outputFile.open("A-large.out", ios::out);

  //Get Basic Info from Files
  inputFile >> N;
  
  //Loop around the different cases
  for (int a = 0; a < N; a++)
    {

      //Retrieve search engine number
      inputFile >> S;
      
      //Loop around the different search engines
      string engine;
      map<string, int> mEngines;
      for (int i = 0; i <= S; i++)
	{
	  getline(inputFile, engine);
	  if (engine.size()!=0) ////Skips the first entry, which is always zero for some fucked up reason.
	     {
	  mEngines[engine] = 0;	
	     }
	}

      //Retrieve query number
      inputFile >> Q;

      //Loop around the different queries
      string query;
      int count = 0;
      int Y = 0;

      for (int j = 0; j <= Q; j++)
	{
	  getline(inputFile, query);  
	  
	  if (query.size()!=0) //Skips the first entry, which is always zero for some fucked up reason.
	    {
	      
	      if (count != S)
		{    
		  if (mEngines[query] == 0)
		    {
		      mEngines[query] = 1;
		      count++;
		    }
		}
	      
	      if (count == S)
		{
		  map<string,int>::iterator it;
		  for (it = mEngines.begin(); it != mEngines.end(); it++)
		    {
		      it->second = 0; //Set the value of each engine int he engine array to zero. 
		    }  
		  
		  mEngines[query] = 1; //The engine that we end up using until mEngines[engine] = mEngines[query]
		  count = 1;
		  Y++; //The Sexy switch occurs here
		}
	      
	    }
	}

      //Write Switch-Number to output file
      outputFile << "Case #"<< a+1 <<": "<< Y << endl;
      
    }

  //Close Files
  inputFile.close();
  outputFile.close();
  
  return 0;
}

