#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class TestCase
{
private:
    map<string,char> transforms;
    map<char,char> opposites;
    vector<char> sequence;
public:
    void read()
    {
        int c;
        cin >> c;
        for(int i = 0; i < c; ++i)
        {
            // read transforms
            char c1, c2, c3;
            cin >> c1 >> c2 >> c3;

            string s1("  ");
            s1[0] = c1;
            s1[1] = c2;
            transforms[s1]=c3;
            
            string s2("  ");
            s2[0] = c2;
            s2[1] = c1;
            transforms[s2]=c3;
        }
        
        int d;
        cin >> d;
        for(int i = 0; i < d; ++i)
        {
            // read opposites
            char c1, c2;
            cin >> c1 >> c2;
            opposites[c1]=c2;
            opposites[c2]=c1;
        }
        
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            // read sequence
            char c;
            cin >> c;
            sequence.push_back(c);
        }
    }
    
    string format_result(const vector<char> v)
    {
        string result("[");
        for(int i = 0; i<v.size(); ++i)
        {
            string step(" ");
            step[0] = v[i];
            if (i < v.size()-1)
                step.append(", ");
            result.append(step);
        }
        
        result.append("]");
        return result;
    }
    
    string solve()
    {
        vector<char> result;
        for(int i = 0; i < sequence.size(); ++i)
        {
            result.push_back(sequence[i]);
            if (result.size() == 1)
                continue;

            // replace
            char replacement;
            bool should_replace = false;
            
            string s1("  ");
            s1[0] = result[result.size()-2];
            s1[1] = result[result.size()-1];
            
            map<string, char>::const_iterator t = transforms.find(s1);
            if (t != transforms.end())
            {
                replacement = t->second;
                should_replace = true;
            }
            
            if (!should_replace)
            {
                string s2("  ");
                s2[0] = result[result.size()-1];
                s2[1] = result[result.size()-2];
                map<string, char>::const_iterator t = transforms.find(s2);
                if (t != transforms.end())
                {
                    replacement = t->second;
                    should_replace = true;
                }
            }
            
            if(should_replace)
            {
                result.pop_back();
                result[result.size()-1] = replacement;
            }
            else
            {
                // cleanup
                char c = sequence[i];
                map<char,char>::const_iterator op = opposites.find(c);
                if (op != opposites.end())
                {
                    char opposite = op->second;
                    if (find(result.begin(), result.end(), opposite) != result.end())
                        result.clear();
                }
            }
        }
        
        return format_result(result);
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
        cout << "Case #" << i+1 << ": " << test_cases[i].solve() << endl;
    }
    
    return 0;
}

