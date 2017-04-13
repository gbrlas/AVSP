#include <iostream>
#include <vector>
#include <string>
using namespace std;

int L, D, N;
int poss[15];
int tot;

vector <string> dict;

void input()
{
	scanf("%d%d%d", &L, &D, &N);
	string inp;
	for(int i = 0; i < D; i++)
	{
		cin >> inp;
		dict.push_back(inp);
	}
}

void process()
{
	int i, j;
	string cur;
	char ch;
	
	for(i = 0; i < D; i++)
	{
		cur = dict[i];
		for(j = 0; j < L; j++)
		{
			ch = cur[j];
			if((poss[j] & (1<<((int)ch-97))) == 0)
				break;
		}
		if(j == L)
			tot++;
	}
}

int main()
{
	input();
	int i, j, k;
	string inp;
	char cur;
	
	for(i = 1; i <= N; i++)
	{
		tot = 0;
		for(j = 0; j < L; j++)
		{
			poss[j] = 0;
		}
		cin >> inp;
		k = 0;
		for(j = 0; j < inp.length(); j++)
		{
			cur = inp[j];
			if(cur == '(')
			{
				j++; 
				cur = inp[j];
				while(cur != ')')
				{
					poss[k] += (1<<((int)cur-97));
					j++;
					cur = inp[j];
				}
				k++;
			}
			else
			{
				poss[k] += (1<<((int)cur-97));
				k++;
			}
		}
		//cout << inp;
		process();
		cout << "Case #" << i << ": " << tot << endl;
	}
}
