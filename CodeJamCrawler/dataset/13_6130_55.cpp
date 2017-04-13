#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int max_n = 10000000;

int ans[max_n+1];

bool is_palindrome(ll x)
{
    vector<int> lol;
    while (x != 0) {
        lol.push_back(x % 10);
        x /= 10;
    }
    
    int i = 0;
    int j = lol.size() - 1;
    
    while (i < j) {
        if (lol[i] != lol[j])
            return false;
        i++;
        j--;
    }
    
    return true;
}

ll sqqqqrttttt(ll boring)
{
    ll a = 1;
    ll b = boring;
    
    while (a < b) {
        ll c = (a + b + 1) / 2;
        if (c * c == boring) {
            return c;   
        } else if (c * c < boring) {
            a = c;
        } else {
            b = c - 1;
        }
    }
    
    return a;
}

int main()
{
    ans[0] = 1;
    for (ll i = 1; i <= max_n; i++) {
        if (is_palindrome(i) && is_palindrome(i*i)) {
            ans[i] = ans[i-1] + 1;   
        } else {
            ans[i] = ans[i-1];   
        }
    }
    
    int t;
    scanf("%i", &t);
    
    for (int i = 0; i < t; i++) {
        ll a, b;  
        scanf("%lli %lli", &a, &b);
        
        ll x = sqrt(a);
        ll y = sqrt(b);
        
        if (x * x == a)
            x--;
        
        if (x*x > a || y*y > b)
        {
            fprintf(stderr, "YOU FUCKED UP!\n");
            return 666;
        }
        
        printf("Case #%i: %i\n", i+1, ans[y] - ans[x]);
    }
    
    return 0;
}
