#include <iostream>
#include <vector>

using namespace std;

main()
{
  int TC, T = 0;
  int a, temp;
  int choosen[16];
  cin >> TC;
  while (T++ < TC)
  {
    for (int i = 0; i < 16; i++)
    {
      choosen[i] = 0;
    }
    cin >> a;
    a--;
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> temp;
        temp--;
        if (i == a)
        {
          choosen[temp]++;
        }
      }
    }
    
    cin >> a;
    a--;
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> temp;
        temp--;
        if (i == a)
        {
          choosen[temp]++;
        }
      }
    }
    
    int res = -1;
    bool valid = false;
    bool bad = false;
    for (int i = 0; i < 16; i++)
    {
      if (choosen[i] == 2)
      {
        if (valid)
        {
          valid = false;
          bad = true;
          break;
        }
        else
        {
          res = i;
          valid = true;
        }
      }
    }
    
    if (valid)
    {
      cout << "Case #" << T << ": " << res+1 << endl;
    }
    else
    {
      if (bad)
      {
        cout << "Case #" << T << ": Bad magician!" << endl;
      }
      else
      {
        cout << "Case #" << T << ": Volunteer cheated!" << endl;
      }
    }
  }
}