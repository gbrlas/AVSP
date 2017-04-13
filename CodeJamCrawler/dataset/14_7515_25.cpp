#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;
    int N = 4;
    cin >> T;
    for (int tCase = 1; tCase <= T; tCase++)
    {
      int row1;
      cin >> row1;
      vector<int> values = vector<int>(N);
      for (int i = 0; i < N; ++i)
      {
	  for (int j = 0; j < N; ++j)
	  {
	      int v;
	      cin >> v;
	      if (i + 1 != row1) continue;
	      values[j] = v;
	  }

      }
      
      int row2;
      cin >> row2;
      int sol;
      int found = 0;
      for (int i = 0; i < N; ++i)
      {
	  for (int j = 0; j < N; ++j)
	  {
	      int v;
	      cin >> v;
	      if (i + 1 != row2 || found > 1) continue;
	      for(int k = 0; k < N; ++k)
	      {
		if (values[k] == v)
		{
		  sol = v;
		  found++; 
		  break;
		}
	      }
	      
	  }
      }
      if (found == 0)
      {
	cout << "Case #" << tCase << ": Volunteer cheated!" << endl;
      }
      else if(found == 1)
      {
	cout << "Case #" << tCase << ": " << sol << endl;
      }
      else
      {
	cout << "Case #" << tCase << ": Bad magician!" << endl;
      }

    }

    return 0;
}
