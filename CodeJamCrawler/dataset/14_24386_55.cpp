
#include <iostream>
#include <algorithm>

int calculate_max(int n, double a[], double b[])
{
    int j = n - 1, count1 = 0;
    for (int i = n -1; i >= 0; i--)
    {
        while (j >= 0 && a[i] <= b[j])
        {
            j--;
        }
        if (j >= 0)
        {
            j--;
            count1++;
        }
    }
    return count1;
}
int main()
{
    double a[1100], b[1100];
    int t, n, testcase = 1;

    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w+", stdout);
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            std::cin >> b[i];
        }
        std::sort(a, a+n);
        std::sort(b, b+n);
        
        int count1 = calculate_max(n, a, b);
        int count2 = calculate_max(n, b, a);
        std::cout << "Case #" << testcase++ << ": " << count1 << " " << n - count2 << std::endl;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
