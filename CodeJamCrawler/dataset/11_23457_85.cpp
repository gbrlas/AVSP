#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Scenario
{
public:
    vector<int> s;
    //vector<int> r;
    int x_s;
    int x_r;
    int sum_s;
};

class TestCase
{
private:
    vector<int> candies;
    int all;
    int sum;
public:
    void read()
    {
        candies.reserve(1000);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;
            candies.push_back(c);
        }
        cout << endl;
        sort(candies.begin(), candies.end());
    }
    
    list<Scenario> scenarios;

    int solve(const Scenario& s)
    {
        for(int i = 0; i < s.s.size(); ++i)
        {
            if ((s.x_s^s.s[i]) == (s.x_r^s.s[i]))
                return s.sum_s-s.s[i];
        }
        
        for(int i = 0; i < s.s.size(); ++i)
        {
            vector<int> ss = s.s;
            ss.erase(ss.begin()+i);
            
            Scenario next;
            next.s = ss;
            next.x_s = s.x_s^s.s[i];
            next.x_r = s.x_r^s.s[i];
            next.sum_s = s.sum_s - s.s[i];
            
            scenarios.push_back(next);
        }
        
        return -1;
    }
    
    int solve()
    {
        all = 0;
        sum = 0;
        for(int i = 0; i < candies.size(); ++i)
        {
            all ^= candies[i];
            sum += candies[i];
        }
        if (all != 0)
            return -1;
        //cerr << "XOR:" << all;
        Scenario start;
        start.s = candies;
        start.x_s = all;
        start.x_r = 0;
        start.sum_s = sum;
        
        scenarios.push_back(start);
        
        while(!scenarios.empty())
        {
            Scenario s = *(scenarios.begin());
            scenarios.pop_front();
            int result = solve(s);
            if (result != -1)
                return result;
        }
        
        return -1;
    }
};

vector<TestCase> test_cases;

void read_input()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        TestCase test_case;
        test_case.read();
        test_cases.push_back(test_case);
    }
}

int main (int argc, const char * argv[])
{
    read_input();
    for(int i = 0; i < test_cases.size(); ++i)
    {
        int r = test_cases[i].solve();
        if (r == -1)
            cout << "Case #" << i+1 << ": NO" << endl;
        else
            cout << "Case #" << i+1 << ": " << r << endl;
    }
    
    return 0;
}

