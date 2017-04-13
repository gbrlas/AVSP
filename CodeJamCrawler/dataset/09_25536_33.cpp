#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

int main(int argc, char *argv[])
{
    std::ifstream input("data.txt");
    std::ofstream output("out.txt");
    std::vector<std::string> word_list;
    int L,D,N;
    input>>L>>D>>N;
    std::string buffer;
    for (int i=0; i<D; i++)
    {
        input>>buffer;
        word_list.push_back(buffer);
    }
    
    int e = 0;
    int count = 0;
    int last_pos = 0;
    std::string::iterator it;
    std::string::iterator p;
    typedef std::set<char> char_set;
    std::map<int, char_set> case_map;
    for (int j=0; j<N; j++)
    {
        input>>buffer;
        while (!buffer.empty() && (last_pos < L))
        {
              it = std::find(buffer.begin(), buffer.end(), '(');
              if (it == buffer.end())
              {
                     for (int k=0; k<buffer.size(); k++)
                     {
                             case_map[last_pos].insert(buffer[k]);
                             last_pos++;
                     }
                     break;
              }
              else
              {
                  for (p = buffer.begin(); p != it; ++p)
                  {
                      case_map[last_pos].insert(*p);
                      last_pos++;
                  }
                  
                  p = std::find(it, buffer.end(), ')');
                  
                  for (std::string::iterator r=it+1; r != p; ++r)
                  {
                      case_map[last_pos].insert(*r);
                  }
                  last_pos++;
                  
                  buffer.erase(buffer.begin(), p+1);
              }
        }//end of while
        /*
        std::cout<<"case index "<<j<<std::endl;        
        for (int u=0; u<L; u++)
        {
            std::copy(case_map[u].begin(), case_map[u].end(), std::ostream_iterator<char>(std::cout));
            std::cout<<std::endl;
        }
        */
        last_pos = 0;
        //judge count
        for (std::vector<std::string>::iterator str_it = word_list.begin(); str_it != word_list.end(); ++str_it)
        {
            for (e=0; e<L; e++)
            {
                if (case_map[e].find((*str_it)[e]) == case_map[e].end())
                {
                 break;
                }
            }
            if (e >= L)
            {
                  count++;
            }
        }
        
        output<<"Case #"<<j+1<<": "<<count<<std::endl;
        case_map.clear();
        count = 0;
    }
    output.close();
    input.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
