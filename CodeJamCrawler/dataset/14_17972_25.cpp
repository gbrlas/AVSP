#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int x = 1; x <= T; ++x)
	{
		int ans1,ans2,no_of_cards=0;
		int long long arr1[4][4],arr2[4][4],cards[4];
		cin >> ans1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin>>arr1[i][j];
			}
		}

		cin>>ans2;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin>>arr2[i][j];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				//cout<<"arr1: "<<arr1[ans1-1][i]<<"\tarr2: "<<arr2[ans2-1][j]<<"\n";
				if(arr1[ans1-1][i] == arr2[ans2-1][j])
				{
					
					cards[no_of_cards] = arr2[ans2-1][j];
					no_of_cards++;
				}
			}
		}
		//cout<<"\nno: "<<no_of_cards;
		switch(no_of_cards)
		{
			case 1: cout<<"Case #"<<x<<": "<<cards[0]<<endl;
					break;
			case 0:	cout<<"Case #"<<x<<": Volunteer cheated!"<<endl;
					break;

			default: cout<<"Case #"<<x<<": Bad magician!"<<endl;
		}
	}

}