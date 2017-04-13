// This code is devoted to Airi who I love.

#include <iostream>

using namespace std;

int width, height;
int rock[100][100];

long long memo[100][100];
int dist[8][2]={
//    {1, -2},
//    {2, -1},
    {2, 1},
    {1, 2},
//    {-1, 2},
//    {-2, 1},
//    {-2, 1},
//    {-1, -2},
};

int size=2;

long long solve(int x, int y)
{
    if(x<0 || x>=width
        || y<0 || y>=height)
        return 0;

    if(memo[y][x]>=0)
    {
        return memo[y][x];
    }

    if(rock[y][x] == 1)
        return 0;

    if(x==width-1 && y == height-1)
        return 1;

    long long ret=0;
    for(int i=0; i<size; i++)
    {
        ret+=solve(x+dist[i][0],
            y+dist[i][1]);
    }

    memo[y][x]=ret;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int rocks;
        cin >> width >> height >> rocks;
        for(int y=0; y<height; y++)
        {
            for(int x=0; x<width; x++)
            {
                rock[y][x] = 0;
                memo[y][x] = -1;
            }
        }
        for(int j=0; j<rocks; j++)
        {
            int x, y;
            cin >> x >> y;
            rock[y-1][x-1] = 1;
        }
        cout << "Case #" << i+1 << ": "
           << solve(0, 0) % 10007
           << endl;
     }
    return 0;
}
