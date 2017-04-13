#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int main(char** argv)
{
	ifstream in;
	in.open("test.input");

	if(!in.is_open())
	{
		cerr<<"Unable to open input"<<endl;
		exit(1);
	}

	ofstream out;
	out.open("test.output");
	if(!out.is_open())
	{
		cerr<<"Unable to open output"<<endl;
		exit(1);
	}

	int numCases;
	in >> numCases;

	for(int i=1; i<=numCases; i++)
	{
		long long n, A, B, C, D, x0, y0, M;
		in >> n; in >> A; in >> B; in >> C; in >> D; in >> x0; in >> y0; in >> M;

		//tree locations
		vector<long long> xcoord;
		vector<long long> ycoord;

		//cout<<"trees: ("<<x0<<","<<y0<<") ";
		xcoord.push_back(x0);
		ycoord.push_back(y0);

		int x = x0; int y=y0;
		for(int j = 1; j<n; j++)
		{
  			x = (A * x + B) % M;
  			y = (C * y + D) % M;
  			xcoord.push_back(x);
  			ycoord.push_back(y);
		}
		out << "Case #"<<i<<": ";

		int numTriangles = 0;
		//cout<<"centers: "<<flush;
		for(int k=0; k<xcoord.size();k++)
		{
			long long x1 = xcoord.at(k);
			long long y1 = ycoord.at(k);
			
			for(int l=(k+1); l<xcoord.size(); l++)
			{
				if(k==l)
					continue;
					
				long long x2 = xcoord.at(l);
				long long y2 = ycoord.at(l);
				
				for(int m=(l+1); m<xcoord.size(); m++)
				{
					if(m==k || m==l)
						continue;
						
				 	long long x3 = xcoord.at(m);
				 	long long y3 = ycoord.at(m);
				 	
				 	//calc center
				 	double xc = ((double)(x1+x2+x3))/3.0;
				 	double yc = ((double)(y1+y2+y3))/3.0;
				 	//cout<<"("<<xc<<","<<yc<<") "<<flush;
				 	
				 	if(xc == floor(xc) && xc==ceil(xc) && yc==floor(yc) && yc==ceil(yc))
				 		numTriangles++;
				}
			}
		}
		cout<<endl;
		out<<numTriangles<<endl;
	}

	out<<flush;
	out.close();
}
