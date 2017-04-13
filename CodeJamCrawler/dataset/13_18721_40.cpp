#include <iostream>
using namespace std;

#define N 105
#define M 105

char lawn[N][M];

bool check(int n, int m)
{
    int max_row[N] = {0};
    int max_col[M] = {0};

    for(int i = 0; i<n; i++)
        max_row[i] = 0;
    for(int j = 0; j<m; j++)
        max_col[j] = 0;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            if(lawn[i][j] > max_row[i])
                max_row[i] = lawn[i][j];

            if(lawn[i][j] > max_col[j])
                max_col[j] = lawn[i][j];
        }

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            if(lawn[i][j] == max_row[i])
                continue;

            if(lawn[i][j] == max_col[j])
                continue;

            return false;
        }

    return true;
}

int main()
{
    int t, n, m;
    cin>>t;
    for(int k = 1; k<=t; k++){
        cin>>n>>m;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                cin>>lawn[i][j];
        
        if(check(n, m))
            cout<<"Case #"<<k<<": YES"<<endl;
        else
            cout<<"Case #"<<k<<": NO"<<endl;
    }

    return 0;
}
