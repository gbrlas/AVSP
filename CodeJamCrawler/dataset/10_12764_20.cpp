// codejam1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{    
	int N,K,T,t=1;
    char *inname = "A-small.in";
	char *outname="A-small.out";
    bool out=false;
	bool snappers[11];
    ifstream infile(inname);
	ofstream outfile(outname);
	
   infile>>T;
	

   for (int p=1;p<=T;p++)
   {  infile>>N;
      infile>>K;

        
     for(int i=1;i<=N;i++)
	 {
	 
	 snappers[i]=false;
	 }
		for (int i=1;i<=K;i++)
		{ 
		  bool previous=snappers[1];
		  snappers[1]=!snappers[1];
		 
		  int k=2;
		  while (previous && (k<=N))
		  {   
			  previous=previous&snappers[k];
			  snappers[k]=!snappers[k];
		      k++;
		  
		  }
		}

      bool previous=true;
			  for(int k=1;k<=N;k++)
			  {
			  previous=previous & snappers[k];
			  
			  
			  }

    out=previous;
             
    if (out)
	outfile<< "Case #"<<t<<": ON"<< endl;
	else
    outfile<< "Case #"<<t<<": OFF"<< endl;
	t++;



}
return 0;
}