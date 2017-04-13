#include<iostream>
#include<set>
#include<vector>
#include<fstream>
using namespace std;
void solve(unsigned int i, unsigned int A, unsigned int B, unsigned int K, ofstream &out)
{
	int ans = 0;
	for(int x = 0; x < A; x++)
	{
		for(int y = 0; y < B; y++)
		{
			unsigned int xy = x&y;
			if(xy < K)
				ans++;
		}
	}
	out<<"Case #"<<i<<": "<<ans<<endl;
}
int main(int argc, char *argv[])
{
	int T;
	
	ifstream input(argv[1]);
        ofstream output("newlottery.txt",ios::trunc|ios::out);
	input >> T;
	for(int i = 0; i < T; i++)
	{
		unsigned int A,B,K;
		input >> A;
		input >> B;
		input >> K;
		solve(i+1,A,B,K,output);
	}
	input.close();
	output.close();
	return 0;
}
