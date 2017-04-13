#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int C;
    cin >> C;
    for(int i = 0; i < C; ++i)
    {
        int N, M, A;
        cin >> N >> M >> A;

        bool solved = false;
        pair<int, int> a, b, c;
        for(int x3 = 1; x3 <= N; ++x3)
        {
            for(int y3 = -M; y3 <= M; ++y3)
            {
                for(int x2 = -N; x2 <= N; ++x2)
                {
                    int temp = (x2 * y3 - A);
                    int y2   = temp / x3;
                    if(y2 * x3 == temp)
                    {
                        // Validate that this is in range
                        if((abs(y3 - y2) <= M) && (abs(y3) <= M) && (abs(y2) <= M) && (abs(x3 - x2) <= N) && (abs(x2) <= N))
                        {
                            int x_off = min(0, min(x2, x3));
                            int y_off = min(0, min(y2, y3));
                            a.first  = -x_off;
                            a.second = -y_off;
                            b.first  = x2 - x_off;
                            b.second = y2 - y_off;
                            c.first  = x3 - x_off;
                            c.second = y3 - y_off;
                            solved   = true;
                            goto done;
                        }
                    }
                }
            }
        }

done:
        cout << "Case #" << (i + 1) << ": ";
        if(!solved)
            cout << "IMPOSSIBLE";
        else
        {
            int ax = b.first - a.first;
            int ay = b.second - a.second;
            int bx = c.first - a.first;
            int by = c.second - a.second;
            int area = abs(ax * by - ay * bx);
            if(area != A)
                cout << "OOPS" << " ";

            cout << a.first << " " << a.second << " " << b.first << " " << b.second << " " << c.first << " " << c.second;
        }
        cout << endl;
    }

    return 0;
}
