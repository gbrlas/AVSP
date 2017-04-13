#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

main()
{
   ifstream infile("B-large.in");
   if(!infile) {
      cerr << "Failed to open input file\n";
      exit(1);
   }
   ofstream outFile("B-large.out");
   if(!outFile) {
      cerr << "Failed to open output file\n";
      exit(1);
   }
   
   int numTestCases, TurnTime, NA, NB;    
   infile >> numTestCases;
   
   for(int mainLoop = 0; mainLoop < numTestCases; mainLoop++)
   {   
       char str[20], *tmp;
       vector<int> depart_A, depart_B, ready_A, ready_B;
       
       infile >> TurnTime >> NA >> NB;
       for(int i=0; i<NA; i++)
       {
           infile>>str;
           tmp = strtok(str, ":");
           int hr = atoi(tmp) * 60;
           tmp = strtok(NULL, "\n");
           int min = atoi(tmp);
           depart_A.push_back(hr+min);
           
           infile>>str;
           tmp = strtok(str, ":");
           hr = atoi(tmp) * 60;
           tmp = strtok(NULL, "\n");
           min = atoi(tmp);
           ready_B.push_back(hr+min+TurnTime);
       }
       
       for(int i=0; i<NB; i++)
       {
           infile>>str;
           tmp = strtok(str, ":");
           int hr = atoi(tmp) * 60;
           tmp = strtok(NULL, "\n");
           int min = atoi(tmp);
           depart_B.push_back(hr+min);
           
           infile>>str;
           tmp = strtok(str, ":");
           hr = atoi(tmp) * 60;
           tmp = strtok(NULL, "\n");
           min = atoi(tmp);
           ready_A.push_back(hr+min+TurnTime);
       }
       
       sort(depart_A.begin(), depart_A.end());
       sort(depart_B.begin(), depart_B.end());
       sort(ready_A.begin(), ready_A.end());
       sort(ready_B.begin(), ready_B.end());
       
       int pos=0;
       for(int i=0; i<ready_A.size(); i++)
       {
           int j;
           for(j=pos; j<depart_A.size(); j++)
               if(ready_A[i] <= depart_A[j])
               {
                   pos = j;
                   depart_A.erase(depart_A.begin()+j);
                   break;
               }
          // if(j==depart_A.size())
          //     break;
       }
       
       pos=0;
       for(int i=0; i<ready_B.size(); i++)
       {
           int j;
           for(j=pos; j<depart_B.size(); j++)
               if(ready_B[i] <= depart_B[j])
               {
                   pos = j;
                   depart_B.erase(depart_B.begin()+j);
                   break;
               }
        //  if(j==depart_A.size())
         //     break;
       }
       
       outFile << "Case #" << mainLoop+1 << ": " << depart_A.size() <<" "<<depart_B.size();
       outFile<<endl;
   }
   cin >> numTestCases;
}
