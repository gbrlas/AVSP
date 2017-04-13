#include <iostream>

int main(int argc, char **argv)
{
    int T;
    std::cin >> T;

    int a[4][4], b[4][4];
    for (int k = 1; k <= T; k++)
    {
        int f, s;

        std::cin >> f;
        f--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                std::cin >> a[i][j];

        std::cin >> s;
        s--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                std::cin >> b[i][j];

        int match = 0, number;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (a[f][i] == b[s][j])
                {
                    number = a[f][i];
                    match++;
                }

        std::cout << "Case #" << k << ": ";
        if (match == 0)
            std::cout << "Volunteer cheated!" << std::endl;
        else if (match == 1)
            std::cout << number << std::endl;
        else
            std::cout << "Bad magician!" << std::endl;
    }
}
