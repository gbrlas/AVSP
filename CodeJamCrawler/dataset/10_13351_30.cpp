// ****************************************************************************
// File: main.cc
// Author: Nigel Struble (ASCII)
// Date: 7/05/2010
// Purpose: 	The main() for the Theme park problem
// ****************************************************************************

#include <iostream>
#include <fstream>


using namespace std;
int main(int args, char *argv[]){
	static size_t ring[1000];
	struct queue{
		int size;
		queue(){size = 0;}
		void insert(size_t n){
			ring[size] = n;
			size++;
		}
		int next_index(int n){
			return ((n +1) % size);
		}
	};
	if (args != 2){
		cout << "wrong input size" << endl;
		return 1;
	}
	ifstream ifs(argv[1]);
	if (ifs.fail()){
		cout << "unable to open file" << endl;
		return 1;
	}
	size_t number_of_cases;
	ifs >> number_of_cases;
	size_t R, k, N, euros(0);
	ifs >> R >> k >> N;
	for(size_t case_number = 0; case_number < number_of_cases; ++case_number){
		euros = 0;
		queue line;
		for(size_t group_number = 0; group_number < N; ++group_number){
			size_t group_size;
			ifs >> group_size;
			line.insert(group_size);
		}
		int queue_index = 0;
		for(size_t run_number = 0; run_number < R; ++run_number){
			size_t people_in_coaster = 0;
			size_t number_of_groups_in_coaster = 0;
			while(people_in_coaster < k && number_of_groups_in_coaster  < N){
				number_of_groups_in_coaster++;
				if(people_in_coaster + ring[queue_index] <= k){
					people_in_coaster += ring[queue_index];
					queue_index = line.next_index(queue_index);
				}else
					break;
			}
			euros += people_in_coaster;				
		}
		cout << "Case #" << case_number +1 << ": " << euros << endl;
		ifs >> R >> k >> N;
	}
	
}
