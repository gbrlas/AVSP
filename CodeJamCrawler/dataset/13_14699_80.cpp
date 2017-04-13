#include "FileUtils.h"


string next_line(istream & in)
{
    string tmp;
    getline(in, tmp);
    return tmp;
}
