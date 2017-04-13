#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <limits>
//#include <gmpxx.h>

#include "FileUtils.h"

using namespace std;

string input_file_test = "test.in";
string output_file_test = "test.out";
string input_file_small = "A-small.in";
string output_file_small = "A-small.out";
string input_file_large = "A-large-practice.in";
string output_file_large = "A-large-practice.out";

ifstream in;
ofstream out;

template<typename T>
vector<T> get_line_to_vector()
{
    string line;
    getline(in, line);
    istringstream line_stream(line);
    istream_iterator<T> line_begin(line_stream), line_end;

    return vector<T>(line_begin, line_end);
}


void print(char g[][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            out << g[i][j] << ' ';
        }
        out << endl;
    }
}

struct Won
{
    Won(char p) : player(p)
    {}
    char player;
};

void check_columns(char g[][4], char player, bool & is_full)
{
    for (int l = 0; l < 4; l++)
    {
        int count = 0;
        for (int r = 0; r < 4; r++)
        {
            if (g[l][r] == player || g[l][r] == 'T')
            {
                ++count;
            }
            else if (g[l][r] == '.')
            {
                is_full = false;
            }
        }
        if (count == 4)
        {
            throw Won(player);
        }
    }
}

void check_lines(char g[][4], char player, bool & is_full)
{
    for (int r = 0; r < 4; r++)
    {
        int count = 0;
        for (int l = 0; l < 4; l++)
        {
            if (g[l][r] == player || g[l][r] == 'T')
            {
                ++count;
            }
            else if (g[l][r] == '.')
            {
                is_full = false;
            }
        }
        if (count == 4)
        {
            throw Won(player);
        }
    }
}


void check_diag_1(char g[][4], char player, bool & is_full)
{
    int count = 0;
    for (int k = 0; k < 4; ++k)
    {
        if (g[k][k] == player || g[k][k] == 'T')
        {
            ++count;
        }
        else if (g[k][k] == '.')
        {
            is_full = false;
        }
    }
    if (count == 4)
    {
        throw Won(player);
    }
}

void check_diag_2(char g[][4], char player, bool & is_full)
{
    int count = 0;
    for (int k = 0; k < 4; ++k)
    {
        if (g[k][3-k] == player || g[k][3-k] == 'T')
        {
            ++count;
        }
        else if (g[k][3-k] == '.')
        {
            is_full = false;
        }
    }
    if (count == 4)
    {
        throw Won(player);
    }
}
void process_test_case(int tc_nb)
{
    char g[4][4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            in >> g[i][j];
        }
    }

    char player = 'O';
    bool is_full = true;
    try
    {
        char player = 'O';
        check_columns(g, player, is_full);
        check_lines(g, player, is_full);
        check_diag_1(g, player, is_full);
        check_diag_2(g, player, is_full);

        player = 'X';
        check_columns(g, player, is_full);
        check_lines(g, player, is_full);
        check_diag_1(g, player, is_full);
        check_diag_2(g, player, is_full);
    }
    catch (const Won & w)
    {
        out << "Case #" << tc_nb << ": " <<  w.player << " won" << endl;
        return;
    }

    out << "Case #" << tc_nb << (is_full ? ": Draw" : ": Game has not completed") << endl;

}

int main()
{
    FileGuard<ifstream> input_guard(in, input_file_small);
    FileGuard<ofstream> output_guard(out, output_file_small);

    int tc_count;
    in >> tc_count;

    for (int tc_nb = 1; tc_nb <= tc_count; ++tc_nb)
    {
        process_test_case(tc_nb);
    }

    return 0;
}
