#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define size(v) (int)sizeof(v)/sizeof(v[0]);
using namespace std;

#define print(v) for (int i=0; i!=size(v); ++i) cout << v[i] << ' ';
#define NL       cout << endl;

void answer (int v1[4], int v2[4])
{
	int cnt = 0;
	int flag;
	for (int i=0; i<4; ++i)
	{
		 if (count(v2, v2+4, v1[i]) > 0)
		 	flag = v1[i];
		 cnt += count(v2, v2+4, v1[i]);
	}
	if (cnt == 0)
	{
		cout << "Volunteer cheated!" << endl;
		return;
	}
	else if (cnt == 1)
	{
		cout << flag << endl;
		return;
	}
	else
	{
		cout << "Bad magician!" << endl;
		return;
	}
}

void input (int a[4][4])
{
	for (int i=0; i<4; ++i)
	{
		for (int j=0; j<4; ++j)
			cin >> a[i][j];
	}
	return;
}


int main()
{
	int T; cin >> T;
	int temp[4][4];
	int a[4], b[4];
	int n;
	for (int itr=0; itr<T; ++itr)
	{
		cin >> n;
		input(temp);
		for (int i=0; i<4; ++i)
			a[i] = temp[n-1][i];
		cin >> n;
		input(temp);
		for (int i=0; i<4; ++i)
			b[i] = temp[n-1][i];
		cout << "Case #" << itr+1 << ": ";
		answer(a, b);
	}
	
	return 0;
}
