#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

// Define the matrix row and column
const int CARD_MATRIX_ROW = 4;
const int CARD_MATRIX_COL = 4;

// Reading the card matrix and return the selected row
string get_selected_row(ifstream& in, int selected)
{
    // Reading card matrix
    string seleted_row;
    string input_row;
    for (int i = 1; i <= CARD_MATRIX_ROW; ++i) {
        // Reading card matrix row, if it is not selected row,
        // just discard it.
        getline(in, input_row);

        // If it is the selected row, reading the related card numbers
        if (selected == i) {
            seleted_row = input_row;
        }
    }

    return seleted_row;
}

int main(int argc, char* argv[])
{
    if (argc > 3) {
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
        // Get user's first answer
        int first_selected;
        input_stream >> first_selected >> ws;

        // Reading the first card matrix
        string selected_row;
        selected_row = get_selected_row(input_stream, first_selected);

        vector<int> cards;
        istringstream first_selected_row(selected_row);
        int card_num;
        for (int k = 0; k < CARD_MATRIX_COL; ++k) {
            first_selected_row >> card_num >> ws;
            cards.push_back(card_num);
        }

        // Reading the second card matrix
        int second_selected;
        input_stream >> second_selected >> ws;
        selected_row = get_selected_row(input_stream, second_selected);
        istringstream second_selected_row(selected_row);

        int selected_num_count = 0;
        int selected_num;
        for (int k = 0; k < CARD_MATRIX_COL; ++k) {
            // Reading a card number, then searching it in the first selected row
            int card_num;
            second_selected_row >> card_num >> ws;
            for (vector<int>::iterator iter=cards.begin(); iter != cards.end(); ++iter) {
                if (*iter == card_num) {
                    selected_num = card_num;
                    ++selected_num_count;
                }
            }
        }

        switch(selected_num_count) {
        case 0:
            out_stream << "Case #" << i << ": " << "Volunteer cheated!" << '\n';
            break;
        case 1:
            out_stream << "Case #" << i << ": " << selected_num << '\n';
            break;
        default:
            out_stream << "Case #" << i << ": " << "Bad magician!" << '\n';
            break;
        }
    }

    input_stream.close();
    out_stream.close();

    return 0;
}
