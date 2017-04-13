#include <fstream>
using namespace std;
char combine[36][3];
char oposed[28][2];
char elemenet[100];
char outelement[100];
int C, D, N;
char GetNoBase(char c1, char c2)
{
    for (int i = 0; i < C; i++)
    {
        if (c1 == combine[i][0] && c2 == combine[i][1])
        {
            return combine[i][2];
        }
        if (c2 == combine[i][0] && c1 == combine[i][1])
        {
            return combine[i][2];
        }
    }
    return 0;
}

bool IsOposed(char c1, char c2)
{
    for (int i = 0; i < D; i++)
    {
        if (c1 == oposed[i][0] && c2 == oposed[i][1])
        {
            return true;
        }
        if (c2 == oposed[i][0] && c1 == oposed[i][1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt");
    int T;
    infile >> T;
    for (int t = 0; t < T; t++)
    {
        infile >> C;
        for (int j = 0; j < C; j++)
        {
            infile >> combine[j][0] >> combine[j][1] >> combine[j][2];
        }
        infile >> D;
        for (int j = 0; j < D; j++)
        {
            infile >> oposed[j][0] >> oposed[j][1];
        }
        infile >> N;
        for (int j = 0; j < N; j++)
        {
            infile >> elemenet[j];
        }
        int op(0), p(0);
        int L = 0;
        while (p < N)
        {
            outelement[L++] = elemenet[p];
            if (L >= 2)
            {
                char c = GetNoBase(outelement[L - 1], outelement[L - 2]);
                if (c != 0)
                {
                    L--;
                    outelement[L - 1] = c;
                }
                for (int j = 0; j < L - 1; j++)
                {
                    if (IsOposed(outelement[j], outelement[L - 1]))
                    {
                        L = 0;
                        break;
                    }
                }
            }
            p++;
        }
        outfile << "Case #" << t + 1 << ": [";
        char *str = "";
        for (int j = 0; j < L; j++)
        {
            outfile << str << outelement[j];
            str = ", ";
        }
        outfile << "]" << endl;
    }

    return 0;
}