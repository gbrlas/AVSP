	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		long double cases, r , t, ans, used,temp;
		string a;
		cin >> cases;
		getline(cin,a); //for extra space
		for(int i =1; i <= cases; i++)
		{
			cin >> r >> t;
			used = 0;
			ans = 0;
			while(t > used)
			{
				temp = (2*r) + (4*ans +1);
				if(t >= (used + temp))
				{
					ans++;
					used += temp;
				}
				else
					break;
			}
			cout << "Case #" << (i) << ": " << (long long int)ans <<"\n";	
			getline(cin,a); //for extra space
		}
		return 0;
	}