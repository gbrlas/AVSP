#include <iostream>
#include<fstream>
#include <string>
using namespace std;
void main()
{
	freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int L,D,N,sum=0;
	string temp,dct,ans;
	string Dict[5000];
    cin>>L>>D>>N;
	for(int i=0;i<D;i++)
	{
		cin>>Dict[i];
	}
	for(int i=0;i<N;i++)
	{	
		cin>>temp;
		sum=0;
		for(int j=0;j<D;j++)
		{
			ans="";
			dct=Dict[j];
			int k=0,l=temp.length(),t=0;
			bool yes=false,add=true;
			while(k<l)
			{
				yes=false;
				if(temp[k]=='(')
				{
					k++;
					while(temp[k]!=')')
					{
						if(temp[k]==dct[t])
						{
							ans+=temp[k];
							k=temp.find(")",k);
							k++;
							t++;
							yes=true;
							break;
						}	
						else k++;
					}
					if(!yes) 
					{
						add=false;
						break;
					}
				}
				else
				{
					while(k<l&&temp[k]!='(')
					{
						if(temp[k]==dct[t])
						{
							ans+=temp[k];
							yes=true;
							k++;
							t++;
						}
						else
						{
							yes=false;
							add=false;
							break;
						}
					}
					if(!yes)break;
				}
			}
			if(add)sum++;
		}
		cout<<"Case #"<<i+1<<": "<<sum<<endl;
	}
}