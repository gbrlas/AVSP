#include <iostream>
#include <string>

using namespace std;

int main()
{
//  char* map = "abcdefghijklmnopqrstuvwxyz";
    char* map = "yhesocvxduiglbkrztnwjpfmaq";
    
    int T;
    string str;
    
    cin >> T;
    getline(cin, str);
    for (int t = 0; t < T; t++)
    {
        getline(cin, str);
        cout << "Case #" << (t + 1) << ": ";
        for (int i = 0; i < str.length(); i++)
        {
        	if (str[i] != ' ')
	            cout << map[str[i] - 'a'];
	        else
	        	cout << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
