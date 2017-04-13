#include <assert.h>

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

struct info_node {
	int			button;
	int			available_time;
	info_node	*next;
};

static inline int mydistance(int src, int dst) {
	return (dst > src) ? (dst - src) : (src - dst);
}

int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": ";

		int 	N; // Number of Buttons
		cin	>> N;
		info_node	*info_array = new info_node[N];
		info_node	Orange	= {1, 0, NULL};
		info_node	Blue	= {1, 0, NULL};
		info_node	*O_previous = &Orange;
		info_node	*B_previous = &Blue;

		// Get inputs
		string 	robot;
		int		target_button;
		int 	i;
		for (i = 0; i < N; ++i) {
			cin >> robot >> target_button;
			assert( target_button > 0);
			info_array[i].button = target_button;

			if (robot == "O") {
				O_previous->next = info_array + i;
				O_previous = info_array + i;
			} else {
				B_previous->next = info_array + i;
				B_previous = info_array + i;
			}
		}

		// To avoid NULL checking
		O_previous->next = &Orange;
		B_previous->next = &Blue;

		int current_time = 0;

		Orange.next->available_time =  current_time + mydistance(Orange.next->button, 1);
		Blue.next->available_time =  current_time + mydistance(Blue.next->button, 1);

		// Get the job done
		for (i = 0; i < N; ++i) {
			if (current_time < info_array[i].available_time)
				current_time = info_array[i].available_time;
			current_time++;
			info_array[i].next->available_time =  current_time
					+ mydistance( info_array[i].next->button, info_array[i].button);
		}

		cout << current_time << endl;

		delete [] info_array;
	}
	return 0;
}
