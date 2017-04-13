#include<iostream>
#include<fstream>
using namespace std;
int data[1004];

int main()
{
	fstream f,f1;
	f.open("a.txt");
	f1.open("b.txt");
	int t,cnt = 1;
	f1>>t;;
	while(t--)
	{
		int n;
		f1>>n;;
		f1>>data[0];
		int temp =data[0];
		int min = data[0];
		int sum = data[0];
		for(int i =1;i<n;i++)
		{
			f1>>data[i];
			temp = temp^data[i];
			if(min>data[i])min=data[i];
			sum+=data[i];
		}
		if(temp==0)
			f<<"Case #"<<cnt++<<": "<<sum-min<<endl;
		else
			f<<"Case #"<<cnt++<<": NO"<<endl;
	}
	f.close();
	f1.close();
	system("pause");
	return 0;
}
