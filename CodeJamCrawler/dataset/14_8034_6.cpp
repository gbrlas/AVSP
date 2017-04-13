/*
 * main.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: jcscottiii
 */

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>
void GetRow(std::unordered_set<unsigned int>* row, std::string line) {
	const char* s;
	s = std::strtok((char *)line.c_str(), " ");
	for (int i = 1; i <= 4; ++i) {
		row->insert(std::stoi(s));
		s = std::strtok(NULL, " ");
	}
}
int main (int argc, char** argv) {
	if (argc != 2) {
		std::printf("Need file\n");
		return 128;
	} else {
		try {
			std::ifstream input(argv[1]);
			std::ofstream output("output.txt");
			if (input.is_open() && output.is_open()) {
				// Get number of cases
				std::string line;
				int line_num = -1;
				unsigned int cases = 0;
				unsigned int case_num = 1;
				unsigned short row_guess1 = 0;
				std::unordered_set<unsigned int> row1;
				unsigned short row_guess2 = 0;
				std::unordered_set<unsigned int> row2;
				while (std::getline(input, line)) {
					switch(line_num) {
					case -1:
						cases = std::stoi(line);
						++line_num;
						break;
					case 0:
						row_guess1 = std::stoi(line);
						++line_num;
						break;
					case 1:
					case 2:
					case 3:
					case 4:
						if (row_guess1== line_num) {
							GetRow(&row1, line);
						}
						++line_num;
						break;
					case 5:
						row_guess2 = std::stoi(line);
						++line_num;
						break;
					case 6:
					case 7:
					case 8:
					case 9:
						if (row_guess2 == line_num - 5) {
							GetRow(&row2, line);
							unsigned int num = 0;
							std::unordered_set<unsigned int> matches;
							for (auto it = row1.begin(); it !=row1.end(); ++it) {
								if (row2.find(*it) != row2.end()) {
									matches.insert(*it);
									num=*it;
								}
							}
							for (auto it = row2.begin(); it !=row2.end(); ++it) {
								if (row1.find(*it) != row1.end()) {
									matches.insert(*it);
									num=*it;
								}
							}
							if(matches.size()>1)
								output << "Case #"<<case_num<<": Bad magician!";
							else if (matches.size()==1)
								output << "Case #"<<case_num<<": "<<num;
							else
								output << "Case #"<<case_num<<": Volunteer cheated!";
							++case_num;
								output<<"\n";
						}
						if(line_num < 9)
							++line_num;
						else {
							line_num=0;
							row1.clear();
							row2.clear();
						}
						break;
					default:
						break;
					}
				}
				output.close();
				input.close();
			}
		} catch (...) {
			std::printf("something went wrong...");
		}
	}
	return 1;
}



