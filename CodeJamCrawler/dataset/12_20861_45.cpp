#include <string>
#include <iostream>
#include <fstream>

#include <boost/lexical_cast.hpp>

char* trans_map="yhesocvxduiglbkrztnwjpfmaq";

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
                unsigned char T=boost::lexical_cast<unsigned long>(line);
                for (int t=1; t<=T; t++)
                {
                    input_file.getline(line, sizeof(line));
                    for (int i=0; line[i]; i++)
                        if (line[i]!=' ' && line[i]>='a' && line[i]<='z')
                            line[i]=trans_map[line[i]-'a'];
                    output_file << "Case #" << t << ": " << line << std::endl;
                }
            }
        }
    }
    catch(...)
    {
    };
}