#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v1;
vector<int> v2;

int num_cases;
int num_items;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    
    int curr_case = 0;
    
    cin >> num_cases;
    while (num_cases--) {
        curr_case++;
        v1.clear();
        v2.clear();
        
        cin >> num_items;
        
        int n;
        for (int i = 0; i < num_items; i++) {
            cin >> n;
            v1.push_back(n);
        }
        
        for (int i = 0; i < num_items; i++) {
            cin >> n;
            v2.push_back(n);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());
        
        long long product = 0;
        for (int i = 0; i < num_items; i++) {
            //cout << v1[i] << " * " << v2[i] << endl;
            product += v1[i] * v2[i];
        }
        
        cout << "Case #" << curr_case << ": " << product << endl;
    }
    
    getchar();
}
