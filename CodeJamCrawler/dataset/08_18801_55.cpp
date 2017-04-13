#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;


void readtime(int& t)
{
	int h,m;
	cin >> h;
	if (cin.get() != ':') throw 0;
	cin >> m;
	t = h * 60 + m;
}


struct Trip
{
	int dir;  // 0 A->B, 1 B->A
	int dep, arr;  // minutes from midnight

	bool operator<(Trip const& other) {
		return dep < other.dep;
	}
};


void Case()
{
	int turnaround;
	cin >> turnaround;
	int NA, NB;
	cin >> NA >> NB;
	vector<Trip> trip(NA+NB);
	for (int i = 0; i < NA+NB; ++i) {
		trip[i].dir = (i >= NA);
		readtime(trip[i].dep);
		readtime(trip[i].arr);
	}
	sort(trip.begin(), trip.end());
	int need[2] = {0,0};
	multiset<int> stations[2];
	for (vector<Trip>::iterator i = trip.begin(); i != trip.end(); ++i) {
		Trip& t = *i;
		multiset<int> &src = stations[t.dir], &dst = stations[!t.dir];
		multiset<int>::iterator lo = src.begin();
		if (src.empty() || *lo > t.dep) {
			++need[t.dir];
		} else {
			src.erase(lo);
		}
		dst.insert(t.arr + turnaround);
	}
	printf("%d %d\n", need[0], need[1]);
}


int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		printf("Case #%d: ", i);
		Case();
	}
}
