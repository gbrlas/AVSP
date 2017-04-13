#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int T, n, k;
string s;
vector < string > a;
set < string > my;
string w;
vector < vector < string > > mas;
int num[100][256];
int z[100][100];
int d[256];
vector < pair < int, int > > v;



int get(string s1, string s2)
{
    int ans = 0;
    int i = 1;
    int j = 1;
    int n1 = 1;
    int n2 = 1;
    
    while (i < s1.size() || j < s2.size()) {
        while (i < s1.size() && s1[i] == s1[i - 1])
            i++, n1++;
        while (j < s2.size() && s2[j] == s2[j - 1])
            j++, n2++;
            
        ans += abs(n1 - n2);
        n1 = 1;
        n2 = 1;
        i++;
        j++;
    }
    
    ans += abs(n1 - n2);
    return ans;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        
        cin >> n;
        a.clear();
        my.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> s;
            
            w.clear();    
            for (int j = 0; j < s.size(); j++) {
                if (j == 0 || s[j] != s[j - 1])
                    w += s[j];
            }
            
            my.insert(w);            
            a.push_back(s);
        }
        
        if (my.size() > 1) {
            cout << "Fegla Won\n";
            continue;
        }
        
        cout << get(a[0], a[1]) << endl;
    }
}
