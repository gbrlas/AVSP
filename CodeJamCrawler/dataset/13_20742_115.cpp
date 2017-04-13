#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(long long ll)
{
	long long lt=ll;
	long long tmp=0;
	while(true)
	{
		tmp+=ll%10;
		ll/=10;
		if(ll==0)
			break;
		tmp*=10;
	}
	if(tmp == lt) return true;
	else return false;
}
int main()
{
	vector<long long> vec;
	long long lg1=1,lg2=100000000000000LL;
	long long bound1=sqrt(lg1);
	long long bound2=sqrt(lg2);
	for(long long j=bound1-1;j<=bound2+1;j++)
	{
		if(j*j>=lg1 && check(j)&& j*j<=lg2 && check(j*j))
			vec.push_back(j*j);
	}
	fstream readfile("theIn.txt");
	fstream writefile("theOut.txt",ios::out) ;
	if(!readfile || !writefile)
		return -1;

	size_t c=0;
	readfile>>c;
	for(size_t i=0;i<c;i++)
	{
		unsigned count=0;
		readfile>>lg1>>lg2;
		for(vector<long long>::iterator it=vec.begin();it!=vec.end();it++)
			if(*it>=lg1 && *it<=lg2) count++;
		writefile<<"Case #"<<i+1<<": "<<count<<endl;
	}
	writefile.close();
	readfile.close();
}