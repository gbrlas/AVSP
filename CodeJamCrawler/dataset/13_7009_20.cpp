#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int strToInt(string line) {
    stringstream ss;
    ss << line;
    int num;
    ss >> num;
    return num;
}

string intToStr(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

bool isPalindrome(string line) {
    return line == string(line.rbegin(), line.rend());
}

int main() {
    int T;
    cin >> T;

    int a, b;
    set<long long> numbers;
    for (int i = 1; i != 1001; ++i) {
        if (isPalindrome(intToStr(i)) && isPalindrome(intToStr(i*i))) {
            numbers.insert(i*i);
        }
    }
    
    for (int t = 0; t != T; ++t) {        
        cin >> a >> b;
        int count = 0;
        for (int i = a; i <= b; ++i) {
            if (numbers.count(i))  {
                count++;
            }
        }
        cout << "Case #" << t+1 << ": " << count << endl;
    }
    
    return 0;
}