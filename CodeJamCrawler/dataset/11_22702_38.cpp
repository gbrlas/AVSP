#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int test = 1; test <= lz; test++){
		int len;
		scanf("%d", &len);
		int wspeed, rspeed;
		scanf("%d %d", &wspeed, &rspeed);
		int t;
		scanf("%d", &t);
		int n;
		scanf("%d", &n);
		vector<int> start(n+1);
		vector<int> end(n+1);
		vector<int> add(n+1);
		for ( int i = 0; i < n; i++) scanf("%d%d%d", &start[i], &end[i], &add[i]);
		start[n] = len;
		end[n] = len;
		add[n] = 0;
		
		vector<pair<int, int> > segs; // speed, distance;
		int at = 0;
		for ( int i = 0; i < n+1; i++ ){			
			
			segs.push_back(pii(0, start[i] - at));
			at = start[i];
			segs.push_back(pii(add[i], end[i]-at));
			at = end[i];
		}
		
		sort(segs.begin(), segs.end());
		double res = 0.0;
		double left = t;
		
		for ( int i = 0; i < segs.size(); i++){
	
			double dist = segs[i].second;
			double neededOnSpeed = (dist)/(segs[i].first+rspeed);
			double doOnSpeed = min(neededOnSpeed, left);
			dist -= doOnSpeed*(segs[i].first+rspeed);
			left -= doOnSpeed;
			res += doOnSpeed;
			
			double neededRest = (dist)/(segs[i].first+wspeed);
			res += neededRest;
			
						
		}
		
		printf("Case #%d: %.9lf\n", test, res);
	}
	return 0;
}
