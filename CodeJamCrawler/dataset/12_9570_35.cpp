#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int greater_or_equal_to_p(int p, vector<int>& total, int googlers,int surprise)
{
  //cout<<"\n";
  //cout<<"p:"<<p<<" ";
  int i=0;
  int highest=0;  
  int result=0;
  if(p==0)
    return googlers;
  for(i=0;i<googlers; i++)
    {
      //cout<<total[i]<<" ";
      if(total[i]==0)
	continue;
      switch(total[i]%3)
	{
	case 0:
	  highest=total[i]/3;
	  if(highest>=p)
	    result++;
	  else
	    {
	      highest=(total[i]/3)+1;
	      if(highest>=p && surprise>0)
		{
		  result++;
		  surprise--;
		}
	    }
	  break;

	case 1:
	  highest=((total[i]-1)/3)+1;
	  if(highest>=p)
	      result++;
	  break;

	case 2:
	  highest=((total[i]-2)/3) +1;
	  if(highest>=p)
	      result++;
	  else
	    {
	      highest=((total[i]-2)/3)+2;
	      if(highest>=p && surprise>0)
		{
		  result++;
		  surprise--;
		}
	    }

	  break;


	}
	  
    }
  return result;
}


#define inputFile "B-large.in"
#define getints line=""; while(1) { c=infile.get(); if(c==' ' || c=='\n' ) break; line=line+c; }

int main()
{
  ifstream infile;
  string line;
  int no_of_tc; int n=1;
  int no_of_googlers=0;
  int no_of_surprise_triplets;
  int p;
  int i=1;
  char c;

  infile.open(inputFile);
  if( infile.is_open() )
    {
      getline(infile,line);
      stringstream(line)>>no_of_tc;
      //cout<<no_of_tc<<" ";
      vector<int> total;      
      while(n<=no_of_tc && infile.good())
	{
	  getints
	  stringstream(line)>>no_of_googlers;
	  //cout<<"no_of_googlers:"<<no_of_googlers<<"\n";

	  getints
	  stringstream(line)>>no_of_surprise_triplets;
	  //cout<<" "<<no_of_surprise_triplets;

	  getints
	  stringstream(line)>>p;
	  //cout<<"p="<<p<<" ";

	  i=1;
	  total.clear();
	  int temp;
	  while(i<=no_of_googlers)
	    {
	      temp=0;
	      getints
	      stringstream(line)>>temp;
	      total.push_back(temp);
	      i++;
	    }

	  cout<<"Case #"<< n <<": "<<greater_or_equal_to_p(p, total,no_of_googlers, no_of_surprise_triplets);
	  cout<<"\n";
	  n++;
	}
    }
  else
    cout<<"file not open";
  infile.close();

  return 0;
}
