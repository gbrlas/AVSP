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

void printvec(const vector<int> &v1)
{

		for(p=0;p<v1.size();p++)
		{
			cout<<'\n'<<"  --  "<<v1[p]<<endl;
		}

}


int main()

{
	
	cout<<"start-----"<<endl;
	ifstream in("A-small.in");
	ofstream out("A-small.out");

	string slin;
	int n; 
	stringstream  stream;
	vector<int> v1,v2;
	
	getline(in,slin);
	n=transStringToInt(slin);   // get case

	for(i=0;i<n;i++)
	{
		v1.clear();
		v2.clear();
		cout<<"Case #"<<i+1<<":"<<endl;
		
		int key;
		int per;
		int letter;
		int temp;
		int result=0;
	

	getline(in,slin);
			
	stringstream  stream;//trans string to int
	stream<<slin;
	stream>>per;
	stream>>key;
	stream>>letter;
	stream.clear();
	//printvec(v1);
//	cout<<"@@@@"<<per<<endl<<key<<endl<<letter<<endl;


	getline(in,slin);
	stream<<slin;
	for(p=0;p<letter;p++)
	{
		stream>>temp;
		v2.push_back(temp);
	
	}
	stream.clear();
	sort(v2.begin(),v2.end());
	result=0;
	int a1=1;
	int count=1;
	printvec(v2);
	for(p=0;p<letter;)
	{
		if(count>key)
		{
			a1++;
			count=1;
		}
		result+=v2[letter-p-1]*a1;
		p++;
		count++;
//		cout<<result<<endl;

	}
			cout<<"result----"<<result<<endl;
		/*
		for(p=0;p<v2.size();p++)
		{
			cout<<"v2"<<"  --  "<<v2[p]<<endl;
		}

*/
		///////////////////////////////output the result
		cout<<'\n'<<"---------------------------------------------"<<'\n';
	out<<"Case #"<<i+1<<": "<<result<<'\n';


	}
	return 0;
}



