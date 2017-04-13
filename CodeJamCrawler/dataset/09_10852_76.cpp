#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{

	int l=0,d=0,n=0;
	int i=0,j=0,i1=0,j1=0;
	int num=0;

	size_t found;


	//	ifstream cin("A-small-practice.in.txt");
	ifstream infile;
	ofstream outfile;







	infile.open("A-small-attempt1.in");
	assert(infile);

	outfile.open("A-small-result.txt");
	assert(outfile);



	infile>>l>>d>>n;
	cout<<"l = "<<l<<endl;
	cout<<"d = "<<d<<endl;
	cout<<"n = "<<n<<endl;


	char c_temp;
	infile.get(c_temp);
	cout<<"c_temp = "<<c_temp<<endl;






	vector<string> w(d);

	for(i=0;i<d;++i)
	{
		getline(infile,w[i]);

		



	}





	int g=0;



	vector<string> p(l);


	for(i=1;i<=n;++i)
	{
		for(j=0;j<l;++j)
		{
			infile.get(c_temp);
			if(c_temp=='\n')
				infile.get(c_temp);

			if(c_temp=='(')
				getline(infile,p[j],')');
			else
				p[j]=p[j]+c_temp;
			



		}





		num=0;



		for(i1=0;i1<d;++i1)
		{

			for(j1=0;j1<l;++j1)
			{

				found=p[j1].find(w[i1][j1]);
				if (found==string::npos)
					break;
				else if(j1==l-1)
					++num;




			}





		}


		outfile<<"Case #"<<i<<": "<<num<<endl;




		for(j=0;j<l;++j)
			p[j].clear();





	}



	w.clear();
	p.clear();


	infile.close();
	outfile.close();





	return 0;





}