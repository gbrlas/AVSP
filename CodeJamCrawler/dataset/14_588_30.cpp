#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <climits>
using namespace std;

#define llint long long
#define lluint unsigned long long
#define uint unsigned int
#define dbl double
#define ldbl long double
#define pint pair<int, int>
#define pllint pair<long long, long long>
#define mp make_pair
#define pb push_back

void debout()
{
#ifdef _DEBUG
    fprintf(stderr, "\n");
#endif
}

template <typename Head, typename... Tail>
void debout(Head H, Tail... T)
{
#ifdef _DEBUG
    cerr << H << ' ';
    debout(T...);
#endif
}

void stressout()
{
#ifdef _DEBUG
    printf("\n");
#endif
}

template <typename Head, typename... Tail>
void stressout(Head H, Tail... T)
{
#ifdef _DEBUG
    cout << H << ' ';
    debout(T...);
#endif
}

llint mod = 1000 * 1000 * 1000 + 7;

const int N = 200, M = 30;
string str[N];

int sum_character[M], entireBlock[M], Suffix[N], Prefix[N], marker[M];
llint fact[N];
vector<int> E[M];

void initialize()
{
    for (int i = 0; i < M; i++)
    {
        sum_character[i] = 0;
        entireBlock[i] = 0;
        marker[i] = 0;
        E[i].clear();
    }

    for (int i = 0; i < N; i++)
    {
        Prefix[i] = 0;
        Suffix[i] = 0;
    }

}

bool strIsEntire(const string &str)
{
    for (int i = 1; i < str.size(); i++)
        if (str[i] != str[i - 1])
            return false;
    return true;
}

bool dfs(int i, int prev = -1)
{
    if (marker[i])
        return true;
    marker[i] = true;
    for (auto it = E[i].begin(); it != E[i].end(); it++)
    {
        if (*it != prev && dfs(*it, i))
            return true;
    }

    return false;
}

void solve()
{
    fact[0] = fact[1] = 1;
    for (llint i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        cerr << "next\n";
        initialize();

        llint answer = 0;

        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            cin >> str[j];

            string tmp = "";
            tmp += str[j][0];
            for (int p = 1; p < str[j].size(); p++)
                if (str[j][p] != str[j][p - 1])
                    tmp += str[j][p];

            str[j] = tmp;

            if (strIsEntire(str[j]))
                entireBlock[str[j][0] - 'a']++;
            else
            {
                int len = str[j].size(), Left = str[j][0] - 'a', Right = str[j][len - 1] - 'a';
                Suffix[Right]++;
                Prefix[Left]++;
                E[Right].pb(Left);
                E[Left].pb(Right);
                if (Suffix[Right] > 1 || Prefix[Left] > 1)
                {
                    cerr << "shit " << j << " " << Suffix[Right] << " " << Prefix[Left] << "\n";
                    answer = -1;
                }

                for (int p = 1; p < len - 1; p++)
                {
                    int ch = str[j][p] - 'a';
                    if (marker[ch] == true)
                        answer = -1;

                    marker[ch] = true;
                }

                marker[str[j][len - 1] - 'a'] = true;
            }

            marker[str[j][0] - 'a'] = true;
        }

        for (int i = 0; i < M; i++)
            marker[i] = false;

        for (int i = 0; i < M; i++)
        {
            if (marker[i] == false && dfs(i))
                answer = -1;
        }

        if (answer == -1)
        {
            printf("Case #%d: 0\n", i + 1);
            continue;
        }

        llint cnt = 0;
        answer = 1;
        for (int i = 0; i < M; i++)
        {
            answer = (answer * fact[entireBlock[i]]) % mod;
            if ((Prefix[i] == 0 && Suffix[i] == 0 && entireBlock[i] > 0) || 
                (Suffix[i] > 0 && Prefix[i] == 0))
                cnt++;
        }

        answer = (answer * fact[cnt]) % mod;
        printf("Case #%d: %lld\n", i + 1, answer);
    }
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    fprintf(stderr, "time is %.5lf\n", (double) clock());

    return 0;
}
