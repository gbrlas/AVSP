#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Not enough parameters!!!" << endl;
        cout << "Usage: MagicTrick input_file_name output_file_name" << endl;
        exit(EXIT_FAILURE);
    }

    // Open file for outputing the result
    ofstream out_stream(argv[2]);

    // Open file for reading the test cases
    ifstream input_stream(argv[1]);
    int case_num;
    input_stream >> case_num >> ws;
    for (int i=1; i <= case_num; ++i) {
        double farm_cost_cookies;
        input_stream >> farm_cost_cookies >> ws;
        double farm_produce_cookies;
        input_stream >> farm_produce_cookies >> ws;
        double exceed_cookies;
        input_stream >> exceed_cookies >> ws;

        double total_seconds = 0;
        // Calculate the max number for checking
        int high_num = static_cast<int>(exceed_cookies / farm_cost_cookies) + 1;
        for (int j = 0; j < high_num; ++j) {
            double cookies_per_secs = 2 + farm_produce_cookies * j;
            double current_seconds = exceed_cookies / cookies_per_secs;
            double next_seconds = farm_cost_cookies / cookies_per_secs + exceed_cookies / (cookies_per_secs + farm_produce_cookies);
            if (next_seconds > current_seconds) {
                total_seconds += current_seconds;
                break;
            }

            total_seconds += (farm_cost_cookies / cookies_per_secs);
        }

        out_stream << "Case #" << i << ": " << showpoint << fixed << setprecision(7) << total_seconds << '\n';
    }

    input_stream.close();
    out_stream.close();

    return 0;
}
