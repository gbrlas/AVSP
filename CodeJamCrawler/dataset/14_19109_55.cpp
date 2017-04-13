// googleCJ_QA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
typedef unsigned int uint;
using namespace std;
 void input(string filename, uint &Ndata, vector<uint> &D, vector<uint> &choice);
 void testoutput(string filename, uint Ndata, vector<uint> D, vector<uint> choice);

int _tmain(int argc, _TCHAR* argv[])
{

	uint Ndata,choice1,choice2;
	uint check[16];
	vector<uint> vbuf1,vbuf2,ans;
	uint buf;

	ifstream infile("good.in");
	ofstream OF("output.txt");

	 infile>>Ndata;


	 for(uint idat=0;idat<Ndata;idat++){
		 vbuf1.resize(0);
		 vbuf2.resize(0);
		 ans.resize(0);

		infile>>choice1;
		for(uint j=0;j<16;j++){
			infile>>buf;
			if((j/4)+1==choice1)
				vbuf1.push_back(buf);
		}

		infile>>choice2;
		for(uint j=0;j<16;j++){
			infile>>buf;
			if((j/4)+1==choice2)
				vbuf2.push_back(buf);
		}

		for(uint i=1;i<17;i++){
			if(std::find(vbuf1.begin(), vbuf1.end(), i) != vbuf1.end()) {
				if(std::find(vbuf2.begin(), vbuf2.end(), i) != vbuf2.end()) {
					ans.push_back(i);
				}
			}
		}

		OF<<"Case #"<<idat+1<<": ";
		if(ans.size()==0) OF<<"Volunteer cheated!"<<endl;
		if(ans.size()==1) OF<<ans[0]<<endl;
		if(ans.size()> 1) OF<<"Bad magician!"<<endl;

	 }


	infile.close();
	OF.close();


	return 0;
}
void testoutput(string filename, uint Ndata, vector<uint> D, vector<uint> choice){
ofstream OF(filename);
	for(uint i=0;i<Ndata*2;i++){
		 OF<<choice[i]<<endl;
		 for(uint j=0;j<16;j++){
			 OF<<D[i*16+j]<<"	";
			 if(j&&(j%4==3)) OF<<endl;
		 }
	 }



OF.close();

}

 void input(string filename, uint &Ndata, vector<uint> &D, vector<uint> &choice){
	
	 ifstream infile(filename);
	 infile>>Ndata;
	 choice.resize(Ndata*2);
	 D.resize(Ndata*16*2);
	 for(uint i=0;i<Ndata*2;i++){
		 infile>>choice[i];
		 for(uint j=0;j<16;j++){
			 infile>>D[i*16+j];
		 }
	 }

	infile.close();
	
}
