#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-7;

int n;
double a[10];
double b[10];
bool sta[10];
bool stb[10];

bool is()
{    
    double m = 0;
    
    for (int i = 0; i < n; i++)
        if (sta[i] == 0 && a[i] > m)
            m = a[i];
            
    for (int j = 0; j < n; j++)
        if (stb[j] == 0 && b[j] > m)
            return 1;
            
    return 0;
}

int tru(int r)
{
    int ans = 0;
    
    if (r == 0)
        return 0;
        
    for (int i = 0; i < n; i++)
    {
        if (sta[i])
            continue;
            
        sta[i] = 1;
        
        int j = -1;
        
        for (int l = 0; l < n; l++)
            if (b[l] > a[i] && stb[l] == 0 && (j == -1 || b[l] < b[j]))
                j = l;
                
        if (j == -1) {
            for (int l = 0; l < n; l++)
                if (stb[l] == 0 && (j == -1 || b[l] < b[j]))
                    j = l;
        }
        
        stb[j] = 1;
        
        ans = max(ans, tru(r - 1) + (a[i] > b[j] ? 1 : 0));
        //~ if (r == 9)
            //~ cout << r << ' ' << a[i] << ' ' << b[j] << endl;
         
        sta[i] = 0;
        stb[j] = 0;
    }
    
    return ans;
}

int rec(int r)
{
    int ans = 0;
    
    if (r == 0)
        return 0;
        
    if (!is()) {
        double m = 1;
        int q;
        
        for (int j = 0; j < n; j++)
            if (stb[j] == 0 && b[j] < m)
            {
                q = j;
                m = b[j];
            }
            
        stb[q] = 1;
        
        int e = -1;
        double m2 = 1;
        
        for (int i = 0; i < n; i++) 
            if (sta[i] == 0 && a[i] > m && a[i] < m2)
            {
                e = i;
                m2 = a[i];
            }
            
        if (e != -1)
        {
            sta[e] = 1;
            ans = max(ans, 1 + rec(r - 1));
            sta[e] = 0;
        }
        
        stb[q] = 0;
        return ans;
    }
        
    for (int i = 0; i < n; i++)
    {
        if (sta[i])
            continue;
            
        sta[i] = 1;
        
        int j = -1;
        
        for (int l = 0; l < n; l++)
            if (b[l] > a[i] && stb[l] == 0 && (j == -1 || b[l] > b[j]))
                j = l;
                
        if (j == -1) {
            for (int l = 0; l < n; l++)
                if (stb[l] == 0 && (j == -1 || b[l] < b[j]))
                    j = l;
        }
        
        stb[j] = 1;
        
        ans = max(ans, rec(r - 1) + (a[i] > b[j] ? 1 : 0));
        //~ if (r == 9)
            //~ cout << r << ' ' << a[i] << ' ' << b[j] << endl;
         
        sta[i] = 0;
        stb[j] = 0;
    }
    
    return ans;
}

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    
    int t;
    cin >> t;
    int ans1, ans2;
    
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        
        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sta[i] = 0;
            stb[i] = 0;
        }
            
        for (int i = 0; i < n; i++) 
            cin >> b[i];
            
        ans1 = 0;
        ans2 = 0;
        
        
        ans1 = rec(n);
        ans2 = tru(n);
        
        cout << ans1 << ' ' << ans2 << endl;
    }
}
