#include <iostream>

using namespace std;

bool diagonal(char ch, char input_2D_array[4][4])
{
	int nTemp = 0;

	for(int nCount = 0; nCount < 4; nCount++)
	{
		if(input_2D_array[nCount][nCount] == ch || input_2D_array[nCount][nCount] == 'T')
		{
			nTemp++;
		}
	}

	if(nTemp == 4)
	{
		return true;
	}
	else
	{
		nTemp = 0;
	}

	for(int nCount_1 = 3, nCount_2 = 0; nCount_1 >= 0, nCount_2 < 4; nCount_1--, nCount_2++)
	{
		if(input_2D_array[nCount_1][nCount_2] == ch || input_2D_array[nCount_1][nCount_2] == 'T')
		{
			nTemp++;
		}

	}

	if(nTemp == 4)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

bool vertical(char ch, char input_2D_array[4][4])
{
	int nTemp = 0;

	for(int nCount_1 = 0; nCount_1 < 4; nCount_1++)
	{
		for(int nCount_2 = 0; nCount_2 < 4; nCount_2++)
		{
			if(input_2D_array[nCount_2][nCount_1] == ch || input_2D_array[nCount_2][nCount_1] == 'T')
			{
				nTemp++;
			}
		}

		if(nTemp == 4)
		{
			return true;
		}
		else
		{
			nTemp = 0;
		}
	}

	return false;
}

bool horizontal(char ch, char input_2D_array[4][4])
{
	int nTemp = 0;

	for(int nCount_1 = 0; nCount_1 < 4; nCount_1++)
	{
		for(int nCount_2 = 0; nCount_2 < 4; nCount_2++)
		{
			if(input_2D_array[nCount_1][nCount_2] == ch || input_2D_array[nCount_1][nCount_2] == 'T')
			{
				nTemp++;
			}
		}

		if(nTemp == 4)
		{
			return true;
		}
		else
		{
			nTemp = 0;
		}
	}

	return false;
}

bool incomplete(char input_2D_array[4][4])
{
	for(int nCount_1 = 0; nCount_1 < 4; nCount_1++)
	{
		for(int nCount_2 = 0; nCount_2 < 4; nCount_2++)
		{
			if(input_2D_array[nCount_1][nCount_2] == '.')
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int nTestCases = 0;
	cin>>nTestCases;

	string *str_outputs = new string[nTestCases];

	//algorithm take every input and then calculate the output
	//X and O are capital letters.

	for(int nCount = 0; nCount < nTestCases; nCount++)
	{
		char input_2D_array[4][4];

		for(int nCount_1 = 0; nCount_1 < 4; nCount_1++)
		{
			for(int nCount_2 = 0; nCount_2 < 4; nCount_2++)
			{
				cin>>input_2D_array[nCount_1][nCount_2];
			}
		}

		//check for 'X' then for 'O'
		if(diagonal('X', input_2D_array) == true)
		{
			//Case #1: X won
			str_outputs[nCount] = "X won";
			continue;
		}
		else if(diagonal('O', input_2D_array) == true)
		{
			str_outputs[nCount] = "O won";
			continue;
		}
		else if(vertical('X', input_2D_array) == true)
		{
			str_outputs[nCount] = "X won";
			continue;
		}
		else if(vertical('O', input_2D_array) == true)
		{
			str_outputs[nCount] = "O won";
			continue;
		}
		else if(horizontal('X', input_2D_array) == true)
		{
			str_outputs[nCount] = "X won";
			continue;
		}
		else if(horizontal('O', input_2D_array) == true)
		{
			str_outputs[nCount] = "O won";
			continue;
		}
		else if(incomplete(input_2D_array) == true)
		{
			str_outputs[nCount] = "Game has not completed";
			continue;
		}
		else
		{
			str_outputs[nCount] = "Draw";
			continue;
		}
	}

	//output the results.

	for(int nCount = 0; nCount < nTestCases; nCount++)
	{
		//Case #1: X won

		cout<<"Case ";
		cout<<"#"<<nCount + 1;
		cout<<": ";
		for(int nCount_1 = 0; nCount_1 < str_outputs[nCount].length(); nCount_1++)
		{
			cout<<str_outputs[nCount][nCount_1];
		}
		cout<<"\n";
	}

	int n;
	cin>>n;

	return 0;
}