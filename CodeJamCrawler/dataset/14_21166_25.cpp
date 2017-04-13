#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	 freopen("J:\\A-small-attempt1.in","r",stdin);
	 freopen("J:\\test2.txt","w",stdout);
	 int temp;
	 int counter;
	 int n_cases;
	 int n1;
	 int n2;
	 cin>>n_cases;

	 
	 for (int k=1;k<=n_cases;k++)
	 {
		 cin>>n1;
	       vector<int> matches;	
	       vector< vector<int> > vec1;
	    for (int i=0;i<4;i++)
	  {		 
		 vector<int> row; 
         for (int j = 0; j < 4; j++) 
		{
		 cin>>temp;
         row.push_back(temp);
         }
         vec1.push_back(row);

	  }
	  
	 
	 cin>>n2;
	  vector< vector<int> > vec2;
	 for (int i=0;i<4;i++)
	 {		 
		 vector<int> row; 
         for (int j = 0; j <4; j++) 
		 {
		 cin>>temp;
         row.push_back(temp);
         }
         vec2.push_back(row);

	 }

	 for ( int i=0;i<4;i++)
	 {
		 for (int j=0;j<4;j++)
		 {
		 if (vec1[n1-1][i]==vec2[n2-1][j])
			 matches.push_back(vec1[n1-1][i]);
			
		 }
	 }
	 
	 if(matches.size()==1)
		 cout<<"Case #"<<k<<":"<<" "<<matches[0]<<endl;
	 else if(matches.size()>1)
		  cout<<"Case #"<<k<<":"<<" "<<"Bad magician!"<<endl;
	 else
		  cout<<"Case #"<<k<<":"<<" "<<"Volunteer cheated!"<<endl;

	 


	 }

}