#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<string.h>
using namespace std;

int main () {
  string line;
  ifstream myfile("input.txt");
  ofstream myop ;
	myop.open("output.txt");
int k=1;
  if (myfile.is_open())
  {
  	getline (myfile,line);
  	 stringstream ss;
  	ss<<line;
    int t;
    ss>>t;
  	//t=line;
  	//getline (myfile,line);
    while (t--)
    {
      getline (myfile,line);
       string s="";
      for(int i=0;i<line.size();i++)
      {
  		string ip="abcdefghijklmnopqrstuvwxyz ";
  		string op="yhesocvxduiglbkrztnwjpfmaq ";
      	
      	int x=-1;
      	x=ip.find(line[i]);
      	s+=op[x];
      }
      myop<<"Case #"<<k<<": "<<s<<"\n";
      k++;
    }
    myfile.close();
    myop.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
