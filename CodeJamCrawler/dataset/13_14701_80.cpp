#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <fstream>
#include <string>

using namespace std;

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

string next_line(istream & in);

#endif // FILEUTILS_H
