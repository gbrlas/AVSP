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
bool ispalindrome(unsigned __int64 num);
bool isPerfectSquare(unsigned __int64 num);
unsigned __int64 start=0;
unsigned __int64 endL=0;


int main()
{
        unsigned __int64 result=1;
        unsigned __int64 intI=0,temp_calc=0;
        int count=0;
       vector< unsigned __int64 >::iterator it64;
       vector< unsigned __int64 > array_nums;

       vector< int>::iterator s;
        int num_test_cases=0;
       string temp;
        char *buff;
       buff= "";

      string filename_write="possible_outcomes.out" ;
	  freopen(filename_write.data(), "w" ,stdout);
	   
	   for(intI=1;intI<=10000000;intI++)
       {
		   if(ispalindrome(intI))
		   {
					temp_calc=intI*intI;
					if(ispalindrome(temp_calc))
						{
							array_nums.push_back(temp_calc);
						}
		   }
		}       
        

	for(it64=array_nums.begin(),intI=0;it64!=array_nums.end();it64++,intI++)
       {
              cout<<*it64<<endl;
       }

	//while(true);
}

bool ispalindrome(unsigned __int64 num)
{
       string result,reverse_str;
       stringstream convert;
       convert << num;
       result = convert.str();
       reverse_str=result;
       reverse(reverse_str.begin(), reverse_str.end());

        if(reverse_str.compare(result)==0)
       {
               return(true );
       }
        else
               return(false );

}
bool isPerfectSquare(unsigned __int64 num)
{
    long double root;
        unsigned __int64 remainder;

   root=std::sqrt(( long double )num);
  
   remainder=ceil(root);

   if(remainder-root>0.0)
               return(false );
   else if(ispalindrome((unsigned __int64 )root))
          return(true );
   else
          return(false );


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
                                  start=atoi((*sit).c_str());
                            else
                              endL=atoi((*sit).c_str());
        }            
}
