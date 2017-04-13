#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("C:\\Users\\Simy\\Downloads\\B-large.in");
	if(in == NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("b.out");

	int T;
	in >> T;
	for(int i=0;i<T;i++)
	{
		int n,s,p;
		in >> n >> s >> p;
		vector<int> a(n);
		for(int j=0;j<n;j++)
		{
			in >> a[j];
		}
		sort(a.begin(),a.end());
		int num=0;
		for(int k=n-1;k>=0;k--)
		{
			if(a[k] == 0)
			{
				if(p==0)
					num++;
			}
			else if(((a[k]+2)/3)>=p)
				num++;
			else if(s>0)
			{
				if(((a[k]+4)/3)>=p)
				{
					s--;
					num++;
				}
			}
		}
		out << "Case #" << i+1 << ": " << num << endl;
	}
}