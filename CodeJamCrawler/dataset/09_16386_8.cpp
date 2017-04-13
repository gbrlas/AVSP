#include<iostream>
#include<list>
#include<algorithm>
#include<windows.h>
#include<string>
#include<dos.h>
#include "math.h"
# include <vector>
#include<map>
# include <algorithm>
#include<set>
using namespace std;


int main ()
{
  string str;
  int inputs;
  cin>>inputs;
  for(int b =0;b<inputs;b++)
  {
	map<char,int> s;
	cin>>str;
	int base =0;
	int value = 0;

	for(int i=0;i<str.length();i++)
	{
	  if(s.find(str[i])== s.end())
	  {
		  base++;
		  s.insert(make_pair(str[i],value++));		  
	  }
	}

	if(base==1) base=2;




	for(map<char,int>::iterator iter = s.begin();iter!=s.end();iter++)
	 {
		 if(iter->second  == 1)
		  iter->second = 0;
		  else if(iter->second  == 0)
		  iter->second = 1;
	  
	}

	  int answer = 0;
	 double pvalue = 0;
	for(int i=str.length()-1;i>=0;i--)
	{
		 int value = s[str[i]] * pow(base,pvalue);
		 answer += value;
		 pvalue++;
	}
	cout<<"Case #"<<b+1<<": "<<answer<<endl;
  }
    return 0;
}    
          
