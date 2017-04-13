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
        stream.exceptions(ios::failbit);
        cerr << "Opening `" << filename << "' ..... ";
        try
        {
            stream.open(filename);
        }
        catch (const ios::failure & e)
        {
            cerr << "[FAILED]" << endl;
            exit(-1);
        }

        cerr << "[SUCCESS]" << endl;
    }

    ~FileGuard()
    {
        m_stream.close();
    }

private:
    StreamTypeT & m_stream;
};

void process_test_case(int tc_nb)
{
    cout << "TC #" << tc_nb << endl;
    string name;
    in >> name;
    size_t len = name.size();
    size_t n;
    in >> n;
    size_t c_found = 0;
    size_t curr = 0;
    size_t count = 0;
    size_t prev_begin = 0;

    while (curr < len)
    {
        // Find group starting at index curr included
        c_found = name.find_first_not_of("aeiou", curr);
        if (c_found == string::npos)
        {
            break ;
        }
        else if (c_found + n > len)
        {
            // not enough consonnants until end
            break ;
        }
        else
        {
            // Find if there is enough consonnants
            size_t v_found = name.find_first_of("aeiou", c_found);
            v_found = min(v_found, len);
            const size_t nb_cons = (v_found - c_found);
            if (nb_cons > n)
            {
                v_found = c_found + n;
            }
            if (nb_cons < n)
            {
                curr = c_found + 1;
            }
            else
            {
                const size_t before =  c_found - (prev_begin);
                const size_t after = len - v_found;
                count += (before + 1) * (after + 1);
                //
                prev_begin = c_found + 1;
                curr = c_found + 1;
            }
        }
    }
    out << "Case #" << tc_nb << ": " << count << endl;


//    out << "Case #" << tc_nb << ": " <<  << endl;
}

int main()
{
    string pb_id = "A";
    string pb_type = "small-attempt0";
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
