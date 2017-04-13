#include <fstream>
using namespace std;

int main()
{
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt");
    int T;
    infile >> T;
    int data[1000];
    int N;
    for (int t = 0; t < T; t++)
    {
        infile >> N;
        for (int i = 0; i < N; i++)
        {
            infile >> data[i];
            data[i]--;
        }
        int p;
        int steps = 0;
        for (int i = 0; i < N; i++)
        {
            if (data[i] == i)
            {
                continue;
            }
            p = i;
            while (true)
            {
                if (data[p] == p)
                {
                    break;
                }
                int temp = data[p];
                data[p] = p;
                p = temp;
                steps++;
            }
        }
        outfile << "Case #" << t + 1 << ": ";
        outfile << steps << ".000000" << endl;
    }

    return 0;
}