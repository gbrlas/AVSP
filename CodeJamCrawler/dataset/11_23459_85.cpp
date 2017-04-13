#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class TestCase
{
private:
    int result;
public:
    void read()
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
        
        vector<int> target = v;
        sort(target.begin(), target.end());

        result = 0;
        for(int i = 0; i < v.size(); ++i)
            if (v[i] != target[i])
                ++result;
    }
    
    int solve()
    {
        return result;
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
        cout << "Case #" << i+1 << ": " << (double)r << ".000000" << endl;
    }
    
    return 0;
}