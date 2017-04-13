#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
    string s;
    
    ifstream cin("B-small-attempt1.in");
    ofstream cout("B-small.out");
    int noOfCases;	
    cin>>noOfCases;	
    getline(cin,s);	

for(int cc=1;cc<=noOfCases;cc++)
   { 
     vector<int> tempo;
     vector<int> final;
     string str;
     int result=0,caseinc=0;	
     getline(cin,str);
     istringstream ss(str);	
     int t,no,p,surpri;
     int buf;
     while(ss>>buf)
	tempo.push_back(buf);
//take out the first three values: n, p and s
     no=tempo[0];
     surpri=tempo[1];
     caseinc=surpri;
     p=tempo[2];

//put the remaining in a vector
     for(int i=3;i<tempo.size();i++)
	final.push_back(tempo[i]);


//sort it in descending order
 sort(final.begin(),final.end(),greater<int>());		 	
	
	for(int i=0;i<final.size();i++)
	{
	   int quotient, mod;
	   if ((final[i]==0)&&(p>0)) continue;
	   if ((final[i]==0)&&(p==0)) {result++; continue;}		
	   quotient=final[i]/3;
	   mod=final[i]%3;		
	   
	   if(quotient>=p) result++;
	   
	   if((p-quotient)==2)	
		{
			if((mod==2)&&(caseinc>0))
				{result++;caseinc--;}
			if((mod==2)&&(caseinc=0)) continue;
			if(mod==1) continue;
			if(mod==0) continue;
		}		


	   if((p-quotient)==1)
		{
			if((mod==0)&&(caseinc>0))
			   { result++;caseinc--;}
			if((mod==0)&&(caseinc==0)) continue;
			if(mod>0) result++;
		}  					   
	  	

	}

cout<<"Case #"<<cc<<": "<<result<<endl;


}


return 0;
}


