#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int row, card, testcases, i, j, k;
    set<int> inter;
    map<int, int> all;
    map<int, int>::iterator it;

    cin >> testcases;
    for(i = 1; i <= testcases; i++)
    {
        cin >> row;
        for(j = 1; j <= 4; j++)
          for(k = 1; k <= 4; k++)
          {
              cin >> card;
              if(j == row)
              {
                  inter.insert(card);
                  if(all.find(card) != all.end())
                      all[card]++;
                  else
                      all[card] = 1;
              }
          }
        
        cin >> row;
        for(j = 1; j <= 4; j++)
          for(k = 1; k <= 4; k++)
          {
              cin >> card;
              if(j == row)
              {
                  inter.insert(card);
                  if(all.find(card) != all.end())
                      all[card]++;
                  else
                      all[card] = 1;
              }
          }
        
        cout << "Case #" << i << ": ";
        if(inter.size() == 8)
            cout << "Volunteer cheated!" << endl;
        else if(inter.size() < 7)
            cout << "Bad magician!" << endl;
        else
        {
            for(it = all.begin(); it != all.end(); it++)
            {
                if((*it).second > 1)
                {
                    cout << (*it).first << endl;
                    break;
                }
            }
        }
          
            
        inter.clear();
        all.clear();
    }
}
