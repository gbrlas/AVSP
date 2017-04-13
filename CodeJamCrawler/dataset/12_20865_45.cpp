#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
                char line[101];
                input_file.getline(line, sizeof(line));
                int T=boost::lexical_cast<int>(line);
                for (int x=1; x<=T; x++)
                {
                    input_file.getline(line, sizeof(line));
                    
                    std::vector<std::string> line_tokens;
                    boost::split(line_tokens, line, boost::is_any_of(" "));

                    int N=boost::lexical_cast<int>(line_tokens[0]);
                    int S=boost::lexical_cast<int>(line_tokens[1]);
                    int p=boost::lexical_cast<int>(line_tokens[2]);
                    int y=0;
                    int s=0;
                    std::vector<int> t;
                    
                    for (int i=0; i<N; i++)
                        t.push_back(boost::lexical_cast<int>(line_tokens[i+3]));

                    for (int i=0; i<N; i++)
                    {
                        int max=(t[i]==0)?0:(t[i]-1)/3+1;
                        int max_with_surprise=((t[i]%3)==1||max==10||t[i]==0)?max:max+1;
                        if (max>=p)
                            y++;
                        else if (max_with_surprise>=p && s<S)
                        {
                            y++;
                            s++;
                        }
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