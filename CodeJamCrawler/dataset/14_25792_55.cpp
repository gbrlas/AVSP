#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define ll long long

inline bool cmp(double x, double y)
{
	return x > y;
}

int main()
{
	freopen("inp2.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; ++t) {
		int N;
		scanf("%d", &N);
		
		vector<double> Naomi;
		vector<double> ken;
		for(int i = 0; i < N; ++i) {
			double data;
			scanf("%lf", &data);
			Naomi.push_back(data);
		}
		
		for(int i = 0; i < N; ++i) {
			double data;
			scanf("%lf", &data);
			ken.push_back(data);
		}
		
		vector<double> v1 = Naomi;
		vector<double> v2 = ken;
		
		sort(Naomi.begin(), Naomi.end());
		sort(ken.begin(), ken.end());
		
		int DecWar = 0;
		for(int i = 0, j = 0; i < N && j < N; i++) {
			if(Naomi[i] > ken[j]) {
				DecWar++;
				j++;
			}
		}
		
		sort(v1.begin(), v1.end(), cmp);
		sort(v2.begin(), v2.end(), cmp);
		
		int War = 0;
		int size = N;
		int pos = 0;
		for(int i = 0; i < N; ++i) {
				int mila;
				bool flg = false;
				for(int j = pos; j < size; ++j) {
					if(v2[j] > v1[i]) {
						flg = true;
						mila = j;
						break;
					}
				}
				
				if(!flg) {
					War++;
					size--;
				} else {
					pos++;
				}
		}
		
		printf("Case #%d: %d %d\n", t, DecWar, War);
	}
	
	return 0;
}
