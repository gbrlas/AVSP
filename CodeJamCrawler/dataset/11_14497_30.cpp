#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cassert>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";

        int prev_orange_pos = 1;
        int prev_orange_time = 0;
        int prev_blue_pos = 1;
        int prev_blue_time = 0;
        int N = 0;
        int total = 0;
        cin >> N;
        char c;
        int pos = 0;
        // read the step, decide time needed.
        for (int j = 1; j <= N; j++)
        {
            cin >> c >> pos;
            if (c == 'O')
            {
                int dis = abs(pos - prev_orange_pos);
                int time1 = dis + 1 + prev_orange_time;
                int time2 = total + 1;
                total = max(time1, time2);
                prev_orange_time = total;
                prev_orange_pos = pos;
            }
            else {
                assert(c == 'B');
                int dis = abs(pos - prev_blue_pos);
                int time1 = dis + 1 + prev_blue_time;
                int time2 = total + 1;
                total = max(time1, time2);
                prev_blue_time = total;
                prev_blue_pos = pos;
            }
        }

        cout << total << "\n";
    }
}
