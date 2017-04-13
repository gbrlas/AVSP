#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#define MAX(x,y) (x) > (y) ? (x) : (y)
#define MIN(x,y) (x) < (y) ? (x) : (y)

using namespace std;

int minGold(vector<int> v, int Q)
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i]= -1;
	}
		int ming = 100000000;
		int coin;
	do
	{
		for (int i=0; i < Q; i++)
			arr[i] = 0;
		coin = 0;
	//	cout << "debug: " <<Q << endl;
	//	for (int i=0; i <v.size(); i++)
	//		cout << v[i] << " ";
		for (int i = 0; i < v.size(); i++)
		{
			arr[v[i] - 1] = -1;
			//left
			for (int j = v[i] - 2; j >= 0; j--)
			{
				if (arr[j] == -1)
					break;
				coin++;
			}
			//right
			for (int j = v[i]; j < Q; j++)
			{
				if (arr[j] == -1)
					break;
				coin ++;
			}
	//			cout << "Coin = : " <<coin <<endl;

		}
	//	cout << "Coin = : " <<coin <<endl;
		ming = MIN(ming,coin);

	}while (next_permutation(v.begin(),v.end()));
	return ming;
}

int main()
{
	ifstream fin ("a.in");
	//int arr[100];
	vector<int> v;
	//for (int i=0; i < 100; i++)
	//{
	//	arr[i] = -1;
	//}
	int N,P, Q, tmpInt;
	fin >> N;
	for (int i=0; i < N ; i++)
	{
		fin >> P >> Q;
		v.erase(v.begin(), v.end());
		for (int j=0; j < Q; j++)
		{
			fin >> tmpInt;
			v.push_back(tmpInt);
		}
//		for (i = 0; i < v.size(); i++)
//			arr[i] = 0;

		cout << "Case #" << i + 1 << ": " << minGold(v,P)<<endl;
	}
	return 0;
}
