#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    ifstream file(argv[1]);
    int T, N, K;
    file >> T;
    for (int i = 1; i <= T; i++)
    {
        file >> N >> K;
        cout << "Case #" << i << ": ";
        if ((K + 1) % ((1 << N)) == 0)
            cout << "ON" << endl;
        else
            cout << "OFF" << endl;
    }
    return 0;
}
