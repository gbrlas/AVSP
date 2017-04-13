#include <iostream>
#include <fstream>
using namespace std;
#include <list>
#include <vector>

int main(){
	
	string input;
  	ifstream myfile ("input.in");
	int current_line = 1;
	int number_of_output;
	int current_output=1;
  	if (myfile.is_open())
  	{
		while ( !myfile.eof() ) {
			int r;
			int k;
			int n;
			if (current_line == 1){
				getline (myfile,input);
				number_of_output = atoi(input.c_str());
				current_line++;
			}
			else if (current_line % 2 == 0){
				//read the three numbers, parse through spaces
				getline (myfile,input);
				current_line++;
			
				string word_list[3];
				int current_word_list = 0;
				string word;
				int fourth_line_input_location;
				string n_value;
				for (unsigned int i=0; i < input.length(); i++){
					if (input[i] != ' '){
						word.append(1, input[i]);
					}
					else{
						fourth_line_input_location = i+1;
						word_list[current_word_list] = word;
						current_word_list++;
						word = "";
					}
				}
				for (unsigned int i=fourth_line_input_location ; i < input.length(); i++){
					n_value.append(1, input[i]);
				}
				r = atoi(word_list[0].c_str());
				k = atoi(word_list[1].c_str());
				n = atoi(n_value.c_str());
			}
			else{
				getline (myfile,input);
				current_line++;
				vector<int> rider_list;
				string word;
				int last_line_input_location;
				string last_value;
				if (input.length() == 1){
					rider_list.push_back(atoi(input.c_str()));
				}
				else{
					for (unsigned int i=0; i < input.length(); i++){
						if (input[i] != ' '){
							word.append(1, input[i]);
						}
						else{
							last_line_input_location = i+1;
							rider_list.push_back(atoi(word.c_str()));
							word = "";
						}
					}
					for (unsigned int i=last_line_input_location ; i < input.length(); i++){
						last_value.append(1, input[i]);
					}
					rider_list.push_back(atoi(last_value.c_str()));	
				}

				
				//now that you have the rider_list built, and you have r # of rides
				int r_temp = r;
				int this_line_total=0;
				while (r_temp > 0){
					//each time, you find out where the array needs to shift
					int temp_sum = 0;
					int counter = 0;
					while (temp_sum + rider_list.front() <= k && counter < n){
						int temp_front = rider_list.front();
						temp_sum += temp_front;
						rider_list.erase (rider_list.begin());
						rider_list.push_back(temp_front);
						counter ++;
					}
					this_line_total += temp_sum;
					r_temp--;
				}
				cout << "Case #" << current_output << ": "<< this_line_total << endl;
				current_output++;
			}
		}
	}
}