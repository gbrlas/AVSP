#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> search_engines, temp_search_engines;

bool SearchEngineAvailable(string str)
{
     for(int i=0; i<temp_search_engines.size(); i++)
         if(str == temp_search_engines[i])
             temp_search_engines.erase(temp_search_engines.begin()+i);

     if(temp_search_engines.size() == 0)
     {
         temp_search_engines = search_engines;
         for(int i=0; i<temp_search_engines.size(); i++)
         if(str == temp_search_engines[i])
             temp_search_engines.erase(temp_search_engines.begin()+i);
                         
         return false;
     }
     return true;
}

main()
{
   ifstream infile("A-small-attempt5.in");
   if(!infile) {
      cerr << "Failed to open input file\n";
      exit(1);
   }
   ofstream outFile("A-small-attempt5.out");
   if(!outFile) {
      cerr << "Failed to open output file\n";
      exit(1);
   }
   
   int numTestCases;    
   infile >> numTestCases;
   char dummy[10];
   
   //If planning to use getline to read input, uncomment the line below
   infile.getline(dummy, 999);  // just to read newline
   int num_search_engines,num_queries;
   char str[101];
   //string str;
   
   for(int mainLoop = 0; mainLoop < numTestCases; mainLoop++)
   {   
       int result = 0;
       search_engines.clear();
       temp_search_engines.clear();
       //queries.clear();
       infile >> num_search_engines;
       infile.getline(dummy, 999);
       for(int i=0; i<num_search_engines; i++)
       {
           infile.getline(str, 999);
           search_engines.push_back(str);
       }
       
       temp_search_engines = search_engines;
       
       infile >> num_queries;
       infile.getline(dummy, 999);
       for(int i=0; i<num_queries; i++)
       {
           infile.getline(str, 999);
           
           if(SearchEngineAvailable(str))
               continue;
           else
           {
               result++;
           }
       }
            
       outFile << "Case #" << mainLoop+1 << ": " << result;
       outFile<<endl;
   }
}
