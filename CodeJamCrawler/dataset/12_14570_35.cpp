#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main(void)
{
	char arr[2][26]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	int n;
	f1>>n;
	int i;
	
	string temp;
	getline(f1,temp);
	f1.clear();
	for(i=0;i<n;i++)
	{
		string sen;
		f2<<"Case #"<<i+1<<": ";
		int j=0;
		getline(f1,sen);
		for(j=0;j<sen.length();j++)
		{
			if(sen[j]==' ')
			{
				f2<<" ";
				continue;
			}
			else
			{
				int k;
				for(k=0;k<26;k++)
				{
					if(sen[j] == arr[0][k])
					{
						f2<<arr[1][k];
						break;
					}
				}
			}
			
		}
		f2<<"\n";
	}
	return 0;
}					

