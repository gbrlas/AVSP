#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main() {
    std::ifstream input("A-small-attempt0.in");
    std::ofstream output("MagicTrick.txt");
    std::string line;
    int number;
    if (input.is_open()) {
        std::getline(input, line);
        int T = atoi(line.c_str());
        for (int t = 1; t <= T; t++) {
            int line_numbers[17] = {};
            for (int c = 1; c <= 2; c++) {
                getline(input, line);
                int guess = atoi(line.c_str());
                int ignore = 4-guess;
                while (guess-- > 0) getline(input, line);
                std::istringstream numbers(line.c_str());
                while (numbers >> number){
                    if (c == 1) line_numbers[number]++;
                    else line_numbers[number]++;
                }
                while (ignore-- > 0) getline(input, line);
            }
            int answer = -1;
            for (int option = 1; option < 17; option++) {
                if (line_numbers[option] == 2 && answer == -1) answer = option;
                else if (line_numbers[option] == 2 ) {
                    output<<"Case #"<<t<<": Bad magician!\n";
                    answer = -2;
                    break;
                }
            }
            if (answer == -1) output<<"Case #"<<t<<": Volunteer cheated!\n";
            else if (answer > -1) output<<"Case #"<<t<<": "<<answer<<std::endl;
        }
    }
    input.close();
    output.close();

    return 0;
}
