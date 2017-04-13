// This code is devoted to Airi who I love.

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Node
{
    bool and;
    bool changable;

    long long toZero, toOne;
};

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int m, v;
        cin >> m >> v;

        vector<Node> nodes(m);
        int j;
        for(j=0; j<(m-1)/2; j++)
        {
            cin >> nodes[j].and >> nodes[j].changable;
        }

        for(; j<m; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp==0)
            {
                nodes[j].toZero = 0;
                nodes[j].toOne = 20000;
            }
            else
            {
                nodes[j].toZero = 20000;
                nodes[j].toOne  = 0;
            }
        }

        for(j=(m-1)/2 -1; j>=0; j--)
        {
            int left=(j+1)*2 -1, right=left+1;
            if(nodes[j].and)
            {
                nodes[j].toZero = min(nodes[left].toZero,  nodes[right].toZero);
                nodes[j].toOne = nodes[left].toOne + nodes[right].toOne;
                if(nodes[j].changable)
                {
                    nodes[j].toZero = min(nodes[j].toZero, 1+ nodes[left].toZero + nodes[right].toZero);
                    nodes[j].toOne  = min(nodes[j].toOne, 1+ min(nodes[left].toOne, nodes[right].toOne));
                }
            }
            else
            {
                nodes[j].toZero = nodes[left].toZero + nodes[right].toZero;
                nodes[j].toOne  = min(nodes[left].toOne, nodes[right].toOne);
                if(nodes[j].changable)
                {
                    nodes[j].toZero = min(nodes[j].toZero, 1+ min(nodes[left].toZero,  nodes[right].toZero));
                    nodes[j].toOne = min(nodes[j].toOne, 1+ nodes[left].toOne + nodes[right].toOne);
                }
            }
        }

        long long ans;
        if(v==0)
            ans=nodes[0].toZero;
        else
            ans=nodes[0].toOne;
        if(ans>=20000)
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        else
             cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}
