#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int T,serial=1;
	ifstream fi;
    fi.open("file.txt");
    ofstream fo;
    fo.open("output.txt");
    fi>>T;
	while(T--)
	{
		int a,b,count=0,x;
		fi>>a;
		int A[4][4],B[4][4],tempa[3],tempb[3];
		for(int i=0;i<4;i++)
		  {
		     for(int j=0;j<4;j++)
	         fi>>A[i][j];
          }
		for(int i=0;i<4;i++)
			tempa[i]=A[a-1][i];
		fi>>b;
		for(int i=0;i<4;i++)
	      {
			 for(int j=0;j<4;j++)
			 fi>>B[i][j];
          }

		for(int i=0;i<4;i++)
			tempb[i]=B[b-1][i];
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(tempa[i]==tempb[j])
				{
					x=tempb[j];
					count++;
				}
			}
		}
		if(count==0)
			fo<<"Case #"<<serial<<": Volunteer cheated!"<<endl;
		else if(count==1)
			fo<<"Case #"<<serial<<": "<<x<<endl;
		else
			fo<<"Case #"<<serial<<": Bad magician!"<<endl;
		serial++;
	}
	fi.close();
	fo.close();
	return 0;
}
