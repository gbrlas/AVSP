#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

class hyj{
    public : char x, y;
};

hyj a[30];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    a[1].x = 'a';
a[1].y = 'y';
a[2].x = 'b';
a[2].y = 'h';
a[3].x = 'c';
a[3].y = 'e';
a[4].x = 'd';
a[4].y = 's';
a[5].x = 'e';
a[5].y = 'o';
a[6].x = 'f';
a[6].y = 'c';
a[7].x = 'g';
a[7].y = 'v';
a[8].x = 'h';
a[8].y = 'x';
a[9].x = 'i';
a[9].y = 'd';
a[10].x = 'j';
a[10].y = 'u';
a[11].x = 'k';
a[11].y = 'i';
a[12].x = 'l';
a[12].y = 'g';
a[13].x = 'm';
a[13].y = 'l';
a[14].x = 'n';
a[14].y = 'b';
a[15].x = 'o';
a[15].y = 'k';
a[16].x = 'p';
a[16].y = 'r';
a[17].x = 'q';
a[17].y = 'z';
a[18].x = 'r';
a[18].y = 't';
a[19].x = 's';
a[19].y = 'n';
a[20].x = 't';
a[20].y = 'w';
a[21].x = 'u';
a[21].y = 'j';
a[22].x = 'v';
a[22].y = 'p';
a[23].x = 'w';
a[23].y = 'f';
a[24].x = 'x';
a[24].y = 'm';
a[25].x = 'y';
a[25].y = 'a';
a[26].x = 'z';
a[26].y = 'q';
    int t;
    cin >> t;
    char ui[10];
    cin.getline(ui, 10);
    for (int r = 1; r <= t; r ++)
    {
        char x[300];
        cin.getline(x, 300);
        string b = x;
        int k = b.length();
        for (int i = 0; i <= k - 1; i ++)
        {
            if (b[i] == ' ') continue;
            for (int j = 1; j <= 26; j ++)
                if (a[j].x == b[i])
                {
                    b[i] = a[j].y;
                    break;
                }

        }
        cout << "Case #" << r << ": " << b << endl;
    }
    return 0;
}
