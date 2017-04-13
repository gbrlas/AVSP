#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fin("ks.in");
	ofstream fout("C_Small.out");
	int t , n , k, r;
	int saveMoney = 0;
	int bank = 0;
	vector <int> groupesMember;
	fin >> t;
	for ( int i = 0 ; i < t; i++)
	{
		fin >> r >> k >> n;
		for ( int j = 0 ; j < n ; j++ )
		{
			int g;
			fin >> g;
			groupesMember.push_back(g);
		}
		for ( int j = 0 ; j < r; j ++)
		{
			for( int counter = 0 ; counter < n ; counter ++ )
			{
				if ( (k - bank) < groupesMember[0] )
					break;
				if ( counter == groupesMember.size())
					break;
				int temp;
				bank += groupesMember[0];
				temp = groupesMember[0];
				groupesMember.erase(groupesMember.begin());
				groupesMember.push_back(temp);
			}
			saveMoney += bank;
			bank = 0;
		}
		fout << "Case #" << i + 1 << ": " << saveMoney << endl;
		groupesMember.erase(groupesMember.begin() , groupesMember.end());
		saveMoney = 0;
	}
}
