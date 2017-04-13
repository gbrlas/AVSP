#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int buttons[t];
	int *button[t];
	char *bot[t];
	
	for (int i = 0; i < t; i++)
	{
		cin >> buttons[i];
		button[i] = new int[buttons[i]];
		bot[i] = new char[buttons[i]];
		for (int j = 0; j < buttons[i]; j++)
			cin >> bot[i][j] >> button[i][j];
	}
	
	int cpo, cpb, dpo, dpb, ao, ab, steps;
	int tm;
	for (int i = 0; i < t; i++)
	{
		cpo = cpb = 1;
		tm=0;
		for (ao = 0; ao<buttons[i]; ao++)
		{
			if (bot[i][ao] == 'O')
			{
				dpo = button[i][ao];
				break;
			}
		}
		for (ab = 0; ab<buttons[i]; ab++)
		{
			if (bot[i][ab] == 'B')
			{
				dpb = button[i][ab];
				break;
			}
		}
		
		while (!(ao == buttons[i] && ab == buttons[i]))
		{
			if (ao < ab)
			{
				steps = abs(dpo-cpo)+1;
				tm = tm+steps;
				if (cpb < dpb)
					cpb = (cpb+steps) < dpb ? (cpb+steps):dpb;
				else
					cpb = (cpb-steps) > dpb ? (cpb-steps):dpb;
				cpo = dpo;
				for (ao++; ao<buttons[i]; ao++)
				{
					if (bot[i][ao] == 'O')
					{
						dpo = button[i][ao];
						break;
					}
				}
			}
			else
			{
				steps = abs(dpb-cpb)+1;
				tm = tm+steps;
				if (cpo < dpo)
					cpo = (cpo+steps) < dpo ? (cpo+steps):dpo;
				else
					cpo = (cpo-steps) > dpo ? (cpo-steps):dpo;
				cpb = dpb;
				for (ab++; ab<buttons[i]; ab++)
				{
					if (bot[i][ab] == 'B')
					{
						dpb = button[i][ab];
						break;
					}
				}
			}
		}
		cout << "Case #" << i+1 << ": " << tm << endl;
			
	}
		
}

