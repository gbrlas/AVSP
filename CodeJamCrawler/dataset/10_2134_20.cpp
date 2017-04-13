#include <iostream>
#include <fstream>
using namespace std;
#include <string>
int toggle(int input){
	if (input == 0){
		return 1;
	}
	return 0;
}

string handle_question(int n, int k){
	//create snappers array
	int snappers[n];
	//initialize them all to 0
	for (int i=0; i < n; i++){
		snappers[i] = 0;
	}
	for (int i=0; i < n; i++){
		// cout << "#" << i << ":" << snappers[i] << endl;
	}
	//create the looper to do the process k times
	int k_looper=0;
	while (k_looper < k){
		//each time
		//loop through the snappers array
		int snapper_array_looper = 0;
		bool encountered_unpowered = false;
		while ( snapper_array_looper < n && !encountered_unpowered){
			// cout << snapper_array_looper << ": "<< snappers[snapper_array_looper] << endl;
			if (snappers[snapper_array_looper] == 0){
					// cout << "FOUND" << endl;
					encountered_unpowered = true;
					snappers[snapper_array_looper] = 1;
			}
			else{
				snappers[snapper_array_looper] = toggle(snappers[snapper_array_looper]);
			}
			snapper_array_looper++;
		}
		k_looper++;
	}
	bool is_powered = true;
	for (int i=0; i < n-1; i++){
		//loop through the entire thing up to n-1, if there is a zero somewhere, retrun off, otherwise return on
		if (snappers[i] == 0){
			is_powered = false;
		}
	}
	if (is_powered && snappers[n-1] == 1){
		return "ON";
	}
	return "OFF";
}
int main(){
	
	fstream file;
	file.open("A-small.in",ios::in|ios::out);
	// 
	int number_of_answers;
	int current_line = 1;
	while ( !file.eof() ) {
		if (current_line == 1){
			string t_string;
		  	file >> t_string;
			number_of_answers = atoi(t_string.c_str());
			current_line++;
		}
		else{
			string t_string;
		  	file >> t_string;
		}
	}
	file.close();
	int n_s[number_of_answers];
	int current_n_s=0;
	int k_s[number_of_answers];
	int current_k_s=0;
	
	string answers[number_of_answers];
	int current_answers =0;
	
	string input;
  	ifstream myfile ("A-small.in");
	current_line = 1;
  	if (myfile.is_open())
  	{
    	while (! myfile.eof() )
    	{
			if (current_line == 1){
				getline (myfile,input);
				current_line++;
			}
			else{
				
				getline (myfile,input);
				current_line++;
				
				string word_list[4];
				int current_word_list = 0;
				
				string word;
				int fourth_line_input_location;
				string duration_string;
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
					word_list[3] = input[input.length()-1];
				}
				for (unsigned int i=fourth_line_input_location ; i < input.length(); i++){
					duration_string.append(1, input[i]);
				}
				n_s[current_n_s]= atoi(word_list[0].c_str());
				current_n_s++;
				k_s[current_k_s] = atoi(duration_string.c_str());
				current_k_s++;
			}
    	}	
	}
	myfile.close();
	for (int i=0; i < number_of_answers; i++){
		cout << "Case #"<< i+1 << ": " << handle_question(n_s[i], k_s[i]) << endl;
	}
	return 0;	
}