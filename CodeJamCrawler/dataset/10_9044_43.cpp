#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T,N,i;
    long long f[100];
    long long K;
    memset(f,0,sizeof(f));
    fstream file,file2;
    file.open("A.txt",ios_base::in | ios_base::out);
    file2.open("A_out.txt",ios_base::in | ios_base::out);
    //freopen("A.", "r", stdin);

    file>>T;
    {
        int index = T;
        while(index--)
        {
            file>>N>>K;
            f[1] = 1;
            for (i = 2;i<=N;++i)
            {
            	f[i] = 2*f[i-1] + 1;
            }
            file2<<"Case #"<<(T-index);
            if (0 == (K+1)%(f[N]+1))
            {
            	file2<<": ON"<<endl;
            }
            else
            {
            	file2<<": OFF"<<endl;
            }
        }
    }

    file.close();
    file2.close();
    system("pause");
    return 0;
}
