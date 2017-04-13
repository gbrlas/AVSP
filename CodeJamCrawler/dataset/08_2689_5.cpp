////////////////////////////////
//
//  Round 1 -- case A
//      coder johnson.zhu 
//  code for Code Jam @ Google
//////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int i,j,k,p;

int transStringToInt(const string s)
{	
	int n;
	stringstream  stream1;//trans string to int
	stream1<<s;
	stream1>>n;
	stream1.clear();
	return n;

}


int main()

{
	
	cout<<"start-----"<<endl;
	ifstream in("A-small.in");
	ofstream out("A-small.out");

	string slin;
	int n,t;
	int result=0;
	stringstream  stream;
	vector<int> v1,v2;
	
	getline(in,slin);
	n=transStringToInt(slin);   // get case

	for(i=0;i<n;i++)
	{
		v1.clear();
		v2.clear();
		result=0;
		cout<<"Case #"<<i+1<<":"<<endl;

		getline(in,slin);
		t=transStringToInt(slin);   // get v
		
		
			int r;
			getline(in,slin);
			stream<<slin;
			for(j=0;j<t;j++)
			{
				stream>>r;
				v1.push_back(r);
			}
			stream.clear();    //get v1

			getline(in,slin);			
			stream<<slin;
			for(j=0;j<t;j++)
			{
				stream>>r;
				v2.push_back(r);
			}
			stream.clear();    //get v1

		/////////////////////////////////

		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());

		for(p=0;p<t;p++)
		{
			result+=v1[p]*v2[t-p-1];
		
		}


		cout<<"result"<<endl<<" --------  "<<result<<endl;
		for(p=0;p<v1.size();p++)
		{
			cout<<"v1"<<"  --  "<<v1[p]<<endl;
		}
		for(p=0;p<v2.size();p++)
		{
			cout<<"v2"<<"  --  "<<v2[p]<<endl;
		}


		///////////////////////////////output the result
		cout<<'\n'<<"---------------------------------------------"<<'\n';
		out<<"Case #"<<i+1<<": "<<result<<'\n';


	}
	return 0;
}



