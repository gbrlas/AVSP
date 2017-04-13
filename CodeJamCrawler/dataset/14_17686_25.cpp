#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    int A[4][4];
    set<int> s, t;
    for (int step = 0; step < T; step++)
    {
        int a, c = 0;
        cin >> a;
        a--;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> A[i][j];
            }
        }
        s.insert(A[a][0]);
        s.insert(A[a][1]);
        s.insert(A[a][2]);
        s.insert(A[a][3]);
        cin >> a;
        a--;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> A[i][j];
            }
        }
        t.insert(A[a][0]);
        t.insert(A[a][1]);
        t.insert(A[a][2]);
        t.insert(A[a][3]);
        set<int>::iterator i;
        int b = -1;
        for (i = s.begin(); i != s.end(); i++)
        {
            if (t.count(*i) != 0)
            {
                c++;
                if (c == 1)
                {
                    b = *i;
                }
            }
        }
        s.clear();
        t.clear();
        if (c == 1)
        {
            cout << "Case #" << step + 1<< ": "  << b << endl;
        }
        if (c > 1)
        {
            cout << "Case #" << step + 1<< ": Bad magician!" << endl;
        }
        if (c == 0)
        {
            cout << "Case #" << step + 1<< ": Volunteer cheated!" << endl;
        }

    }
    return 0;
}
