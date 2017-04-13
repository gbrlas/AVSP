#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (int) (n); (i)++)

int windowNum[33] = {0};
int checkboard[32][32];
int templateWindow[32][32];
const char* binaryNums[16] = {"0000", "0001", "0010", "0011",
						"0100", "0101", "0110", "0111",
						"1000", "1001", "1010", "1011", "1100",
						"1101", "1110", "1111"};

void constructTemplateWindow(void)
{
	for(int i = 0; i < 32; i++)
	{
		int color = i % 2;
		for(int j = 0; j < 32; j++)
		{
			templateWindow[i][j] = color;
			color = (color + 1) % 2;
		}
	}
}

bool compareTwoWindow(int win1[32][32], int left1, int up1,
					  int win2[32][32], int left2, int up2,
					  int windowSize)
{
	// win2 as template
	int sum = 0;
	for(int i = 0; i < windowSize; i++)
	{
		for(int j = 0; j < windowSize; j++)
		{
			sum += (win1[up1 + i][left1 + j] + win2[up2 + i][left2 + j]) % 2;
		}
	}
	if(sum == 0 || sum == windowSize * windowSize)
	{
		for(int i = 0; i < windowSize; i++)
			for(int j = 0; j < windowSize; j++)
			{
				win1[up1 + i][left1 + j] = -1;
			}
		return true;
	}
	return false;
}

bool checkValidBoard(int win[32][32], int left, int up, int windowSize)
{
	for(int i = 0; i < windowSize; i++)
		for(int j = 0; j < windowSize; j++)
		{
			if(win[up + i][left + j] == -1)
				return false;
		}
	return true;
}

int main(int argc, char *argv)
{
	ifstream input("C-small-attempt0.in");
	ofstream output("C-small.out");
	int T;
	input>>T;

	//bool aa = compareTwoWindow(templateWindow2, 0, 0, templateWindow, 0, 0, 32);
	FOR(cases, T)
	{
		constructTemplateWindow();
		for(int i = 0; i < 33; i++)
			windowNum[i] = 0;
		int M,N;
		input>>M>>N;
		FOR(i,M)
		{
			//FOR(j,N)
			//{
			string str;
			input>>str;
			FOR(k, str.size())
			{
				int index;
				if(str[k] >= '0' && str[k] <= '9')
				{
				    index = str[k] - '0';
				}
				else if(str[k] >= 'A' && str[k] <= 'F')
				{
					index = str[k] - 'A' + 10;
				}
				string currentBinaryNum(binaryNums[index]);
				FOR(h, 4)
				{
					checkboard[i][k * 4 + h] = currentBinaryNum[h] - '0';
				}
			}
			//}
		}
		int maxSize = min(M, N);
		for(int currentSize = maxSize; currentSize >= 1; currentSize--)
		{
			for(int i = 0; i < M; i++)
			{
				if(i + currentSize > M)
					break;
				for(int j = 0; j < N; j++)
				{
					if(j + currentSize > N)
						break;
					if(checkValidBoard(checkboard, j, i, currentSize))
					{
						bool flag = compareTwoWindow(checkboard, j, i,
							templateWindow, 0, 0, currentSize);
						if(flag)
						{
							windowNum[currentSize]++;
						}
					}
				}
			}
		}
		vector<int> windowSizes;
		vector<int> num;
		for(int i = maxSize; i > 0; i--)
		{
			if(windowNum[i] > 0)
			{
				windowSizes.push_back(i);
				num.push_back(windowNum[i]);
			}
		}
		output<<"Case #"<<cases+1<<": "<<windowSizes.size()<<endl;
		for(int i = 0; i < windowSizes.size(); i++)
		{
			output<<windowSizes[i]<<" "<<num[i]<<endl;
		}
	}
}