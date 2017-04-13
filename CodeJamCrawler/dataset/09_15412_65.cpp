/*
ID: nilsmolin2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>

#define inf 99999

using namespace std;

ifstream fin ("4.in");
ofstream fout ("4.out");

int t, n;
long double ans;
long double a, b, c;
int x[501];
int y[501];
int z[501];
int vx[501];
int vy[501];
int vz[501];

int main() {
    fin >> t;
    for(int i = 0; i < t; i++) {
       fin >> n;
       for(int i = 0; i < n; i++) {
            fin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
       }
       long double sx = 0, sy = 0, sz = 0, svx = 0, svy = 0, svz = 0;
       for(int i = 0; i < n; i++) {
            sx += x[i];
            sy += y[i];
            sz += z[i];
            svx += vx[i];
            svy += vy[i];
            svz += vz[i];
       }
       a = svx*svx + svy*svy + svz*svz;
       b = 2*(sx*svx + sy*svy + sz*svz);
       c = sx*sx + sy*sy + sz*sz;
       if(a == 0) ans  = 0;
       else if( b*b - 4*a*c >= 0) {
            ans = (-b-sqrt(b*b - 4*a*c))/(2*a);
            if(ans < 0) ans = (-b+sqrt(b*b - 4*a*c))/(2*a);
            if(ans < 0) ans = 0;
       } else {
            ans = -b/(2*a);
            if(ans < 0) ans = 0;
       }
       long double temp = a*ans*ans+b*ans+c;
       if(temp < 0) temp = 0;
       temp = sqrt(temp)/n;
       //printf("%1.5fL %1.5fL",temp,ans);
       fout.precision(15);
       fout << "Case #" << i + 1 << ": " << temp << " " << ans << endl;
    }
    system("PAUSE");
    return 0;
}
