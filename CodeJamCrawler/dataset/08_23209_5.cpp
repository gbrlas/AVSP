#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

main()
{
   ifstream infile("A-small-attempt2.in");
   if(!infile) {
      cerr << "Failed to open input file\n";
      exit(1);
   }
   ofstream outFile("A-small-attempt2.out");
   if(!outFile) {
      cerr << "Failed to open output file\n";
      exit(1);
   }
   
   int numTestCases, numCords;
   vector<int> cordsX,cordsY;
      
   infile >> numTestCases;
   
   for(int mainLoop = 0; mainLoop < numTestCases; mainLoop++)
   {   
       infile >> numCords;
       
       int tempVar, result=0;
       cordsX.clear();
       cordsY.clear();
       
       for(int tempCount = 0; tempCount < numCords; tempCount++)
       {
           infile >> tempVar;
           cordsX.push_back(tempVar);
       }
       
       for(int tempCount = 0; tempCount < numCords; tempCount++)
       {
           infile >> tempVar;
           cordsY.push_back(tempVar);
       }
       
       sort(cordsX.begin(),cordsX.end());
       sort(cordsY.begin(),cordsY.end());
       
       for(int tempCount = 0; tempCount < numCords; tempCount++)
       {
          cout<<"X:" <<cordsX[tempCount]<<" ";
          cout<<"Y:" <<cordsY[tempCount]<<" ";
       }
       
       for(int tempCount = 0; tempCount < numCords; tempCount++)
       {
           result += cordsX[tempCount]*cordsY[cordsY.size()-tempCount-1];
       }
       
       outFile << "Case #" << mainLoop+1 << ": " << result;

       outFile<<endl;
   }
   cin >> numTestCases;
}
