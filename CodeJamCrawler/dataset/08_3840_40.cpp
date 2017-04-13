#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;

ifstream cin("C-small-attempt0.in");
ofstream cout("C-small-attempt0.out");

double eps = 1E-9;

class A
{
public:
    double compute()
    {
        cin >> n;
        x_ = y_ = z_ = p = vector<double>(n); 
        for(int i = 0; i < n; ++i)
            cin >> x_[i] >> y_[i] >> z_[i] >> p[i];

        return findMin();
    }

    double findMin()
    {
        double l = 0, u = 1000000.0, m1, m2;
        while (u - l > eps && u - l > eps * l)
        {
            m1 = (2 * l + u) / 3.0;
            m2 = (l + 2 * u) / 3.0;
            if (findMin(m1) < findMin(m2))
            {
                u = m2;
            }
            else
                l = m1;
        }
        return findMin(l);
    }


    double findMin(double x)
    {
        double l = 0, u = 1000000.0, m1, m2;
        while (u - l > eps && u - l > eps * l)
        {
            m1 = (2 * l + u) / 3.0;
            m2 = (l + 2 * u) / 3.0;
            if (findMin(x, m1) < findMin(x, m2))
            {
                u = m2;
            }
            else
                l = m1;
        }
        return findMin(x, l);
    }


    double findMin(double x, double y)
    {
        double l = 0, u = 1000000.0, m1, m2;
        while (u - l > eps && u - l > eps * l)
        {
            m1 = (2 * l + u) / 3.0;
            m2 = (l + 2 * u) / 3.0;
            if (f(x, y, m1) < f(x, y, m2))
            {
                u = m2;
            }
            else
                l = m1;
        }
        return f(x, y, l);
    }

    double f(double x, double y, double z)
    {
        double result = 0.0, val;
        for(int i = 0; i < n; ++i)
        {
            val = fabs(x_[i] - x) + fabs(y_[i] - y) + fabs(z_[i] - z);
            val /= p[i];
            if (val > result)
            {
                result = val;
            }
        }
        return result;
    }
    vector<double> x_, y_, z_, p;
    int n;
};


int main()
{
    int testNum = 0;
    cin >> testNum;
    for(int test = 1; test <= testNum; ++test)
    {
        double result = 0;
        A a;
        result = a.compute();


        cout << fixed << setprecision( 6 ) << "Case #" << test <<": " << result <<endl;
    }

    return 0;
}