#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int jail[101], P;

int go(int idx)
{
	int cnt = 0;

	for(int a = idx-1; a >=1; a-- )
	{
		if( jail[a] == 0 ) break;
		cnt++;
	}

	for(int a = idx+1; a <= P; a++ )
	{
		if( jail[a] == 0 ) break;
		cnt++;
	}

	return cnt;
}

int main()
{
	int T; 
	ifstream in; 
	ofstream out;
	in.open("C-small-attempt0.in");
	out.open("C.out");
	in >> T; 

	for(int i = 1; i <= T; i++ )
	{
		int Q, n;
		in >> P >> Q; 
		vector<int> release;
		for(int a = 0; a < Q; a++ )
		{
			in >> n;
			release.push_back(n);
		}

		for(int a = 1; a <= P; a++ ) jail[a] = 1;

		sort(release.begin(), release.end());
		int ret = 0, Min = 987654321;
		do{
			for(int a = 1; a <= P; a++ ) jail[a] = 1;
			ret = 0;
			for(int a = 0; a < Q; a++ )
			{
				jail[release[a]] = 0;
				ret+= go(release[a]);
			}

			if( ret < Min ) Min = ret;


		}while(next_permutation(release.begin(), release.end()));
				

		cout << "Case #" << i << ": " << Min << endl;
		out << "Case #" << i << ": " << Min << endl;
	}

	return 0;
}