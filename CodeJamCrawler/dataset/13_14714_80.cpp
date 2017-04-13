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

using namespace std;

ifstream in;
ofstream out;

template<typename StreamTypeT>
class FileGuard
{
public:
    FileGuard(StreamTypeT & stream, string filename)
        : m_stream(stream)
    {
        stream.open(filename);
    }

    ~FileGuard()
    {
        m_stream.close();
    }

private:
    StreamTypeT & m_stream;
};

string next_line(istream & in)
{
    string tmp;
    getline(in, tmp);
    return tmp;
}

template<typename T>
vector<T> get_line_to_vector()
{
    string line;
    getline(in, line);
    istringstream line_stream(line);
    istream_iterator<T> line_begin(line_stream), line_end;

    return vector<T>(line_begin, line_end);
}

bool check_row(vector<vector<int> > lawn, int cell, int row)
{
    const int cols = lawn[0].size();

    for (int k = 0; k < cols; ++k)
    {
        if (lawn[row][k] > cell)
        {
            return false;
        }
    }
    return true;
}

bool check_column(vector<vector<int> > lawn, int cell, int col)
{
    const int rows = lawn.size();

    for (int k = 0; k < rows; ++k)
    {
        if (lawn[k][col] > cell)
        {
            return false;
        }
    }
    return true;
}
void process_test_case(int tc_nb)
{
    int  nb_rows, nb_columns;
    in >> nb_rows;
    in >> nb_columns;

    vector<vector<int> > lawn;
    for (int i = 0; i < nb_rows; ++i)
    {
        vector<int> row;
        for (int j = 0; j < nb_columns; ++j)
        {
            int tmp;
            in >> tmp;
            row.push_back(tmp);
        }
        lawn.push_back(row);
    }

    // Check the lawn:
    for (int i = 0; i < nb_rows; ++i)
    {
        for (int j = 0; j < nb_columns; ++j)
        {
            if (! (check_row(lawn, lawn[i][j], i)
                   || check_column(lawn, lawn[i][j], j)))
            {
                out << "Case #" << tc_nb << ": " << "NO" << endl;
                return;
            }
        }
    }
    out << "Case #" << tc_nb << ": " << "YES" << endl;
}

int main()
{
    string pb_id = "B";
    string pb_type = "small";
    FileGuard<ifstream> input_guard(in, pb_id + "-" + pb_type + ".in");
    FileGuard<ofstream> output_guard(out, pb_id + "-" + pb_type + ".out");

    cout << "Input file:  " << pb_id + "-" + pb_type + ".in"  << endl;
    cout << "Output file: " << pb_id + "-" + pb_type + ".out" << endl;

    int tc_count;
    in >> tc_count;

    cout << "#tc_count: " << tc_count << endl;

    for (int tc_nb = 1; tc_nb <= tc_count; ++tc_nb)
    {
        process_test_case(tc_nb);
    }

    return 0;
}
