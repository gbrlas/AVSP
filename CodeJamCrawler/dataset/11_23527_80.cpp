#include <fstream>
using namespace std;
int main()
{
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt");
    int T;
    infile >> T;
    int t = 0;
    int N;
    for (int i = 0; i < T; i++)
    {
        t++;
        infile >> N;
        int Sum = 0;
        int temp;
        int Min = 0xFFFFFFF;
        int cor = 0;
        while (N)
        {
            infile >> temp;
            Sum += temp;
            Min = min(Min, temp);
            cor ^= temp;
            N--;
        }
        outfile << "Case #" << t << ": ";
        if (0 == cor)
        {
            outfile << Sum - Min << endl;
        }
        else
        {
            outfile << "NO" << endl;
        }
    }

    return 0;
}