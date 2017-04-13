#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>
#include <ext/hash_map>
// C++ Big Integer Library
// http://mattmccutchen.net/bigint/
//#include "BigIntegerLibrary.hh"


using namespace std;
//using namespace __gnu_cxx;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;


void runCase(int caseNum) {
    int N, M;
    cin >> N >> M;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<double, double> > pts;


    double xd = abs(x1 - x2);
    double yd = abs(y1 - y2);

    double c = sqrt(xd * xd + yd * yd);

    //cout << "Case #" << caseNum << ":";
    printf("Case #%d:", caseNum);

    for (int i = 0; i < M; ++i) {
        double x, y;
        cin >> x >> y;
        double r0 = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        double r1 = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
        if (r0 + r1 <= c) {
            printf(" %.7f", 0.0);
            continue;
        }
        double cba = acos((r1 * r1 + c * c - r0 * r0) / (2.0 * r1 * c));
        double cbd = 2 * cba;
        double cab = acos((r0 * r0 + c * c - r1 * r1) / (2.0 * r0 * c));
        double cad = 2 * cab;

        double r = 0.5 * cbd * r1 * r1 - 0.5 * r1 * r1 * sin(cbd)
            + 0.5 * cad * r0 * r0 - 0.5 * r0 * r0 * sin(cad);
        printf(" %.7f", r);

    }
    printf("\n");
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        runCase(i + 1);

	//runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
//a
