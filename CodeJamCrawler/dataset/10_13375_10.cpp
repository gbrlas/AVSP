
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

class calculate_theme_park
{

};


int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("We need at least 2 parameters. %d parameters were submitted\n", argc - 1);

		return 1;
	}

	// input data file
	FILE * fin  = fopen(argv[1], "r");

	// output data file
	FILE * fout = fopen(argv[2], "w");

	int T = 0; // number of test cases

	int R = 0; // number of times roller coaster runs in the day

	int k = 0; // The roller coaster can hold k people at once

	int N = 0; // number of groups

	fscanf(fin, " %d ", &T);

	printf("There are %d test cases\n", T);

	// going through T test cases
	for (int i = 0; i < T; i++)
	{
		fscanf(fin, " %d %d %d ", &R, &k, &N);

		queue<int> groups_queue;

		queue<int> boarded_ride;

		int total_money_made_so_far = 0;

		// initial loading of groups into the queue
		for (int j = 0; j < N; j++)
		{
			int curr_group_size = 0;

			fscanf(fin, " %d ", &curr_group_size);

			groups_queue.push(curr_group_size);
		}

		// the roller coaster rides will go for R times in the day
		for (int x = 0; x < R; x++)
		{
			int ride_count = 0;

			while (groups_queue.size() > 0)
			{
				stringstream ss;

				ss << groups_queue.front();

				int group_size = 0;

				ss >> group_size;

				if ((ride_count + group_size) <= k)
				{
					ride_count += group_size;

					boarded_ride.push(group_size);
					groups_queue.pop();

				} else {

					break;
				}
			}

			// sending the groups that boarded to the back of the queue
			while(boarded_ride.size() > 0)
			{
				stringstream ss;

				ss << boarded_ride.front();

				int group_size = 0;

				ss >> group_size;

				boarded_ride.pop();

				groups_queue.push(group_size);
			}

			total_money_made_so_far += ride_count;
		}

		fprintf(fout, "Case #%d: %d\n", (i+1), total_money_made_so_far);
		fprintf(stdout, "Case #%d: %d\n", (i+1), total_money_made_so_far);
	}

	return 0;
}
