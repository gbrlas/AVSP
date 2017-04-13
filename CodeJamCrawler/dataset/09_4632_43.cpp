#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outfile("out.txt");
	ifstream infile("A-small-attempt0.in");
	int L,D,N;
	bool Ist;
	infile>>L>>D>>N;
	char str[5000][15];
	char temp[420];
	int i,j,k,t,m,p,n;
	int a[15][5000];
	for(i=0;i<D;i++)
		infile>>str[i];
	for(j=1;j<=N;j++)
	{
		m=0;
		p=0;
		Ist = false;
		infile>>temp;
		t=strlen(temp);
		for(k=0;k<t;k++)
		{
			if(temp[k]=='(')
				Ist = true;
			else if(temp[k]==')')
			{
				Ist = false;
				n = p;
				m++;
				p=0;
			}
			else
			{
				if(m==0)
				{
					for(i=0;i<D;i++)
						if(temp[k]==str[i][m])
							a[0][p++] = i;
				}
				else
				{
					for(i=0;i<n;i++)
						if(temp[k]==str[a[m-1][i]][m])
							a[m][p++] = a[m-1][i];
				}
				if(!Ist)
				{
					n = p;
					m++;
					p=0;
				}
			}
		}
		outfile<<"Case #"<<j<<": "<<n<<endl;
	}
	outfile.close();
	infile.close();
	return 0;
}
