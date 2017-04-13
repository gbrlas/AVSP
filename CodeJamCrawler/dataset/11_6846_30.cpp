#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main()
{
	ifstream in; 
	ofstream out; 

	in.open("A-small-attempt1.in");
	out.open("A-small.txt"); 
	
	int cnt = 1, TestCase;

	in >> TestCase; 

	while(TestCase--)
	{
		int time1 = 0, time2 = 0, num, button;
		char ch;
		vector<pair<char,int> > Button;
		vector<char> B_Button;
		vector<char> O_Button;

		in >> num; 

		for(int a = 0; a < num; a++ )
		{
			in >> ch >> button; 
			Button.push_back(make_pair(ch, button) );

			if( ch == 'B' ) B_Button.push_back(button);
			else O_Button.push_back(button);
		}

		int B_Cur = 1, O_Cur = 1;
		int idx = 0, B_idx = 0, O_idx = 0; 
		int move = 0, time = 0;

		for(int a = 0; a < num; a++ )
		{
			if( Button[a].first == 'O') 
			{		
				move = abs(O_Button[O_idx] - O_Cur); 
				if( B_idx < B_Button.size() )
				{
					if( B_Button[B_idx] > B_Cur)
					{
						B_Cur += ( move + 1);
						if( B_Cur >= B_Button[B_idx] ) B_Cur = B_Button[B_idx];
					}
					else
					{
						B_Cur -= (move + 1);
						if( B_Cur <= B_Button[B_idx] ) B_Cur = B_Button[B_idx];
					}
				}
				O_Cur = O_Button[O_idx];
				time += (move+1);
				O_idx++;
			}
			else
			{
				move = abs(B_Button[B_idx] - B_Cur); 
				if( O_idx < O_Button.size()) 
				{
					if( O_Button[O_idx] > O_Cur)
					{
						O_Cur += ( move + 1);
						if( O_Cur >= O_Button[O_idx] ) O_Cur = O_Button[O_idx];
					}
					else
					{
						O_Cur -= (move + 1);
						if( O_Cur <= O_Button[O_idx] ) O_Cur = O_Button[O_idx];
					}
				}
				B_Cur = B_Button[B_idx];
				time += (move+1);
				B_idx++;
			}
		}
		cout << "Case #" << cnt << ": " << time << endl;
		out << "Case #" << cnt++ << ": " << time << endl;
	}
	out.close(); 
	in.close();

	return 0;
}