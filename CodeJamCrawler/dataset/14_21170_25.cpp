#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	 int n_cases;	
	 
	 	 
	 double C,F,X;	
	 freopen("J:\\B-large.in","r",stdin); 
	 freopen("J:\\test2.txt","w",stdout); 
	  cin>>n_cases;
	 for  (int i=1; i<=n_cases; i++)
	 {
		  double  cps=2;	
		 double  time_elapsed=0;
		 cin>>C>>F>>X;
	 while(X/cps > (C/cps+ X/(cps+F)))
	 {
		
		 time_elapsed+=C/cps;
		 cps +=F;
	 }
		 time_elapsed+=X/cps;
		  cout.precision(10);
		 cout<<"Case #"<<i<<":"<<" "<<time_elapsed<<endl;
	 }

}