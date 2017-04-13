// QB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
#include<algorithm>
#include<bitset>

typedef unsigned int uint;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	uint Ndata;
	ifstream infile("good.in");
	ofstream OF("output.txt");

	 
    //std::cout << x << std::endl;


	 infile>>Ndata;


	 for(uint idat=0;idat<Ndata;idat++){
		 uint a,b,k;
		 
		 infile>>a>>b>>k;
		 bitset<32> A(a);
		 bitset<32> B(b);
		 bitset<32> K(k);
		 //cout<<A<<endl;

		 uint icount=0;
		 for(uint ia=0;ia<a;ia++){
			for(uint ib=0;ib<b;ib++){
				bitset<32> A0(ia);
				bitset<32> B0(ib);
				bitset<32> K0=A0&B0;
				if(K0.to_ulong()<k) icount++;
			}
		 }
		 OF<<"Case #"<<idat+1<<": "<<icount<<endl;


	 }

	 


	 infile.close();
	 OF.close();


	return 0;
}

