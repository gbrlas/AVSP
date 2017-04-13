// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sum(char* a, unsigned int len)
{
	int su=0;

	 for (int x=0;x<len;x++)
	 {
		 su = su + (a[x]-'0');
	 }
	 return su;
}
bool cek(char* a, char* b, unsigned int len)
{
	for (int x=1;x<len;x++)
	{
		if(b[x]=='0')
			continue;

		string bbb(b+x);
		bbb.append(b,x);

		//cout << "hasil:: " <<bbb << endl;

		if(bbb.compare(a)==0)
			return true;
		
	}
	return false;
}
int compareaaa (char* a, char* b, unsigned int len)
{
	int sa = sum(a,len);
	int sb = sum(b,len);

	return sa-sb;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	fflush(stdin);
	cin >> T;

	for (int i=0;i<T;i++)
	{
		unsigned int A,B;
		char aa[12],bb[12];
		int res =0;

		cin >> A;
		cin >> B;

		for (unsigned int n=A; n<B;n++)
		{
			sprintf(aa,"%i",n);
			unsigned int len = strlen(aa);
			int sa = sum(aa,len);

			for (unsigned int m=n+1; m<=B;m++)
			{
				sprintf(bb,"%i",m);
				int sb = sum(bb,len);

				int ss=sa-sb;
				if(ss==0)
				{
					//cout << "hasilaaaaa:: " <<bb << endl;
					if(cek(aa,bb,len))
					{
						res++;
						continue;
					}
				}

				if(ss>0)
					m += (ss-1);
				//else if(ss<0)
				//	m +=
			}
		}




		cout <<"Case #" << i+1 << ": ";
		cout << res << endl;
	}
	return 0;
}

