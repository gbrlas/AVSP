#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

int exp2(int N)
{
	if(N==0)
		return 1;
	return 2*exp2(N-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T,N,K;
	fin>>T;
	bool flag;
	int temp;
	for(int i=0;i<T;i++)
	{
		flag=false;
		fin>>N>>K;
		if(K==0)
		{
			fout<<"Case #"<<(i+1)<<": "<<"OFF"<<endl;
			continue;
		}
		temp=exp2(N);
        for(int j=1;j<INT_MAX;j++)
		{
            if((j*temp-1)<=K)
			{
				if((j*temp-1)==K)
				{
                    fout<<"Case #"<<(i+1)<<": "<<"ON"<<endl;
				    flag=true;
			        break;
				}
			}
			else
				break;
		}
		if(!flag)
           fout<<"Case #"<<(i+1)<<": "<<"OFF"<<endl;
	}
	return 0;
}

