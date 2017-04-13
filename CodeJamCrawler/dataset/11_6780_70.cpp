#include <iostream>
#include <string>
using namespace std;
int toNum(char c)
{
	return c-'A';
}
void solve_test(int test_num)
{
	char elem[26][26];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			elem[i][j]=0;
	bool opos_el[26][26];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
		{
			opos_el[i][j]=false;
			elem[i][j]=0;
		}
	int c,d,n;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		char e1,e2,r;
		cin>>e1>>e2>>r;
		elem[toNum(e1)][toNum(e2)]=r;
		elem[toNum(e2)][toNum(e1)]=r;
	}
	cin>>d;
	for(int i=0;i<d;i++)
	{
		char e1,e2;
		cin>>e1>>e2;
		opos_el[toNum(e1)][toNum(e2)]=true;
		opos_el[toNum(e2)][toNum(e1)]=true;
	}
	cin>>n;
	string res;
	char pc=0;
	for(int i=0;i<n;i++)
	{
		char c;cin>>c;
		bool ops=false;
		if(elem[toNum(pc)][toNum(c)])
		{
			res.erase(res.size()-1,1);
			res+=elem[toNum(pc)][toNum(c)];
		}
		else
		{
			for(int j=0;j<res.size();j++)
				if(opos_el[toNum(res[j])][toNum(c)])
				{
					ops=true;
					break;
				}
			if(ops)res="";
			else res+=c;
		}
		if(res.size()==0)pc=0;
		else pc=res[res.size()-1];
	}
	cout<<"Case #"<<test_num<<": [";
	for(int i=0;i<res.size();i++)cout<<(i==0?"":", ")<<res[i];
	cout<<"]\n";
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		solve_test(i+1);
}
