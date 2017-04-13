//Code Jam "Saving the universe"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool testSt(vector <bool> &st)
{
	for(int i = 0; i < st.size(); i++)
	{
		if(st[i])
			return true;
	}
	return false;
}
	
int main()
{
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int S, Q;
		cin >> S;
		
		vector <string> searchEng(S, "");
		char str[101];
		
		cin.clear();
		cin.ignore();
		for(int j = 0; j < S; j++)
		{
			cin.getline(str, 101);
			searchEng[j] = str;
		}
		
		cin >> Q;
		vector <string> query(Q, "");
		cin.clear();
		cin.ignore();
		for(int j = 0; j < Q; j++)
		{
			cin.getline(str, 101);
			query[j] = str;
		}
		
		vector <bool> st(S, true);
		int ans = 0;
		for(int j = 0; j < Q;)
		{
			while(testSt(st))
			{
				int pos = find(searchEng.begin(), searchEng.end(), query[j]) - searchEng.begin();
				st[pos] = false;
				j++;
				if(j >= Q)
					break;
			}
			
			//cout << "j = " << j << endl;
			if(!testSt(st))
			{
				ans++;
				j--;		
			}
			for(int k = 0; k < S; k++)
			{
				st[k] = true;
			}
		}
		
		cout << "Case #" << i + 1 << ": " << ans;
		if(i != N - 1)
			cout << endl; 
	}
	
	return 0;
}
