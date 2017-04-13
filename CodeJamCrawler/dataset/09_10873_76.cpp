#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



int sfind(string &s1, string &s2, int n, int m, const int &s1_len, const int &s2_len)//n must in [0...18]!!!!!!!
{
	size_t found;

	int num=0;
	int n1=0,m1=0;

	if(n==18)
	{
		if(m<s2_len)
		{
			found=s2.find(s1[18],m);
			while(  (found!=string::npos)&&(m<s2_len)  )
			{

				++num;
				num = num%10000;
				m = (int)found + 1;
				found=s2.find(s1[18],m);

			}

		}



		
			return num;

	}



	while(m<s2_len)
	{
		
	
		found=s2.find(s1[n],m);
		m = (int)found + 1;


		
		if(found==string::npos)
		{

			//num = 0;
			return num;

		}
		else
		{
			m1 = (int)found + 1;
			n1 = n+1;

			num = num + sfind(s1,s2,n1,m1,s1_len,s2_len);
			num = num%10000;

		
		}



	
	}



	return num;



};







int main(int argc, char* argv[])
{

	int n=0;
	int i=0,j=0,i1=0,j1=0;
	int num=0;

	//size_t found;

	string s;
	s="welcome to code jam";


	//	ifstream cin("A-small-practice.in.txt");
	ifstream infile;
	ofstream outfile;







	infile.open("C-small-attempt0.in");
	assert(infile);

	outfile.open("C-small-result.txt");
	assert(outfile);



	infile>>n;

	cout<<"n = "<<n<<endl;


	char c_temp;
	infile.get(c_temp);
	cout<<"c_temp = "<<c_temp<<endl;






	vector<string> w(n);

	for(i=0;i<n;++i)
	{

		getline(infile,w[i],'\n');

	}




	outfile << setfill('0');



	for(i=1;i<=n;++i)
	{



		outfile<<"Case #"<<i<<":"<<" "<<setw(4)<<sfind(s,w[i-1],0,0,19,(int)w[i-1].length())<<endl;



	}







	w.clear();


	infile.close();
	outfile.close();





	return 0;





}