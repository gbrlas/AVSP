#include<iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;
 int main() {
	 ofstream myfile ("output1.txt");
	 fstream mydata("B-small-attempt2.in", std::ios_base::in);
	 int s;
	 mydata>>s;
	 for(int i=1;i<=s;i++) {
		 double c,f,x;
		 mydata>>c>>f>>x;
		 double mn=x/2,t=-1,k=2;
		 for(double y=1;y<=x;y++) {
			 t+=c/k;
			 k+=f;

			 mn=min(mn,t+(x/k+1));
		 }
		 myfile.precision(7);
		 myfile<<"Case #"<<i<<": "<<fixed<<mn<<endl;
	 }
	 return 0;
 }
