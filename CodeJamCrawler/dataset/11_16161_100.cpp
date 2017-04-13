#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

int main()
{
	ifstream fin("mag.in");
	ofstream fout("mag.out");
	int T, C, D, N;
	fin >> T;
	char comb[26][26];
	bool opp[26][26];
	for (int casenum = 1; casenum <= T; casenum++)
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				comb[i][j] = '@';
				opp[i][j] = false;
			}
		}
		fin >> C;
		char x, y, z;
		for (int i = 0; i < C; i++)
		{
			fin >> x >> y >> z;
			comb[x - 'A'][y - 'A'] = z;
			comb[y - 'A'][x - 'A'] = z;
		}
		fin >> D;
		for (int j = 0; j < D; j++)
		{
			fin >> x >> y;
			opp[x - 'A'][y - 'A'] = true;
			opp[y - 'A'][x - 'A'] = true;
		}
		fin >> N;
		vector<char> ans;
		int leng = 0;
		for (int k = 0; k < N; k++)
		{
			fin >> x;
			if ((leng > 0) && (comb[x - 'A'][ans[leng-1] - 'A'] != '@'))
			{
				ans.pop_back();
				ans.push_back(comb[x - 'A'][ans[leng-1] - 'A']);
			}
			else
			{
				bool clrd = false;
				for (int ls = 0; ls < leng; ls++)
				{
					if (opp[x - 'A'][ans[ls] - 'A'])
					{
						ans.clear();
						clrd = true;
						leng = 0;
						break;
					}
				}
				if (!clrd)
				{
					ans.push_back(x);
					leng++;
				}
			}
		}
		fout << "Case #" << casenum << ": [";
		for (int ls = 0; ls < leng - 1; ls++)
			fout << ans[ls] << ", ";
		if (leng > 0)
			fout << ans[leng-1];
		fout << ']' << endl;
	}
}
