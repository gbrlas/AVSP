#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T,i,j,cur,count;
    long long g[1001];
    long long R,K,N,sum,g_num;

    fstream file,file2;
    file.open("in.txt",ios_base::in | ios_base::out);
    file2.open("out.txt",ios_base::in | ios_base::out);

    file>>T;
    int index = T;
    while (index--)
    {
        memset(g,0,sizeof(g));
        file>>R>>K>>N;
        for (i = 1;i<=N;++i)
            file>>g[i];
        sum = 0;
        cur = 1;
        for (i = 1;i<=R;++i)
        {
            g_num = 0;
            count = 0;
            for ( j = cur;count<=N;j=(j+1)%(N+1) )
            {
                g_num += g[j];
                ++count;
                if (g_num>K)
                {
                    g_num -= g[j];
                    cur = j;
                    break;
                }
            }
            sum += g_num;
        }

        file2<<"Case #"<<(T-index)<<": "<<sum<<endl;
    }


    file.close();
    file2.close();
    system("pause");
    return 0;
}
