#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <sstream> 
#include <set> 
#include <map> 
#include <vector> 
#include <list> 
#include <string>
#include <algorithm>

using namespace std;

stringstream& GetLineStream(stringstream& aLineStream)
{
		string line; 
        do 
        { 
			getline(cin,line); 
        } 
        while(line==""); 
        aLineStream<<line; 
		return aLineStream;
}

template<typename F, typename S>
void  ReadPair(const string& aLine, F& aFirst, S& aSecond)
{
		int pos=aLine.find(':'); 
		stringstream first(aLine.substr(0,pos));
		first>>aFirst;
		stringstream second(aLine.substr(pos+1));
		second>>aSecond;
}

string result;

void NexPermut()
{
   		string line; 
        do 
        { 
			getline(cin,line); 
        } 
        while(line==""); 
        result = line;
		do {
		   bool succ = next_permutation(result.begin(), result.end());
		   if (!succ) {
			result.insert(result.begin()+1, '0');
		   }
		}
		 while(result[0]=='0');

}


void PrintResult(int i)
{//printf("Case #%d: %.7lf\n", i,CheapestWay);
		cout<<"Case #"<<i<<": ";
		cout<<result;
		cout<<"\n";
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int N;
	cin>>N;

	for(int i=1;i<=N;++i)
	{
		NexPermut();
		PrintResult(i);
	}
	return 0;
}
