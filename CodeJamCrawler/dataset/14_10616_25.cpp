#include <iostream>
#include <iomanip>

using namespace std;

void doCase() {
	double farm_cost, farm_rate, goal;
	cin >> farm_cost >> farm_rate >> goal;

	double seconds = 0, current_rate = 2;

	while( goal/current_rate > (goal/(current_rate+farm_rate) + farm_cost/current_rate) ) {
		seconds += farm_cost/current_rate;
		current_rate += farm_rate;
	}

	seconds += goal/current_rate;

	cout << seconds;
}

int main() {
	int T;
	cin >> T;
	cout << setprecision(10);
	for( int i=0; i<T; ++i ) {
		cout << "Case #" << (i+1) << ": ";
		doCase();
		cout << endl;
	}
}
