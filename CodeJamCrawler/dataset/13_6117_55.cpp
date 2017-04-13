#include <cstdio>
using namespace std;

char data[4][5];

bool check(char a, char b, char c, char d, int test)
{
    int x = 0;
    int o = 0;
    int t = 0;

    char data[] = {a, b, c, d};

    for (int i = 0; i < 4; i++) {
        switch (data[i]) {
        case 'X':
            x++;
            break;
        case 'O':
            o++;
            break;
        case 'T':
            t++;
            break;
        }
    }

    if (x == 4 || (x == 3 && t == 1)) {
        printf("Case #%i: X won\n", test + 1);
        return false;
    } else if (o == 4 || (o == 3 && t == 1)) {
        printf("Case #%i: O won\n", test + 1);
        return false;
    } else {
        return true;
    }
}

int main()
{
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%s", data[j]);
        }
        
        bool ended = false;

        for (int j = 0; j < 4; j++) {
            if (!check(data[j][0], data[j][1], data[j][2], data[j][3], i) ||
                !check(data[0][j], data[1][j], data[2][j], data[3][j], i)) {
                ended = true;
                break;
            }
        }

        if (!ended &&
            !check(data[0][0], data[1][1], data[2][2], data[3][3], i) ||
            !check(data[0][3], data[1][2], data[2][1], data[3][0], i)) {
            ended = true;
        }
        
        if (ended) continue;

        bool draw = true;
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (data[x][y] == '.') {
                    draw = false;
                    goto exit_loop;
                }
            }
        }
        
    exit_loop:
        if (draw) {
            printf("Case #%i: Draw\n", i+1);
        } else {
            printf("Case #%i: Game has not completed\n", i+1);
        }
    }

    return 0;
}
