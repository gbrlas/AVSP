#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int t, i, j, n;
	int o[100], b[100];
	char s[201];
	char c;
	int p, pb, po;
	int io, ib, no, nb;
	int ans;
	cin >> t;
	for(i = 0; i < t; i++){
		cin >> n;
		ans = 0;
		no = nb = 0;
		pb = po = 1;
		for(j = 0; j < n; j++){
			cin >> c >> p;
			if(c == 'O'){
				o[no++] = p;
			} else {
				b[nb++] = p;
			}
			s[j] = c;
		}
		io = ib = 0;
		int step;
		for(j = 0; j < n; j++){
			if(s[j] == 'O'){
				step = (int)fabs(o[io] - po);
				po = o[io];
				if(ib < nb && b[ib] != pb){
					pb += (b[ib] - pb) / fabs(b[ib] - pb) * min(step + 1.0, fabs(b[ib] - pb) );
				}
				ans += step + 1;
				io++;
			} else {
				step = fabs(b[ib] - pb);
				pb = b[ib];
				if(io < no && o[io] != po){
					po += (o[io] - po) / fabs(o[io] - po) * min(step + 1.0, fabs(o[io] - po) );
				}
				ans += step + 1;
				ib++;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
    return 0;
}
