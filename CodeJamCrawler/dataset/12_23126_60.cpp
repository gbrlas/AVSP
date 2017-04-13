#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>


int main(int argc, char *argv[])
{
    std::string inString("ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv");
    std::string outString("our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up");
    assert(inString.size()==outString.size());

    std::map<char, char> in2out, out2in;
    for(int i = 0; i < inString.size(); i++)
    {
        in2out[inString[i]] = outString[i];
        out2in[outString[i]] = inString[i];
    }

    std::string alphas("abcdefghijklmnopqrstuvwxyz");
    assert(alphas.size()==26);

    std::vector<char> unknownIns, unknownOuts;
    for(int i = 0; i < alphas.size(); i++)
    {
        if(in2out.find(alphas[i])==in2out.end())
        {
            unknownIns.push_back(alphas[i]);
        }

        if(out2in.find(alphas[i])==out2in.end())
        {
            unknownOuts.push_back(alphas[i]);
        }
    }
    assert(unknownIns.size()==unknownOuts.size());


    // manually insert mapping for missing characters
    in2out['q'] = 'z'; in2out['z'] = 'q';
    out2in['q'] = 'z'; out2in['z'] = 'q';


    // manually set mapping for q and z
    int ncases;
    std::cin >> ncases;
    std::string ignoreLine;
    std::getline(std::cin, ignoreLine);

    for(int i = 0; i < ncases; i++)
    {
        std::string newInString;
        std::getline(std::cin, newInString);
        
        std::cout << "Case #" << i+1 << ": ";
        for(int j = 0; j < newInString.size(); j++)
        {
            std::cout << in2out[newInString[j]];
        }
        std::cout << std::endl;
    }
}
