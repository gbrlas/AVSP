#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
using namespace std;

//#define inputFile "input.txt"
#define inputFile "A-small-attempt0.in"


int main()
{
  ifstream infile;
  string line;
  char c;
  int no_of_tc;
  int i=1;
  map<char,char> dict;
  dict['a']='y';
  dict['b']='h';  dict['c']='e';  dict['d']='s';   dict['e']='o';  dict['f']='c'; 
  dict['g']='v';  dict['h']='x';  dict['i']='d';   dict['j']='u';  dict['k']='i'; 
  dict['l']='g';  dict['m']='l';  dict['n']='b';   dict['o']='k';  dict['p']='r'; 
  dict['q']='z';  dict['r']='t';  dict['s']='n';   dict['t']='w';  dict['u']='j'; 
  dict['v']='p';  dict['w']='f';  dict['x']='m';   dict['y']='a';  dict['z']='q'; 

  infile.open(inputFile);
  if( infile.is_open() )
    {
      getline(infile,line);
      stringstream(line)>>no_of_tc;
      //cout<<no_of_tc<<"\n";
      //cout<<"Output"<<"\n";
      cout<<"Case #"<<i<<": ";
      while(i<=no_of_tc)
	{
	  c=infile.get();
	  if(!infile.good()){break;}
	  if(c=='\n')
	    {
	      i++;
	      if(i>no_of_tc) break;
	      cout<<"\nCase #"<<i<<": ";
	      continue;
	    }
	  if(c==' ')
	    cout<<" ";
	  else 	  cout<<dict[c];
	 
	}
    }
  else
    cout<<"file not open";
  infile.close();

  return 0;
}
