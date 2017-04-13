#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

int main(void) {

    
 std::ifstream input("B-large.in");
 std::ofstream output("CookieTime.txt");
 std:: string line;

 if (input.is_open()) {
    std::getline(input, line);
    int test_num  = atoi(line.c_str());
    for (int t = 1; t <= test_num; t++) {
        double rate = 2.0000000;
        double total_time = 0.0000000;
        double C;
        double F;
        double X;
        bool printed = false;
        getline(input, line);
        std::istringstream numbers(line.c_str());
        numbers >> C >> F >> X;
        while (!printed) {
        if ((X/rate) <= ((C/rate)+(X/(rate+F)))){
            total_time += (X/rate);
            output << "Case #"<<t<<": "<<std::setprecision(10)<<total_time<<std::endl;
            printed = true;
        }
        else {
            total_time += (C/rate);
                        rate += F;
        }
        }
    }
 }
input.close();
output.close();

return 0;
}
