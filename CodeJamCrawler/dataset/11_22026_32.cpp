#include <assert.h>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

using namespace std;

struct myType {
	int			index;
	long long	start_time;
	long long	distance;
	long long	end_time;
	static bool cmp (const myType &first, const myType &second) {
		return true;
	}
};


int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": " ;
		int L, N, C;
		long long	t;
		cin	>> L >> t >> N >> C;
		assert (L >= 0 && t >= 0 && C > 0 && N >= C);
		vector<long long>	distanceC(C);
		for (int i=0; i<C; i++) {
			cin >> distanceC[i];
			assert (distanceC[i] > 0);
			distanceC[i] *= 2;
		}
		vector<myType>	data(N);
		data[0].index = 0;
		data[0].distance = distanceC[0];
		data[0].end_time = distanceC[0];
		for (int i=1, index_C = 1; i<N; i++, index_C++) {
			if (index_C == C)
				index_C = 0;
			data[i].index = i;
			data[i].start_time = data[i-1].end_time;
			data[i].distance = distanceC[index_C];
			data[i].end_time = data[i-1].end_time + data[i].distance;
		}

		vector<myType>	candidate;
		for (int i=0; i<N; i++) {
			if (data[i].end_time > t) {
				candidate.push_back(data[i]);
			}
		}

		long long max_savedTime = 0;
		if(candidate.size() == 0 || L == 0) {

		} else if (L == 1){
			for (int i=0; i<candidate.size(); i++) {
				long long currentSavedTime;
				if (candidate[i].start_time >= t)
					currentSavedTime = candidate[i].distance / 2;
				else {
					currentSavedTime = (candidate[i].distance -  (t - candidate[i].start_time ) )/ 2;
				}
				max_savedTime = max(max_savedTime, currentSavedTime);
			}
		} else if (L == 2) {
			for (int i=0; i<candidate.size(); i++) {
				long long currentSavedTime;
				if (candidate[i].start_time >= t)
					currentSavedTime = candidate[i].distance / 2;
				else {
					currentSavedTime = (candidate[i].distance -  (t - candidate[i].start_time ) )/ 2;
				}

				long long max_st2 = 0;
				for (int j=i+1; j<candidate.size(); j++) {
					if (candidate[j].end_time - currentSavedTime <= t) {
						continue;
					}
					long long currentST2;
					if (candidate[j].start_time  - currentSavedTime >= t)
						currentST2 = candidate[j].distance / 2;
					else {
						currentST2 = (candidate[j].distance -  (t - candidate[i].start_time + currentSavedTime) )/ 2;
					}
					max_st2 = max(max_st2, currentST2);
				}

				max_savedTime = max(max_savedTime, currentSavedTime + max_st2);
			}
		}

		cout << data[N-1].end_time - max_savedTime << endl;
	}
}
