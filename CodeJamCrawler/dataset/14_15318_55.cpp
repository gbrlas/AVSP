#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <double> naomi, ken;


void solve(int case_)
{
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        double a;
        scanf("%lf", &a);
        naomi.push_back(a);
    }
    for (int i=0; i<N; i++)
    {
        double a;
        scanf("%lf", &a);
        ken.push_back(a);
    }

    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    int dw_points=0;
    int n=naomi.size()-1;
    for (int k=ken.size()-1; k>=0; k--)
    {
        if (naomi[n]>ken[k])
        {
            n--;
            dw_points++;
        }
    }

    int k=ken.size()-1;
    int w_points=N;
    for (int n=naomi.size()-1; n>=0; n--)
    {
        if (ken[k]>naomi[n])
        {
            w_points--;
            k--;
        }
    }

    printf("Case #%d: %d %d\n", case_, dw_points, w_points);
}


int main()
{
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        solve(t);
        naomi.clear();
        ken.clear();
    }
}
