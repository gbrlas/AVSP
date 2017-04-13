#include <iostream>

using namespace std;

int counter = 1;
void cardCheck(int x[4][4], int y[4][4], int choice1, int choice2)
{
int limit = 0;
int card;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if (x[choice1 - 1][i] == y[choice2 - 1][j])
			{
				limit += 1;
				card = x[choice1 -1][i];
			}
		}	
	}
	if (limit > 1)
		cout << "Case #" <<counter << ": Bad magician!" << endl;
	else if (limit == 0)
  	cout << "Case #" <<counter<< ": Volunteer cheated!" << endl;
	else if (limit == 1)
		cout << "Case #" <<counter<< ": " << card << endl;
counter++;
}

int main()
{
	int choice1;
	int choice2;
	int cards1[4][4];
	int cards2[4][4];
	int caseNum;
	cin>>caseNum;
	for (int i = 0; i < caseNum; i++)
	{
  	cin>>choice1;	
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
				cin>>cards1[row][col];
  	cin>>choice2;	
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
				cin>>cards2[row][col];
		cardCheck(cards1, cards2, choice1, choice2);
	}
}	
