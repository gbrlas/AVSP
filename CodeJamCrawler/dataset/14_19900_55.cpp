#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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
        int block_num;
        input_stream >> block_num >> ws;

        // Reading Naomi's blocks and sort it.
        double block_weight;
        vector<double> naomi_blocks;
        for (int j=0; j < block_num; ++j) {
            input_stream >> block_weight >> ws;
            naomi_blocks.push_back(block_weight);
        }
        sort(naomi_blocks.begin(), naomi_blocks.end());

        // Reading Ken's blocks and sort it.
        vector<double> ken_blocks;
        for (int j=0; j < block_num; ++j) {
            input_stream >> block_weight >> ws;
            ken_blocks.push_back(block_weight);
        }
        sort(ken_blocks.begin(), ken_blocks.end());

        // For deceitful case, calculate Ken's score
        int n = block_num - 1;
        for (int j = block_num-1; j >= 0; --j) {
            if (naomi_blocks[n] > ken_blocks[j]) {
                --n;
            }
        }
        int naomi_deceitful_score = block_num - n - 1;

        // For normal case, calculate Ken's score
        int k = 0;
        for (int j=0; j < block_num; ++j) {
            if (ken_blocks[j] > naomi_blocks[k]) {
                ++k;
            }
        }
        int naomi_normal_score = block_num - k;

        out_stream << "Case #" << i << ": " << naomi_deceitful_score << " " << naomi_normal_score << '\n';
    }

    input_stream.close();
    out_stream.close();

    return 0;
}
