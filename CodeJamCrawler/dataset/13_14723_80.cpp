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

#include <gmpxx.h> // http://gmplib.org

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

bool palindrome (string nb)
{
    const size_t sz =  nb.size() - 1;
    const size_t end = nb.size() / 2;
    for (size_t k = 0; k < end; ++k)
    {
        if (nb[k] != nb[sz - k])
        {
            return false;
        }
    }
    return true;
}

void process_test_case(int tc_nb)
{
    string begin_string, end_string;
    in >> begin_string >> end_string;
    const mpz_class begin(begin_string);
    const mpz_class end(end_string);

    mpz_class sbegin = sqrt(begin);
    const mpz_class send = sqrt(end);

    if (sbegin * sbegin < begin)
    {
        sbegin += 1;
    }

    long long counter = 0;
    for (mpz_class k = sbegin; k <= send; ++k)
    {
        if (palindrome(k.get_str()))
        {
            const mpz_class t = k * k;
            if (palindrome(t.get_str()))
            {
                ++counter;
            }
        }
    }

    out << "Case #" << tc_nb << ": " << counter << endl;

}

int main()
{
    string pb_id = "C";
    string pb_type = "small";
    FileGuard<ifstream> input_guard(in, pb_id + "-" + pb_type + ".in");
    FileGuard<ofstream> output_guard(out, pb_id + "-" + pb_type + ".out");

    cout << pb_id + "-" + pb_type + ".in" << endl;
    cout << pb_id + "-" + pb_type + ".out" << endl;

    int tc_count;
    in >> tc_count;

    for (int tc_nb = 1; tc_nb <= tc_count; ++tc_nb)
    {
        process_test_case(tc_nb);
    }

    return 0;
}
