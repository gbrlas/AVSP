#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

int main(int argc, char** argv)
{
    try
    {
        if (argc>2)
        {
            std::ifstream input_file(argv[1]);
            std::ofstream output_file(argv[2]);
            if (input_file.good())
            {
                char line[64];
                input_file.getline(line, sizeof(line));
                int T=boost::lexical_cast<int>(line);
                for (int x=1; x<=T; x++)
                {
                    input_file.getline(line, sizeof(line));
                    
                    std::vector<std::string> line_tokens;
                    boost::split(line_tokens, line, boost::is_any_of(" "));
                    
                    int A=boost::lexical_cast<int>(line_tokens[0]);
                    int B=boost::lexical_cast<int>(line_tokens[1]);
                    int y=0;
                    for (int m=A; m<=B; m++)
                    {
                        std::string m_str=boost::lexical_cast<std::string>(m);
                        size_t m_len=m_str.length();

                        std::set<std::string> n_strs;
                        for (unsigned int i=1; i<m_len; i++)
                            n_strs.insert(m_str.substr(m_len-i, i)+m_str.substr(0, m_len-i));

                        for (std::set<std::string>::const_iterator n_str_it=n_strs.begin(); n_str_it!=n_strs.end(); n_str_it++)
                            if (m_str<*n_str_it && boost::lexical_cast<int>(*n_str_it)<=B)
                                y++;
                    }

                    output_file << "Case #" << x << ": " << y << std::endl;
                }
            }
        }
    }
    catch(...)
    {
    };
}