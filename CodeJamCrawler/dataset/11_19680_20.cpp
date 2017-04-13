#include <iostream>
using namespace std;

int t, n;

int dist(int a, int b)
{
    if (a < b) return b - a;
    else return a - b;
}

int main()
{
   freopen("A-large.in", "r", stdin);
   freopen("output2.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int total = 0;
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        int pos[2];
        int ti[2];
        pos[0] = pos[1] = 1;
        ti[0] = ti[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            string who;
            cin >> who;
            int w;
            if (who == "O") w = 1;
            if (who == "B") w = 0;
            int goal;
            cin >> goal;
            int d = dist(goal, pos[w]) + 1;
            if (d <= ti[w]) {
                  total = total + 1;
                  ti[w] = 0;
                  pos[w] = goal;
                  ti[1 - w]++;
            }
            else
            {
                total = total + d - ti[w];
                ti[1 - w] = ti[1 - w] + d - ti[w];
                ti[w] = 0;
                pos[w] = goal;
            }
//            cout << total << endl;
        }
     //   while (1);
     cout << total << endl;
    }
  //  while (1);
    return 0;
}

