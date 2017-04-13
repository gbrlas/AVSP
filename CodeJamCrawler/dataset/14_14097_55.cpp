#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	string name1="input.txt";
	string name2="output.txt";
	ifstream ist(name1.c_str());
	ofstream ost(name2.c_str());
	ist>>n;
	for (int i=0;i<n;i++)
	{
		int number;
		ist>>number;
		vector<double> d1,d2;
		double temp;
		for (int j=0;j<number;j++) 
		{
			ist>>temp;
			d1.push_back(temp);
		}
		for (int j=0;j<number;j++) 
		{
			ist>>temp;
			d2.push_back(temp);
		}
		sort(d1.begin(),d1.end());
		sort(d2.begin(),d2.end());
		int h1,t1,h2,t2;
		h1=0;
		h2=0;
		t1=number-1;
		t2=t1;
		int times=0;
		int points=0;
		while (times!=number){
			if (d1[h1]>d2[h2]){points++;h1++;h2++;}
			else {h1++;t2--;}
			times++;
		}
		h1=0;
		h2=0;
		t1=number-1;
		t2=t1;
		int points2=0;
		while (h1!=number){
			while (d1[h1]>d2[h2])
			{
				h2++;
				if (h2==number) {
					points2+=number-h1;
					h1=number;
					break;
				}	
			}
			if (h1==number) break;
			h1++;
			h2++;
			if (h2==number) {
				points2+=number-h1;
				break;
			}
		}
		ost<<"Case #"<<i+1<<": "<<points<<" "<<points2<<endl;
	}
}