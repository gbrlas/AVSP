#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	string key =   "yhesocvxduiglbkrztnwjpfmaq";
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;++i)
	{
		string tmp;
		getline(cin,tmp);
		for(int j=0;j<tmp.size();++j)
		{
			if(tmp[j]!=' ')
				tmp[j] = key[tmp[j]-'a'];
		}
		cout<<"Case #"<<i+1<<": "<<tmp<<endl;
	}
	return 0;
}