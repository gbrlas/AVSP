#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int cards[4][4];
	int cards1[4];
	int cards2[4];
	int result;
	int counter2 = 0;
	int T;
	int answer1 , answer2 , i , j , counter = 0;
	ofstream myfile ("Output.txt");
	std::fstream mydata("D:\\A-small-attempt1.in", std::ios_base::in);
	mydata >> T;
	while(T != 0)
	{
		mydata >> answer1;
		counter2++;
		for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j < 4 ; j++)
			{
				mydata >> cards[i][j];
			}
		}
		for(i = 0 ; i < 4 ; i++)
		{
			cards1[i] = cards[answer1-1][i];
		}
		mydata >> answer2;
		for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j < 4 ; j++)
			{
				mydata >> cards[i][j];
			}
		}
		for(i = 0 ; i < 4 ; i++)
		{
			cards2[i] = cards[answer2-1][i];
		}
		for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j < 4 ; j++)
			{
				if(cards1[i] == cards2[j]) {result = cards2[j]; counter++;}
			}
		}
		if(counter == 1) {myfile << "Case #" << counter2 << ": " << result;}
		else if(counter > 1) {myfile << "Case #" << counter2 << ": " << "Bad magician!";}
		else if(counter == 0) {myfile << "Case #" << counter2 << ": " << "Volunteer cheated!";}
		myfile << "\n";
		T--;
		counter = 0;
	}
	return 0;
}
