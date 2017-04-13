#include <iostream>
#include <fstream>

int main()
{
    std::fstream input("input.in", std::fstream::in);
    std::fstream output("output.out", std::fstream::out);

    int test_cases;
    input >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int R, C;
        input >> R >> C;

        char tileset[R][C];
        int r, c;
        for (r = 0; r < R; r++)
        {
            for (c = 0; c < C; c++)
                input >> tileset[r][c];
        }

        bool possible = true;
        r = 0; c = 0;
        while (possible && r < R)
        {
            //std::cout << tileset[r][c];
            if (tileset[r][c] == '#')
            {
                if (tileset[r][c+1] == '#' && tileset[r+1][c] == '#' && tileset[r+1][c+1] == '#')
                {
                    tileset[r][c] = '/'; tileset[r][c+1] = '\\';
                    tileset[r+1][c] = '\\'; tileset[r+1][c+1] = '/';
                }
                else
                    possible =  false;
            }

            c++;
            if (c > C)
            {
                c = 0;
                r++;
                //std::cout << std::endl;
            }
        }

        output << "Case #" << test_case+1 << ":" << std::endl;
        if (possible)
        {
            for (r=0; r < R; r++)
            {
                for (c=0; c < C; c++)
                    output << tileset[r][c];
                output << std::endl;
            }
        }
        else
            output << "Impossible" << std::endl;
    }

    system("pause");

    return 0;
}
