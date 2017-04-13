#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;

int r,c,d;
ll arr[1<<10][1<<10];
ll sum[1<<10][1<<10];
ll xsum[1<<10][1<<10];
ll ysum[1<<10][1<<10];
char ss[1<<10];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> r >> c >> d;
		//cout << "r = " << r << ", c = " << c << ", d= " << d << endl;
		for (int i = 0; i < r; i++){
			scanf("%s", ss);
			for (int j = 0; j < c; j++){
				arr[i][j] = (ss[j] - '0');
			}
		}
		memset(sum,0,sizeof(sum));
		memset(xsum,0,sizeof(xsum));
		memset(ysum,0,sizeof(ysum));
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + arr[i][j];
				xsum[i+1][j+1] = xsum[i][j+1] + xsum[i+1][j] - xsum[i][j] + i*arr[i][j];
				ysum[i+1][j+1] = ysum[i][j+1] + ysum[i+1][j] - ysum[i][j] + j*arr[i][j];
			}
		}
		/*for (int i = 0; i <= r; i++){
			for (int j = 0; j <= c; j++)
				cout << sum[i][j] << " ";
			cout << endl;
		}*/
		ll curr = min(r,c);
		for (; curr >= 3; curr--){
			bool okay = false;
			for (int i = 0; i + curr <= r; i++){
				for (int j = 0; j + curr <= c; j++){
					ll mass = sum[i+curr][j+curr] - sum[i][j+curr]-sum[i+curr][j]+sum[i][j];
					ll xm = xsum[i+curr][j+curr] - xsum[i][j+curr]-xsum[i+curr][j]+xsum[i][j];
					ll ym = ysum[i+curr][j+curr] - ysum[i][j+curr]-ysum[i+curr][j]+ysum[i][j];
					for (int ii = i; ii < i + curr; ii += curr-1)
						for (int jj = j; jj < j+curr; jj += curr-1){
							mass -= arr[ii][jj];
							xm -= ii * arr[ii][jj];
							ym -= jj * arr[ii][jj];
						}
					if (curr == 5 && i == 1 && j == 1){
						//cout << "mass = " << mass << ", i = " << xm << ", j = " << ym << endl;	
					}
					if (mass*(2*i+curr-1) == 2*xm && mass * (2*j+curr-1) == 2*ym) {
						okay = true;
						//cout << "found square: size = " << curr << ", x = " << i << ", y = " << j << endl;
						break;
					}
				}
				if (okay) break;
			}
			if (okay) break;
		}
		if (curr < 3){
			printf("Case #%d: IMPOSSIBLE\n",zz);
		}
		else printf("Case #%d: %lld\n",zz,curr);
	}
	
	return 0;
}
