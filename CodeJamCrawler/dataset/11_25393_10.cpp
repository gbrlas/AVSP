#include <iostream>
#include <vector>
#include <fstream>
#include <set>
using namespace std;

vector<bool> addBinaire(vector<bool> &nb1, vector<bool> &nb2)
{
	vector<bool> res;
	if(nb1.size() < nb2.size())
		return addBinaire(nb2, nb1);
	bool carry = 0,fin2 = false;
	for(int i = 0; i < nb1.size(); i++)
	{
		bool resOp;
		if(i == nb2.size())
			fin2 = true;

		if(!fin2)
		{
			resOp = nb1[i] ^ nb2[i];
		}
		else
		{
			resOp = nb1[i] ;
		}
		res.push_back(resOp);
	}
	return res;
}

int binTo(vector<bool> num)
{
	long long puis2 = 1, res = 0;
	for(int i = 0; i < num.size(); i++)
	{
		res += puis2 * num[i];
		puis2 *= 2;
	}
	return res;
}
vector<bool> toBin(int nbr)
{
	vector<bool> res;
	while(nbr)
	{
		res.push_back(nbr % 2);
		nbr /= 2;
	}
	return res;
}

int realsumpart(vector<int> &vec , vector<int>&indices)
{
	int sum = 0;
	for(int i =0 ; i < indices.size(); i++)
	{
		sum += vec[indices[i]];
	}
	return sum;
}
int sumpart(vector<int> &vec , vector<int>&indices)
{
	vector<bool> res;

	for(int i =0 ; i < indices.size(); i++)
	{
		vector<bool> b = toBin(vec[indices[i]]);
		res = addBinaire (res, b);
	}
	return binTo(res);
}


template<class T>
ostream& operator<< (ostream &o, vector<T> &vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		o << vec[i] << " ";
	}
	return o;
}
void comb(vector<int>& vec, int m,int pos, vector<int>&chemin,int depth, int &max)
{
	if(depth == m)
	{
		vector<bool> nums;
		nums.assign( vec.size(), false );
		vector<int> chemin2 , chemin1;
		for(int i = 0; i < chemin.size();i++)
			nums[chemin[i]] = true;
		for(int i = 0; i < vec.size(); i++)
		{
			if(!nums[i])
				chemin2.push_back(i);
		}
		//cout << chemin << endl;
		//cout << chemin2 << endl;
		int part1 = sumpart(vec, chemin);
		int part2 = sumpart(vec, chemin2);
		int realpart2 = realsumpart(vec, chemin2);
		if(part1 == part2)
		{
			if(realpart2 > max)
				max  = realpart2;
		}
		return;
	}
	for(int i = pos; i < vec.size(); i++)
	{
		chemin.push_back(i);
		comb(vec, m, i+1, chemin, depth + 1, max);
		chemin.pop_back();
	}
}

void showBin(vector<bool> num)
{
	for(int i = num.size() - 1 ; i>=0; i--)
		cout << num[i];
	cout << endl;
}

int main()
{
	int N;
	ifstream fin("file.in");
	ofstream fout("file.out");
	fin >> N;
	for(int i = 0; i < N; i++)
	{
		int numd;
		fin >> numd;
		vector<int> dandy;
		for(int j = 0;j <  numd;j++)
		{
			int r;
			fin >> r;
			dandy.push_back(r);
		}
		int max =  -1;
		vector<int> chemin;
		for(int l = 0; l < dandy.size() / 2;l++)
			comb(dandy, l + 1, 0, chemin, 0, max);
		fout << "Case #" << (i+1)<<": ";
		if(max == -1)
			fout << "NO";
		else
			fout << max;
		fout << endl;
	}
	fout.close();
	fin.close();
	return 0;
}
