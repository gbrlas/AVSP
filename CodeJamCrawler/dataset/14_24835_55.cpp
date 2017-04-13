#include <fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
bool v[20];
int T, A1, A2, raspuns;
int main()
{
    int i, j, multiple, x;
    fin>>T;
    for(int k = 1; k <= T; k++)
    {
            raspuns = 0;
            multiple = 0;
            fin>>A1;
            for(i = 1; i <= 16; i++)
                v[i] = false;
            for(i = 1; i <= 4; i++)
                for(j = 1; j <= 4; j++)
                {
                    fin >> x;
                    if(i == A1) v[x] = 1;
                }
            fin >> A2;
            for(i = 1; i <= 4; i++)
                for(j = 1; j <= 4; j++)
                {
                    fin >> x;
                    if(i == A2)
                    {
                     if(v[x] == true){
                     if(raspuns == 0)raspuns = x;
                        else multiple = 1;
                                    }
                    }
                }
            fout<<"Case #"<<k<<": ";
            if(multiple == 1)fout<<"Bad magician!\n";
                else if(raspuns == 0)fout<<"Volunteer cheated!\n";
                    else fout<<raspuns<<"\n";
    }
    return 0;
}
