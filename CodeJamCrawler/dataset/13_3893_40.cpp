#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<istream>
#include<iterator>
#include <sstream>
#include<math.h>


using namespace std;
void tokenize_string(string str);
unsigned __int64 startNum=0;
unsigned __int64 endNum=0;
vector<unsigned __int64> possibilities;

void main()
{
	char buff[140];
	unsigned __int64 temp;
	int number_of_test_cases=0,intI=0;
	int count=0;
	vector<unsigned __int64>::iterator pit;
	vector<int> results;
	vector<int>::iterator rit;

	  string filename_write,filename;

	  filename= "possible_outcomes.out" ;
	  freopen(filename.data(), "r" ,stdin);

	  while(fgets(buff,sizeof(buff),stdin))
	  {		
			temp=atoi(buff);
			possibilities.push_back(temp);
		  //tokenize_string(buff);
	  }

	  cin.clear();

	  filename= "C-small-attempt0.in" ;
	  freopen(filename.data(), "r" ,stdin);

	  filename_write="small.out";
	  freopen(filename_write.data(), "w",stdout);

	  fgets(buff,sizeof(buff),stdin);
	  number_of_test_cases=atoi(buff);
	  intI=0;
	  while(intI<number_of_test_cases)
	  {	
		  fgets(buff,sizeof(buff),stdin);
		  count=0;
		  startNum=0;

			temp=atoi(buff);
			tokenize_string(buff);

			for(pit=possibilities.begin();pit!=possibilities.end();pit++)
			{
				if(*pit<startNum)
					continue;
				else if(*pit>endNum)
					break;
				else
					count++;
			}

			results.push_back(count);
			intI++;
		}
	   
	  
	  for(rit=results.begin(),intI=1;rit!=results.end();rit++,intI++)
       {
              cout<< "Case #"<<intI<<": " <<*rit<<endl;
                 
       }

}

void tokenize_string(string str)
{
        int turn=0;
     vector<string>::iterator sit;
     stringstream ss(str);
    istream_iterator<string> begin(ss),end;
    vector<string> temp(begin, end);
     
     for(sit=temp.begin();sit!=temp.end();sit++,turn++)
        {
                            if(turn==0)
                                  startNum=atoi((*sit).c_str());
                            else
                              endNum=atoi((*sit).c_str());
        }            
}