#include <fstream>
#include <vector>

using namespace std;

int v[100][100];
char c[100][100];
char dir[100][100];
char mapb[100][100];

int H, W;

int mask[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void DFS(int i, int j, int num)
{
    mapb[i][j] = num;

    if (i > 0 && dir[i-1][j] == 4)
        DFS(i-1, j, num);

    if (j > 0 && dir[i][j-1] == 3)
        DFS(i, j-1, num);

    if (i < H-1 && dir[i+1][j] == 1)
        DFS(i+1, j, num);

    if (j < W-1 && dir[i][j+1] == 2)
        DFS(i, j+1, num);
}

int main()
{
    ifstream cin("B-small.in");
    ofstream cout("B-small.out");

    int T;
    cin>>T;

    
    for (int i = 1; i <= T; i++)
    {

        cin>>H>>W;

        char cur = 'a';

        c[0][0] = cur;

        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < W; k++)
                cin>>v[j][k];
        }

        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < W; k++)
            {
                int min = v[j][k];
                for (int m = 0; m < 4; m++)
                {
                    if (j+mask[m][0] >= 0 && j+mask[m][0] < H && k+mask[m][1] >= 0 && k+mask[m][1] < W && v[ j+mask[m][0] ][ k+mask[m][1] ] < min)
                    {
                        dir[j][k] = m+1;
                        min = v[ j+mask[m][0] ][ k+mask[m][1] ];
                    }
                }

                if (v[j][k] == min)
                    dir[j][k] = 0;

            }
        }
        
        int num = 0;
        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < W; k++)
            {
                if (dir[j][k] == 0)
                    DFS(j, k, num++);
            }
        }

        vector<char> mp;
        mp.resize(26, 0);
        char let = 'a';

        cout<<"Case #"<<i<<":"<<endl;

        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < W; k++)
            {
                if (mp[mapb[j][k]] == 0)
                {
                    mp[mapb[j][k]] = let;
                    let++;
                }

                cout<<mp[mapb[j][k]]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}