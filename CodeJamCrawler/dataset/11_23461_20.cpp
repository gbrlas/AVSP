#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> scores;
vector<double> wp;
vector<double> owp;
vector<double> oowp;
vector<double> rpi;

double calc_wp_without(int team, int opponent)
{
    int won;
    int lost;
    
    lost = won = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if (i == opponent)
            continue;
        if (scores[team][i] == '1')
        {
            ++won;
        }
        else if (scores[team][i] == '0')
        {
            ++lost;
        }
    }
    
    if (won+lost > 0)
        return (double)won/(double)(won+lost);
    else
        return 0.0;
}

double calc_wp(int team)
{
    int won;
    int lost;
    
    lost = won = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if (scores[team][i] == '1')
        {
            ++won;
        }
        else if (scores[team][i] == '0')
        {
            ++lost;
        }
    }
    
    if (won+lost > 0)
        return (double)won/(double)(won+lost);
    else
        return 0.0;
}

double calc_owp(int team)
{
    double result = 0.0;
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        if (scores[team][i] == '.')
            continue;
        result += calc_wp_without(i,team);
        count++;
    }
    if (count > 0)
        return result/(double)count;
    else
        return 0.0;
}

double calc_oowp(int team)
{
    double result = 0.0;
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        if (scores[team][i] == '.')
            continue;
        result += owp[i];
        count++;
    }
    if(count > 0)
        return result/(double)count;
    else
        return 0.0;
}

void solve(int t)
{
    scores.clear();
    wp.clear();
    owp.clear();
    oowp.clear();
    rpi.clear();

    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        scores.push_back(s);
    }
    
    //
    // RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP
    //
    
    // wp for i
    for(int i = 0; i < n; ++i)
    {
        wp.push_back(calc_wp(i));
    }
    
    for(int i = 0; i < n; ++i)
    {
        owp.push_back(calc_owp(i));
    }
    
    for(int i = 0; i < n; ++i)
    {
        oowp.push_back(calc_oowp(i));
    }
    
    for(int i = 0; i < n; ++i)
    {
        rpi.push_back(0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
    }
    
    cout << "Case #" << t+1 << ":"<< endl;
    for(int i = 0; i < n; ++i)
        cout << rpi[i] << endl;
}


int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        solve(i);
}