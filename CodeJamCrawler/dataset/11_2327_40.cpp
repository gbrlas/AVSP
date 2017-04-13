#include<iostream>
using namespace std;

const int maxr = 55;

int r,c;
string in[maxr];

inline int fixit()
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(in[i][j]=='#') {
				if(i==r-1 || in[i+1][j]!='#')
					return 1;
				if(j==c-1 || in[i][j+1]!='#')
					return 1;
				if(in[i+1][j+1]!='#')
					return 1;
				in[i][j] = '/';
				in[i+1][j] = '\\';
				in[i][j+1] = '\\';
				in[i+1][j+1] = '/';
			}
	return 0;
}

int main ()
{
	int testn =0;
	cin>>testn;
	for(int tn = 0;tn<testn;tn++) {
		cin>>r>>c;
		for(int i=0;i<r;i++)
			cin>>in[i];
		cout<<"Case #"<<tn+1<<":"<<endl;
		if(fixit())
			cout<<"Impossible"<<endl;
		else {
			for(int i=0;i<r;i++)
				cout<<in[i]<<endl;
		}

	}
}
