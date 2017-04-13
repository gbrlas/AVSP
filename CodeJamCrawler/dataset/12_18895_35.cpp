#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cmath>


using namespace std;

int main()
{
string s;

    ifstream cin("C-small-attempt0.in");
    ofstream cout("C-small.out");
    int noOfCases;
    cin>>noOfCases;
    getline(cin,s);
for (int cc=1;cc<=noOfCases;cc++){
	int finalCounter=0;
	string str; int buf;
	vector<int> tempo;
	getline(cin,str);
        istringstream ss(str);
	while(ss>>buf)
        tempo.push_back(buf);


for(int it=tempo[0];it<=tempo[1];it++)
{

int digits = floor( log10( abs( it != 0 ? it : 1 ) ) ) + 1;
int r[digits];
int n=it; // This value represents n
int number=n;
for(int i=0;i<digits;i++)//convert n to array format r[]
	{
		int q; int m;
		q=number/10;
		m= number % 10;
		r[i]=m;
		number=q;

     }


for(int j=0;j<digits;j++){
    int bucket,m=0;
    bucket=r[0];
            for(int k=1;k<digits;k++){
                r[k-1]=r[k];
                }
     r[digits-1]=bucket;
     for(int c=0;c<digits;c++)
     {m=m+((r[c])*(pow(10,c)));}

     //checking condi A<n<m<B

     if((n>=tempo[0])&&(m>n)&&(m<=tempo[1]))
      finalCounter++;
    }

//end of n loops

}
cout<<"Case #"<<cc<<": "<<finalCounter<<endl;
}

return 0;
}





