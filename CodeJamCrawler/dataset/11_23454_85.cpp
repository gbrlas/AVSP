#include <iostream>
#include <vector>
using namespace std;

static const int MAX_TEST_CASES = 100;
static const int MAX_BUTTONS = 100;

class ButtonPress
{
public:
    char robot;
    int button;
public:
    void read()
    {
        cin >> robot >> button;
    }
};

class TestCase
{
private:
    int buttons;
    vector<ButtonPress> button_presses;
    
    int orange;
    int blue;
    int next_button;
    
    int orange_target;
    int blue_target;
    
    int find_next_target(char robot)
    {
        for(int i = next_button; i < button_presses.size(); ++i)
        {
            if (button_presses[i].robot != robot)
                continue;
            return button_presses[i].button;
        }
        return -1;
    }
    
    void find_next_target()
    {
        orange_target = find_next_target('O');
        blue_target = find_next_target('B');
    }
public:
    void read()
    {
        cin >> buttons;
        for(int i = 0; i < buttons; ++i)
        {
            ButtonPress button;
            button.read();
            button_presses.push_back(button);
        }
    }
    
    int solve()
    {
        orange = 1;
        blue = 1;
        next_button = 0;
        
        int result = 0;
        
        find_next_target();
        
        while(next_button < button_presses.size())
        {
            bool pressed = false;
            ++result;
            if (orange == orange_target)
            {
                if (button_presses[next_button].robot == 'O') // (&& button_presses[next_button].button == orange)
                {
                    if (button_presses[next_button].button != orange)
                    {
                        cerr << "Mixup!" << endl;
                        return -1;
                    }
                    // press the button, find next target
                    ++next_button;
                    orange_target = find_next_target('O');
                    pressed = true;
                }
            }
            else
            {
                if (orange_target != -1)
                {
                    if (orange_target > orange)
                        ++orange;
                    else
                        --orange;
                }
            }
            
            if (blue == blue_target)
            {
                if (button_presses[next_button].robot == 'B')
                {
                    if (button_presses[next_button].button != blue)
                    {
                        cerr << "Mixup!" << endl;
                        return -1;
                    }
                    if (!pressed)
                    {
                        ++next_button;
                        blue_target = find_next_target('B');
                    }
                }
            }
            else
            {
                if (blue_target != -1)
                {
                    if (blue_target > blue)
                        ++blue;
                    else
                        --blue;
                }
            }
            
        }
       
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
        cout << "Case #" << i+1 << ": " << test_cases[i].solve() << endl;
    }
    
    return 0;
}

