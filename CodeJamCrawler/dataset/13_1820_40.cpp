#include <fstream>

using namespace std;

int main()
{
    ifstream fin("a.in");
    ofstream fout("a.out");
    int t;
    fin >> t;
    char m[4][4];
    for (int i = 0; i < t; ++i)
    {
        bool flag = false;
        int tmp3 = 0, tmp4 = 0;
        fin >> m[0][0] >> m[0][1] >> m[0][2] >> m[0][3];
        fin >> m[1][0] >> m[1][1] >> m[1][2] >> m[1][3];
        fin >> m[2][0] >> m[2][1] >> m[2][2] >> m[2][3];
        fin >> m[3][0] >> m[3][1] >> m[3][2] >> m[3][3];

        for (int k = 0; k < 4; ++k)
        {
            int tmp1 = 0, tmp2 = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (m[k][j] == 'O' || m[k][j] == 'T')
                    ++tmp1;
                if (m[k][j] == 'X' || m[k][j] == 'T')
                    ++tmp2;
            }
            if (tmp1 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "O won\n";
                flag = true;
                break;
            }
            if (tmp2 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "X won\n";
                flag = true;
                break;
            }

            tmp1 = 0, tmp2 = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (m[j][k] == 'O' || m[j][k] == 'T')
                    ++tmp1;
                if (m[j][k] == 'X' || m[j][k] == 'T')
                    ++tmp2;
            }
            if (tmp1 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "O won\n";
                flag = true;
                break;
            }
            if (tmp2 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "X won\n";
                flag = true;
                break;
            }
            if (m[k][k] == 'O' || m[k][k] == 'T')
                ++tmp3;
            if (m[k][k] == 'X' || m[k][k] == 'T')
                ++tmp4;
            if (tmp3 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "O won\n";
                flag = true;
                break;
            }
            if (tmp4 == 4)
            {
                fout << "Case #" << i + 1 << ": " << "X won\n";
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            tmp3 = 0;
            tmp4 = 0;
            for (int k = 3, j = 0; k >= 0; --k, ++j)
            {
                if (m[j][k] == 'O' || m[j][k] == 'T')
                    ++tmp3;
                if (m[j][k] == 'X' || m[j][k] == 'T')
                    ++tmp4;
                if (tmp3 == 4)
                {
                    fout << "Case #" << i + 1 << ": " << "O won\n";
                    flag = true;
                    break;
                }
                if (tmp4 == 4)
                {
                    fout << "Case #" << i + 1 << ": " << "X won\n";
                    flag = true;
                    break;
                }
            }
        }

        if (flag == false)
        {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (m[j][k] == '.')
                    {
                        flag = true;
                    }
                }
            }
            if (flag == true)
            {
                fout << "Case #" << i + 1 << ": " << "Game has not completed\n";
                flag = false;
            }
            else
            {
                fout << "Case #" << i + 1 << ": " << "Draw\n";
                flag = false;
            }
        }

        //fout << "Case #" << i + 1 << ": " << (temp - 4 + temp1) / 12 << "\'" << (temp - 4 + temp1) % 12 << "\" to " << (temp + 4) / 12 << "\'" << (temp + 4) % 12 << "\"" << endl;
    }
    return 0;
}
